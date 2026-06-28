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
    // 建構物件並初始化預設狀態。
    hahaha_capture_desktop_gdi();
    // 解構物件並釋放相關資源。
    ~hahaha_capture_desktop_gdi();

    // 以既有物件內容建構新的物件實例。
    hahaha_capture_desktop_gdi(const hahaha_capture_desktop_gdi& hcdg);
    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_desktop_gdi(hahaha_capture_desktop_gdi&& hcdg) noexcept;
    // 複製指派目前物件內容。
    hahaha_capture_desktop_gdi& operator=(const hahaha_capture_desktop_gdi& hcdg);
    // 移動指派目前物件內容。
    hahaha_capture_desktop_gdi& operator=(hahaha_capture_desktop_gdi&& hcdg) noexcept;

    // 複製來源物件的內部狀態。
    void Copy(const hahaha_capture_desktop_gdi& hcdg);
    // 接手來源物件的內部資源。
    void Move(hahaha_capture_desktop_gdi&& hcdg) noexcept;

public:
    // 重設內部狀態。
    int Reset();

    // 列出所有螢幕
    int List_Monitors(std::vector<std::wstring>& list);

    // Zero-copy: bitmap 必須在 Open() 時 AttachExternalBuffer()
    int Open(int monitor_index);

    // Zero-copy: BitBlt 直接寫入 bitmap.Image_Ptr_
	int Grab();
    // 擷取目前資料並輸出到目標物件。
    int Grab(const halib::roi& roi /* 要處理的區域範圍。 */);


    // 關閉並釋放目前持有的資源。
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
    // 列舉螢幕輸出並收集座標資訊。
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
