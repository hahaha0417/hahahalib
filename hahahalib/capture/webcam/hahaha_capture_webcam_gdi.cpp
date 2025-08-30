//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_webcam_gdi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi::hahaha_capture_webcam_gdi()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi::~hahaha_capture_webcam_gdi()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi::hahaha_capture_webcam_gdi(const hahaha_capture_webcam_gdi& hcwg)
{
    Reset();
	Copy(hcwg);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi::hahaha_capture_webcam_gdi(hahaha_capture_webcam_gdi&& hcwg) noexcept
{
    Move(std::move(hcwg));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi& hahaha_capture_webcam_gdi::operator=(const hahaha_capture_webcam_gdi& hcwg)
{
	Copy(hcwg);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_gdi& hahaha_capture_webcam_gdi::operator=(hahaha_capture_webcam_gdi&& hcwg) noexcept
{
	if (this != &hcwg)
    {
        Move(std::move(hcwg));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_gdi::Copy(const hahaha_capture_webcam_gdi& hcwg)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_gdi::Move(hahaha_capture_webcam_gdi&& hcwg) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_gdi::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------