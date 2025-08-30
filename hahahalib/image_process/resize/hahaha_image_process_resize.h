//---------------------------------------------------------------------------

#ifndef hahaha_image_process_resizeH
#define hahaha_image_process_resizeH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\resize\hahaha_define_image_process_resize.h>
#include <shape\hahaha_roi.h>
#include <bitmap\hahaha_c_bitmap.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace image_process
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace resize
{
//---------------------------------------------------------------------------

class hahaha_image_process_resize
{
public:
	//---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst,
        const halib_def_image::resize& method

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst,
        const halib_def_image::resize& method

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
        const halib_def_image::resize& method

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Resize_Linear(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Resize_Linear(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

    static halib_def::result Resize_Linear(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );

public:

};



//---------------------------------------------------------------------------
} // resize
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib_image
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

typedef hahahalib::image_process::resize::hahaha_image_process_resize resize;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------

#endif
