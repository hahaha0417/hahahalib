//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_event_triggerH
#define hahaha_thread_pool_event_triggerH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_queue_timer
{
public:
	hahaha_queue_timer();
	~hahaha_queue_timer();

	hahaha_queue_timer(const hahaha_queue_timer& hqt);
    hahaha_queue_timer(hahaha_queue_timer&& hqt) noexcept;
	hahaha_queue_timer& operator=(const hahaha_queue_timer& hqt);
	hahaha_queue_timer& operator=(hahaha_queue_timer&& hqt) noexcept;
	void Copy(const hahaha_queue_timer& hqt);
    void Move(hahaha_queue_timer&& hqt) noexcept;
public:
	int Reset();

public:
public:
	static void CALLBACK Timer_Callback(PVOID lpParam, BOOLEAN TimerOrWaitFired);

public:
	virtual int Handle();
public:
	virtual int Create();
	virtual int Close();
    virtual int Wait();
public:
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
