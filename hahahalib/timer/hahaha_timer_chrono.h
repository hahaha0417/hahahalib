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
	// 建構物件並初始化預設狀態。
	hahaha_timer_chrono();
	// 解構物件並釋放相關資源。
	~hahaha_timer_chrono();

	// 以既有物件內容建構新的物件實例。
	hahaha_timer_chrono(const hahaha_timer_chrono& htc);
    // 以移動方式建構物件並接手既有資源。
    hahaha_timer_chrono(hahaha_timer_chrono&& htc) noexcept;
	// 複製指派目前物件內容。
	hahaha_timer_chrono& operator=(const hahaha_timer_chrono& htc);
    // 移動指派目前物件內容。
    hahaha_timer_chrono& operator=(hahaha_timer_chrono&& htc) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_timer_chrono& htc);
    // 接手來源物件的內部資源。
    void Move(hahaha_timer_chrono&& htc) noexcept;
public:
	// 重設內部狀態。
	int Reset();
	// 開始執行目前功能流程。
	int Start();
	// 結束計時並固定終點時間。
	int End();

    //默认输出毫秒
	template<typename Duration=std::chrono::milliseconds>
	// 計算目前累積的耗時。
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
