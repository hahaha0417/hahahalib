#pragma hdrstop
#include "hahaha_capture_form_desktop_duplication.h"
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#include <dwmapi.h>
#ifndef DWMWA_EXTENDED_FRAME_BOUNDS
#define DWMWA_EXTENDED_FRAME_BOUNDS 9
#endif

//已經有自己的 Form / Window（VCL / MFC / Win32）
//HWND hwnd = Form1->Handle;
//目前前景視窗
//HWND hwnd = GetForegroundWindow();
//用滑鼠位置找視窗（最常用於螢幕擷取工具）
//POINT pt;
//GetCursorPos(&pt);
//HWND hwnd = WindowFromPoint(pt);
//避免抓到子視窗（例如按鈕）
//HWND hwnd = GetAncestor(WindowFromPoint(pt), GA_ROOT);
//知道視窗標題
//HWND hwnd = FindWindow(NULL, L"Notepad");
//視窗類別名稱
//HWND hwnd = FindWindow(L"Notepad", NULL);
//
//hahahalib::hahaha_capture_form_gdi cap;
//
// form 有更新才會有畫面
////	HWND hwnd = GetForegroundWindow();   // 或任何你要的方法
//HWND hwnd = FindEdgeWindowByClass();
//
//capture_form_desktop_duplication_.Is_Cursor_Draw_ = true;
//// ★ 要不要包含標題欄？
//capture_form_desktop_duplication_.Is_Capture_Window_Frame_ = false;   // 含標題欄
//capture_form_desktop_duplication_.Open(hwnd);
//
////	capture_form_desktop_duplication_.Grab(halib::roi(100, 100, 200, 200));
//capture_form_desktop_duplication_.Grab();
//f_lib::bmp::Save(L"D:\\Desktop\\ttt\\webcam.bmp", *capture_form_desktop_duplication_.Bitmap_);
//
////	capture_form_desktop_duplication_.Close();
//
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::~hahaha_capture_form_desktop_duplication()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication(
    hahaha_capture_form_desktop_duplication&& other) noexcept
{
    Move(std::move(other));
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication&
hahaha_capture_form_desktop_duplication::operator=(
    hahaha_capture_form_desktop_duplication&& other) noexcept
{
    if (this != &other)
    {
        Reset();
        Move(std::move(other));
    }
    return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Move(
    hahaha_capture_form_desktop_duplication&& other) noexcept
{
    Width_          = other.Width_;
    Height_         = other.Height_;
    Is_Open_        = other.Is_Open_;
    Is_Cursor_Draw_ = other.Is_Cursor_Draw_;
    Is_Capture_Window_Frame_ = other.Is_Capture_Window_Frame_;

    Hwnd_        = other.Hwnd_;
    Window_Rect_ = other.Window_Rect_;
    Output_Desc_ = other.Output_Desc_;
    Dup_Desc_    = other.Dup_Desc_;

    Device_      = std::move(other.Device_);
    Context_     = std::move(other.Context_);
    Output1_     = std::move(other.Output1_);
    Duplication_ = std::move(other.Duplication_);
    Staging_Tex_ = std::move(other.Staging_Tex_);
    Bitmap_      = std::move(other.Bitmap_);

    other.Width_          = 0;
    other.Height_         = 0;
    other.Is_Open_        = false;
    other.Is_Cursor_Draw_ = false;
    other.Hwnd_           = nullptr;
    SetRectEmpty(&other.Window_Rect_);

    std::memset(&other.Output_Desc_, 0, sizeof(other.Output_Desc_));
    std::memset(&other.Dup_Desc_,    0, sizeof(other.Dup_Desc_));
}
//---------------------------------------------------------------------------
int hahaha_capture_form_desktop_duplication::Reset()
{
    Device_        = nullptr;
    Context_       = nullptr;
    Output1_       = nullptr;
    Duplication_   = nullptr;
    Staging_Tex_   = nullptr;
    Bitmap_.reset();

    Width_          = 0;
    Height_         = 0;
    Is_Open_        = false;
    Is_Cursor_Draw_ = false;
    Is_Capture_Window_Frame_ = false;

    Hwnd_ = nullptr;
    SetRectEmpty(&Window_Rect_);

    std::memset(&Output_Desc_, 0, sizeof(Output_Desc_));
    std::memset(&Dup_Desc_,    0, sizeof(Dup_Desc_));

    return 0;
}
//---------------------------------------------------------------------------
bool hahaha_capture_form_desktop_duplication::FindOutputForWindow(HWND hwnd,
    halib_def::com_ptr<IDXGIOutput1>& out_output1,
    DXGI_OUTPUT_DESC& out_desc
)
{
    if (!IsWindow(hwnd))
    {
        return false;
    }

    RECT wr_{};
    if (!GetWindowRect(hwnd, &wr_))
    {
        return false;
    }

    POINT center_{};
    center_.x = (wr_.left + wr_.right) / 2;
    center_.y = (wr_.top  + wr_.bottom) / 2;

    IDXGIFactory1* raw_factory_ = nullptr;
    if (FAILED(CreateDXGIFactory1(IID_PPV_ARGS(&raw_factory_))))
    {
        return false;
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

            if (PtInRect(&desc_.DesktopCoordinates, center_))
            {
                IDXGIOutput1* raw_output1_ = nullptr;
                if (FAILED(output_->QueryInterface(IID_PPV_ARGS(&raw_output1_))))
                {
                    return false;
                }

                out_output1.reset(raw_output1_);
                out_desc = desc_;
                return true;
            }

            ++j_;
        }

        ++i_;
    }

    return false;
}
//---------------------------------------------------------------------------
int hahaha_capture_form_desktop_duplication::Open(HWND hwnd)
{
    if (Is_Open_)
    {
        return 0;
    }

    if (!IsWindow(hwnd))
    {
        return -1;
    }

    Hwnd_ = hwnd;


    // 取得真正的視窗像素邊界（含標題列、陰影）
    RECT wr_{};
    if (FAILED(DwmGetWindowAttribute(hwnd, DWMWA_EXTENDED_FRAME_BOUNDS, &wr_, sizeof(wr_))))
    {
        GetWindowRect(hwnd, &wr_);
    }

    // 若不包含標題列 → 去掉標題列高度
    if (!Is_Capture_Window_Frame_)
    {
        RECT cr_{};
        GetClientRect(hwnd, &cr_);

        POINT pt_{ cr_.left, cr_.top };
        ClientToScreen(hwnd, &pt_);

        int title_h_ = pt_.y - wr_.top;
        wr_.top += title_h_;
    }

    Window_Rect_ = wr_;

    // 找到視窗所在的輸出螢幕
    if (!FindOutputForWindow(hwnd, Output1_, Output_Desc_))
    {
        return -1;
    }

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
        &raw_ctx_)))
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

    Width_  = Window_Rect_.right  - Window_Rect_.left;
    Height_ = Window_Rect_.bottom - Window_Rect_.top;

    // staging texture（整個螢幕）
    D3D11_TEXTURE2D_DESC td_{};
    td_.Width            = Dup_Desc_.ModeDesc.Width;
    td_.Height           = Dup_Desc_.ModeDesc.Height;
    td_.MipLevels        = 1;
    td_.ArraySize        = 1;
    td_.Format           = Dup_Desc_.ModeDesc.Format;
    td_.SampleDesc.Count = 1;
    td_.Usage            = D3D11_USAGE_STAGING;
    td_.CPUAccessFlags   = D3D11_CPU_ACCESS_READ;

    ID3D11Texture2D* raw_tex_ = nullptr;
    if (FAILED(Device_->CreateTexture2D(&td_, nullptr, &raw_tex_)))
    {
        return -1;
    }

    Staging_Tex_.reset(raw_tex_);

    Bitmap_.reset(new halib::bitmap_alloc_argb());
    Bitmap_->Resize(Width_, Height_);

    Is_Open_ = true;
    return 0;
}
//---------------------------------------------------------------------------

int hahaha_capture_form_desktop_duplication::Grab()
{
    if (!Is_Open_)
    {
        return -1;
    }

    // 視窗可能移動或縮放，每次抓取前更新
    // 視窗可能移動或縮放，每次抓取前更新
    RECT wr{};
    if (FAILED(DwmGetWindowAttribute(Hwnd_, DWMWA_EXTENDED_FRAME_BOUNDS, &wr, sizeof(wr))))
        GetWindowRect(Hwnd_, &wr);

    // 若不包含標題列 → 去掉標題列高度
    if (!Is_Capture_Window_Frame_)
    {
        RECT cr{};
        GetClientRect(Hwnd_, &cr);

        POINT pt{ cr.left, cr.top };
        ClientToScreen(Hwnd_, &pt);

        int title_h = pt.y - wr.top;
        wr.top += title_h;
    }

    Window_Rect_ = wr;

    int win_w = wr.right  - wr.left;
    int win_h = wr.bottom - wr.top;



    if (win_w <= 0 || win_h <= 0)
    {
        return -1;
    }

    // 若大小變了，重建 bitmap
    if (win_w != Width_ || win_h != Height_)
    {
        Width_  = win_w;
        Height_ = win_h;

        if (!Bitmap_)
        {
            Bitmap_.reset(new halib::bitmap_alloc_argb());
        }
        Bitmap_->Resize(Width_, Height_);
    }

    DXGI_OUTDUPL_FRAME_INFO info{};
    IDXGIResource* raw_frame = nullptr;

    HRESULT hr = Duplication_->AcquireNextFrame(16, &info, &raw_frame);
    if (hr == DXGI_ERROR_WAIT_TIMEOUT)
    {
        return 1;
    }
    if (FAILED(hr))
    {
        return -1;
    }

    if (info.AccumulatedFrames == 0)
    {
        Duplication_->ReleaseFrame();
        return 1;
    }

    halib_def::com_ptr<IDXGIResource> frame;
    frame.reset(raw_frame);

    ID3D11Texture2D* raw_tex = nullptr;
    frame->QueryInterface(IID_PPV_ARGS(&raw_tex));

    halib_def::com_ptr<ID3D11Texture2D> tex;
    tex.reset(raw_tex);

    Context_->CopyResource(Staging_Tex_.get(), tex.get());

    D3D11_MAPPED_SUBRESOURCE map{};
    Context_->Map(Staging_Tex_.get(), 0, D3D11_MAP_READ, 0, &map);

    uint8_t* src = (uint8_t*)map.pData;
    size_t   src_pitch = map.RowPitch;

    uint8_t* dst = (uint8_t*)Bitmap_->Image_Ptr_;
    size_t   dst_pitch = Width_ * 4; // BGRA

    // 視窗左上角相對於輸出螢幕的 offset
    int offset_x = Window_Rect_.left - Output_Desc_.DesktopCoordinates.left;
    int offset_y = Window_Rect_.top  - Output_Desc_.DesktopCoordinates.top;

    // 簡單裁切（假設視窗完全在該輸出內）
    for (int y = 0; y < Height_; ++y)
    {
        uint8_t* src_line = src + (offset_y + y) * src_pitch + offset_x * 4;
        uint8_t* dst_line = dst + y * dst_pitch;
        memcpy(dst_line, src_line, dst_pitch);
    }

    // 畫滑鼠游標（座標改成視窗內）
    CURSORINFO ci{};
    ci.cbSize = sizeof(ci);

    if (Is_Cursor_Draw_ && GetCursorInfo(&ci) && (ci.flags & CURSOR_SHOWING))
    {
        ICONINFO ii{};
        if (GetIconInfo(ci.hCursor, &ii))
        {
            int cursor_x = ci.ptScreenPos.x - Window_Rect_.left - ii.xHotspot;
            int cursor_y = ci.ptScreenPos.y - Window_Rect_.top  - ii.yHotspot;

            HBITMAP hbm = ii.hbmColor ? ii.hbmColor : ii.hbmMask;

            BITMAP bmp{};
            GetObject(hbm, sizeof(bmp), &bmp);

            int w = bmp.bmWidth;
            int h = bmp.bmHeight;

            BITMAPINFO bi{};
            bi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
            bi.bmiHeader.biWidth       = w;
            bi.bmiHeader.biHeight      = -h; // top-down
            bi.bmiHeader.biPlanes      = 1;
            bi.bmiHeader.biBitCount    = 32;
            bi.bmiHeader.biCompression = BI_RGB;

            std::vector<uint32_t> pixels(w * h);

            HDC hdc = GetDC(NULL);
            GetDIBits(hdc, hbm, 0, h, pixels.data(), &bi, DIB_RGB_COLORS);
            ReleaseDC(NULL, hdc);

            for (int y = 0; y < h; ++y)
            {
                for (int x = 0; x < w; ++x)
                {
                    int dst_x = cursor_x + x;
                    int dst_y = cursor_y + y;

                    if (dst_x < 0 || dst_y < 0 || dst_x >= Width_ || dst_y >= Height_)
                    {
                        continue;
                    }

                    uint32_t src_px = pixels[y * w + x];
                    uint8_t  a      = (src_px >> 24) & 0xFF;
                    if (a == 0)
                    {
                        continue;
                    }

                    uint32_t* dst_px = (uint32_t*)Bitmap_->Image_Ptr_ +
                                       dst_y * Width_ + dst_x;
                    *dst_px = src_px;
                }
            }

            DeleteObject(ii.hbmColor);
            DeleteObject(ii.hbmMask);
        }
    }

    Context_->Unmap(Staging_Tex_.get(), 0);
    Duplication_->ReleaseFrame();

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_capture_form_desktop_duplication::Grab(const halib::roi& /*roi*/)
{
    if (!Is_Open_)
    {
        return -1;
    }

    // 目前先保留介面，未實作 ROI 版本
    return 0;
}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Close()
{
    Reset();
}
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
