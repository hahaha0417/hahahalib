//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_time_set_event_timerH
#define hahaha_thread_pool_time_set_event_timerH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pool_time_set_event_timer
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_thread_pool_time_set_event_timer();
	// 解構物件並釋放相關資源。
	~hahaha_thread_pool_time_set_event_timer();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_pool_time_set_event_timer(const hahaha_thread_pool_time_set_event_timer& htptset);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_pool_time_set_event_timer(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_pool_time_set_event_timer& operator=(const hahaha_thread_pool_time_set_event_timer& htptset);
	// 移動指派目前物件內容。
	hahaha_thread_pool_time_set_event_timer& operator=(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_thread_pool_time_set_event_timer& htptset);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
public:
	// 作為 thread pool timer 的 callback 入口。
	static void CALLBACK Timer_Callback(
        UINT timer_id,  // 觸發的 timer 識別碼。
        UINT msg,  // Windows timer message 代碼。
        DWORD_PTR user,  // 建立 timer 時帶入的自訂使用者資料。
        DWORD_PTR dw1,  // callback 附帶的第一個平台參數。
        DWORD_PTR dw2  // callback 附帶的第二個平台參數。
    );

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
    UINT Timer_ID_;   // timeSetEvent 回傳的 ID
    DWORD Period_;   // 記錄週期
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
