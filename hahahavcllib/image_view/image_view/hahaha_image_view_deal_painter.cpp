//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <image_view\hahaha_image_view_painter.h>

#include "hahaha_image_view_deal_painter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_deal_painter::hahaha_image_view_deal_painter()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_deal_painter::~hahaha_image_view_deal_painter()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_deal_painter::hahaha_image_view_deal_painter(const hahaha_image_view_deal_painter& hivdp)
{
    Reset();
	Copy(hivdp);
}
//---------------------------------------------------------------------------
hahaha_image_view_deal_painter::hahaha_image_view_deal_painter(hahaha_image_view_deal_painter&& hivdp) noexcept
{
    Move(std::move(hivdp));

}
//---------------------------------------------------------------------------
hahaha_image_view_deal_painter& hahaha_image_view_deal_painter::operator=(const hahaha_image_view_deal_painter& hivdp)
{
	Copy(hivdp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_deal_painter& hahaha_image_view_deal_painter::operator=(hahaha_image_view_deal_painter&& hivdp) noexcept
{
	if (this != &hivdp)
    {
        Move(std::move(hivdp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_deal_painter::Copy(const hahaha_image_view_deal_painter& hivdp)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view_deal_painter::Move(hahaha_image_view_deal_painter&& hivdp) noexcept
{
    Painters_.swap(hivdp.Painters_);

}
//---------------------------------------------------------------------------
int hahaha_image_view_deal_painter::Reset()
{
    // std::vector<hahaha_image_view_painter*>().swap(Painters_);

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_view_deal_painter::Add_Painter(hahaha_image_view_painter* painter)
{
    Painters_.emplace_back(painter);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_view_deal_painter::Delete_Painter(const hahaha_image_view_painter* painter)
{
    std::vector<hahaha_image_view_painter*> painters_;

    int n = Painters_.size();
    halib_def::result result_ = halib_def::result::FAILURE;

    for(int i = 0; i < n; i++)
    {
        if(Painters_[i] == painter)
        {
            result_ = halib_def::result::SUCCESS;
            continue;
        }
        painters_.emplace_back(Painters_[i]);
    }
    painters_.swap(Painters_);

    return result_;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_view_deal_painter::Clear_Painter()
{
   std::vector<hahaha_image_view_painter*>().swap(Painters_);

   return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------