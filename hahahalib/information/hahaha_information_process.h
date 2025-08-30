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
	hahaha_information_process();
	~hahaha_information_process();

	hahaha_information_process(const hahaha_information_process& hip);
    hahaha_information_process(hahaha_information_process&& hip) noexcept;
	hahaha_information_process& operator=(const hahaha_information_process& hip);
	hahaha_information_process& operator=(hahaha_information_process&& hip) noexcept;
	void Copy(const hahaha_information_process& hip);
    void Move(hahaha_information_process&& hip) noexcept;
public:
	int Reset();

public:
    static BOOL CALLBACK Enum_Windows_Procedure(HWND hwnd, LPARAM lparam);
public:
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
