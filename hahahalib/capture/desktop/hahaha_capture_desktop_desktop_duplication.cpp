//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_desktop_desktop_duplication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::~hahaha_capture_desktop_desktop_duplication()
{

}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication(const hahaha_capture_desktop_desktop_duplication& hcddd)
{
    Reset();
	Copy(hcddd);
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication::hahaha_capture_desktop_desktop_duplication(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
    Move(std::move(hcddd));
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication& hahaha_capture_desktop_desktop_duplication::operator=(const hahaha_capture_desktop_desktop_duplication& hcddd)
{
	Copy(hcddd);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_desktop_desktop_duplication& hahaha_capture_desktop_desktop_duplication::operator=(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{
	if (this != &hcddd)
    {
        Move(std::move(hcddd));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Copy(const hahaha_capture_desktop_desktop_duplication& hcddd)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_desktop_desktop_duplication::Move(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_desktop_desktop_duplication::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------