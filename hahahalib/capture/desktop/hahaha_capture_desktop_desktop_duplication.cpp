#pragma hdrstop
#include <cstring>
#include "hahaha_capture_desktop_desktop_duplication.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma package(smart_init)

namespace
{
//---------------------------------------------------------------------------
struct hahahalib_monitor_context
{
    int TargetIndex;
    int CurrentIndex;
    HMONITOR Monitor;
};
//---------------------------------------------------------------------------
BOOL CALLBACK MonitorEnumerateProc(HMONITOR monitor, HDC, LPRECT, LPARAM data)
{
    auto* context = reinterpret_cast<hahahalib_monitor_context*>(data);
    if (context->CurrentIndex == context->TargetIndex)
    {
        context->Monitor = monitor;
        return FALSE;
    }

    ++context->CurrentIndex;
    return TRUE;
}
//---------------------------------------------------------------------------
HMONITOR GetMonitorByIndex(int index)
{
    hahahalib_monitor_context context{ index, 0, nullptr };
    EnumDisplayMonitors(nullptr, nullptr, MonitorEnumerateProc, reinterpret_cast<LPARAM>(&context));
    if (!context.Monitor)
    {
        context.Monitor = MonitorFromPoint(POINT{ 0, 0 }, MONITOR_DEFAULTTOPRIMARY);
    }

    return context.Monitor;
}
//---------------------------------------------------------------------------
RECT NormalizeRect(RECT rect) noexcept
{
    if (rect.left > rect.right)
    {
        std::swap(rect.left, rect.right);
    }
    if (rect.top > rect.bottom)
    {
        std::swap(rect.top, rect.bottom);
    }
    return rect;
}
//---------------------------------------------------------------------------
bool IntersectRectsSafe(RECT& out, const RECT& a, const RECT& b) noexcept
{
    RECT result{};
    if (!IntersectRect(&result, &a, &b))
    {
        out = RECT{};
        return false;
    }
    out = result;
    return true;
}
//---------------------------------------------------------------------------
}

namespace hahahalib
{


//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::~hahaha_capture_desktop_desktop_duplication()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    Move(std::move(hcddd));
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication& hahaha_capture_desktop_desktop_duplication::operator=(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    if (this != &hcddd)
    {
        Reset();
        Move(std::move(hcddd));
    }

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Move(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    if (this != &hcddd)
    {
        Stop();

        Device_ = std::move(hcddd.Device_);
        Context_ = std::move(hcddd.Context_);
        Duplication_ = std::move(hcddd.Duplication_);
        Staging_Texture_ = std::move(hcddd.Staging_Texture_);

        Staging_Width_ = hcddd.Staging_Width_;
        Staging_Height_ = hcddd.Staging_Height_;
        hcddd.Staging_Width_ = 0;
        hcddd.Staging_Height_ = 0;

        {
            std::lock(Frame_Mutex_, hcddd.Frame_Mutex_);
            std::lock_guard<std::mutex> lockSelf(Frame_Mutex_, std::adopt_lock);
            std::lock_guard<std::mutex> lockOther(hcddd.Frame_Mutex_, std::adopt_lock);
            Frame_Snapshot_ = std::move(hcddd.Frame_Snapshot_);
        }

        {
            std::lock(State_Mutex_, hcddd.State_Mutex_);
            std::lock_guard<std::mutex> lockSelf(State_Mutex_, std::adopt_lock);
            std::lock_guard<std::mutex> lockOther(hcddd.State_Mutex_, std::adopt_lock);
            Capturing_ = hcddd.Capturing_;
            Options_ = hcddd.Options_;

            hcddd.Capturing_ = false;
            hcddd.Options_ = {};
        }
    }
}
//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Reset()
{
    Stop();
    return 0;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Initialize()
{
    return Ensure_Device();
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Start(const hahaha_capture_desktop_desktop_duplication_options& options)
{
    Options_ = options;
    if (!Ensure_Device())
    {
        return false;
    }

    Stop();

    if (!Create_Duplication(options.Monitor_Index_))
    {
        return false;
    }

    {
        std::lock_guard<std::mutex> lock(State_Mutex_);
        Capturing_ = true;
    }
    return true;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Start_By_Monitor(HMONITOR monitor, int timeout_ms)
{
    if (!monitor)
    {
        return false;
    }

    Options_ = {};
    Options_.Timeout_Ms_ = timeout_ms;
    Use_Monitor_Handle_ = true;
    Monitor_ = monitor;

    if (!Ensure_Device())
    {
        return false;
    }

    Stop();

    if (!Create_Duplication_By_Monitor(monitor))
    {
        return false;
    }

    {
        std::lock_guard<std::mutex> lock(State_Mutex_);
        Capturing_ = true;
    }
    return true;
}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Stop()
{
    Duplication_.reset();

    {
        std::lock_guard<std::mutex> lock(Frame_Mutex_);
        Frame_Snapshot_ = {};
        Staging_Texture_.reset();
        Staging_Width_ = 0;
        Staging_Height_ = 0;
        Staging_Format_ = DXGI_FORMAT_UNKNOWN;
    }
    {
        std::lock_guard<std::mutex> lock(State_Mutex_);
        Capturing_ = false;
    }
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Is_Capturing() const noexcept
{
    std::lock_guard<std::mutex> lock(State_Mutex_);
    return Capturing_;
}
//---------------------------------------------------------------------------
RECT hahaha_capture_desktop_desktop_duplication::Get_Output_Desktop_Rect() const noexcept
{
    return Output_Desktop_Rect_;
}
//---------------------------------------------------------------------------
HMONITOR hahaha_capture_desktop_desktop_duplication::Get_Monitor() const noexcept
{
    return Monitor_;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Capture_Frame(hahaha_capture_desktop_desktop_duplication_frame& frame)
{
    if (!Duplication_ || !Context_)
    {
        return false;
    }

    IDXGIResource* resource_raw_ = nullptr;
    DXGI_OUTDUPL_FRAME_INFO frame_info_{};

    auto hr = Duplication_->AcquireNextFrame(Options_.Timeout_Ms_, &frame_info_, &resource_raw_);
    if (hr == DXGI_ERROR_WAIT_TIMEOUT)
    {
        return false;
    }

    if (FAILED(hr))
    {
        Stop();
        if ((hr == DXGI_ERROR_ACCESS_LOST) || (hr == DXGI_ERROR_SESSION_DISCONNECTED))
        {
            if (Use_Monitor_Handle_ && Monitor_)
            {
                Create_Duplication_By_Monitor(Monitor_);
            }
            else
            {
                Create_Duplication(Options_.Monitor_Index_);
            }
        }

        return false;
    }

    com_unique_ptr<IDXGIResource> resource_(resource_raw_);

    ID3D11Texture2D* frame_texture_raw_ = nullptr;
    hr = resource_ ? resource_->QueryInterface(__uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&frame_texture_raw_)) : E_POINTER;
    com_unique_ptr<ID3D11Texture2D> frame_texture_(frame_texture_raw_);

    if (SUCCEEDED(hr) && frame_texture_)
    {
        if (Copy_Frame_To_Snapshot(frame_texture_.get()))
        {
            std::lock_guard<std::mutex> lock(Frame_Mutex_);
            frame = Frame_Snapshot_;
            Duplication_->ReleaseFrame();
            return true;
        }
    }

    Duplication_->ReleaseFrame();
    return false;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Capture_Region(const RECT& desktop_rect, hahaha_capture_desktop_desktop_duplication_frame& frame)
{
    if (!Duplication_ || !Context_)
    {
        return false;
    }

    IDXGIResource* resource_raw_ = nullptr;
    DXGI_OUTDUPL_FRAME_INFO frame_info_{};

    auto hr = Duplication_->AcquireNextFrame(Options_.Timeout_Ms_, &frame_info_, &resource_raw_);
    if (hr == DXGI_ERROR_WAIT_TIMEOUT)
    {
        return false;
    }

    if (FAILED(hr))
    {
        Stop();
        if ((hr == DXGI_ERROR_ACCESS_LOST) || (hr == DXGI_ERROR_SESSION_DISCONNECTED))
        {
            if (Use_Monitor_Handle_ && Monitor_)
            {
                Create_Duplication_By_Monitor(Monitor_);
            }
            else
            {
                Create_Duplication(Options_.Monitor_Index_);
            }
        }
        return false;
    }

    com_unique_ptr<IDXGIResource> resource_(resource_raw_);

    ID3D11Texture2D* frame_texture_raw_ = nullptr;
    hr = resource_ ? resource_->QueryInterface(__uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&frame_texture_raw_)) : E_POINTER;
    com_unique_ptr<ID3D11Texture2D> frame_texture_(frame_texture_raw_);
    if (FAILED(hr) || !frame_texture_)
    {
        Duplication_->ReleaseFrame();
        return false;
    }

    D3D11_TEXTURE2D_DESC desc_{};
    frame_texture_->GetDesc(&desc_);
    if (desc_.Width == 0 || desc_.Height == 0)
    {
        Duplication_->ReleaseFrame();
        return false;
    }
    if (desc_.Format != DXGI_FORMAT_B8G8R8A8_UNORM &&
        desc_.Format != DXGI_FORMAT_B8G8R8A8_UNORM_SRGB &&
        desc_.Format != DXGI_FORMAT_R8G8B8A8_UNORM &&
        desc_.Format != DXGI_FORMAT_R8G8B8A8_UNORM_SRGB)
    {
        Duplication_->ReleaseFrame();
        return false;
    }

    if (!Ensure_Staging_Texture(desc_))
    {
        Duplication_->ReleaseFrame();
        return false;
    }

    Context_->CopyResource(Staging_Texture_.get(), frame_texture_.get());

    D3D11_MAPPED_SUBRESOURCE mapped_{};
    hr = Context_->Map(Staging_Texture_.get(), 0, D3D11_MAP_READ, 0, &mapped_);
    if (FAILED(hr) || !mapped_.pData)
    {
        Duplication_->ReleaseFrame();
        return false;
    }

    const RECT output_rect_ = NormalizeRect(Output_Desktop_Rect_);
    RECT requested_ = NormalizeRect(desktop_rect);
    RECT intersect_{};
    if (!IntersectRectsSafe(intersect_, requested_, output_rect_))
    {
        Context_->Unmap(Staging_Texture_.get(), 0);
        Duplication_->ReleaseFrame();
        return false;
    }

    const int crop_width_ = static_cast<int>(intersect_.right - intersect_.left);
    const int crop_height_ = static_cast<int>(intersect_.bottom - intersect_.top);
    if (crop_width_ <= 0 || crop_height_ <= 0)
    {
        Context_->Unmap(Staging_Texture_.get(), 0);
        Duplication_->ReleaseFrame();
        return false;
    }

    const int offset_x_ = static_cast<int>(intersect_.left - output_rect_.left);
    const int offset_y_ = static_cast<int>(intersect_.top - output_rect_.top);
    const size_t src_row_pitch_ = mapped_.RowPitch;
    const size_t bytes_per_pixel_ = 4;
    const size_t dst_stride_ = static_cast<size_t>(crop_width_) * bytes_per_pixel_;

    std::vector<uint8_t> data_(static_cast<size_t>(crop_height_) * dst_stride_);
    for (int row = 0; row < crop_height_; ++row)
    {
        const size_t src_offset_ = (static_cast<size_t>(offset_y_ + row) * src_row_pitch_) + (static_cast<size_t>(offset_x_) * bytes_per_pixel_);
        const uint8_t* src_ = static_cast<const uint8_t*>(mapped_.pData) + src_offset_;
        std::memcpy(data_.data() + static_cast<size_t>(row) * dst_stride_, src_, dst_stride_);
    }

    Context_->Unmap(Staging_Texture_.get(), 0);
    Duplication_->ReleaseFrame();

    frame.Data_ = std::move(data_);
    frame.Width_ = crop_width_;
    frame.Height_ = crop_height_;
    frame.Stride_ = static_cast<int>(dst_stride_);
    return frame.Is_Valid();
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Ensure_Device()
{
    if (Device_)
    {
        return true;
    }

    UINT creation_flags_ = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
#ifdef _DEBUG
    creation_flags_ |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL feature_levels_[] =
    {
        D3D_FEATURE_LEVEL_11_1,
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0
    };
    const UINT feature_level_count_ = static_cast<UINT>(sizeof(feature_levels_) / sizeof(feature_levels_[0]));

    ID3D11Device* device_raw_ = nullptr;
    ID3D11DeviceContext* context_raw_ = nullptr;
    auto hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, creation_flags_,
        feature_levels_, feature_level_count_, D3D11_SDK_VERSION, &device_raw_, nullptr, &context_raw_);

    if (FAILED(hr))
    {
        return false;
    }

    Device_.reset(device_raw_);
    Context_.reset(context_raw_);
    return true;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Create_Duplication(int monitor_index)
{
    if (!Device_)
    {
        return false;
    }

    Use_Monitor_Handle_ = false;
    Monitor_ = GetMonitorByIndex(monitor_index);

    IDXGIDevice* dxgi_device_raw_ = nullptr;
    auto hr = Device_->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgi_device_raw_));
    com_unique_ptr<IDXGIDevice> dxgi_device_(dxgi_device_raw_);
    if (FAILED(hr) || !dxgi_device_)
    {
        return false;
    }

    IDXGIAdapter* adapter_raw_ = nullptr;
    hr = dxgi_device_->GetAdapter(&adapter_raw_);
    com_unique_ptr<IDXGIAdapter> adapter_(adapter_raw_);
    if (FAILED(hr) || !adapter_)
    {
        return false;
    }

    com_unique_ptr<IDXGIOutput> output_;
    com_unique_ptr<IDXGIOutput> first_output_;
    int current_ = 0;
    for (UINT i = 0; ; ++i)
    {
        IDXGIOutput* candidate_raw_ = nullptr;
        if (FAILED(adapter_->EnumOutputs(i, &candidate_raw_)) || !candidate_raw_)
        {
            break;
        }

        com_unique_ptr<IDXGIOutput> candidate_(candidate_raw_);

        if (!first_output_)
        {
            first_output_ = std::move(candidate_);
        }

        if (current_ == monitor_index)
        {
            output_ = std::move(candidate_);
            break;
        }

        ++current_;
    }

    if (!output_ && first_output_)
    {
        output_ = std::move(first_output_);
    }
    first_output_.reset();

    if (output_)
    {
        DXGI_OUTPUT_DESC output_desc_{};
        if (SUCCEEDED(output_->GetDesc(&output_desc_)))
        {
            Monitor_ = output_desc_.Monitor;
            Output_Desktop_Rect_ = output_desc_.DesktopCoordinates;
        }
    }

    IDXGIOutput1* output1_raw_ = nullptr;
    hr = output_ ? output_->QueryInterface(__uuidof(IDXGIOutput1), reinterpret_cast<void**>(&output1_raw_)) : E_POINTER;
    com_unique_ptr<IDXGIOutput1> output1_(output1_raw_);
    if (FAILED(hr) || !output1_)
    {
        return false;
    }

    IDXGIOutputDuplication* duplication_raw_ = nullptr;
    hr = output1_->DuplicateOutput(Device_.get(), &duplication_raw_);
    com_unique_ptr<IDXGIOutputDuplication> duplication_(duplication_raw_);
    if (FAILED(hr) || !duplication_)
    {
        return false;
    }

    Duplication_ = std::move(duplication_);
    return true;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Create_Duplication_By_Monitor(HMONITOR monitor)
{
    if (!Device_ || !monitor)
    {
        return false;
    }

    Use_Monitor_Handle_ = true;
    Monitor_ = monitor;

    IDXGIDevice* dxgi_device_raw_ = nullptr;
    auto hr = Device_->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&dxgi_device_raw_));
    com_unique_ptr<IDXGIDevice> dxgi_device_(dxgi_device_raw_);
    if (FAILED(hr) || !dxgi_device_)
    {
        return false;
    }

    IDXGIAdapter* adapter_raw_ = nullptr;
    hr = dxgi_device_->GetAdapter(&adapter_raw_);
    com_unique_ptr<IDXGIAdapter> adapter_(adapter_raw_);
    if (FAILED(hr) || !adapter_)
    {
        return false;
    }

    com_unique_ptr<IDXGIOutput> output_;
    com_unique_ptr<IDXGIOutput> first_output_;
    for (UINT i = 0; ; ++i)
    {
        IDXGIOutput* candidate_raw_ = nullptr;
        if (FAILED(adapter_->EnumOutputs(i, &candidate_raw_)) || !candidate_raw_)
        {
            break;
        }

        com_unique_ptr<IDXGIOutput> candidate_(candidate_raw_);
        if (!first_output_)
        {
            first_output_ = std::move(candidate_);
            candidate_ = nullptr;
        }

        if (!candidate_)
        {
            continue;
        }

        DXGI_OUTPUT_DESC desc_{};
        if (SUCCEEDED(candidate_->GetDesc(&desc_)) && desc_.Monitor == monitor)
        {
            output_ = std::move(candidate_);
            Output_Desktop_Rect_ = desc_.DesktopCoordinates;
            break;
        }
    }

    if (!output_ && first_output_)
    {
        DXGI_OUTPUT_DESC desc_{};
        if (SUCCEEDED(first_output_->GetDesc(&desc_)))
        {
            Monitor_ = desc_.Monitor;
            Output_Desktop_Rect_ = desc_.DesktopCoordinates;
        }
        output_ = std::move(first_output_);
    }
    first_output_.reset();

    IDXGIOutput1* output1_raw_ = nullptr;
    hr = output_ ? output_->QueryInterface(__uuidof(IDXGIOutput1), reinterpret_cast<void**>(&output1_raw_)) : E_POINTER;
    com_unique_ptr<IDXGIOutput1> output1_(output1_raw_);
    if (FAILED(hr) || !output1_)
    {
        return false;
    }

    IDXGIOutputDuplication* duplication_raw_ = nullptr;
    hr = output1_->DuplicateOutput(Device_.get(), &duplication_raw_);
    com_unique_ptr<IDXGIOutputDuplication> duplication_(duplication_raw_);
    if (FAILED(hr) || !duplication_)
    {
        return false;
    }

    Duplication_ = std::move(duplication_);
    return true;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Ensure_Staging_Texture(const D3D11_TEXTURE2D_DESC& desc)
{
    if (Staging_Texture_ &&
        Staging_Width_ == static_cast<int>(desc.Width) &&
        Staging_Height_ == static_cast<int>(desc.Height) &&
        Staging_Format_ == desc.Format)
    {
        return true;
    }

    D3D11_TEXTURE2D_DESC staging_desc_ = desc;
    staging_desc_.BindFlags = 0;
    staging_desc_.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
    staging_desc_.Usage = D3D11_USAGE_STAGING;
    staging_desc_.MiscFlags = 0;
    staging_desc_.ArraySize = 1;
    staging_desc_.MipLevels = 1;
    staging_desc_.SampleDesc.Count = 1;
    staging_desc_.SampleDesc.Quality = 0;

    ID3D11Texture2D* staging_texture_raw_ = nullptr;
    auto hr = Device_->CreateTexture2D(&staging_desc_, nullptr, &staging_texture_raw_);
    if (FAILED(hr))
    {
        Staging_Texture_.reset();
        Staging_Width_ = 0;
        Staging_Height_ = 0;
        return false;
    }

    Staging_Texture_.reset(staging_texture_raw_);
    Staging_Width_ = static_cast<int>(staging_desc_.Width);
    Staging_Height_ = static_cast<int>(staging_desc_.Height);
    Staging_Format_ = staging_desc_.Format;
    return true;
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Ensure_Staging_Texture(int width, int height, DXGI_FORMAT format)
{
    if (width <= 0 || height <= 0)
    {
        return false;
    }

    D3D11_TEXTURE2D_DESC desc_{};
    desc_.Width = static_cast<UINT>(width);
    desc_.Height = static_cast<UINT>(height);
    desc_.Format = format;
    desc_.ArraySize = 1;
    desc_.MipLevels = 1;
    desc_.SampleDesc.Count = 1;
    desc_.SampleDesc.Quality = 0;
    return Ensure_Staging_Texture(desc_);
}
//---------------------------------------------------------------------------
bool hahaha_capture_desktop_desktop_duplication::Copy_Frame_To_Snapshot(ID3D11Texture2D* frame_texture)
{
    if (!frame_texture || !Context_)
    {
        return false;
    }

    D3D11_TEXTURE2D_DESC desc_{};
    frame_texture->GetDesc(&desc_);
    if (desc_.Width == 0 || desc_.Height == 0)
    {
        return false;
    }
    if (desc_.Format != DXGI_FORMAT_B8G8R8A8_UNORM &&
        desc_.Format != DXGI_FORMAT_B8G8R8A8_UNORM_SRGB &&
        desc_.Format != DXGI_FORMAT_R8G8B8A8_UNORM &&
        desc_.Format != DXGI_FORMAT_R8G8B8A8_UNORM_SRGB)
    {
        return false;
    }

    if (!Ensure_Staging_Texture(desc_))
    {
        return false;
    }

    Context_->CopyResource(Staging_Texture_.get(), frame_texture);

    D3D11_MAPPED_SUBRESOURCE mapped_{};
    auto hr = Context_->Map(Staging_Texture_.get(), 0, D3D11_MAP_READ, 0, &mapped_);
    if (FAILED(hr))
    {
        return false;
    }

    const size_t row_pitch_ = mapped_.RowPitch;
    std::vector<uint8_t> data_(static_cast<size_t>(desc_.Height) * row_pitch_);
    for (UINT row = 0; row < desc_.Height; ++row)
    {
        std::memcpy(data_.data() + row * row_pitch_,
            static_cast<uint8_t*>(mapped_.pData) + row * row_pitch_,
            row_pitch_);
    }

    Context_->Unmap(Staging_Texture_.get(), 0);

    {
        std::lock_guard<std::mutex> lock_(Frame_Mutex_);
        Frame_Snapshot_.Data_ = std::move(data_);
        Frame_Snapshot_.Width_ = static_cast<int>(desc_.Width);
        Frame_Snapshot_.Height_ = static_cast<int>(desc_.Height);
        Frame_Snapshot_.Stride_ = static_cast<int>(row_pitch_);
    }
    return true;
}
//---------------------------------------------------------------------------
} // namespace hahahalib
