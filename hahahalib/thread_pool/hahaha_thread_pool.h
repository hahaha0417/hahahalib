//---------------------------------------------------------------------------

#ifndef hahaha_thread_poolH
#define hahaha_thread_poolH
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//https://learn.microsoft.com/en-us/windows/win32/procthread/thread-pool-api
//https://www.cnblogs.com/Super-biscuits/p/16199336.html
//https://blog.csdn.net/baidu_16370559/article/details/126954011 * 有空再做其他款
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pool
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_thread_pool();
	// 解構物件並釋放相關資源。
	~hahaha_thread_pool();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_pool(const hahaha_thread_pool& htp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_pool(hahaha_thread_pool&& htp) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_pool& operator=(const hahaha_thread_pool& htp);
    // 移動指派目前物件內容。
    hahaha_thread_pool& operator=(hahaha_thread_pool&& htp) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_thread_pool& htp);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_pool&& htp) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 建立所需資源並完成初始化。
	int Create(const DWORD& thread_max = 4, const DWORD& thread_min = 1);
	// 關閉並釋放目前持有的資源。
	int Close();
	// 回傳目前狀態判斷結果。
	BOOL Is_Open();
public:
	// 作為 thread pool callback 入口，轉呼叫物件處理函式。
	static void WINAPI CallBack_Task(PTP_CALLBACK_INSTANCE instance, PVOID parameter);
	// 加入新的項目或工作。
	int Add_Task();
	// 執行主要處理邏輯。
	virtual int Handle();
public:

public:
	// 線程池
	PTP_POOL Thread_Pool_;
	TP_CALLBACK_ENVIRON Thread_Pool_Environment_;
	DWORD Thread_Max_;
	DWORD Thread_Min_;
	BOOL Is_Open_;




};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
