//---------------------------------------------------------------------------

#ifndef hahaha_image_view_painterH
#define hahaha_image_view_painterH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
#include <image_view\painter\hahaha_image_view_painter_action.h>
#include <image_view\painter\hahaha_image_view_painter_event.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_image_view_painter :
    public hahahalib::hahaha_image_view_painter_action,
    public hahahalib::hahaha_image_view_painter_event
{
public:
	hahaha_image_view_painter();
	~hahaha_image_view_painter();

	hahaha_image_view_painter(const hahaha_image_view_painter& hivp);
    hahaha_image_view_painter(hahaha_image_view_painter&& hivp) noexcept;
	hahaha_image_view_painter& operator=(const hahaha_image_view_painter& hivp);
    hahaha_image_view_painter& operator=(hahaha_image_view_painter&& hivp) noexcept;
	void Copy(const hahaha_image_view_painter& hivp);
    void Move(hahaha_image_view_painter&& hivp) noexcept;
public:
	int Reset();

public:
    //---------------------------------------------------------------------------
    // event
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
public:

public:

public:

public:


};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_image_view_painter image_view_painter;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

#endif
