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
    static halib_def::result Rotate(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst,
        const halib_def_image::warp_affine_rotate& rotate,
        const halib_def_image::warp_affine_rotate_method& method

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst,
        const halib_def_image::warp_affine_rotate& rotate,
        const halib_def_image::warp_affine_rotate_method& method

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
        const halib_def_image::warp_affine_rotate& rotate,
        const halib_def_image::warp_affine_rotate_method& method

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_180(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_270(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_180(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_270(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_180(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_270(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_180(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_270(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_180(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_270(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_180(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_270(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    // nearest
    //-------------------------
    static halib_def::result Rotate_Nearest_90(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_180(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_270(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Horizontal_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Nearest_Vertical_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    //-------------------------
    // linear
    //-------------------------
    static halib_def::result Rotate_Linear_90(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_180(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_270(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Horizontal_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Linear_Vertical_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );
    //-------------------------
    // cubic
    //-------------------------
    static halib_def::result Rotate_Cubic_90(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_180(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_270(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Horizontal_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Rotate_Cubic_Vertical_Flip(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
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
