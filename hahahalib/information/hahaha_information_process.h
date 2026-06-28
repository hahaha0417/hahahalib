//---------------------------------------------------------------------------

#ifndef hahaha_information_processH
#define hahaha_information_processH
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
class hahaha_information_process_item;
//---------------------------------------------------------------------------
class hahaha_information_process
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_information_process();
	// 解構物件並釋放相關資源。
	~hahaha_information_process();

	// 以既有物件內容建構新的物件實例。
	hahaha_information_process(const hahaha_information_process& hip);
    // 以移動方式建構物件並接手既有資源。
    hahaha_information_process(hahaha_information_process&& hip) noexcept;
	// 複製指派目前物件內容。
	hahaha_information_process& operator=(const hahaha_information_process& hip);
	// 移動指派目前物件內容。
	hahaha_information_process& operator=(hahaha_information_process&& hip) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_information_process& hip);
    // 接手來源物件的內部資源。
    void Move(hahaha_information_process&& hip) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 列舉系統視窗並收集程序資訊。
    static BOOL CALLBACK Enum_Windows_Procedure(HWND hwnd, LPARAM lparam);
public:
    // 取得指定資料或狀態。
    int Get_All();
public:

public:
public:
public:
public:
    std::vector<hahaha_information_process_item> Processes_;
public:
	bool Visible_Only_;
    bool Show_In_Taskbar_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
