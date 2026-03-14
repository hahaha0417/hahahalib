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
	hahaha_thread_pool_time_set_event_timer();
	~hahaha_thread_pool_time_set_event_timer();

	hahaha_thread_pool_time_set_event_timer(const hahaha_thread_pool_time_set_event_timer& htptset);
    hahaha_thread_pool_time_set_event_timer(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
	hahaha_thread_pool_time_set_event_timer& operator=(const hahaha_thread_pool_time_set_event_timer& htptset);
	hahaha_thread_pool_time_set_event_timer& operator=(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
	void Copy(const hahaha_thread_pool_time_set_event_timer& htptset);
    void Move(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept;
public:
	int Reset();

public:
public:
	static void CALLBACK Timer_Callback(
        UINT timer_id,
        UINT msg,
        DWORD_PTR user,
        DWORD_PTR dw1,
        DWORD_PTR dw2
    );

public:
	virtual int Handle();
public:
	virtual int Create(DWORD due_timer, DWORD period);      // ms
    virtual int Change_Timer(DWORD due_timer, DWORD period);      // ms
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
