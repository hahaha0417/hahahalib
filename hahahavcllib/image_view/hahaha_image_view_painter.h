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
	// 建構物件並初始化預設狀態。
	hahaha_image_view_painter();
	// 解構物件並釋放相關資源。
	~hahaha_image_view_painter();

	// 以既有物件內容建構新的物件實例。
	hahaha_image_view_painter(const hahaha_image_view_painter& hivp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_image_view_painter(hahaha_image_view_painter&& hivp) noexcept;
	// 複製指派目前物件內容。
	hahaha_image_view_painter& operator=(const hahaha_image_view_painter& hivp);
    // 移動指派目前物件內容。
    hahaha_image_view_painter& operator=(hahaha_image_view_painter&& hivp) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_image_view_painter& hivp);
    // 接手來源物件的內部資源。
    void Move(hahaha_image_view_painter&& hivp) noexcept;
public:
	// 重設內部狀態。
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