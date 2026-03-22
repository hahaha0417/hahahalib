//---------------------------------------------------------------------------

#ifndef hahaha_image_process_colorH
#define hahaha_image_process_colorH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
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
namespace color
{
//---------------------------------------------------------------------------

class hahaha_image_process_color
{
public:
    //---------------------------------------------------------------------------
    static halib_def::result RGB_To_Gray(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result Gray_To_RGB(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result ARGB_To_Gray(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result Gray_To_ARGB(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
    	const unsigned char value_alpha
    );
    //---------------------------------------------------------------------------
    static halib_def::result RGB_To_YUV422(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_yuy2& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result YUV422_To_RGB(const halib::bitmap_yuy2& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result YUY2_To_UYVY(const halib::bitmap_yuy2& src,
        const halib::roi& roi_src,
        halib::bitmap_uyvy& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result UYVY_To_YUY2(const halib::bitmap_uyvy& src,
        const halib::roi& roi_src,
        halib::bitmap_yuy2& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result YUY2_To_YVYU(const halib::bitmap_yuy2& src,
        const halib::roi& roi_src,
        halib::bitmap_yvyu& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result YVYU_To_YUY2(const halib::bitmap_yvyu& src,
        const halib::roi& roi_src,
        halib::bitmap_yuy2& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    static halib_def::result ARGB_To_YUV422(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_yuy2& dst,
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    static halib_def::result YUV422_To_ARGB(const halib::bitmap_yuy2& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst
    );
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

public:

};




//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // color
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

typedef hahahalib::image_process::color::hahaha_image_process_color color;



//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------

#endif
