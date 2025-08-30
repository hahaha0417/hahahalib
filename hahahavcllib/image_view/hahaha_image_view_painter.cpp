//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "hahaha_image_view_painter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_painter::hahaha_image_view_painter()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_painter::~hahaha_image_view_painter()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_painter::hahaha_image_view_painter(const hahaha_image_view_painter& hivp)
{
    Reset();
	Copy(hivp);
}
//---------------------------------------------------------------------------
hahaha_image_view_painter::hahaha_image_view_painter(hahaha_image_view_painter&& hivp) noexcept
{
    Move(std::move(hivp));

}
//---------------------------------------------------------------------------
hahaha_image_view_painter& hahaha_image_view_painter::operator=(const hahaha_image_view_painter& hivp)
{
	Copy(hivp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_painter& hahaha_image_view_painter::operator=(hahaha_image_view_painter&& hivp) noexcept
{
	if (this != &hivp)
    {
        Move(std::move(hivp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_painter::Copy(const hahaha_image_view_painter& hivp)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view_painter::Move(hahaha_image_view_painter&& hivp) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_image_view_painter::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------