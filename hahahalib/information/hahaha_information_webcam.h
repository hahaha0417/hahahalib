//---------------------------------------------------------------------------

#ifndef hahaha_information_webcamH
#define hahaha_information_webcamH
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
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_information_webcam_item;
//---------------------------------------------------------------------------
class hahaha_information_webcam
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_information_webcam();
	// 解構物件並釋放相關資源。
	~hahaha_information_webcam();

	// 以既有物件內容建構新的物件實例。
	hahaha_information_webcam(const hahaha_information_webcam& hiw);
    // 以移動方式建構物件並接手既有資源。
    hahaha_information_webcam(hahaha_information_webcam&& hiw) noexcept;
	// 複製指派目前物件內容。
	hahaha_information_webcam& operator=(const hahaha_information_webcam& hiw);
	// 移動指派目前物件內容。
	hahaha_information_webcam& operator=(hahaha_information_webcam&& hiw) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_information_webcam& hiw);
    // 接手來源物件的內部資源。
    void Move(hahaha_information_webcam&& hiw) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 取得指定資料或狀態。
    int Get_All();
public:
public:
public:
public:
    std::vector<hahaha_information_webcam_item> Webcams_;
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif