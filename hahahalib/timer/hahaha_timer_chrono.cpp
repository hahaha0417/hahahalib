//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_timer_chrono.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <timer\hahaha_timer_chrono.h>
//#include <thread>
//hahahalib::hahaha_timer_chrono Timer_;
//Timer_.Start();
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
//Timer_.End();
//ShowMessage(UnicodeString(Timer_.Time_Ms()) + "秒");
//---------------------------------------------------------------------------
hahaha_timer_chrono::hahaha_timer_chrono()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_timer_chrono::~hahaha_timer_chrono()
{

}
//---------------------------------------------------------------------------
hahaha_timer_chrono::hahaha_timer_chrono(const hahaha_timer_chrono& htc)
{
	Copy(htc);
}
//---------------------------------------------------------------------------
hahaha_timer_chrono::hahaha_timer_chrono(hahaha_timer_chrono&& htc) noexcept
{
	Move(std::move(htc));

}
//---------------------------------------------------------------------------
hahaha_timer_chrono& hahaha_timer_chrono::operator=(const hahaha_timer_chrono& htc)
{
	Copy(htc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_timer_chrono& hahaha_timer_chrono::operator=(hahaha_timer_chrono&& htc) noexcept
{
	if (this != &htc)
    {
        Move(std::move(htc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_timer_chrono::Copy(const hahaha_timer_chrono& htc)
{
	Start_ = htc.Start_;
	End_ = htc.End_;
}
//---------------------------------------------------------------------------
void hahaha_timer_chrono::Move(hahaha_timer_chrono&& htc) noexcept
{
	Start_ = htc.Start_;
	End_ = htc.End_;

    htc.Reset();
}
//---------------------------------------------------------------------------
int hahaha_timer_chrono::Reset()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> origin_;
	Start_ = origin_;
	End_ = origin_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer_chrono::Start()
{
	Start_ = std::chrono::high_resolution_clock::now();
	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer_chrono::End()
{
	End_ = std::chrono::high_resolution_clock::now();
    return 0;
}
//---------------------------------------------------------------------------
template<typename Duration>
int64_t hahaha_timer_chrono::Time()
{
	return std::chrono::duration_cast<Duration>(End_ - Start_).count();
}
//---------------------------------------------------------------------------
//毫妙
int64_t hahaha_timer_chrono::Time_Ms()
{
	return Time<std::chrono::milliseconds>();
}
//---------------------------------------------------------------------------
//微妙
int64_t hahaha_timer_chrono::Time_Micro()
{
	return Time<std::chrono::microseconds>();
}
//---------------------------------------------------------------------------
//nano second
int64_t hahaha_timer_chrono::Time_Nano()
{
	return Time<std::chrono::nanoseconds>();
}
//---------------------------------------------------------------------------
//second
int64_t hahaha_timer_chrono::Time_Seconds()
{
	return Time<std::chrono::seconds>();
}
//---------------------------------------------------------------------------
//minute
int64_t hahaha_timer_chrono::Time_Minutes()
{
	return Time<std::chrono::minutes>();
}
//---------------------------------------------------------------------------
//hour
int64_t hahaha_timer_chrono::Time_Hour()
{
	return Time<std::chrono::hours>();
}


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------