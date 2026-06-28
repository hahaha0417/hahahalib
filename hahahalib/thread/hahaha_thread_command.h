//---------------------------------------------------------------------------

#ifndef hahaha_thread_commandH
#define hahaha_thread_commandH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
#include <queue>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//https://learn.microsoft.com/en-us/windows/win32/sync/using-event-objects
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_mutex;
class hahaha_thread_command_command;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

class hahaha_thread_command
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_thread_command();
	// 解構物件並釋放相關資源。
	~hahaha_thread_command();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_command(const hahaha_thread_command& htc);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_command(hahaha_thread_command&& htc) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_command& operator=(const hahaha_thread_command& htc);
    // 移動指派目前物件內容。
    hahaha_thread_command& operator=(hahaha_thread_command&& htc) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_thread_command& htc);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_command&& htc) noexcept;
public:
	// 重設內部狀態。
	virtual int Reset();
public:
	// 作為執行緒進入點，轉呼叫物件內部流程。
	static DWORD WINAPI Thread_Start(void* parameter);
	// 執行執行緒主流程。
	virtual int Thread_Proc();
public:
	// 執行主要處理邏輯。
	virtual int Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command);

public:
	// 建立所需資源並完成初始化。
	virtual int Create();
	// 關閉並釋放目前持有的資源。
	virtual int Close();
    // 等待背景工作、事件或外部程序完成。
    virtual int Wait();
public:
    // 加入新的項目或工作。
    virtual int Add_Command();
    // 收到命令後執行對應處理。
    virtual int On_Command();
public:
//    危險，小心使用
	int Terminate();
public:
	DWORD Thread_Id_;
	HANDLE Thread_;
    HANDLE Event_Run_;
    HANDLE Event_Wait_;
	HANDLE Event_Exit_;
public:
	std::queue<std::unique_ptr<hahahalib::hahaha_thread_command_command>> Queue_Command_;
    std::unique_ptr<hahaha_mutex> Mutex_;
public:
public:
    bool Is_Close_;
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
