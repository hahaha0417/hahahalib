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
	hahaha_thread_pool_queue_timer();
	~hahaha_thread_pool_queue_timer();

	hahaha_thread_pool_queue_timer(const hahaha_thread_pool_queue_timer& htpqt);
    hahaha_thread_pool_queue_timer(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
	hahaha_thread_pool_queue_timer& operator=(const hahaha_thread_pool_queue_timer& htpqt);
	hahaha_thread_pool_queue_timer& operator=(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
	void Copy(const hahaha_thread_pool_queue_timer& htpqt);
    void Move(hahaha_thread_pool_queue_timer&& htpqt) noexcept;
public:
	int Reset();

public:
public:
	static void CALLBACK Timer_Callback(PVOID parameter, BOOLEAN timer_or_wait_fired);

public:
	virtual int Handle();
public:
	virtual int Create(DWORD due_timer, DWORD period);      // ms
    virtual int Change_Timer(DWORD due_timer, DWORD period);      // ms
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
