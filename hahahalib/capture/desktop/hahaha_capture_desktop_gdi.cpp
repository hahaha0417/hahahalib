//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_desktop_gdi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi::~hahaha_capture_desktop_gdi()
{

}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi(const hahaha_capture_desktop_gdi& hcdg)
{
    Reset();
	Copy(hcdg);
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi::hahaha_capture_desktop_gdi(hahaha_capture_desktop_gdi&& hcdg) noexcept
{
    Move(std::move(hcdg));
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi& hahaha_capture_desktop_gdi::operator=(const hahaha_capture_desktop_gdi& hcdg)
{
	Copy(hcdg);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_gdi& hahaha_capture_desktop_gdi::operator=(hahaha_capture_desktop_gdi&& hcdg) noexcept
{
	if (this != &hcdg)
    {
        Move(std::move(hcdg));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_gdi::Copy(const hahaha_capture_desktop_gdi& hcdg)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_gdi::Move(hahaha_capture_desktop_gdi&& hcdg) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_desktop_gdi::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------