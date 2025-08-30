//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_timer_high_precision.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <timer\hahaha_timer_high_precision.h>
//#include <thread>
//hahahalib::hahaha_timer_high_precision Timer_;
//Timer_.Start();
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
//Timer_.End();
//ShowMessage(UnicodeString(Timer_.Time_Ms()) + "毫秒");
//---------------------------------------------------------------------------
hahaha_timer_high_precision::hahaha_timer_high_precision()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_timer_high_precision::~hahaha_timer_high_precision()
{

}
//---------------------------------------------------------------------------
hahaha_timer_high_precision::hahaha_timer_high_precision(const hahaha_timer_high_precision& hthp)
{
	Copy(hthp);
}
//---------------------------------------------------------------------------
hahaha_timer_high_precision::hahaha_timer_high_precision(hahaha_timer_high_precision&& hthp) noexcept
{
	Move(std::move(hthp));
}
//---------------------------------------------------------------------------
hahaha_timer_high_precision& hahaha_timer_high_precision::operator=(const hahaha_timer_high_precision& hthp)
{
	Copy(hthp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_timer_high_precision& hahaha_timer_high_precision::operator=(hahaha_timer_high_precision&& hthp) noexcept
{
	if (this != &hthp)
    {
        Move(std::move(hthp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_timer_high_precision::Copy(const hahaha_timer_high_precision& hthp)
{
	Ticks_ = hthp.Ticks_;
	Start_ = hthp.Start_;
	End_ = hthp.End_;
}
//---------------------------------------------------------------------------
void hahaha_timer_high_precision::Move(hahaha_timer_high_precision&& hthp) noexcept
{
	Ticks_ = hthp.Ticks_;
	Start_ = hthp.Start_;
	End_ = hthp.End_;

    hthp.Reset();
}
//---------------------------------------------------------------------------
int hahaha_timer_high_precision::Reset()
{
	LARGE_INTEGER origin_;

	Start_ = origin_;
	End_ = origin_;
	Ticks_ = origin_;

	QueryPerformanceFrequency(&Ticks_);

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer_high_precision::Start()
{
	QueryPerformanceCounter(&Start_);
	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer_high_precision::End()
{
	QueryPerformanceCounter(&End_);
    return 0;
}
//---------------------------------------------------------------------------
double hahaha_timer_high_precision::Time()
{
	// ms
	return (double)(End_.QuadPart - Start_.QuadPart) * 1000.0 / (double)Ticks_.QuadPart;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------