//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <cmath>
//---------------------------------------------------------------------------
#include <ippcc.h>
#include <ippi.h>
//---------------------------------------------------------------------------
#include <image_process\set\hahaha_image_process_set.h>
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <image_process\color\hahaha_image_process_color.h>
#include <image_process\resize\hahaha_image_process_resize.h>
//---------------------------------------------------------------------------
#include "hahaha_image_view.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//ha::Form_Image_View_->Set_Image_View(ha::Image_View_.get());
//
//ha::Image_View_->View_Thumbnail_Interpolation_ = halib_def::image_view_view_thumbnail_interpolation::NEAREST;
//ha::Image_View_->View_Direction_ = halib_def::image_view_view_direction::NORMAL;
//ha::Image_View_->View_Ratio_ = 1.0;
//ha::Image_View_->Is_View_Scroll_ = true;
//
//ha::Image_View_->Add_Painter(ha::Painter_Roi_.get());
//ha::Image_View_->Add_Painter(ha::Painter_Information_.get());
//ha::Image_View_->Add_Painter(ha::Painter_Png_.get());
////---------------------------------------------------------------------------
//ha::Form_Image_View_->Show();
//
//f_lib::jpeg::Load(L"C:\\Users\\hahaha\\Desktop\\ttt\\4K_hor.jpg", *bitmap_rgb_image_view_);
//
//bitmap_argb_image_view_->Resize(bitmap_rgb_image_view_->Width_, bitmap_rgb_image_view_->Height_);
//
//halib_image::copy::Copy(
//    *bitmap_rgb_image_view_,
//    halib::roi(0, 0, bitmap_rgb_image_view_->Width_ - 1, bitmap_rgb_image_view_->Height_ - 1),
//    *bitmap_argb_image_view_,
//    halib::roi(0, 0, bitmap_argb_image_view_->Width_ - 1, bitmap_argb_image_view_->Height_ - 1)
//);
//
////	f_lib::bmp::Load(L"C:\\Users\\hahaha\\Desktop\\ttt\\4K_hor_gray.jpg", *bitmap_gray_image_view_);
////	ha::Image_View_->View_Direction_ = halib_def::image_view_view_direction::ROTATE_270;
//ha::Image_View_->Bitmap_ = bitmap_argb_image_view_.get();
//ha::Image_View_->Is_View_Thumbnail_ = false;
//ha::Image_View_->Image_Center_ = halib::point_double((double)(bitmap_argb_image_view_->Width_ - 1 ) / 2,
//    (double)(bitmap_argb_image_view_->Height_ - 1 ) / 2
//);
//
//ha::Image_View_->Background_Color_ = TColor(RGB(60, 60, 60));
//
//ha::Image_View_->Is_View_Bitmap_Full_ = true;
//
//ha::Image_View_->Repaint();
//
//int rrr = 0;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view::hahaha_image_view()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view::~hahaha_image_view()
{

}
//---------------------------------------------------------------------------
hahaha_image_view::hahaha_image_view(const hahaha_image_view& hiv)
{
    Reset();
	Copy(hiv);
}
//---------------------------------------------------------------------------
hahaha_image_view::hahaha_image_view(hahaha_image_view&& hiv) noexcept
{
    hahaha_image_view_action::Move(std::move(hiv));
    hahaha_image_view_event::Move(std::move(hiv));
    hahaha_image_view_deal_painter::Move(std::move(hiv));
    Move(std::move(hiv));
}
//---------------------------------------------------------------------------
hahaha_image_view& hahaha_image_view::operator=(const hahaha_image_view& hiv)
{
	Copy(hiv);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view& hahaha_image_view::operator=(hahaha_image_view&& hiv) noexcept
{
    if (this != &hiv)
    {
        hahaha_image_view_action::Move(std::move(hiv));
        hahaha_image_view_event::Move(std::move(hiv));
        hahaha_image_view_deal_painter::Move(std::move(hiv));
        Move(std::move(hiv));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view::Copy(const hahaha_image_view& hiv)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view::Move(hahaha_image_view&& hiv) noexcept
{
    hahaha_image_view_event::Image_View_ = this;


    View_Thumbnail_Interpolation_ = hiv.View_Thumbnail_Interpolation_;
    View_Direction_ = hiv.View_Direction_;
    View_Ratio_ = hiv.View_Ratio_;
    Is_View_Thumbnail_ = hiv.Is_View_Thumbnail_;
    Is_Update_Scrollbar_Position_Center_ = hiv.Is_Update_Scrollbar_Position_Center_;
    //
    View_Width_ = hiv.View_Width_;
    View_Height_ = hiv.View_Height_;
    //
    Bitmap_ = hiv.Bitmap_;
    //
    Canvas_ = hiv.Canvas_;
    //
    Background_Color_ = hiv.Background_Color_;
    //
    Image_Center_ = hiv.Image_Center_;
    //
    Image_View_Roi_ = hiv.Image_View_Roi_;
    //


	Bitmap_Thumbnail_ = std::move(hiv.Bitmap_Thumbnail_);

    //
	Background_Color_Buffer_ = std::move(hiv.Background_Color_Buffer_);

    // 第一次寬會不一樣，可以一樣顏色
	Background_Color_Old_ = hiv.Background_Color_Old_;
	//
	Is_View_Bitmap_Full_ = hiv.Is_View_Bitmap_Full_;
	Is_View_Scroll_ = hiv.Is_View_Scroll_;
	View_Ratio_Old_ = hiv.View_Ratio_Old_;
	Is_Update_Ui_ = hiv.Is_Update_Ui_;
	Is_Repaint_ = hiv.Is_Repaint_;
    Is_Repaint_View_Image_ = hiv.Is_Repaint_View_Image_;
    Is_Invalidate_View_Image_ = hiv.Is_Invalidate_View_Image_;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Reset()
{
    hahaha_image_view_event::Image_View_ = this;


    View_Thumbnail_Interpolation_ = halib_def::image_view_view_thumbnail_interpolation::NONE;
    View_Direction_ = halib_def::image_view_view_direction::NONE;
    View_Ratio_ = 1.0;
    Is_View_Thumbnail_ = false;
    Is_Update_Scrollbar_Position_Center_ = false;
    //
    View_Width_ = 0;
    View_Height_ = 0;
    //
    Bitmap_ = NULL;
    //
    Canvas_ = NULL;
    //
    Background_Color_ = TColor(RGB(0, 0, 0));
    //
    Image_Center_ = halib::point_double(0, 0);
    //
    Image_View_Roi_ = halib::roi_double(-1, -1, -1, -1);
    //


	if(Bitmap_Thumbnail_.get() == NULL)
    {
        Bitmap_Thumbnail_.reset(new halib::bitmap_alloc_argb);
    }
    Bitmap_Thumbnail_->Resize(10, 10);
    Bitmap_Thumbnail_->Clear();
    //
	if(Background_Color_Buffer_.get() == NULL)
    {
		Background_Color_Buffer_.reset(new halib::bitmap_alloc_argb);
    }
    Background_Color_Buffer_->Resize(10, 10);
    Background_Color_Buffer_->Clear();
    // 第一次寬會不一樣，可以一樣顏色
	Background_Color_Old_ = TColor(RGB(0, 0, 0));
	//
	Is_View_Bitmap_Full_ = false;
	Is_View_Scroll_ = false;
	View_Ratio_Old_ = 999999;
	Is_Update_Ui_ = false;
	Is_Repaint_ = false;
    Is_Repaint_View_Image_ = false;
    Is_Invalidate_View_Image_ = false;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_image_view::Repaint()
{
	Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)Form_Image_View_;

    if(form_ == NULL)
    {
        return 0;
    }

    if(Bitmap_ == NULL)
    {
        return 0;
	}

    if(!Enabled_)
    {
        return 0;
	}

    if(Is_View_Bitmap_Full_)
	{
		Set_View_Ratio_Full_Image();
	}
	else
	{
        Update_UI();
	}

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Painters_[i]->Enabled_)
                {
                    continue;
                }

				if(!Painters_[i]->Visibled_)
				{
                    continue;
                }

                halib_def::image_view_result result_ = Painters_[i]->On_Paint_Begin(*Image_View_);

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return 0;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
	// 更新背景
	//---------------------------------------------------------------------------
//	// 因為paintbox & panel移除了，這裡統一用TImage的bitmap處理
//	// 經實測，這會造成其他地方閃爍，不要用
//	Canvas_->Brush->Style = bsSolid;
//	Canvas_->Pen->Style = psSolid;
//	Canvas_->Pen->Width = 1;
//
//	Canvas_->Brush->Color = Background_Color_;
//	Canvas_->Pen->Color = Background_Color_;
//
//	Canvas_->Rectangle(0, 0, View_Width_ - 1, View_Height_ - 1);
	//---------------------------------

    if(View_Width_ != Background_Color_Buffer_->Width_ ||
        Background_Color_ != Background_Color_Old_
    )
    {
        unsigned char r_ = GetRValue(Background_Color_);
		unsigned char g_ = GetGValue(Background_Color_);
        unsigned char b_ = GetBValue(Background_Color_);

        Background_Color_Buffer_->Resize(View_Width_, 1);

        for(int i = 0; i < View_Width_; i++)
        {
            unsigned char* ptr_src_ = (*Background_Color_Buffer_)[0];
            int step_ = i * 4;

            ptr_src_[step_] = b_;
            ptr_src_[step_ + 1] = g_;
            ptr_src_[step_ + 2] = r_;
            ptr_src_[step_ + 3] = 1;
        }

        Background_Color_Old_ = Background_Color_;
    }


	//---------------------------------
	if(Is_Repaint_)
	{
        // 不能用ipp，因為TBitmap是反的scanline
        int w_ = form_->view_image->Picture->Bitmap->Width;
        int h_ = form_->view_image->Picture->Bitmap->Height;

		if(h_ > 0)
		{

            for(int j = 0; j < form_->view_image->Picture->Bitmap->Height; j++)
            {
                unsigned char* ptr_src_ = (*Background_Color_Buffer_)[0];
                unsigned char* ptr_dst_ = (unsigned char*)form_->view_image->Picture->Bitmap->ScanLine[h_ - j - 1];

                memcpy(ptr_dst_, ptr_src_, Background_Color_Buffer_->Stride_);
            }


		}




    }

    //---------------------------------------------------------------------------
	//---------------------------------------------------------------------------
    // 先更新
	Update_Image_Roi();

    halib::point_double point_image_left_top_ = halib::point_double(Image_View_Roi_.X1_,
        Image_View_Roi_.Y1_
    );
	halib::point_double point_image_right_bottom_ = halib::point_double(Image_View_Roi_.X2_ - 1,
        Image_View_Roi_.Y2_ - 1
    );

	// 要取Image_View_Roi_回算的位置
	halib::point_double point_view_left_top_;
	halib::point_double point_view_right_bottom_;

    Image_To_View(point_image_left_top_,
        point_view_left_top_
    );
    Image_To_View(point_image_right_bottom_,
        point_view_right_bottom_
    );




	// 會有誤差問題，採truncate
	halib::roi view_roi_ = halib::roi(point_view_left_top_.X_,
		point_view_left_top_.Y_,
		point_view_right_bottom_.X_,
		point_view_right_bottom_.Y_
	);

	//---------------------------------------------------------------------------
	if(point_view_left_top_.X_ <= point_view_right_bottom_.X_)
    {
		view_roi_.X1_ = point_view_left_top_.X_;
		view_roi_.X2_ = point_view_right_bottom_.X_;
    }
    else
    {
		view_roi_.X1_ = point_view_right_bottom_.X_;
		view_roi_.X2_ = point_view_left_top_.X_;
    }

	if(point_view_left_top_.Y_ <= point_view_right_bottom_.Y_)
    {
		view_roi_.Y1_ = point_view_left_top_.Y_;
		view_roi_.Y2_ = point_view_right_bottom_.Y_;
    }
    else
    {
		view_roi_.Y1_ = point_view_right_bottom_.Y_;
		view_roi_.Y2_ = point_view_left_top_.Y_;
    }

    if(view_roi_.X1_ < 0)
    {
        view_roi_.X1_ = 0;
    }

    if(view_roi_.Y1_ < 0)
    {
        view_roi_.Y1_ = 0;
    }

    if(view_roi_.X2_ > (View_Width_ - 1))
    {
        view_roi_.X2_ = View_Width_ - 1;
    }

    if(view_roi_.Y2_ > (View_Height_ - 1))
    {
        view_roi_.Y2_ = View_Height_ - 1;
    }



    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // 縮圖
    //---------------------------------------------------------------------------
    {
        int w_ = form_->view_image->Picture->Bitmap->Width;
        int h_ = form_->view_image->Picture->Bitmap->Height;

		if(h_ > 0)
		{
            //---------------------------------------------------------------------------
            if(!Is_View_Thumbnail_)
            {
                if(Bitmap_->Bits_ == 8)
                {
                    std::unique_ptr<halib::bitmap_alloc_gray> bitmap_gray_;
                    if(bitmap_gray_.get() == NULL)
                    {
                        bitmap_gray_.reset(new halib::bitmap_alloc_gray);
                    }

                    // 由於定義不一樣，這裡直接寫，只有nearest，linear，cubic
                    if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            // 擷取區塊
                            halib_image::resize::Resize_Nearest(
                                *(halib::bitmap_gray*)Bitmap_,
								halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            // 擷取區塊
                            halib_image::resize::Resize_Linear(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            // 擷取區塊
//                            halib_image::resize::Resize_Nearest(
//                                *(halib::bitmap_gray*)Bitmap_,
//                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
//                                *bitmap_gray_,
//                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
//                            );
                        }


                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_90(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
								halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_90(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
							);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_90(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_180(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_180(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_180(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_270(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_270(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_270(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Horizontal_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
                    {
                        if(bitmap_gray_->Width_ != view_roi_.Width() ||
                            bitmap_gray_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_gray_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Vertical_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Vertical_Flip(
                                *(halib::bitmap_gray*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_gray_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
					}

					Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());

                    // 畫到縮圖上
                    halib_image::color::Gray_To_ARGB(*bitmap_gray_,
                        halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1),
						*Bitmap_Thumbnail_,
                        halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1),
                        255
                    );

                }
                else if(Bitmap_->Bits_ == 24)
                {
                    std::unique_ptr<halib::bitmap_alloc_rgb> bitmap_rgb_;
                    if(bitmap_rgb_.get() == NULL)
                    {
                        bitmap_rgb_.reset(new halib::bitmap_alloc_rgb);
                    }

                    // 由於定義不一樣，這裡直接寫，只有nearest，linear，cubic
                    if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            // 擷取區塊
                            halib_image::resize::Resize_Nearest(
                                *(halib::bitmap_rgb*)Bitmap_,
								halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            // 擷取區塊
                            halib_image::resize::Resize_Linear(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            // 擷取區塊
//                            halib_image::resize::Resize_Nearest(
//                                *(halib::bitmap_rgb*)Bitmap_,
//                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
//                                *bitmap_rgb_,
//                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
//                            );
                        }


                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_90(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
								halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_90(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
							);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_90(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_180(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_180(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_180(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_270(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_270(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_270(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Horizontal_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
                    {
                        if(bitmap_rgb_->Width_ != view_roi_.Width() ||
                            bitmap_rgb_->Height_ != view_roi_.Height()
                        )
                        {
                            bitmap_rgb_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Vertical_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Vertical_Flip(
                                *(halib::bitmap_rgb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *bitmap_rgb_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
					}

					Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());

                    // 畫到縮圖上
                    halib_image::copy::Copy(*bitmap_rgb_,
                        halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1),
						*Bitmap_Thumbnail_,
                        halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                    );

                }
                else if(Bitmap_->Bits_ == 32)
                {
					if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
                    {
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
                            Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::resize::Resize_Nearest(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::resize::Resize_Linear(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                            );
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
//                            halib_image::resize::Resize_Nearest(
//                                *(halib::bitmap_argb*)Bitmap_,
//                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
//                                *Bitmap_Thumbnail_,
//                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
//                            );
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
                    {
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
                            Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_90(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_90(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_90(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
                    {
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
                            Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_180(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_180(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_180(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
					{
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
                            Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_270(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
								halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_270(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_270(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
					{
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
                            Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
                        }

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Horizontal_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
                    {
                        if(Bitmap_Thumbnail_->Width_ != view_roi_.Width() ||
                            Bitmap_Thumbnail_->Height_ != view_roi_.Height()
                        )
                        {
							Bitmap_Thumbnail_->Resize(view_roi_.Width(), view_roi_.Height());
						}

                        if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::NEAREST)
                        {
                            halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::LINEAR)
                        {
                            halib_image::warp_affine_rotate::Rotate_Linear_Vertical_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                        else if(View_Thumbnail_Interpolation_ == halib_def::image_view_view_thumbnail_interpolation::CUBIC)
                        {
                            halib_image::warp_affine_rotate::Rotate_Cubic_Vertical_Flip(
                                *(halib::bitmap_argb*)Bitmap_,
                                halib::roi(Image_View_Roi_.X1_, Image_View_Roi_.Y1_, Image_View_Roi_.X2_, Image_View_Roi_.Y2_),
                                *Bitmap_Thumbnail_,
                                halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1)
                        	);
                        }
                    }
                }
                //---------------------------------------------------------------------------





                //---------------------------------------------------------------------------
                Is_View_Thumbnail_ = true;
                //---------------------------------------------------------------------------
            }




            //---------------------------------------------------------------------------

            //---------------------------------------------------------------------------
            //Image_View_Roi_

            //---------------------------------------------------------------------------

            //---------------------------------------------------------------------------
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 影像

    //---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
	if(Is_Repaint_)
	{
        //---------------------------------------------------------------------------
		{
			int w_ = form_->view_image->Picture->Bitmap->Width;
			int h_ = form_->view_image->Picture->Bitmap->Height;

			if(h_ > 0)
			{

				halib::bitmap_ptr_argb temp_((unsigned char*)form_->view_image->Picture->Bitmap->ScanLine[0]);

				temp_.Resize(w_, h_);


				halib_image::copy::Copy(
					*Bitmap_Thumbnail_,
					halib::roi(0, 0, view_roi_.Width() - 1, view_roi_.Height() - 1),
					temp_,
					view_roi_
				);

				//---------------------------------------------------------------------------
				//
				//---------------------------------------------------------------------------

			}
		}

	}

	if(Is_Repaint_View_Image_)
	{
		//---------------------------------------------------------------------------
        // 不能在執行緒跑
		form_->view_image->Repaint();

	}
    if(Is_Invalidate_View_Image_)
	{
		//---------------------------------------------------------------------------
        // 不能在執行緒跑
		form_->view_image->Invalidate();

	}


    // 不能用這個，畫圖跟畫線會分開，導致閃屏
	// PostMessage(form_->Handle, MESSAGE_IMAGE_VIEW_VIEW_IMAGE_REPAINT, 0, 0);
    //---------------------------------------------------------------------------


    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Painters_[i]->Enabled_)
                {
                    continue;
                }

				if(!Painters_[i]->Visibled_)
				{
                    continue;
				}

                halib_def::image_view_result result_ = Painters_[i]->On_Paint_Design(*Image_View_);

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return 0;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Painters_[i]->Enabled_)
                {
                    continue;
                }

				if(!Painters_[i]->Visibled_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Painters_[i]->On_Paint_End(*Image_View_);

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return 0;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    Is_Repaint_ = false;
    Is_Repaint_View_Image_ = false;
    Is_Invalidate_View_Image_ = false;

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Update_Image_Roi()
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)Form_Image_View_;

	if(form_ == NULL)
	{
		return 0;
	}

	if(Bitmap_ == NULL)
	{
		return 0;
	}

    int bitmap_width_ = Bitmap_->Width_;
    int bitmap_height_ = Bitmap_->Height_;

	{
        // 因為有放大16倍的關係，故意多取，讓他truncate
        // 是影像對應畫面，不是畫面對應影像
		halib::point_double point_view_left_top_ = halib::point_double(0 - 16,
			0 - 16
		);


		halib::point_double point_view_right_bottom_ = halib::point_double(View_Width_ - 1 + 16,
			View_Height_ - 1 + 16
		);


		halib::point_double point_image_left_top_;
		halib::point_double point_image_right_bottom_;

		View_To_Image(point_view_left_top_,
			point_image_left_top_
		);
		View_To_Image(point_view_right_bottom_,
			point_image_right_bottom_
		);


		//---------------------------------------------------------------------------
		if(point_image_left_top_.X_ <= point_image_right_bottom_.X_)
		{
			Image_View_Roi_.X1_ = point_image_left_top_.X_;
			Image_View_Roi_.X2_ = point_image_right_bottom_.X_;
		}
		else
		{
			Image_View_Roi_.X1_ = point_image_right_bottom_.X_;
			Image_View_Roi_.X2_ = point_image_left_top_.X_;
		}

		if(point_image_left_top_.Y_ <= point_image_right_bottom_.Y_)
		{
			Image_View_Roi_.Y1_ = point_image_left_top_.Y_;
			Image_View_Roi_.Y2_ = point_image_right_bottom_.Y_;
		}
		else
		{
			Image_View_Roi_.Y1_ = point_image_right_bottom_.Y_;
			Image_View_Roi_.Y2_ = point_image_left_top_.Y_;
		}

		if(Image_View_Roi_.X1_ < 0)
		{
			Image_View_Roi_.X1_ = 0;
		}

		if(Image_View_Roi_.Y1_ < 0)
		{
			Image_View_Roi_.Y1_ = 0;
		}

		if(Image_View_Roi_.X2_ > (Bitmap_->Width_ - 1))
		{
			Image_View_Roi_.X2_ = Bitmap_->Width_ - 1;
		}

		if(Image_View_Roi_.Y2_ > (Bitmap_->Height_ - 1))
		{
			Image_View_Roi_.Y2_ = Bitmap_->Height_ - 1;
		}
	}

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Update_UI()
{
    Is_Update_Ui_ = true;

	Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)Form_Image_View_;

	if(form_ == NULL)
	{
		return 0;
	}

	if(Bitmap_ == NULL)
	{
		return 0;
	}

    Update_UI_View();



	int bitmap_width_ = Bitmap_->Width_;
    int bitmap_height_ = Bitmap_->Height_;



	Update_Image_Roi();

    //---------------------------------------------------------------------------

    {
        int w_ = std::round(Image_View_Roi_.Width());
        int h_ = std::round(Image_View_Roi_.Height());

        if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
        {
			// 要算縮圖佔畫面多少
            if(bitmap_width_ > w_)
            {
				if(form_->horizontal_bar->Max != bitmap_width_ - w_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_width_ - w_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_width_ - w_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_width_ - w_ + 1) / 10);
					if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
					}

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

            if(bitmap_height_ > h_)
            {
				if(form_->vertical_bar->Max != bitmap_height_ - h_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_height_ - h_;
					form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_height_ - h_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_height_ - h_ + 1) / 10);
					if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }
        else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
        {
			// 要算縮圖佔畫面多少
			if(bitmap_height_ > h_)
            {
				if(form_->horizontal_bar->Max != bitmap_height_ - h_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_height_ - h_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_height_ - h_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_height_ - h_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

			if(bitmap_width_ > w_)
            {
				if(form_->vertical_bar->Max != bitmap_width_ - w_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_width_ - w_;
					form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_width_ - w_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_width_ - w_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }
        else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
        {
			// 要算縮圖佔畫面多少
            if(bitmap_width_ > w_)
            {
				if(form_->horizontal_bar->Max != bitmap_width_ - w_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_width_ - w_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_width_ - w_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_width_ - w_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
                    }

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

            if(bitmap_height_ > h_)
            {
				if(form_->vertical_bar->Max != bitmap_height_ - h_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_height_ - h_;
					form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_height_ - h_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_height_ - h_ + 1) / 10);
					if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }
        else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
        {
			// 要算縮圖佔畫面多少
			if(bitmap_height_ > h_)
            {
				if(form_->horizontal_bar->Max != bitmap_height_ - h_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_height_ - h_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_height_ - h_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_height_ - h_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

			if(bitmap_width_ > w_)
            {
				if(form_->vertical_bar->Max != bitmap_width_ - w_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_width_ - w_;
					form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_width_ - w_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_width_ - w_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }
        else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
        {
			// 要算縮圖佔畫面多少
            if(bitmap_width_ > w_)
            {
				if(form_->horizontal_bar->Max != bitmap_width_ - w_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_width_ - w_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_width_ - w_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_width_ - w_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
                    }

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

            if(bitmap_height_ > h_)
            {
				if(form_->vertical_bar->Max != bitmap_height_ - h_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_height_ - h_;
					form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_height_ - h_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_height_ - h_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }
        else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
        {
			// 要算縮圖佔畫面多少
            if(bitmap_width_ > w_)
            {
				if(form_->horizontal_bar->Max != bitmap_width_ - w_)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = bitmap_width_ - w_;
					form_->horizontal_bar->LargeChange = std::floor((double)(bitmap_width_ - w_ + 1));
					form_->horizontal_bar->SmallChange = std::floor((double)(bitmap_width_ - w_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = std::floor((double)(bitmap_width_ - w_) / 2);
                    }

                    form_->horizontal_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->horizontal_bar->Max != 2)
                {
                    form_->horizontal_bar->Min = 0;
                    form_->horizontal_bar->Max = 2;
                    form_->horizontal_bar->LargeChange = 1;
                    form_->horizontal_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->horizontal_bar->Position = 1;
                    }

                    form_->horizontal_bar->Enabled = false;
                }

            }

            if(bitmap_height_ > h_)
            {
				if(form_->vertical_bar->Max != bitmap_height_ - h_)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = bitmap_height_ - h_;
                    form_->vertical_bar->LargeChange = std::floor((double)(double)(bitmap_height_ - h_ + 1));
					form_->vertical_bar->SmallChange = std::floor((double)(double)(bitmap_height_ - h_ + 1) / 10);
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = std::floor((double)(bitmap_height_ - h_) / 2);
                    }

                    form_->vertical_bar->Enabled = true;
                }

            }
            else
            {
				if(form_->vertical_bar->Max != 2)
                {
                    form_->vertical_bar->Min = 0;
                    form_->vertical_bar->Max = 2;
                    form_->vertical_bar->LargeChange = 1;
                    form_->vertical_bar->SmallChange = 1;
                    if(!Is_Update_Scrollbar_Position_Center_)
                    {
                        form_->vertical_bar->Position = 1;
                    }

                    form_->vertical_bar->Enabled = false;
                }

			}
        }


    }

    {
		double ratio_ = 0;
		if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}
		else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Height_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Width_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}
		else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}
		else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Height_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Width_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}
		else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}
		else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
		{
			double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
			double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

			// 取小的
			if(w_ratio_ <= h_ratio_)
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = w_ratio_;
			}
			else
			{
				// 必須包含全畫面，取小速點第二位會影響精確度
				ratio_ = h_ratio_;
			}
		}





        // 因為可能0.29999999，讓他進位
		double ratio_level = (double)std::ceil((ratio_ + 0.000001) * 10) / 10;

		if((form_->view_ratio->Text != L"全部" && View_Ratio_ != View_Ratio_Old_) ||
			(form_->view_ratio->Text == L"全部" && View_Ratio_ != View_Ratio_Old_) ||
			form_->view_ratio->Items->Count == 0 ||
			(ratio_level == ratio_ &&form_->view_ratio->Items->Count > 1 && form_->view_ratio->Items->Strings[1] != UnicodeString((int)(ratio_level * 100) + 10) + L"%") ||
			(ratio_level != ratio_ &&form_->view_ratio->Items->Count > 1 && form_->view_ratio->Items->Strings[1] != UnicodeString((int)(ratio_level * 100)) + L"%")
		)
		{
			int index_old_ = form_->view_ratio->ItemIndex;
			if(ratio_level == ratio_)
			{
				form_->view_ratio->Items->BeginUpdate();
				form_->view_ratio->Items->Clear();
				form_->view_ratio->Items->Add(L"全部");
				for(int i = (int)(ratio_level * 100) + 10; i <= 100; i = i + 10)
				{
					form_->view_ratio->Items->Add(UnicodeString(i) + L"%");
				}

				for(int i = 200; i <= 1600; i = i + 100)
				{
					form_->view_ratio->Items->Add(UnicodeString(i) + L"%");
				}

				form_->view_ratio->Items->EndUpdate();
			}
			else
			{
				form_->view_ratio->Items->BeginUpdate();
				form_->view_ratio->Items->Clear();
				form_->view_ratio->Items->Add(L"全部");
				for(int i = (int)(ratio_level * 100); i <= 100; i = i + 10)
				{
					form_->view_ratio->Items->Add(UnicodeString(i) + L"%");
				}

				for(int i = 200; i <= 1600; i = i + 100)
				{
					form_->view_ratio->Items->Add(UnicodeString(i) + L"%");
				}

				form_->view_ratio->Items->EndUpdate();
			}

			if(Is_View_Bitmap_Full_)
			{
				int index_ = form_->view_ratio->Items->IndexOf(L"全部");
				if(index_ == -1)
				{
					form_->view_ratio->ItemIndex = index_old_;
					form_->view_ratioChange(NULL);
				}
				else
				{
					form_->view_ratio->ItemIndex = index_;
				}
			}
			else
			{
				int index_ = form_->view_ratio->Items->IndexOf(UnicodeString((int)(View_Ratio_ * 100)) + L"%");
				if(index_ == -1)
				{
					form_->view_ratio->ItemIndex = index_old_;
					form_->view_ratioChange(NULL);
				}
				else
				{
					form_->view_ratio->ItemIndex = index_;
				}

			}

            View_Ratio_Old_ = View_Ratio_;
		}



    }


    if(!Is_Update_Scrollbar_Position_Center_)
    {
        Is_Update_Scrollbar_Position_Center_ = true;
	}

    Is_Update_Ui_ = false;

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Update_UI_View()
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)Form_Image_View_;

	if(form_ == NULL)
    {
        return 0;
    }

    View_Width_ = form_->view_image->Width;
    View_Height_ = form_->view_image->Height;

    if(form_->view_image->Picture->Bitmap->PixelFormat != pf32bit)
    {
        form_->view_image->Picture->Bitmap->PixelFormat = pf32bit;
    }


    if(form_->view_image->Picture->Bitmap->Width != View_Width_ ||
        form_->view_image->Picture->Bitmap->Height != View_Height_
    )
    {
        //---------------------------------------------------------------------------
        // chatGPT
        // TBitmap 的記憶體存儲方式  自上而下
        //---------------------------------------------------------------------------
        form_->view_image->Picture->Bitmap->SetSize(View_Width_, -View_Height_);


    }




    return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Set_View_Ratio_Full_Image()
{
    Thahaha_image_view_form* form_ = (Thahaha_image_view_form*)Form_Image_View_;

    if(form_ == NULL)
    {
        return 0;
    }

    if(Bitmap_ == NULL)
    {
        return 0;
    }

	Update_UI_View();

	if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
    {
		double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
	}
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
	{
		double w_ratio_ = (double)View_Width_ / Bitmap_->Height_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Width_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
    {
		double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
    {
		double w_ratio_ = (double)View_Width_ / Bitmap_->Height_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Width_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
	}
    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
    {
		double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
	}
    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
    {
		double w_ratio_ = (double)View_Width_ / Bitmap_->Width_;
		double h_ratio_ = (double)View_Height_ / Bitmap_->Height_;

		// 取小的
		if(w_ratio_ <= h_ratio_)
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = w_ratio_;
		}
		else
		{
			// 必須包含全畫面，取小速點第二位會影響精確度
			View_Ratio_ = h_ratio_;
		}
	}



	Update_UI();


	return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::View_To_Image(const halib::point_double& point_view, halib::point_double& point_image) const
{
    if(View_Direction_ == halib_def::image_view_view_direction::NONE)
    {
        return 0;
    }

    halib::point_double point_view_center_ = halib::point_double(
		(double)(View_Width_ - 1) / 2,
		(double)(View_Height_ - 1) / 2
    );

    if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
    {
		point_image.X_ = Image_Center_.X_ + (point_view.X_ - point_view_center_.X_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view.Y_ - point_view_center_.Y_) / View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
    {
		point_image.X_ = Image_Center_.X_ + (point_view_center_.Y_ - point_view.Y_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view.X_ - point_view_center_.X_) / View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
    {
		point_image.X_ = Image_Center_.X_ + (point_view_center_.X_ - point_view.X_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view_center_.Y_ - point_view.Y_) / View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
    {
		point_image.X_ = Image_Center_.X_ + (point_view.Y_ - point_view_center_.Y_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view_center_.X_ - point_view.X_) / View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
    {
		point_image.X_ = Image_Center_.X_ + (point_view_center_.X_ - point_view.X_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view.Y_ - point_view_center_.Y_) / View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
    {
		point_image.X_ = Image_Center_.X_ + (point_view.X_ - point_view_center_.X_) / View_Ratio_;
		point_image.Y_ = Image_Center_.Y_ + (point_view_center_.Y_ - point_view.Y_) / View_Ratio_;
    }

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_image_view::Image_To_View(const halib::point_double& point_image, halib::point_double& point_view) const
{
    if(View_Direction_ == halib_def::image_view_view_direction::NONE)
    {
        return 0;
    }

//	halib::point_double point_image_center_ = halib::point_double(
//		(double)(Bitmap_->Width_ - 1) / 2,
//		(double)(Bitmap_->Height_ - 1) / 2
//	);
	const halib::point_double& point_image_center_ = Image_Center_;

	halib::point_double point_view_center_ = halib::point_double(
		(double)View_Width_ / 2,
		(double)View_Height_ / 2
	);

    if(View_Direction_ == halib_def::image_view_view_direction::NORMAL)
    {
		point_view.X_ = point_view_center_.X_ + (point_image.X_ - point_image_center_.X_) * View_Ratio_;
		point_view.Y_ = point_view_center_.Y_ + (point_image.Y_ - point_image_center_.Y_) * View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
    {
		point_view.X_ = point_view_center_.X_ + (point_image_center_.Y_ - point_image.Y_) * View_Ratio_;
		point_view.Y_ = point_view_center_.Y_ + (point_image.X_ - point_image_center_.X_) * View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
    {
		point_view.X_ = point_view_center_.X_ + (point_image_center_.X_ - point_image.X_) * View_Ratio_;
		point_view.Y_ = point_view_center_.Y_ + (point_image_center_.Y_ - point_image.Y_) * View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
	{
		point_view.X_ = point_view_center_.X_ + (point_image.Y_ - point_image_center_.Y_) * View_Ratio_;
		point_view.Y_ = point_view_center_.Y_ + (point_image_center_.X_ - point_image.X_) * View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
    {
		point_view.X_ = point_view_center_.X_ + (point_image_center_.X_ - point_image.X_) * View_Ratio_;
		point_view.Y_ = point_view_center_.Y_ + (point_image.Y_ - point_image_center_.Y_) * View_Ratio_;
    }
    else if(View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
    {
		point_view.X_ = point_view_center_.X_ + (point_image.X_ - point_image_center_.X_) * View_Ratio_;
        point_view.Y_ = point_view_center_.Y_ + (point_image_center_.Y_ - point_image.Y_) * View_Ratio_;
    }

    return 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------