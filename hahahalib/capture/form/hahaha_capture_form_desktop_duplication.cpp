//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_form_desktop_duplication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::~hahaha_capture_form_desktop_duplication()
{

}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication(const hahaha_capture_form_desktop_duplication& hcfdd)
{
    Reset();
	Copy(hcfdd);
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{
    Move(std::move(hcfdd));
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication& hahaha_capture_form_desktop_duplication::operator=(const hahaha_capture_form_desktop_duplication& hcfdd)
{
	Copy(hcfdd);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication& hahaha_capture_form_desktop_duplication::operator=(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{
	if (this != &hcfdd)
    {
        Move(std::move(hcfdd));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Copy(const hahaha_capture_form_desktop_duplication& hcfdd)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Move(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_form_desktop_duplication::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------