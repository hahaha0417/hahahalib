//---------------------------------------------------------------------------

#ifndef hahaha_capture_form_gdiH
#define hahaha_capture_form_gdiH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

#include <windows.h>
#include <vector>
#include <memory>
#include <bitmap\hahaha_c_bitmap_alloc.h>
#include <bitmap\hahaha_c_bitmap_ptr.h>
#include <shape\hahaha_roi.h>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_form_gdi
{
public:
    hahaha_capture_form_gdi();
    ~hahaha_capture_form_gdi();

    hahaha_capture_form_gdi(const hahaha_capture_form_gdi& hcfg);
    hahaha_capture_form_gdi(hahaha_capture_form_gdi&& hcfg) noexcept;
    hahaha_capture_form_gdi& operator=(const hahaha_capture_form_gdi& hcfg);
    hahaha_capture_form_gdi& operator=(hahaha_capture_form_gdi&& hcfg) noexcept;

    void Copy(const hahaha_capture_form_gdi& hcfg);
    void Move(hahaha_capture_form_gdi&& hcfg) noexcept;

public:
    int Reset();

    // 開啟指定視窗（Form / HWND）
    // Zero-copy: bitmap 必須在 Open() 時 AttachExternalBuffer()
    int Open(HWND hwnd);

    // Zero-copy: BitBlt 直接寫入 bitmap.Image_Ptr_
    int Grab();
    int Grab(const halib::roi& roi);

    void Close();

public:
    HWND Form_Wnd_;
    int  Width_;
    int  Height_;
    int  Left_;
    int  Top_;
    bool Is_Open_;
    bool Is_Cursor_Draw_;
    bool Is_Capture_Window_Frame_;   // true = 含標題欄, false = 只擷取 client


public:
    HDC     Form_DC_;
    HDC     Mem_DC_;
    HBITMAP DIB_;
    HBITMAP Old_Bitmap_;
    void*   Bits_;

    std::unique_ptr<halib::bitmap_ptr_rgb> Bitmap_;
};

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

#endif

