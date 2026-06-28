//---------------------------------------------------------------------------

#ifndef hahaha_thread_pauseH
#define hahaha_thread_pauseH
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
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pause
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_thread_pause();
	// 解構物件並釋放相關資源。
	~hahaha_thread_pause();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_pause(const hahaha_thread_pause& htp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_pause(hahaha_thread_pause&& htp) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_pause& operator=(const hahaha_thread_pause& htp);
	// 移動指派目前物件內容。
	hahaha_thread_pause& operator=(hahaha_thread_pause&& htp) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_thread_pause& htp);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_pause&& htp) noexcept;
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
	virtual int Handle();
public:
	// 建立所需資源並完成初始化。
	virtual int Create();
	// 關閉並釋放目前持有的資源。
	virtual int Close();
    // 等待背景工作、事件或外部程序完成。
    virtual int Wait();
public:
    // 將暫停中的執行緒恢復執行。
    virtual int Enabled();
    // 讓執行緒進入暫停狀態。
    virtual int Disabled();
public:
//    危險，小心使用
	virtual int Terminate();
public:
	DWORD Thread_Id_;
	HANDLE Thread_;
    HANDLE Event_Run_;
    HANDLE Event_Wait_;
	HANDLE Event_Exit_;
public:
    bool Is_Close_;
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
