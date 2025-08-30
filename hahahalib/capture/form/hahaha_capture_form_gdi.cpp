//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_form_gdi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_form_gdi::hahaha_capture_form_gdi()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi::~hahaha_capture_form_gdi()
{

}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi::hahaha_capture_form_gdi(const hahaha_capture_form_gdi& hcfg)
{
    Reset();
	Copy(hcfg);
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi::hahaha_capture_form_gdi(hahaha_capture_form_gdi&& hcfg) noexcept
{
    Move(std::move(hcfg));
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi& hahaha_capture_form_gdi::operator=(const hahaha_capture_form_gdi& hcfg)
{
	Copy(hcfg);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_form_gdi& hahaha_capture_form_gdi::operator=(hahaha_capture_form_gdi&& hcfg) noexcept
{
	if (this != &hcfg)
    {
        Move(std::move(hcfg));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_form_gdi::Copy(const hahaha_capture_form_gdi& hcfg)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_form_gdi::Move(hahaha_capture_form_gdi&& hcfg) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_form_gdi::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------