//---------------------------------------------------------------------------

#ifndef hahaha_processH
#define hahaha_processH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
//---------------------------------------------------------------------------
#include <define\hahaha_define_sync.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//https://learn.microsoft.com/zh-tw/windows/win32/procthread/creating-processes
class hahaha_process
{
public:
	hahaha_process();
	~hahaha_process();

	hahaha_process(const hahaha_process& hp);
    hahaha_process(hahaha_process&& hp);
	hahaha_process& operator=(const hahaha_process& hp);
    hahaha_process& operator=(hahaha_process&& hp);
	void Copy(const hahaha_process& hp);
    void Move(hahaha_process&& hp);
public:
	int Reset();
public:
	int Create(const std::wstring& command_line);
	int Close();
	int Terminate();
public:
    hahaha_define_sync Wait(const DWORD& milliseconds = INFINITE);
public:
	std::unique_ptr<STARTUPINFO> Start_Up_Info_;
	std::unique_ptr<PROCESS_INFORMATION> Process_Information_;
    std::wstring Command_Line_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
