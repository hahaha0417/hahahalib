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
	// 建構物件並初始化預設狀態。
	hahaha_timer();
	// 解構物件並釋放相關資源。
	~hahaha_timer();

	// 以既有物件內容建構新的物件實例。
	hahaha_timer(const hahaha_timer& ht);
    // 以移動方式建構物件並接手既有資源。
    hahaha_timer(hahaha_timer&& ht) noexcept;
	// 複製指派目前物件內容。
	hahaha_timer& operator=(const hahaha_timer& ht);
    // 移動指派目前物件內容。
    hahaha_timer& operator=(hahaha_timer&& ht) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_timer& ht);
    // 接手來源物件的內部資源。
    void Move(hahaha_timer&& ht) noexcept;
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
	clock_t Start_;
	clock_t End_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
