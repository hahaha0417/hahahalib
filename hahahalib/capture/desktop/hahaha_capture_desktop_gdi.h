#ifndef hahaha_capture_desktop_gdiH
#define hahaha_capture_desktop_gdiH
#pragma once

#include <windows.h>
#include <vector>
#include <memory>
#include <string>
#include <bitmap\hahaha_c_bitmap_alloc.h>
#include <bitmap\hahaha_c_bitmap_ptr.h>
#include <shape\hahaha_roi.h>
//---------------------------------------------------------------------------
namespace hahahalib
{


//---------------------------------------------------------------------------
class hahaha_capture_desktop_gdi
{
public:
    hahaha_capture_desktop_gdi();
    ~hahaha_capture_desktop_gdi();

    hahaha_capture_desktop_gdi(const hahaha_capture_desktop_gdi& hcdg);
    hahaha_capture_desktop_gdi(hahaha_capture_desktop_gdi&& hcdg) noexcept;
    hahaha_capture_desktop_gdi& operator=(const hahaha_capture_desktop_gdi& hcdg);
    hahaha_capture_desktop_gdi& operator=(hahaha_capture_desktop_gdi&& hcdg) noexcept;

    void Copy(const hahaha_capture_desktop_gdi& hcdg);
    void Move(hahaha_capture_desktop_gdi&& hcdg) noexcept;

public:
    int Reset();

    // 列出所有螢幕
    int List_Monitors(std::vector<std::wstring>& list);

    // Zero-copy: bitmap 必須在 Open() 時 AttachExternalBuffer()
    int Open(int monitor_index);

    // Zero-copy: BitBlt 直接寫入 bitmap.Image_Ptr_
	int Grab();
    int Grab(const halib::roi& roi);


    void Close();

public:
    int Monitor_Index_;
    int Width_;
    int Height_;
    int Left_;
    int Top_;
	bool Is_Open_;
	bool Is_Cursor_Draw_;

public:
    static BOOL CALLBACK Monitor_Enum_Proc(HMONITOR hMon, HDC, LPRECT rc, LPARAM data);

public:
    HDC     Screen_DC_;
    HDC     Mem_DC_;
    HBITMAP DIB_;
    HBITMAP Old_Bitmap_;
    void*   Bits_;

    std::vector<RECT> Monitor_Rects_;

    std::unique_ptr<halib::bitmap_ptr_rgb> Bitmap_;
};
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
#endif

