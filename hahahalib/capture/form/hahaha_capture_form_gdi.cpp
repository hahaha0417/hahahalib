//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include "hahaha_capture_form_gdi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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
//HWND hwnd = GetForegroundWindow();   // 或任何你要的方法
//cap.Is_Cursor_Draw_ = true;
//// ★ 要不要包含標題欄？
//cap.Is_Capture_Window_Frame_ = true;   // 含標題欄
//cap.Open(hwnd);
//
////	cap.Grab();
//
//cap.Grab(halib::roi(100, 100, 200, 200));
////	cap.Grab(halib::roi());
//f_lib::bmp::Save(L"D:\\Desktop\\ttt\\webcam.bmp", *cap.Bitmap_);
//
//cap.Close();
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

// 建構物件並初始化預設狀態。
hahaha_capture_form_gdi::hahaha_capture_form_gdi()
{
    Reset();
}
//---------------------------------------------------------------------------
// 解構物件並釋放相關資源。
hahaha_capture_form_gdi::~hahaha_capture_form_gdi()
{
    Close();
}
//---------------------------------------------------------------------------
// 以既有物件內容建構新的物件實例。
hahaha_capture_form_gdi::hahaha_capture_form_gdi(const hahaha_capture_form_gdi& hcfg)
{
    Reset();
    Copy(hcfg);
}
//---------------------------------------------------------------------------
// 以移動方式建構物件並接手既有資源。
hahaha_capture_form_gdi::hahaha_capture_form_gdi(hahaha_capture_form_gdi&& hcfg) noexcept
{
    Move(std::move(hcfg));
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi&
hahaha_capture_form_gdi::operator=(const hahaha_capture_form_gdi& hcfg)
{
    if (this != &hcfg)
    {
        Close();
        Reset();
        Copy(hcfg);
    }
    return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi&
// 移動指派目前物件內容。
hahaha_capture_form_gdi::operator=(hahaha_capture_form_gdi&& hcfg) noexcept
{
    if (this != &hcfg)
    {
        Close();
        Move(std::move(hcfg));
    }
    return *this;
}
//---------------------------------------------------------------------------
// 複製來源物件的內部狀態。
void hahaha_capture_form_gdi::Copy(const hahaha_capture_form_gdi& hcfg)
{
    // 不複製 GDI 狀態，只複製參數
    Form_Wnd_       = hcfg.Form_Wnd_;
    Width_          = hcfg.Width_;
    Height_         = hcfg.Height_;
    Left_           = hcfg.Left_;
    Top_            = hcfg.Top_;
    Is_Open_        = hcfg.Is_Open_;
    Is_Cursor_Draw_ = hcfg.Is_Cursor_Draw_;
    Is_Capture_Window_Frame_ = hcfg.Is_Capture_Window_Frame_;
}
//---------------------------------------------------------------------------
// 接手來源物件的內部資源。
void hahaha_capture_form_gdi::Move(hahaha_capture_form_gdi&& hcfg) noexcept
{
    Form_Wnd_       = hcfg.Form_Wnd_;
    Width_          = hcfg.Width_;
    Height_         = hcfg.Height_;
    Left_           = hcfg.Left_;
    Top_            = hcfg.Top_;
    Is_Open_        = hcfg.Is_Open_;
    Is_Cursor_Draw_ = hcfg.Is_Cursor_Draw_;
    Is_Capture_Window_Frame_ = hcfg.Is_Capture_Window_Frame_;

    Form_DC_        = hcfg.Form_DC_;
    Mem_DC_         = hcfg.Mem_DC_;
    DIB_            = hcfg.DIB_;
    Old_Bitmap_     = hcfg.Old_Bitmap_;
    Bits_           = hcfg.Bits_;
    Bitmap_         = std::move(hcfg.Bitmap_);

    hcfg.Form_Wnd_       = nullptr;
    hcfg.Form_DC_        = nullptr;
    hcfg.Mem_DC_         = nullptr;
    hcfg.DIB_            = nullptr;
    hcfg.Old_Bitmap_     = nullptr;
    hcfg.Bits_           = nullptr;
    hcfg.Is_Open_        = false;
    hcfg.Is_Cursor_Draw_ = false;
}
//---------------------------------------------------------------------------
// 重設內部狀態。
int hahaha_capture_form_gdi::Reset()
{
    Form_Wnd_       = nullptr;
    Width_          = 0;
    Height_         = 0;
    Left_           = 0;
    Top_            = 0;
    Is_Open_        = false;
    Is_Cursor_Draw_ = false;
    Is_Capture_Window_Frame_ = false;

    Form_DC_    = nullptr;
    Mem_DC_     = nullptr;
    DIB_        = nullptr;
    Old_Bitmap_ = nullptr;
    Bits_       = nullptr;

    Bitmap_.reset();

    return 0;
}
//---------------------------------------------------------------------------
// 開啟指定資源或建立連線。
int hahaha_capture_form_gdi::Open(HWND hwnd)
{
    if (Is_Open_)
    {
        return 0;
    }

    if (!hwnd)
    {
        return -1;
    }

    Form_Wnd_ = hwnd;

    RECT rc_{};
    POINT pt_{0, 0};

    if (Is_Capture_Window_Frame_)
    {
        // ★ 模式 B：擷取整個視窗（含標題欄）
        GetWindowRect(Form_Wnd_, &rc_);

        Left_   = rc_.left;
        Top_    = rc_.top;
        Width_  = rc_.right  - rc_.left;
        Height_ = rc_.bottom - rc_.top;

        // ★ WindowDC = 包含標題欄 + 邊框
        Form_DC_ = GetWindowDC(Form_Wnd_);
    }
    else
    {
        // ★ 模式 A：只擷取 client（不含標題欄）
        GetClientRect(Form_Wnd_, &rc_);

        pt_.x = 0;
        pt_.y = 0;
        ClientToScreen(Form_Wnd_, &pt_);

        Left_   = pt_.x;
        Top_    = pt_.y;
        Width_  = rc_.right  - rc_.left;
        Height_ = rc_.bottom - rc_.top;

        // ★ DC = client area only
        Form_DC_ = GetDC(Form_Wnd_);
    }

    if (!Form_DC_)
    {
        return -1;
    }

    Mem_DC_ = CreateCompatibleDC(Form_DC_);
    if (!Mem_DC_)
    {
        if (Is_Capture_Window_Frame_)
            ReleaseDC(Form_Wnd_, Form_DC_);
        else
            ReleaseDC(Form_Wnd_, Form_DC_);

        Form_DC_ = nullptr;
        return -1;
    }

    // 建立 top-down DIBSection（24-bit）
    BITMAPINFO bmi_{};
    bmi_.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    bmi_.bmiHeader.biWidth       = Width_;
    bmi_.bmiHeader.biHeight      = -Height_;
    bmi_.bmiHeader.biPlanes      = 1;
    bmi_.bmiHeader.biBitCount    = 24;
    bmi_.bmiHeader.biCompression = BI_RGB;

    DIB_ = CreateDIBSection(Form_DC_, &bmi_, DIB_RGB_COLORS, &Bits_, NULL, 0);
    if (!DIB_ || !Bits_)
    {
        DeleteDC(Mem_DC_);
        ReleaseDC(Form_Wnd_, Form_DC_);
        Mem_DC_  = nullptr;
        Form_DC_ = nullptr;
        return -1;
    }

    Old_Bitmap_ = (HBITMAP)SelectObject(Mem_DC_, DIB_);

    Bitmap_.reset(new halib::bitmap_ptr_rgb((unsigned char*)Bits_));
    Bitmap_->Resize(Width_, Height_);

    Is_Open_ = true;
    return 0;
}

//---------------------------------------------------------------------------
// 擷取目前資料並輸出到目標物件。
int hahaha_capture_form_gdi::Grab()
{
	if (!Is_Open_)
    {
        return -1;
	}

    // ★ Zero-copy: BitBlt 直接寫入 bitmap.Image_Ptr_
    BitBlt(
        Mem_DC_,
        0, 0,
        Width_, Height_,
        Form_DC_,
        0, 0,
        SRCCOPY | CAPTUREBLT
    );

    // ★ 正確的滑鼠指標繪製（與 desktop 版相同，只是基準改成視窗）
    CURSORINFO ci_{};
    ci_.cbSize = sizeof(ci_);

    if (Is_Cursor_Draw_ && GetCursorInfo(&ci_) && (ci_.flags & CURSOR_SHOWING))
    {
        ICONINFO ii_{};
        if (GetIconInfo(ci_.hCursor, &ii_))
        {
            // 視窗左上角為基準
            int cursor_x_ = ci_.ptScreenPos.x - Left_ - ii_.xHotspot;
            int cursor_y_ = ci_.ptScreenPos.y - Top_  - ii_.yHotspot;

            HBITMAP hbm_ = ii_.hbmColor ? ii_.hbmColor : ii_.hbmMask;

            BITMAP bmp_{};
            GetObject(hbm_, sizeof(bmp_), &bmp_);

            int w_ = bmp_.bmWidth;
            int h_ = bmp_.bmHeight;

            // ★ 讀取 32-bit BGRA 游標像素
            BITMAPINFO bi_{};
            bi_.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
            bi_.bmiHeader.biWidth       = w_;
            bi_.bmiHeader.biHeight      = -h_;
            bi_.bmiHeader.biPlanes      = 1;
            bi_.bmiHeader.biBitCount    = 32;
            bi_.bmiHeader.biCompression = BI_RGB;

            std::vector<uint32_t> pixels_(w_ * h_);

            HDC hdc_ = GetDC(NULL);
            GetDIBits(hdc_, hbm_, 0, h_, pixels_.data(), &bi_, DIB_RGB_COLORS);
            ReleaseDC(NULL, hdc_);

            // ★ 寫入 BGR24（3 bytes per pixel）
            uint8_t* dstBase_ = (uint8_t*)Bitmap_->Image_Ptr_;
            int dstPitch_     = Width_ * 3;   // 24-bit pitch（不含 padding）

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
                    uint8_t  a_   = (src_ >> 24) & 0xFF;
                    if (a_ == 0)
                    {
                        continue;
                    }

                    uint8_t b_ = (src_      ) & 0xFF;
                    uint8_t g_ = (src_ >>  8) & 0xFF;
                    uint8_t r_ = (src_ >> 16) & 0xFF;

                    uint8_t* dst_ = dstBase_ + dst_y_ * dstPitch_ + dst_x_ * 3;

                    dst_[0] = b_;
                    dst_[1] = g_;
                    dst_[2] = r_;
                }
            }

            DeleteObject(ii_.hbmColor);
            DeleteObject(ii_.hbmMask);
        }
    }

    return 0;
}
//---------------------------------------------------------------------------
// 擷取目前資料並輸出到目標物件。
int hahaha_capture_form_gdi::Grab(const halib::roi& roi)
{
    if (!Is_Open_)
    {
        return -1;
    }

    int rw_ = roi.Width();
    int rh_ = roi.Height();

    // ROI BitBlt：來源是視窗 DC，目的地是 DIBSection
    BitBlt(
        Mem_DC_,
        roi.X1_, roi.Y1_,
        rw_, rh_,
        Form_DC_,
        roi.X1_, roi.Y1_,
        SRCCOPY | CAPTUREBLT
    );

    CURSORINFO ci_{};
    ci_.cbSize = sizeof(ci_);

    if (Is_Cursor_Draw_ && GetCursorInfo(&ci_) && (ci_.flags & CURSOR_SHOWING))
    {
        ICONINFO ii_{};
        if (GetIconInfo(ci_.hCursor, &ii_))
        {
            int cursor_x_ = ci_.ptScreenPos.x - Left_ - ii_.xHotspot;
            int cursor_y_ = ci_.ptScreenPos.y - Top_  - ii_.yHotspot;

            // 滑鼠是否在 ROI 內
            if (cursor_x_ >= roi.X1_ && cursor_x_ < roi.X2_ &&
                cursor_y_ >= roi.Y1_ && cursor_y_ < roi.Y2_)
            {
                int local_x_ = cursor_x_ - roi.X1_;
                int local_y_ = cursor_y_ - roi.Y1_;

                HBITMAP hbm_ = ii_.hbmColor ? ii_.hbmColor : ii_.hbmMask;

                BITMAP bmp_{};
                GetObject(hbm_, sizeof(bmp_), &bmp_);

                int w_ = bmp_.bmWidth;
                int h_ = bmp_.bmHeight;

                // ★ 讀取 32-bit BGRA 游標像素
                BITMAPINFO bi_{};
                bi_.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
                bi_.bmiHeader.biWidth       = w_;
                bi_.bmiHeader.biHeight      = -h_;
                bi_.bmiHeader.biPlanes      = 1;
                bi_.bmiHeader.biBitCount    = 32;
                bi_.bmiHeader.biCompression = BI_RGB;

                std::vector<uint32_t> pixels_(w_ * h_);

                HDC hdc_ = GetDC(NULL);
                GetDIBits(hdc_, hbm_, 0, h_, pixels_.data(), &bi_, DIB_RGB_COLORS);
                ReleaseDC(NULL, hdc_);

                // ★ 寫入 BGR24（3 bytes per pixel）
                uint8_t* dst_base_ = (uint8_t*)Bitmap_->Image_Ptr_;
                int      dst_pitch_ = Width_ * 3;

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
                        uint8_t  a_   = (src_ >> 24) & 0xFF;
                        if (a_ == 0)
                        {
                            continue;
                        }

                        uint8_t b_ = (src_      ) & 0xFF;
                        uint8_t g_ = (src_ >>  8) & 0xFF;
                        uint8_t r_ = (src_ >> 16) & 0xFF;

                        uint8_t* dst_ = dst_base_ + dst_y_ * dst_pitch_ + dst_x_ * 3;

                        dst_[0] = b_;
                        dst_[1] = g_;
                        dst_[2] = r_;
                    }
                }
            }

            DeleteObject(ii_.hbmColor);
            DeleteObject(ii_.hbmMask);
        }
    }

    return 0;
}
//---------------------------------------------------------------------------
// 關閉並釋放目前持有的資源。
void hahaha_capture_form_gdi::Close()
{
    if (Mem_DC_ && Old_Bitmap_)
    {
        SelectObject(Mem_DC_, Old_Bitmap_);
        Old_Bitmap_ = nullptr;
    }

    if (DIB_)
    {
        DeleteObject(DIB_);
        DIB_ = nullptr;
    }

    if (Mem_DC_)
    {
        DeleteDC(Mem_DC_);
        Mem_DC_ = nullptr;
    }

    if (Form_DC_ && Form_Wnd_)
    {
        ReleaseDC(Form_Wnd_, Form_DC_);
        Form_DC_ = nullptr;
    }

    Bits_    = nullptr;
    Is_Open_ = false;
}
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
