//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <shape\function\hahaha_shape_function_roi.h>
#include <shape\hahaha_point.h>
#include "hahaha_capture_desktop_gdi.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// 建構物件並初始化預設狀態。
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi()
{
    Reset();
}
//---------------------------------------------------------------------------
// 解構物件並釋放相關資源。
hahaha_capture_desktop_gdi::~hahaha_capture_desktop_gdi()
{

}

//---------------------------------------------------------------------------
// 以既有物件內容建構新的物件實例。
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi(const hahaha_capture_desktop_gdi& hcdg)
{
    Reset();
    Copy(hcdg);
}
//---------------------------------------------------------------------------
// 以移動方式建構物件並接手既有資源。
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi(hahaha_capture_desktop_gdi&& hcdg) noexcept
{
    Move(std::move(hcdg));
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi&
hahaha_capture_desktop_gdi::operator=(const hahaha_capture_desktop_gdi& hcdg)
{
    if (this != &hcdg)
    {
        Close();
        Reset();
        Copy(hcdg);
    }
    return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi&
// 移動指派目前物件內容。
hahaha_capture_desktop_gdi::operator=(hahaha_capture_desktop_gdi&& hcdg) noexcept
{
    if (this != &hcdg)
    {
        Close();
        Move(std::move(hcdg));
    }
    return *this;
}

//----------------------------------------------------------
void hahaha_capture_desktop_gdi::Copy(const hahaha_capture_desktop_gdi& hcdg)
{
    // 不複製 GDI 狀態，只複製參數
    Monitor_Index_ = hcdg.Monitor_Index_;
    Width_         = hcdg.Width_;
    Height_        = hcdg.Height_;
    Left_          = hcdg.Left_;
	Top_           = hcdg.Top_;
	Is_Open_       = hcdg.Is_Open_;
	Is_Cursor_Draw_ = hcdg.Is_Cursor_Draw_;
}
//---------------------------------------------------------------------------
// 接手來源物件的內部資源。
void hahaha_capture_desktop_gdi::Move(hahaha_capture_desktop_gdi&& hcdg) noexcept
{
    Monitor_Index_ = hcdg.Monitor_Index_;
    Width_         = hcdg.Width_;
    Height_        = hcdg.Height_;
    Left_          = hcdg.Left_;
    Top_           = hcdg.Top_;
	Is_Open_       = hcdg.Is_Open_;
	Is_Cursor_Draw_ = hcdg.Is_Cursor_Draw_;

    Screen_DC_     = hcdg.Screen_DC_;
    Mem_DC_        = hcdg.Mem_DC_;
    DIB_           = hcdg.DIB_;
    Old_Bitmap_    = hcdg.Old_Bitmap_;
    Bits_          = hcdg.Bits_;

    Monitor_Rects_ = std::move(hcdg.Monitor_Rects_);

    hcdg.Screen_DC_  = nullptr;
    hcdg.Mem_DC_     = nullptr;
    hcdg.DIB_        = nullptr;
    hcdg.Old_Bitmap_ = nullptr;
    hcdg.Bits_       = nullptr;
	hcdg.Is_Open_    = false;
	hcdg.Is_Cursor_Draw_ = false;
}

//---------------------------------------------------------------------------
// 重設內部狀態。
int hahaha_capture_desktop_gdi::Reset()
{
    Monitor_Index_ = 0;
    Width_ = Height_ = 0;
    Left_ = Top_ = 0;
	Is_Open_ = false;
	Is_Cursor_Draw_ = false;

    Screen_DC_ = nullptr;
    Mem_DC_ = nullptr;
    DIB_ = nullptr;
    Old_Bitmap_ = nullptr;
    Bits_ = nullptr;

    Monitor_Rects_.clear();
    return 0;
}

//---------------------------------------------------------------------------
// 列舉螢幕輸出並收集座標資訊。
BOOL CALLBACK hahaha_capture_desktop_gdi::Monitor_Enum_Proc(HMONITOR, HDC, LPRECT rc, LPARAM data)
{
    auto* self_ = reinterpret_cast<hahaha_capture_desktop_gdi*>(data);
    self_->Monitor_Rects_.push_back(*rc);
    return TRUE;
}
//---------------------------------------------------------------------------
// 列出目前可擷取的螢幕清單。
int hahaha_capture_desktop_gdi::List_Monitors(std::vector<std::wstring>& list)
{
    Monitor_Rects_.clear();
    EnumDisplayMonitors(NULL, NULL, Monitor_Enum_Proc, (LPARAM)this);

    list.clear();
    for (int i = 0; i < (int)Monitor_Rects_.size(); i++)
    {
        RECT r_ = Monitor_Rects_[i];
        int w_ = r_.right - r_.left;
        int h_ = r_.bottom - r_.top;

        wchar_t buf_[256];
        swprintf(buf_, 256, L"Monitor %d: %dx%d (%d,%d)", i, w_, h_, r_.left, r_.top);
        list.push_back(buf_);
    }

    return (int)Monitor_Rects_.size();
}

//---------------------------------------------------------------------------
// 開啟指定資源或建立連線。
int hahaha_capture_desktop_gdi::Open(int monitor_index)
{
    if (Is_Open_)
    {
        return 0;
    }

    Monitor_Rects_.clear();
    EnumDisplayMonitors(NULL, NULL, Monitor_Enum_Proc, (LPARAM)this);

    if (monitor_index < 0 || monitor_index >= (int)Monitor_Rects_.size())
    {
        return -1;
    }

    Monitor_Index_ = monitor_index;

    RECT r_ = Monitor_Rects_[monitor_index];
    Left_ = r_.left;
    Top_ = r_.top;
    Width_ = r_.right - r_.left;
    Height_ = r_.bottom - r_.top;

    Screen_DC_ = GetDC(NULL);
    if (!Screen_DC_)
    {
        return -1;
    }

    Mem_DC_ = CreateCompatibleDC(Screen_DC_);
    if (!Mem_DC_)
    {
        ReleaseDC(NULL, Screen_DC_);
        Screen_DC_ = nullptr;
        return -1;
    }

    // 建立 top-down DIBSection
    BITMAPINFO bmi_ = {};
    bmi_.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi_.bmiHeader.biWidth = Width_;
    bmi_.bmiHeader.biHeight = -Height_;
    bmi_.bmiHeader.biPlanes = 1;
    bmi_.bmiHeader.biBitCount = 24;
    bmi_.bmiHeader.biCompression = BI_RGB;

    DIB_ = CreateDIBSection(Screen_DC_, &bmi_, DIB_RGB_COLORS, &Bits_, NULL, 0);
    if (!DIB_ || !Bits_)
    {
        DeleteDC(Mem_DC_);
        ReleaseDC(NULL, Screen_DC_);
        Mem_DC_ = nullptr;
        Screen_DC_ = nullptr;
        return -1;
    }

    Old_Bitmap_ = (HBITMAP)SelectObject(Mem_DC_, DIB_);

    // ★ Zero-copy: bitmap 使用 DIBSection 的記憶體
    Bitmap_.reset(new halib::bitmap_ptr_rgb((unsigned char*)Bits_));
    Bitmap_->Resize(Width_, Height_);

    Is_Open_ = true;
    return 0;
}

//---------------------------------------------------------------------------
// 擷取目前資料並輸出到目標物件。
int hahaha_capture_desktop_gdi::Grab()
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
		Screen_DC_,
		Left_, Top_,
		SRCCOPY | CAPTUREBLT
	);

    // ★ 正確的滑鼠指標繪製（使用 GetDIBits 取得像素資料）
	CURSORINFO ci_ = {};
	ci_.cbSize = sizeof(ci_);

	if (Is_Cursor_Draw_ && GetCursorInfo(&ci_) && (ci_.flags & CURSOR_SHOWING))
	{
		ICONINFO ii_ = {};
		if (GetIconInfo(ci_.hCursor, &ii_))
		{
			int cursor_x_ = ci_.ptScreenPos.x - Left_ - ii_.xHotspot;
			int cursor_y_ = ci_.ptScreenPos.y - Top_  - ii_.yHotspot;

			HBITMAP hbm_ = ii_.hbmColor ? ii_.hbmColor : ii_.hbmMask;

			BITMAP bmp_ = {};
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
            int dstPitch_ = Width_ * 3;   // ★ 24-bit pitch（不含 padding）

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
int hahaha_capture_desktop_gdi::Grab(const halib::roi& roi)
{
    if (!Is_Open_)
    {
        return -1;
    }

    int rw_ = roi.Width();
    int rh_ = roi.Height();

    // ★ ROI BitBlt：目的地永遠從 (0,0)
    BitBlt(
        Mem_DC_,
        roi.X1_, roi.Y1_,
        rw_, rh_,
        Screen_DC_,
        Left_ + roi.X1_, Top_ + roi.Y1_,
        SRCCOPY | CAPTUREBLT
    );

    // ★ 滑鼠繪製
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
                // ★ ROI 內部座標
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
                int dst_pitch_ = Width_ * 3;   // ★ 24-bit pitch（不含 padding）

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
void hahaha_capture_desktop_gdi::Close()
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

    if (Screen_DC_)
    {
        ReleaseDC(NULL, Screen_DC_);
        Screen_DC_ = nullptr;
    }

    Bits_ = nullptr;
    Is_Open_ = false;
}
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
