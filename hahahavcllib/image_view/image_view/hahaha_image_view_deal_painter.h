//---------------------------------------------------------------------------

#ifndef hahaha_image_view_deal_painterH
#define hahaha_image_view_deal_painterH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_image_view_painter;
//---------------------------------------------------------------------------
class hahaha_image_view_deal_painter
{
public:
	hahaha_image_view_deal_painter();
	~hahaha_image_view_deal_painter();

	hahaha_image_view_deal_painter(const hahaha_image_view_deal_painter& hivdp);
    hahaha_image_view_deal_painter(hahaha_image_view_deal_painter&& hivdp) noexcept;
	hahaha_image_view_deal_painter& operator=(const hahaha_image_view_deal_painter& hivdp);
    hahaha_image_view_deal_painter& operator=(hahaha_image_view_deal_painter&& hivdp) noexcept;
	void Copy(const hahaha_image_view_deal_painter& hivdp);
    void Move(hahaha_image_view_deal_painter&& hivdp) noexcept;
public:
	int Reset();

public:
    halib_def::result Add_Painter(hahaha_image_view_painter* painter);
    halib_def::result Delete_Painter(const hahaha_image_view_painter* painter);
    halib_def::result Clear_Painter();
public:
    std::vector<hahaha_image_view_painter*> Painters_;
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
