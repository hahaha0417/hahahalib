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
	// 建構物件並初始化預設狀態。
	hahaha_timer_high_precision();
	// 解構物件並釋放相關資源。
	~hahaha_timer_high_precision();

	// 以既有物件內容建構新的物件實例。
	hahaha_timer_high_precision(const hahaha_timer_high_precision& hthp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_timer_high_precision(hahaha_timer_high_precision&& hthp) noexcept;
	// 複製指派目前物件內容。
	hahaha_timer_high_precision& operator=(const hahaha_timer_high_precision& hthp);
    // 移動指派目前物件內容。
    hahaha_timer_high_precision& operator=(hahaha_timer_high_precision&& hthp) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_timer_high_precision& hthp);
    // 接手來源物件的內部資源。
    void Move(hahaha_timer_high_precision&& hthp) noexcept;
public:
	// 重設內部狀態。
	int Reset();
	// 開始執行目前功能流程。
	int Start();
	// 結束計時並固定終點時間。
	int End();
	// 計算目前累積的耗時。
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
