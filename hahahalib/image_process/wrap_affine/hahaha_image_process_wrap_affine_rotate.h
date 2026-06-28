//---------------------------------------------------------------------------

#ifndef hahaha_image_process_wrap_affine_rotateH
#define hahaha_image_process_wrap_affine_rotateH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\warp_affine\hahaha_define_image_process_warp_affine_rotate.h>
#include <shape\hahaha_roi.h>
#include <bitmap\hahaha_c_bitmap.h>
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace image_process
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace warp_affine
{
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------

// roi to roi，可以順便縮小，所以有Nearest，Linear，Cubic
class hahaha_image_process_warp_affine_rotate
{
public:
    //---------------------------------------------------------------------------
    // base
    //---------------------------------------------------------------------------



	//---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::warp_affine_rotate& rotate,  // 描述仿射旋轉參數的設定物件。
        const halib_def_image::warp_affine_rotate_method& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::warp_affine_rotate& rotate,  // 描述仿射旋轉參數的設定物件。
        const halib_def_image::warp_affine_rotate_method& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::warp_affine_rotate& rotate,  // 描述仿射旋轉參數的設定物件。
        const halib_def_image::warp_affine_rotate_method& method  // 指定要使用的插值或處理方法。

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 180 度。
    static halib_def::result Rotate_Nearest_180(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 270 度。
    static halib_def::result Rotate_Nearest_270(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做水平翻轉。
    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做垂直翻轉。
    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Linear_180(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Linear_270(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做水平翻轉。
    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做垂直翻轉。
    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Cubic_180(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Cubic_270(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做水平翻轉。
    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做垂直翻轉。
    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 180 度。
    static halib_def::result Rotate_Nearest_180(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 270 度。
    static halib_def::result Rotate_Nearest_270(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做水平翻轉。
    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做垂直翻轉。
    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Linear_180(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Linear_270(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做水平翻轉。
    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做垂直翻轉。
    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Cubic_180(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Cubic_270(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做水平翻轉。
    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做垂直翻轉。
    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 180 度。
    static halib_def::result Rotate_Nearest_180(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式將影像旋轉 270 度。
    static halib_def::result Rotate_Nearest_270(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做水平翻轉。
    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以最近鄰方式做垂直翻轉。
    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Linear_180(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Linear_270(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做水平翻轉。
    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以線性插值方式做垂直翻轉。
    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 180 度。
    static halib_def::result Rotate_Cubic_180(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式將影像旋轉 270 度。
    static halib_def::result Rotate_Cubic_270(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做水平翻轉。
    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 以三次插值方式做垂直翻轉。
    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------


public:

};

//---------------------------------------------------------------------------
} // warp_affine
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib_image
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

typedef hahahalib::image_process::warp_affine::hahaha_image_process_warp_affine_rotate warp_affine_rotate;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------


#endif
