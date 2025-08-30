//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_capture_webcam_desktop_duplication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication::hahaha_capture_webcam_desktop_duplication()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication::~hahaha_capture_webcam_desktop_duplication()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication::hahaha_capture_webcam_desktop_duplication(const hahaha_capture_webcam_desktop_duplication& hcwdd)
{
    Reset();
	Copy(hcwdd);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication::hahaha_capture_webcam_desktop_duplication(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept
{
    Move(std::move(hcwdd));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication& hahaha_capture_webcam_desktop_duplication::operator=(const hahaha_capture_webcam_desktop_duplication& hcwdd)
{
	Copy(hcwdd);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_desktop_duplication& hahaha_capture_webcam_desktop_duplication::operator=(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept
{
	if (this != &hcwdd)
    {
        Move(std::move(hcwdd));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_desktop_duplication::Copy(const hahaha_capture_webcam_desktop_duplication& hcwdd)
{

}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_desktop_duplication::Move(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_desktop_duplication::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------