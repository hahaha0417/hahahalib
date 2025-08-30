//---------------------------------------------------------------------------

#ifndef hahaha_information_process_itemH
#define hahaha_information_process_itemH
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_information_process_item
{
public:
	hahaha_information_process_item();
	~hahaha_information_process_item();

	hahaha_information_process_item(const hahaha_information_process_item& hipi);
    hahaha_information_process_item(hahaha_information_process_item&& hipi) noexcept;
	hahaha_information_process_item& operator=(const hahaha_information_process_item& hipi);
	hahaha_information_process_item& operator=(hahaha_information_process_item&& hipi) noexcept;
	void Copy(const hahaha_information_process_item& hipi);
    void Move(hahaha_information_process_item&& hipi) noexcept;
public:
	int Reset();

public:
public:
public:
public:
public:
public:
    DWORD Id_Process_;
    std::wstring Title_Window_;
    std::wstring Name_Exe_;
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
