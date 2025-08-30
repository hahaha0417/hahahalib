//---------------------------------------------------------------------------

#ifndef hahaha_image_process_rotateH
#define hahaha_image_process_rotateH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\rotate\hahaha_define_image_process_rotate.h>
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
namespace rotate
{
//---------------------------------------------------------------------------

class hahaha_image_process_rotate
{
public:
    //---------------------------------------------------------------------------
    // base
    //---------------------------------------------------------------------------
    // 旋轉後目標roi
    static halib_def::result Rotate_Roi(
        const halib::roi& roi_src,
        halib::roi& roi_dst,
        const double& angle
    );


	//---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst,
    	const double& angle,
        const halib_def_image::rotate& method

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst,
    	const double& angle,
        const halib_def_image::rotate& method

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
    	const double& angle,
        const halib_def_image::rotate& method

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst,
        const double& angle
    );

    static halib_def::result Rotate_Linear(const halib::bitmap_gray& src,
        const halib::roi& roi_src,
        halib::bitmap_gray& dst,
        const halib::roi& roi_dst,
        const double& angle
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst,
    	const double& angle
    );

    static halib_def::result Rotate_Linear(const halib::bitmap_rgb& src,
        const halib::roi& roi_src,
        halib::bitmap_rgb& dst,
        const halib::roi& roi_dst,
    	const double& angle
    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
    	const double& angle
    );

    static halib_def::result Rotate_Linear(const halib::bitmap_argb& src,
        const halib::roi& roi_src,
        halib::bitmap_argb& dst,
        const halib::roi& roi_dst,
    	const double& angle
    );

    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------

public:

};



//---------------------------------------------------------------------------
} // rotate
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

typedef hahahalib::image_process::rotate::hahaha_image_process_rotate rotate;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------

#endif
