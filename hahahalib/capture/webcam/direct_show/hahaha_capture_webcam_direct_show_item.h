//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_direct_show_itemH
#define hahaha_capture_webcam_direct_show_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Windows.h>
#include <vector>
#include <string>
#include <memory>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_capture_webcam_direct_show_item
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_capture_webcam_direct_show_item();
	// 解構物件並釋放相關資源。
	~hahaha_capture_webcam_direct_show_item();

	// 以既有物件內容建構新的物件實例。
	hahaha_capture_webcam_direct_show_item(const hahaha_capture_webcam_direct_show_item& hcwdsi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_webcam_direct_show_item(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
	// 複製指派目前物件內容。
	hahaha_capture_webcam_direct_show_item& operator=(const hahaha_capture_webcam_direct_show_item& hcwdsi);
	// 移動指派目前物件內容。
	hahaha_capture_webcam_direct_show_item& operator=(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_capture_webcam_direct_show_item& hcwdsi);
    // 接手來源物件的內部資源。
    void Move(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
public:
public:
public:
public:
public:
    int Fps_;
    int Width_;
    int Height_;
    int Bits_;
    GUID Sub_Type_;
    std::wstring Format_;
    std::wstring Description_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif