//---------------------------------------------------------------------------

#ifndef hahaha_image_process_wrap_affineH
#define hahaha_image_process_wrap_affineH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\warp_affine\hahaha_define_image_process_warp_affine.h>
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


class hahaha_image_process_warp_affine
{
public:
//    //---------------------------------------------------------------------------
//    // base
//    //---------------------------------------------------------------------------
//    // 旋轉後目標roi
//    static halib_def::result Rotate_Roi(
//        const halib_image::roi& roi_src,
//        halib_image::roi& roi_dst,
//        const double& angle
//    );
//
//
//	//---------------------------------------------------------------------------
//    // gray
//    //---------------------------------------------------------------------------
//    static halib_def::result Rotate(const halib_image::image_gray& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_gray& dst,
//        const halib_image::roi& roi_dst,
//    	const double& angle,
//        const halib_def_image::rotate& method
//
//    );
//
//    //---------------------------------------------------------------------------
//    // color
//    //---------------------------------------------------------------------------
//    static halib_def::result Rotate(const halib_image::image_rgb& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_rgb& dst,
//        const halib_image::roi& roi_dst,
//    	const double& angle,
//        const halib_def_image::rotate& method
//
//    );
//
//
//    //---------------------------------------------------------------------------
//    // gray
//    //---------------------------------------------------------------------------
//    static halib_def::result Rotate_Nearest(const halib_image::image_gray& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_gray& dst,
//        const halib_image::roi& roi_dst,
//        const double& angle
//    );
//
//    static halib_def::result Rotate_Linear(const halib_image::image_gray& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_gray& dst,
//        const halib_image::roi& roi_dst,
//        const double& angle
//    );
//
//    //---------------------------------------------------------------------------
//    // color
//    //---------------------------------------------------------------------------
//    static halib_def::result Rotate_Nearest(const halib_image::image_rgb& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_rgb& dst,
//        const halib_image::roi& roi_dst,
//    	const double& angle
//    );
//
//    static halib_def::result Rotate_Linear(const halib_image::image_rgb& src,
//        const halib_image::roi& roi_src,
//        halib_image::image_rgb& dst,
//        const halib_image::roi& roi_dst,
//    	const double& angle
//    );



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

typedef hahahalib::image_process::warp_affine::hahaha_image_process_warp_affine warp_affine;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------


#endif
