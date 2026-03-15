//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_thread_pool_time_set_event_timer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer::hahaha_thread_pool_time_set_event_timer()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer::~hahaha_thread_pool_time_set_event_timer()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer::hahaha_thread_pool_time_set_event_timer(const hahaha_thread_pool_time_set_event_timer& htptset)
{
    Reset();
	Copy(htptset);
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer::hahaha_thread_pool_time_set_event_timer(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept
{
    Move(std::move(htptset));
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer& hahaha_thread_pool_time_set_event_timer::operator=(const hahaha_thread_pool_time_set_event_timer& htptset)
{
	Copy(htptset);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool_time_set_event_timer& hahaha_thread_pool_time_set_event_timer::operator=(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept
{
	if (this != &htptset)
    {
        Move(std::move(htptset));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_time_set_event_timer::Copy(const hahaha_thread_pool_time_set_event_timer& htptset)
{
    Timer_ID_ = 0;
    Period_ = htptset.Period_;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_time_set_event_timer::Move(hahaha_thread_pool_time_set_event_timer&& htptset) noexcept
{
    Timer_ID_ = htptset.Timer_ID_;
    Period_ = htptset.Period_;

    htptset.Reset();
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer::Reset()
{
    Timer_ID_ = 0;
    Period_ = 0;
    return 0;
}
//---------------------------------------------------------------------------
void CALLBACK hahaha_thread_pool_time_set_event_timer::Timer_Callback(
    UINT timer_id,
    UINT msg,
    DWORD_PTR user,
    DWORD_PTR dw1,
    DWORD_PTR dw2
)
{
	hahaha_thread_pool_time_set_event_timer* timer_ =
		reinterpret_cast<hahaha_thread_pool_time_set_event_timer*>(user);

    if (timer_)
    {
        timer_->Handle();
    }

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer::Handle()
{
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer::Create(DWORD due_timer, DWORD period)
{
    Period_ = period;

	Timer_ID_ = timeSetEvent(
        period,                 // 週期
        1,                      // 最小解析度
        Timer_Callback,         // callback
        (DWORD_PTR)this,        // user data
        TIME_PERIODIC | TIME_CALLBACK_FUNCTION
    );

	return (Timer_ID_ != 0) ? 0 : -1;;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer::Change_Timer(DWORD due_timer, DWORD period)
{
    Close();
    return Create(due_timer, period);
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_time_set_event_timer::Close()
{
	if (Timer_ID_ != 0)
    {
        timeKillEvent(Timer_ID_);
        Timer_ID_ = 0;
    }
	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------