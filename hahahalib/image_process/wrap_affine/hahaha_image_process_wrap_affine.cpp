//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippi.h>
#include <ipps.h>
#include <ippcore.h>
#include "hahaha_image_process_wrap_affine.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

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

//---------------------------------------------------------------------------


////---------------------------------------------------------------------------
//// base
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate_Roi(
//    const halib_image::roi& roi_src,
//	halib_image::roi& roi_dst,
//    const double &angle
//)
//{
//#if defined(_DEBUG)
//
//#endif
//    IppStatus status_ = ippStsNoErr;
//
//    double shift_x_ = 0, shift_y_ = 0;
//    double coeffs_[2][3] = {0};
//    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};
//    double bound_[2][2] = {0};
//
//
//
//    status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);
//
//    if (status_ != ippStsNoErr)
//    {
//
//        // return status;
//        return halib_def::result::FAILURE;
//    }
//
//    status_ = ippiGetAffineBound(roi_src_use_,
//    	bound_,
//		coeffs_
//    );
//
//    roi_dst.X1_ = bound_[0][0];
//    roi_dst.Y1_ = bound_[0][1];
//    roi_dst.X2_ = bound_[1][0];
//    roi_dst.Y2_ = bound_[1][1];
//
//    return halib_def::result::SUCCESS;
//}
//
//
//
//
////---------------------------------------------------------------------------
//// gray
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate(const halib_image::image_gray& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_gray& dst,
//    const halib_image::roi& roi_dst,
//    const double& angle,
//    const halib_def_image::rotate& method
//
//)
//{
//    // 用if else 簡單寫就好
//
//    return halib_def::result::SUCCESS;
//}
//
////---------------------------------------------------------------------------
//// color
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate(const halib_image::image_rgb& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_rgb& dst,
//    const halib_image::roi& roi_dst,
//    const double& angle,
//    const halib_def_image::rotate& method
//
//)
//{
//    // 用if else 簡單寫就好
//
//	return halib_def::result::SUCCESS;
//}
//
////---------------------------------------------------------------------------
//// gray
////---------------------------------------------------------------------------
///*
//
//*/
//halib_def::result hahaha_image_process_warp_affine::Rotate_Nearest(const halib_image::image_gray& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_gray& dst,
//	const halib_image::roi& roi_dst,
//    const double& angle
//)
//{
//#if defined(_DEBUG)
//    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
//        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
//    );
//    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
//        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
//    );
//#endif
//
//
//    return halib_def::result::SUCCESS;
//}
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate_Linear(const halib_image::image_gray& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_gray& dst,
//    const halib_image::roi& roi_dst,
//    const double& angle
//)
//{
//#if defined(_DEBUG)
//    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
//        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
//    );
//    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
//        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
//    );
//#endif
//
//    return halib_def::result::SUCCESS;
//}
//
////---------------------------------------------------------------------------
//// color
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate_Nearest(const halib_image::image_rgb& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_rgb& dst,
//    const halib_image::roi& roi_dst,
//    const double& angle
//)
//{
//#if defined(_DEBUG)
//    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
//        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
//    );
//    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
//        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
//    );
//#endif
//
//
//
//    return halib_def::result::SUCCESS;
//}
////---------------------------------------------------------------------------
//halib_def::result hahaha_image_process_warp_affine::Rotate_Linear(const halib_image::image_rgb& src,
//    const halib_image::roi& roi_src,
//    halib_image::image_rgb& dst,
//    const halib_image::roi& roi_dst,
//    const double& angle
//)
//{
//#if defined(_DEBUG)
//    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
//        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
//    );
//    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
//        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
//    );
//#endif
//
//
//
//	return halib_def::result::SUCCESS;
//}
////---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------


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
