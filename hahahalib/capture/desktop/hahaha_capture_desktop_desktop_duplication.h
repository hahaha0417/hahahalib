#ifndef hahaha_capture_desktop_desktop_duplicationH
#define hahaha_capture_desktop_desktop_duplicationH
#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include <windows.h>
#include <d3d11.h>
#include <dxgi1_2.h>

#include <define/hahaha_define_com.h>
#include <shape/hahaha_roi.h>
#include <bitmap\hahaha_c_bitmap_alloc.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_capture_desktop_desktop_duplication
{
public:
    hahaha_capture_desktop_desktop_duplication();
    ~hahaha_capture_desktop_desktop_duplication();

    hahaha_capture_desktop_desktop_duplication(const hahaha_capture_desktop_desktop_duplication&) = delete;
    hahaha_capture_desktop_desktop_duplication& operator=(const hahaha_capture_desktop_desktop_duplication&) = delete;

    hahaha_capture_desktop_desktop_duplication(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
    hahaha_capture_desktop_desktop_duplication& operator=(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;

    void Move(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;

public:
    int Reset();

    int List_Monitors(std::vector<std::wstring>& list);
    int Open(int monitor_index);

    int Grab();
    int Grab(const halib::roi& roi);

    void Close();

public:
	int   Width_;
	int   Height_;
	bool  Is_Open_;
	bool Is_Cursor_Draw_;

    DXGI_OUTPUT_DESC    Output_Desc_{};
    DXGI_OUTDUPL_DESC   Dup_Desc_{};

    halib_def::com_ptr<ID3D11Device>            Device_;
    halib_def::com_ptr<ID3D11DeviceContext>     Context_;
    halib_def::com_ptr<IDXGIOutput1>            Output1_;
	halib_def::com_ptr<IDXGIOutputDuplication>  Duplication_;
	halib_def::com_ptr<ID3D11Texture2D>         Staging_Tex_;

    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_;
};
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
#endif

