//---------------------------------------------------------------------------

#ifndef hahaha_timerH
#define hahaha_timerH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <time.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/clock?view=msvc-170
class hahaha_timer
{
public:
	hahaha_timer();
	~hahaha_timer();

	hahaha_timer(const hahaha_timer& ht);
    hahaha_timer(hahaha_timer&& ht) noexcept;
	hahaha_timer& operator=(const hahaha_timer& ht);
    hahaha_timer& operator=(hahaha_timer&& ht) noexcept;
	void Copy(const hahaha_timer& ht);
    void Move(hahaha_timer&& ht) noexcept;
public:
	int Reset();
	int Start();
	int End();
	double Time();
public:
	clock_t Start_;
	clock_t End_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
