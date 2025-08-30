//---------------------------------------------------------------------------

#ifndef hahaha_information_monitor_itemH
#define hahaha_information_monitor_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Windows.h>
#include <vector>
#include <string>
#include <memory>
//---------------------------------------------------------------------------
#include <shape\hahaha_rectangle.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_information_monitor_item
{
public:
	hahaha_information_monitor_item();
	~hahaha_information_monitor_item();

	hahaha_information_monitor_item(const hahaha_information_monitor_item& himi);
    hahaha_information_monitor_item(hahaha_information_monitor_item&& himi) noexcept;
	hahaha_information_monitor_item& operator=(const hahaha_information_monitor_item& himi);
	hahaha_information_monitor_item& operator=(hahaha_information_monitor_item&& himi) noexcept;
	void Copy(const hahaha_information_monitor_item& himi);
    void Move(hahaha_information_monitor_item&& himi) noexcept;
public:
	int Reset();

public:
    HMONITOR Handle_Monitor_;
	std::unique_ptr<halib::rect> Region_Monitor_;
    std::unique_ptr<halib::rect> Region_Work_;
    DWORD Flag_;
    std::wstring Name_Device_;
    std::wstring Name_Product_;

public:
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
