//---------------------------------------------------------------------------

#ifndef hahaha_image_viewH
#define hahaha_image_viewH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
// event有引用vcl，不要拿掉
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

#include <image_view\image_view\hahaha_image_view_action.h>
#include <image_view\image_view\hahaha_image_view_deal_painter.h>
#include <image_view\image_view\hahaha_image_view_event.h>
//---------------------------------------------------------------------------

#include <define\image_view\hahaha_define_image_view_view_thumbnail_interpolatation.h>
#include <define\image_view\hahaha_define_image_view_view_direction.h>
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_roi.h>
#include <bitmap\hahaha_c_bitmap_alloc.h>
#include <bitmap\hahaha_c_bitmap_ptr.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_mutex;
//---------------------------------------------------------------------------
class hahaha_image_view :
    public hahaha_image_view_action,
    public hahaha_image_view_event,
    public hahaha_image_view_deal_painter
{
public:
	hahaha_image_view();
	~hahaha_image_view();

	hahaha_image_view(const hahaha_image_view& hiv);
    hahaha_image_view(hahaha_image_view&& hiv) noexcept;
	hahaha_image_view& operator=(const hahaha_image_view& hiv);
    hahaha_image_view& operator=(hahaha_image_view&& hiv) noexcept;
	void Copy(const hahaha_image_view& hiv);
    void Move(hahaha_image_view&& hiv) noexcept;
public:
	int Reset();

public:
    //---------------------------------------------------------------------------
    // event
    //---------------------------------------------------------------------------

    

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
public:
    // 座標轉換，屬架構，不做回傳halib::point，繼承再實現
    // 避免搞混，限制double
    virtual int View_To_Image(const halib::point_double& point_view, halib::point_double& point_image) const;
    virtual int Image_To_View(const halib::point_double& point_image, halib::point_double& point_view) const;
public:
    // 畫面重畫
    virtual int Repaint();
    // 更新元件顯示
    virtual int Update_UI();
    // 更新View長寬
	virtual int Update_UI_View();
    // 更新View長寬
    virtual int Update_Image_Roi();
    // 顯示全部影像
	virtual int Set_View_Ratio_Full_Image();
public:

public:

    // 背景顏色
    TColor Background_Color_;
    TCanvas* Canvas_;
public:
    // 設定為public方便讀取操作

    // 要設定東西，請用form_image_view_->Set_Image_View(image_view_);
    TForm* Form_Image_View_;

    // 縮圖內插，請用Set_Image_View_View_Thumbnail_Interpolation操作
	// View_Thumbnail_Interpolation_ = halib_def::image_view_view_thumbnail_interpolation::NONE;
    halib_def::image_view_view_thumbnail_interpolation View_Thumbnail_Interpolation_;
    // 顯示方向
    halib_def::image_view_view_direction View_Direction_;
    // 顯示比例，請用Set_Image_View_View_Ratio操作
    double View_Ratio_;
    // 是否已內插
	bool Is_View_Thumbnail_;
	// 是否要重繪
	bool Is_Repaint_;
    // 是否重繪view_image
	bool Is_Repaint_View_Image_;
    // 更新畫面
    bool Is_Invalidate_View_Image_;
    // 是否已更新Scrollbar Position
    bool Is_Update_Scrollbar_Position_Center_;
    // 影像
    halib::bitmap* Bitmap_;
    // 影像中心
    halib::point_double Image_Center_;
    // 影像顯示Roi
	halib::roi_double Image_View_Roi_;
	// 全畫面
	bool Is_View_Bitmap_Full_;

    bool Is_View_Scroll_;
    //
    bool Is_Update_Ui_;

public:

    // 加速，避免存取控件屬性
    int View_Width_;
    int View_Height_;
public:
    std::unique_ptr<halib::bitmap_alloc_argb> Bitmap_Thumbnail_;
public:

    std::unique_ptr<halib::bitmap_alloc_argb> Background_Color_Buffer_;
	TColor Background_Color_Old_;
    double View_Ratio_Old_;
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
typedef hahahalib::hahaha_image_view image_view;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

#endif
