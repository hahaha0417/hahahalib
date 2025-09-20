//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_thread_pool_queue_timer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer::hahaha_thread_pool_queue_timer()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer::~hahaha_thread_pool_queue_timer()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer::hahaha_thread_pool_queue_timer(const hahaha_thread_pool_queue_timer& htpqt)
{
    Reset();
	Copy(htpqt);
}
//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer::hahaha_thread_pool_queue_timer(hahaha_thread_pool_queue_timer&& htpqt) noexcept
{
    Move(std::move(htpqt));
}
//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer& hahaha_thread_pool_queue_timer::operator=(const hahaha_thread_pool_queue_timer& htpqt)
{
	Copy(htpqt);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool_queue_timer& hahaha_thread_pool_queue_timer::operator=(hahaha_thread_pool_queue_timer&& htpqt) noexcept
{
	if (this != &htpqt)
    {
        Move(std::move(htpqt));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_queue_timer::Copy(const hahaha_thread_pool_queue_timer& htpqt)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_pool_queue_timer::Move(hahaha_thread_pool_queue_timer&& htpqt) noexcept
{
    Timer_ = htpqt.Timer_;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_queue_timer::Reset()
{
    Timer_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------
void CALLBACK hahaha_thread_pool_queue_timer::Timer_Callback(PVOID parameter, BOOLEAN timer_or_wait_fired)
{
    if(!timer_or_wait_fired)
    {
        return;
    }

    hahaha_thread_pool_queue_timer* timer_ = (hahaha_thread_pool_queue_timer*)parameter;
    timer_->Handle();

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_queue_timer::Handle()
{
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_queue_timer::Create(DWORD due_timer, DWORD period)
{
    CreateTimerQueueTimer(&Timer_,
    	NULL,
        Timer_Callback,
        this,
        due_timer,
        period,
        WT_EXECUTEDEFAULT
    );
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_queue_timer::Change_Timer(DWORD due_timer, DWORD period)
{
    // 把週期改成 500ms，立即觸發下一次
    ChangeTimerQueueTimer(NULL, Timer_, due_timer, period);
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_queue_timer::Close()
{
    if(Timer_ != NULL)
    {
        // 刪除 timer
    	DeleteTimerQueueTimer(NULL, Timer_, NULL);
        Timer_ = NULL;
    }
    return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------