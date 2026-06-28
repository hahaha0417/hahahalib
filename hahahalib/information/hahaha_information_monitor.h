//---------------------------------------------------------------------------

#ifndef hahaha_information_monitorH
#define hahaha_information_monitorH
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
class hahaha_information_monitor_item;
//---------------------------------------------------------------------------
class hahaha_information_monitor
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_information_monitor();
	// 解構物件並釋放相關資源。
	~hahaha_information_monitor();

	// 以既有物件內容建構新的物件實例。
	hahaha_information_monitor(const hahaha_information_monitor& him);
    // 以移動方式建構物件並接手既有資源。
    hahaha_information_monitor(hahaha_information_monitor&& him) noexcept;
	// 複製指派目前物件內容。
	hahaha_information_monitor& operator=(const hahaha_information_monitor& him);
	// 移動指派目前物件內容。
	hahaha_information_monitor& operator=(hahaha_information_monitor&& him) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_information_monitor& him);
    // 接手來源物件的內部資源。
    void Move(hahaha_information_monitor&& him) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 列舉顯示器資訊並收集結果。
    static BOOL CALLBACK Procedure_Enum(HMONITOR handle_monitor,
    	HDC hdc_monitor,  // 目前列舉到的螢幕 DC。
        LPRECT lprect_monitor,  // 目前螢幕對應的座標範圍。
        LPARAM dw_data  // 傳入列舉 callback 的自訂資料。
    );
public:
    // 取得指定資料或狀態。
    int Get_All();
public:
    // 取得指定資料或狀態。
    int Get_Monitor_Primary_Index();
    // 取得指定資料或狀態。
    std::wstring Get_Monitor_Model_From_HMonitor(HMONITOR hmonitor);
    // 解析輸入內容並更新結果。
    std::wstring Parse_Edid_Model(const BYTE* edid_data, DWORD data_size);
public:
public:
public:
    std::vector<hahaha_information_monitor_item> Monitors_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
