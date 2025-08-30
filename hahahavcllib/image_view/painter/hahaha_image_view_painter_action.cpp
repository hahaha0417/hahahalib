//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_image_view_painter_action.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_painter_action::hahaha_image_view_painter_action()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_action::~hahaha_image_view_painter_action()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_painter_action::hahaha_image_view_painter_action(const hahaha_image_view_painter_action& hivpa)
{
    Reset();
	Copy(hivpa);
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_action::hahaha_image_view_painter_action(hahaha_image_view_painter_action&& hivpa) noexcept
{
    Move(std::move(hivpa));

}
//---------------------------------------------------------------------------
hahaha_image_view_painter_action& hahaha_image_view_painter_action::operator=(const hahaha_image_view_painter_action& hivpa)
{
	Copy(hivpa);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_action& hahaha_image_view_painter_action::operator=(hahaha_image_view_painter_action&& hivpa) noexcept
{
	if (this != &hivpa)
    {
        Move(std::move(hivpa));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_painter_action::Copy(const hahaha_image_view_painter_action& hivpa)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view_painter_action::Move(hahaha_image_view_painter_action&& hivpa) noexcept
{
    Enabled_ = hivpa.Enabled_;
    Visibled_ = hivpa.Visibled_;
    Action_ = hivpa.Action_;

    hivpa.Reset();
}
//---------------------------------------------------------------------------
int hahaha_image_view_painter_action::Reset()
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