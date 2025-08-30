//---------------------------------------------------------------------------

#ifndef hahaha_timer_high_precisionH
#define hahaha_timer_high_precisionH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/clock?view=msvc-170
// https://blog.csdn.net/xp178171640/article/details/118306073
class hahaha_timer_high_precision
{
public:
	hahaha_timer_high_precision();
	~hahaha_timer_high_precision();

	hahaha_timer_high_precision(const hahaha_timer_high_precision& hthp);
    hahaha_timer_high_precision(hahaha_timer_high_precision&& hthp) noexcept;
	hahaha_timer_high_precision& operator=(const hahaha_timer_high_precision& hthp);
    hahaha_timer_high_precision& operator=(hahaha_timer_high_precision&& hthp) noexcept;
	void Copy(const hahaha_timer_high_precision& hthp);
    void Move(hahaha_timer_high_precision&& hthp) noexcept;
public:
	int Reset();
	int Start();
	int End();
	double Time();
public:
	LARGE_INTEGER Ticks_;
	LARGE_INTEGER Start_;
	LARGE_INTEGER End_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
