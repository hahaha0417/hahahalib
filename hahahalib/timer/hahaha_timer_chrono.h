//---------------------------------------------------------------------------

#ifndef hahaha_timer_chronoH
#define hahaha_timer_chronoH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <chrono>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// 注意：似乎高精度因為硬體的關係，只能準到毫秒，暫時不要用
//---------------------------------------------------------------------------
// https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/clock?view=msvc-170
// https://kheresy.wordpress.com/2013/12/27/c-stl-chrono/
class hahaha_timer_chrono
{
public:
	hahaha_timer_chrono();
	~hahaha_timer_chrono();

	hahaha_timer_chrono(const hahaha_timer_chrono& htc);
    hahaha_timer_chrono(hahaha_timer_chrono&& htc) noexcept;
	hahaha_timer_chrono& operator=(const hahaha_timer_chrono& htc);
    hahaha_timer_chrono& operator=(hahaha_timer_chrono&& htc) noexcept;
	void Copy(const hahaha_timer_chrono& htc);
    void Move(hahaha_timer_chrono&& htc) noexcept;
public:
	int Reset();
	int Start();
	int End();

    //默认输出毫秒
	template<typename Duration=std::chrono::milliseconds>
	int64_t Time();

	//毫妙
	int64_t Time_Ms();

	//微妙
	int64_t Time_Micro();

	//nano second
	int64_t Time_Nano();

	//second
	int64_t Time_Seconds();

	//minute
	int64_t Time_Minutes();

	//hour
	int64_t Time_Hour();


public:
	std::chrono::time_point<std::chrono::high_resolution_clock> Start_;
	std::chrono::time_point<std::chrono::high_resolution_clock> End_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
