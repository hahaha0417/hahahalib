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
    // 建構物件並初始化預設狀態。
    hahaha_capture_form_gdi();
    // 解構物件並釋放相關資源。
    ~hahaha_capture_form_gdi();

    // 以既有物件內容建構新的物件實例。
    hahaha_capture_form_gdi(const hahaha_capture_form_gdi& hcfg);
    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_form_gdi(hahaha_capture_form_gdi&& hcfg) noexcept;
    // 複製指派目前物件內容。
    hahaha_capture_form_gdi& operator=(const hahaha_capture_form_gdi& hcfg);
    // 移動指派目前物件內容。
    hahaha_capture_form_gdi& operator=(hahaha_capture_form_gdi&& hcfg) noexcept;

    // 複製來源物件的內部狀態。
    void Copy(const hahaha_capture_form_gdi& hcfg);
    // 接手來源物件的內部資源。
    void Move(hahaha_capture_form_gdi&& hcfg) noexcept;

public:
    // 重設內部狀態。
    int Reset();

    // 開啟指定視窗（Form / HWND）
    // Zero-copy: bitmap 必須在 Open() 時 AttachExternalBuffer()
    int Open(HWND hwnd /* 目標視窗的 Windows Handle。 */);

    // Zero-copy: BitBlt 直接寫入 bitmap.Image_Ptr_
    int Grab();
    // 擷取目前資料並輸出到目標物件。
    int Grab(const halib::roi& roi /* 要處理的區域範圍。 */);

    // 關閉並釋放目前持有的資源。
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
