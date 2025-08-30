//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_information_webcam_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_webcam_item::hahaha_information_webcam_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_webcam_item::~hahaha_information_webcam_item()
{

}
//---------------------------------------------------------------------------
hahaha_information_webcam_item::hahaha_information_webcam_item(const hahaha_information_webcam_item& hiwi)
{
    Reset();
	Copy(hiwi);
}
//---------------------------------------------------------------------------
hahaha_information_webcam_item::hahaha_information_webcam_item(hahaha_information_webcam_item&& hiwi) noexcept
{
    Move(std::move(hiwi));
}
//---------------------------------------------------------------------------
hahaha_information_webcam_item& hahaha_information_webcam_item::operator=(const hahaha_information_webcam_item& hiwi)
{
	Copy(hiwi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_webcam_item& hahaha_information_webcam_item::operator=(hahaha_information_webcam_item&& hiwi) noexcept
{
	if (this != &hiwi)
    {
        Move(std::move(hiwi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_webcam_item::Copy(const hahaha_information_webcam_item& hiwi)
{
    Name_Device_ = hiwi.Name_Device_;
}
//---------------------------------------------------------------------------
void hahaha_information_webcam_item::Move(hahaha_information_webcam_item&& hiwi) noexcept
{
    Name_Device_ = std::move(hiwi.Name_Device_);

    hiwi.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_webcam_item::Reset()
{
    Name_Device_ = L"";

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------