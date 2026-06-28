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
// 建構物件並初始化預設狀態。
hahaha_timer_chrono::hahaha_timer_chrono()
{
	Reset();
}
//---------------------------------------------------------------------------
// 解構物件並釋放相關資源。
hahaha_timer_chrono::~hahaha_timer_chrono()
{

}
//---------------------------------------------------------------------------
// 以既有物件內容建構新的物件實例。
hahaha_timer_chrono::hahaha_timer_chrono(const hahaha_timer_chrono& htc)
{
	Copy(htc);
}
//---------------------------------------------------------------------------
// 以移動方式建構物件並接手既有資源。
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
// 複製來源物件的內部狀態。
void hahaha_timer_chrono::Copy(const hahaha_timer_chrono& htc)
{
	Start_ = htc.Start_;
	End_ = htc.End_;
}
//---------------------------------------------------------------------------
// 接手來源物件的內部資源。
void hahaha_timer_chrono::Move(hahaha_timer_chrono&& htc) noexcept
{
	Start_ = htc.Start_;
	End_ = htc.End_;

    htc.Reset();
}
//---------------------------------------------------------------------------
// 重設內部狀態。
int hahaha_timer_chrono::Reset()
{
	std::chrono::time_point<std::chrono::high_resolution_clock> origin_;
	Start_ = origin_;
	End_ = origin_;

	return 0;
}
//---------------------------------------------------------------------------
// 開始執行目前功能流程。
int hahaha_timer_chrono::Start()
{
	Start_ = std::chrono::high_resolution_clock::now();
	return 0;
}
//---------------------------------------------------------------------------
// 結束計時並固定終點時間。
int hahaha_timer_chrono::End()
{
	End_ = std::chrono::high_resolution_clock::now();
    return 0;
}
//---------------------------------------------------------------------------
template<typename Duration>
// 計算目前累積的耗時。
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
