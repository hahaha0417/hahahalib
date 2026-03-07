#include "hahaha_capture_desktop_desktop_duplication.h"
#pragma comment(lib, "d3d11.lib")

#pragma comment(lib, "dxgi.lib")
//---------------------------------------------------------------------------
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
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication(
    hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    Move(std::move(hcddd));
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication&
hahaha_capture_desktop_desktop_duplication::operator=(
    hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    if (this != &hcddd)
    {
        Reset();
        Move(std::move(hcddd));
    }
    return *this;
}

//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Move(
    hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    Width_   = hcddd.Width_;
    Height_  = hcddd.Height_;
	Is_Open_ = hcddd.Is_Open_;
	Is_Cursor_Draw_ = hcddd.Is_Cursor_Draw_;

	Output_Desc_ = hcddd.Output_Desc_;
	Dup_Desc_    = hcddd.Dup_Desc_;

	Device_        = std::move(hcddd.Device_);
	Context_       = std::move(hcddd.Context_);
	Output1_       = std::move(hcddd.Output1_);
	Duplication_   = std::move(hcddd.Duplication_);
	Staging_Tex_   = std::move(hcddd.Staging_Tex_);
	Bitmap_        = std::move(hcddd.Bitmap_);

	hcddd.Width_   = 0;
	hcddd.Height_  = 0;
	hcddd.Is_Open_ = false;


    std::memset(&hcddd.Output_Desc_, 0, sizeof(hcddd.Output_Desc_));
    std::memset(&hcddd.Dup_Desc_,    0, sizeof(hcddd.Dup_Desc_));
}

//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Reset()
{
    Device_        = nullptr;
    Context_       = nullptr;
    Output1_       = nullptr;
    Duplication_   = nullptr;
    Staging_Tex_   = nullptr;
    Bitmap_.reset();

    Width_   = 0;
    Height_  = 0;
	Is_Open_ = false;
	Is_Cursor_Draw_ = false;

    std::memset(&Output_Desc_, 0, sizeof(Output_Desc_));
    std::memset(&Dup_Desc_,    0, sizeof(Dup_Desc_));

    return 0;
}

//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::List_Monitors(std::vector<std::wstring>& list)
{
    list.clear();

    IDXGIFactory1* raw_factory_ = nullptr;
    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&raw_factory_))))
    {
        return -1;
    }

    halib_def::com_ptr<IDXGIFactory1> factory_;
    factory_.reset(raw_factory_);

    UINT i_ = 0;
    IDXGIAdapter1* raw_adapter_ = nullptr;

    while (factory_->EnumAdapters1(i_, &raw_adapter_) != DXGI_ERROR_NOT_FOUND)
    {
        halib_def::com_ptr<IDXGIAdapter1> adapter_;
        adapter_.reset(raw_adapter_);
        raw_adapter_ = nullptr;

        UINT j_ = 0;
        IDXGIOutput* raw_output_ = nullptr;

        while (adapter_->EnumOutputs(j_, &raw_output_) != DXGI_ERROR_NOT_FOUND)
        {
            halib_def::com_ptr<IDXGIOutput> output_;
            output_.reset(raw_output_);
            raw_output_ = nullptr;

            DXGI_OUTPUT_DESC desc_{};
            output_->GetDesc(&desc_);

            wchar_t buf_[256];
            swprintf(buf_, 256, L"%s (%ld,%ld) %ldx%ld",
                desc_.DeviceName,
                desc_.DesktopCoordinates.left,
                desc_.DesktopCoordinates.top,
                desc_.DesktopCoordinates.right - desc_.DesktopCoordinates.left,
                desc_.DesktopCoordinates.bottom - desc_.DesktopCoordinates.top);

            list.push_back(buf_);

            j_++;
        }

        i_++;
    }

    return (int)list.size();
}

//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Open(int monitor_index)
{
    if (Is_Open_)
    {
        return 0;
    }

    // 建立 DXGI Factory
    IDXGIFactory1* raw_factory_ = nullptr;
    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&raw_factory_))))
    {
        return -1;
    }

    halib_def::com_ptr<IDXGIFactory1> factory_;
    factory_.reset(raw_factory_);

    // 找到指定 monitor
    UINT i_ = 0, count_ = 0;
    IDXGIAdapter1* raw_adapter_ = nullptr;

    while (factory_->EnumAdapters1(i_, &raw_adapter_) != DXGI_ERROR_NOT_FOUND)
    {
        halib_def::com_ptr<IDXGIAdapter1> adapter_;
        adapter_.reset(raw_adapter_);
        raw_adapter_ = nullptr;

        UINT j_ = 0;
        IDXGIOutput* raw_output_ = nullptr;

        while (adapter_->EnumOutputs(j_, &raw_output_) != DXGI_ERROR_NOT_FOUND)
        {
            halib_def::com_ptr<IDXGIOutput> output_;
            output_.reset(raw_output_);
            raw_output_ = nullptr;

            if (count_ == (UINT)monitor_index)
            {
                output_->GetDesc(&Output_Desc_);

                IDXGIOutput1* raw_output1_ = nullptr;
                if (FAILED(output_->QueryInterface(IID_PPV_ARGS(&raw_output1_))))
                {
                    return -1;
                }

                Output1_.reset(raw_output1_);
                goto FOUND;
            }

            j_++;
            count_++;
        }

        i_++;
    }

    return -1;

FOUND:

    // 建立 D3D11 device
    D3D_FEATURE_LEVEL fl_{};
    ID3D11Device* raw_dev_ = nullptr;
    ID3D11DeviceContext* raw_ctx_ = nullptr;

    if (FAILED(D3D11CreateDevice(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        D3D11_CREATE_DEVICE_BGRA_SUPPORT,
        nullptr, 0,
        D3D11_SDK_VERSION,
        &raw_dev_,
        &fl_,
        &raw_ctx_))
    )
    {
        return -1;
    }

    Device_.reset(raw_dev_);
    Context_.reset(raw_ctx_);

    // 建立 duplication
    IDXGIOutputDuplication* raw_dup_ = nullptr;
    if (FAILED(Output1_->DuplicateOutput(Device_.get(), &raw_dup_)))
    {
        return -1;
    }

    Duplication_.reset(raw_dup_);
    Duplication_->GetDesc(&Dup_Desc_);

    Width_  = Dup_Desc_.ModeDesc.Width;
    Height_ = Dup_Desc_.ModeDesc.Height;

    // 建立 staging texture
    D3D11_TEXTURE2D_DESC td_{};
    td_.Width            = Width_;
    td_.Height           = Height_;
    td_.MipLevels        = 1;
    td_.ArraySize        = 1;
    td_.Format           = Dup_Desc_.ModeDesc.Format;  // ★ 使用來源格式
    td_.SampleDesc.Count = 1;
    td_.Usage            = D3D11_USAGE_STAGING;
    td_.CPUAccessFlags   = D3D11_CPU_ACCESS_READ;
    td_.BindFlags        = 0;
    td_.MiscFlags        = 0;



    ID3D11Texture2D* raw_tex_ = nullptr;
    if (FAILED(Device_->CreateTexture2D(&td_, nullptr, &raw_tex_)))
    {
        return -1;
    }

    Staging_Tex_.reset(raw_tex_);

    // 建立 bitmap
    Bitmap_.reset(new halib::bitmap_alloc_argb());
    Bitmap_->Resize(Width_, Height_);

    Is_Open_ = true;
    return 0;
}

//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Grab()
{
    if (!Is_Open_)
    {
        return -1;
    }

    DXGI_OUTDUPL_FRAME_INFO info_{};
    IDXGIResource* raw_frame_ = nullptr;


    HRESULT hr_ = Duplication_->AcquireNextFrame(16, &info_, &raw_frame_);
    if (hr_ == DXGI_ERROR_WAIT_TIMEOUT)
    {
        return 1;
    }
    if (FAILED(hr_))
    {
        return -1;
    }

    if (info_.AccumulatedFrames == 0)
    {
        Duplication_->ReleaseFrame();
        return 1; // 沒有新畫面
    }

    halib_def::com_ptr<IDXGIResource> frame_;
    frame_.reset(raw_frame_);

    ID3D11Texture2D* raw_tex_ = nullptr;
    frame_->QueryInterface(IID_PPV_ARGS(&raw_tex_));

    halib_def::com_ptr<ID3D11Texture2D> tex_;
    tex_.reset(raw_tex_);

    Context_->CopyResource(Staging_Tex_.get(), tex_.get());

    D3D11_MAPPED_SUBRESOURCE map_{};
    Context_->Map(Staging_Tex_.get(), 0, D3D11_MAP_READ, 0, &map_);

    uint8_t* dst_ = (uint8_t*)Bitmap_->Image_Ptr_;
    uint8_t* src_ = (uint8_t*)map_.pData;

    size_t dst_pitch_ = Width_ * 4;   // BGRA
    size_t src_pitch_ = map_.RowPitch; // DXGI padded pitch

    for (int y = 0; y < Height_; y++)
    {
        memcpy(dst_ + y * dst_pitch_, src_ + y * src_pitch_, dst_pitch_);
    }

	// ★ 正確的滑鼠指標繪製（使用 GetDIBits 取得像素資料）
	CURSORINFO ci_{};
	ci_.cbSize = sizeof(ci_);

	if (Is_Cursor_Draw_ && GetCursorInfo(&ci_) && (ci_.flags & CURSOR_SHOWING))
	{
		ICONINFO ii_{};
		if (GetIconInfo(ci_.hCursor, &ii_))
		{
			int cursor_x_ = ci_.ptScreenPos.x - Output_Desc_.DesktopCoordinates.left - ii_.xHotspot;
			int cursor_y_ = ci_.ptScreenPos.y - Output_Desc_.DesktopCoordinates.top  - ii_.yHotspot;

			HBITMAP hbm_ = ii_.hbmColor ? ii_.hbmColor : ii_.hbmMask;

			BITMAP bmp_{};
			GetObject(hbm_, sizeof(bmp_), &bmp_);

			int w_ = bmp_.bmWidth;
			int h_ = bmp_.bmHeight;

			// 建立 DIB buffer
			BITMAPINFO bi_{};
			bi_.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
			bi_.bmiHeader.biWidth       = w_;
			bi_.bmiHeader.biHeight      = -h_;  // top-down
			bi_.bmiHeader.biPlanes      = 1;
			bi_.bmiHeader.biBitCount    = 32;
			bi_.bmiHeader.biCompression = BI_RGB;

			std::vector<uint32_t> pixels_(w_ * h_);

			HDC hdc_ = GetDC(NULL);
			GetDIBits(hdc_, hbm_, 0, h_, pixels_.data(), &bi_, DIB_RGB_COLORS);
			ReleaseDC(NULL, hdc_);

			// 畫到桌面影像上
			for (int y = 0; y < h_; y++)
			{
				for (int x = 0; x < w_; x++)
				{
					int dst_x_ = cursor_x_ + x;
					int dst_y_ = cursor_y_ + y;

					if (dst_x_ < 0 || dst_y_ < 0 || dst_x_ >= Width_ || dst_y_ >= Height_)
                    {
                        continue;
                    }

					uint32_t src_ = pixels_[y * w_ + x];
					uint8_t a_ = (src_ >> 24) & 0xFF;
					if (a_ == 0)
                    {
                        continue;
                    }

					uint32_t* dst_ = (uint32_t*)Bitmap_->Image_Ptr_ + dst_y_ * Width_ + dst_x_;
					*dst_ = src_;
				}
			}

			DeleteObject(ii_.hbmColor);
			DeleteObject(ii_.hbmMask);
		}
	}

    Context_->Unmap(Staging_Tex_.get(), 0);
    Duplication_->ReleaseFrame();

    return 0;
}

//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Grab(const halib::roi& roi)
{
    if (!Is_Open_)
    {
        return -1;
    }

    return 0;
}

//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Close()
{
    Reset();
}
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
