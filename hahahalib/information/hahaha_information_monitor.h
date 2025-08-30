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
	hahaha_information_monitor();
	~hahaha_information_monitor();

	hahaha_information_monitor(const hahaha_information_monitor& him);
    hahaha_information_monitor(hahaha_information_monitor&& him) noexcept;
	hahaha_information_monitor& operator=(const hahaha_information_monitor& him);
	hahaha_information_monitor& operator=(hahaha_information_monitor&& him) noexcept;
	void Copy(const hahaha_information_monitor& him);
    void Move(hahaha_information_monitor&& him) noexcept;
public:
	int Reset();

public:
    static BOOL CALLBACK Procedure_Enum(HMONITOR handle_monitor,
    	HDC hdc_monitor,
        LPRECT lprect_monitor,
        LPARAM dw_data
    );
public:
    int Get_All();
public:
    int Get_Monitor_Primary_Index();
    std::wstring Get_Monitor_Model_From_HMonitor(HMONITOR hmonitor);
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
