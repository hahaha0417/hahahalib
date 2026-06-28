#ifndef hahaha_capture_form_desktop_duplicationH
#define hahaha_capture_form_desktop_duplicationH
#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include <windows.h>
#include <d3d11.h>
#include <dxgi1_2.h>

#include <define/hahaha_define_com.h>
#include <shape/hahaha_roi.h>
#include <bitmap/hahaha_c_bitmap_alloc.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_capture_form_desktop_duplication
{
public:
    // 建構物件並初始化預設狀態。
    hahaha_capture_form_desktop_duplication();
    // 解構物件並釋放相關資源。
    ~hahaha_capture_form_desktop_duplication();

    hahaha_capture_form_desktop_duplication(const hahaha_capture_form_desktop_duplication&) = delete;
    hahaha_capture_form_desktop_duplication& operator=(const hahaha_capture_form_desktop_duplication&) = delete;

    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_form_desktop_duplication(hahaha_capture_form_desktop_duplication&& other) noexcept;
    // 移動指派目前物件內容。
    hahaha_capture_form_desktop_duplication& operator=(hahaha_capture_form_desktop_duplication&& other) noexcept;

    // 接手來源物件的內部資源。
    void Move(hahaha_capture_form_desktop_duplication&& other) noexcept;

public:
    // 重設內部狀態。
    int Reset();

    // 新增 include_titlebar 選項
    int Open(HWND hwnd /* 目標視窗的 Windows Handle。 */);

    // 擷取目前資料並輸出到目標物件。
    int Grab();
    // 擷取目前資料並輸出到目標物件。
    int Grab(const halib::roi& roi /* 要處理的區域範圍。 */);

    // 關閉並釋放目前持有的資源。
    void Close();

    // 依視窗位置尋找對應的 DXGI 輸出裝置。
    static bool FindOutputForWindow(HWND hwnd,  // 目標視窗的 Windows Handle。
        halib_def::com_ptr<IDXGIOutput1>& out_output1,  // 輸出的 DXGI Output1 物件。
        DXGI_OUTPUT_DESC& out_desc
    );

public:
    int   Width_;
    int   Height_;
    bool  Is_Open_;
    bool  Is_Cursor_Draw_;
    bool  Is_Capture_Window_Frame_;   // ★ 新增

    HWND  Hwnd_;
    RECT  Window_Rect_;            // 真正像素邊界（DWM）

    DXGI_OUTPUT_DESC   Output_Desc_;
    DXGI_OUTDUPL_DESC  Dup_Desc_;

    halib_def::com_ptr<ID3D11Device>           Device_;
    halib_def::com_ptr<ID3D11DeviceContext>    Context_;
    halib_def::com_ptr<IDXGIOutput1>           Output1_;
    halib_def::com_ptr<IDXGIOutputDuplication> Duplication_;
    halib_def::com_ptr<ID3D11Texture2D>        Staging_Tex_;

    std::unique_ptr<halib::bitmap_alloc_argb>  Bitmap_;
};

//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
#endif
