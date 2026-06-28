//---------------------------------------------------------------------------

#ifndef hahaha_information_webcam_itemH
#define hahaha_information_webcam_itemH
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
class hahaha_information_webcam_item
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_information_webcam_item();
	// 解構物件並釋放相關資源。
	~hahaha_information_webcam_item();

	// 以既有物件內容建構新的物件實例。
	hahaha_information_webcam_item(const hahaha_information_webcam_item& hiwi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_information_webcam_item(hahaha_information_webcam_item&& hiwi) noexcept;
	// 複製指派目前物件內容。
	hahaha_information_webcam_item& operator=(const hahaha_information_webcam_item& hiwi);
	// 移動指派目前物件內容。
	hahaha_information_webcam_item& operator=(hahaha_information_webcam_item&& hiwi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_information_webcam_item& hiwi);
    // 接手來源物件的內部資源。
    void Move(hahaha_information_webcam_item&& hiwi) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
public:
public:
public:
public:
public:
    std::wstring Name_Device_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif