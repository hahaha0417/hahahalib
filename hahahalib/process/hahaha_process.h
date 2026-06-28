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
	// 建構物件並初始化預設狀態。
	hahaha_process();
	// 解構物件並釋放相關資源。
	~hahaha_process();

	// 以既有物件內容建構新的物件實例。
	hahaha_process(const hahaha_process& hp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_process(hahaha_process&& hp);
	// 複製指派目前物件內容。
	hahaha_process& operator=(const hahaha_process& hp);
    // 移動指派目前物件內容。
    hahaha_process& operator=(hahaha_process&& hp);
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_process& hp);
    // 接手來源物件的內部資源。
    void Move(hahaha_process&& hp);
public:
	// 重設內部狀態。
	int Reset();
public:
	// 建立所需資源並完成初始化。
	int Create(const std::wstring& command_line);
	// 關閉並釋放目前持有的資源。
	int Close();
	// 要求外部程序結束。
	int Terminate();
public:
    // 等待背景工作、事件或外部程序完成。
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
