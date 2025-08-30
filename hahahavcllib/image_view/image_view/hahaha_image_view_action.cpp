//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_image_view_action.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_action::hahaha_image_view_action()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_action::~hahaha_image_view_action()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_action::hahaha_image_view_action(const hahaha_image_view_action& hiva)
{
    Reset();
	Copy(hiva);
}
//---------------------------------------------------------------------------
hahaha_image_view_action::hahaha_image_view_action(hahaha_image_view_action&& hiva) noexcept
{
    Move(std::move(hiva));

}
//---------------------------------------------------------------------------
hahaha_image_view_action& hahaha_image_view_action::operator=(const hahaha_image_view_action& hiva)
{
    Copy(hiva);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_action& hahaha_image_view_action::operator=(hahaha_image_view_action&& hiva) noexcept
{
	if (this != &hiva)
    {
        Move(std::move(hiva));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_action::Copy(const hahaha_image_view_action& hiva)
{
    Enabled_ = hiva.Enabled_;
    Visibled_ = hiva.Visibled_;
    Action_ = hiva.Action_;

}
//---------------------------------------------------------------------------
void hahaha_image_view_action::Move(hahaha_image_view_action&& hiva) noexcept
{
    Enabled_ = hiva.Enabled_;
    Visibled_ = hiva.Visibled_;
    Action_ = hiva.Action_;

    hiva.Reset();

}
//---------------------------------------------------------------------------
int hahaha_image_view_action::Reset()
{
    Enabled_ = true;
    Visibled_ = true;
    Action_ = true;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------