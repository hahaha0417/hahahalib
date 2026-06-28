//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_queue_timerH
#define hahaha_thread_pool_queue_timerH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pool_queue_timer
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_thread_pool_queue_timer();
	// 解構物件並釋放相關資源。
	~hahaha_thread_pool_queue_timer();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_pool_queue_timer(const hahaha_thread_pool_queue_timer& htpqt);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_pool_queue_timer(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_pool_queue_timer& operator=(const hahaha_thread_pool_queue_timer& htpqt);
	// 移動指派目前物件內容。
	hahaha_thread_pool_queue_timer& operator=(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_thread_pool_queue_timer& htpqt);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
public:
	// 作為 thread pool timer 的 callback 入口。
	static void CALLBACK Timer_Callback(PVOID parameter, BOOLEAN timer_or_wait_fired);

public:
	// 執行主要處理邏輯。
	virtual int Handle();
public:
	// 建立所需資源並完成初始化。
	virtual int Create(DWORD due_timer, DWORD period);      // ms
    virtual int Change_Timer(DWORD due_timer, DWORD period);      // ms
	// 關閉並釋放目前持有的資源。
	virtual int Close();
public:
    HANDLE Timer_;
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
