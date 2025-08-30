//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_timer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <timer\hahaha_timer.h>
//#include <thread>
//hahahalib::hahaha_timer Timer_;
//Timer_.Start();
//std::this_thread::sleep_for(std::chrono::milliseconds(100));
//Timer_.End();
//ShowMessage(UnicodeString(Timer_.Time_Ms()) + "秒");
//---------------------------------------------------------------------------
hahaha_timer::hahaha_timer()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_timer::~hahaha_timer()
{

}
//---------------------------------------------------------------------------
hahaha_timer::hahaha_timer(const hahaha_timer& ht)
{
	Copy(ht);
}
//---------------------------------------------------------------------------
hahaha_timer::hahaha_timer(hahaha_timer&& ht) noexcept
{
	Move(std::move(ht));
}
//---------------------------------------------------------------------------
hahaha_timer& hahaha_timer::operator=(const hahaha_timer& ht)
{
	Copy(ht);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_timer& hahaha_timer::operator=(hahaha_timer&& ht) noexcept
{
	if (this != &ht)
    {
        Move(std::move(ht));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_timer::Copy(const hahaha_timer& ht)
{
	Start_ = ht.Start_;
	End_ = ht.End_;
}
//---------------------------------------------------------------------------
void hahaha_timer::Move(hahaha_timer&& ht) noexcept
{
	Start_ = ht.Start_;
	End_ = ht.End_;

    ht.Reset();

}
//---------------------------------------------------------------------------
int hahaha_timer::Reset()
{
	Start_ = 0;
	End_ = 0;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer::Start()
{
	Start_ = clock();
	return 0;
}
//---------------------------------------------------------------------------
int hahaha_timer::End()
{
	End_ = clock();
    return 0;
}
//---------------------------------------------------------------------------
double hahaha_timer::Time()
{
	// 秒
	return (double)(End_ - Start_) / CLOCKS_PER_SEC;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------