//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippi.h>
#include <ipps.h>
#include <ippcore.h>
#include "hahaha_image_process_rotate.h"
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
namespace rotate
{
//---------------------------------------------------------------------------
// (0, 0) 旋轉
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// base
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Roi(
    const halib::roi& roi_src,
	halib::roi& roi_dst,
    const double &angle
)
{
#if defined(_DEBUG)

#endif
    IppStatus status_ = ippStsNoErr;

    double shift_x_ = 0, shift_y_ = 0;
    double coeffs_[2][3] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};
    double bound_[2][2] = {0};



    status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    roi_dst.X1_ = bound_[0][0];
    roi_dst.Y1_ = bound_[0][1];
    roi_dst.X2_ = bound_[1][0];
    roi_dst.Y2_ = bound_[1][1];

    return halib_def::result::SUCCESS;
}




//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst,
    const double& angle,
    const halib_def_image::rotate& method

)
{
    // 用if else 簡單寫就好

    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst,
    const double& angle,
    const halib_def_image::rotate& method

)
{
    // 用if else 簡單寫就好

	return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// argb
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const double& angle,
    const halib_def_image::rotate& method

)
{
    // 用if else 簡單寫就好

	return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
/*
halib::bitmap_gray image_gray_;
halib::bitmap_rgb image_rgb_;
halib::bitmap_argb image_argb_;

halib::bitmap_gray image_gray_1;

halib::bitmap_gray image_gray_2;

halib::bitmap_gray image_gray_3;

hahahalib::Bitmap_Load(L"E:\\桌面\\ttt\\iTW_gray.bmp", image_gray_);



image_gray_1.Clear();
image_gray_2.Clear();
image_gray_3.Clear();

// 整張
{
    halib::roi dst_roi_;

    halib::rotate::Rotate_Roi(halib::roi(0, 0, bitmap_gray_.Width_ - 1, bitmap_gray_.Height_ - 1),
        dst_roi_,
        45
    );

    bitmap_gray_1.Resize(dst_roi_.Width(), dst_roi_.Height());

    halib::rotate::Rotate_Nearest(image_gray_,
        halib::roi(0, 0, bitmap_gray_.Width_ - 1, bitmap_gray_.Height_ - 1),
        image_gray_1,
        halib::roi(0, 0, bitmap_gray_1.Width_ - 1, bitmap_gray_1.Height_ - 1),
        45
    );

    hahahalib::Bitmap_Save(L"E:\\桌面\\ttt\\iTW_rotate_gray_1.bmp", image_gray_1, halib_def::bitmap_direction::REVERSE);
}

// 局部
{
    halib::roi dst_roi_;

    halib::rotate::Rotate_Roi(halib::roi(100, 100, 300, 300),
        dst_roi_,
        45
    );

    bitmap_gray_2.Resize(dst_roi_.Width(), dst_roi_.Height());

    halib::rotate::Rotate_Nearest(bitmap_gray_,
        halib::roi(100, 100, 300, 300),
        bitmap_gray_2,
        halib::roi(0, 0, image_gray_2.Width_ - 1, image_gray_2.Height_ - 1),
        45
    );

    hahahalib::Bitmap_Save(L"E:\\桌面\\ttt\\iTW_rotate_gray_2.bmp", image_gray_2, halib_def::bitmap_direction::REVERSE);
}

// roi
{
    halib::roi dst_roi_;

    halib::rotate::Rotate_Roi(halib::roi(100, 100, 300, 300),
        dst_roi_,
        45
    );

    bitmap_gray_3.Resize(dst_roi_.Width() + 100, dst_roi_.Height() + 100);

    halib::rotate::Rotate_Nearest(image_gray_,
        halib::roi(100, 100, 300, 300),
        bitmap_gray_3,
        halib::roi(50, 50, 250, 250),
        45
    );

    hahahalib::Bitmap_Save(L"E:\\桌面\\ttt\\iTW_rotate_gray_3.bmp", image_gray_3, halib_def::bitmap_direction::REVERSE);
}
*/
halib_def::result hahaha_image_process_rotate::Rotate_Nearest(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
	const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[1] = {0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippNearest,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineNearestInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);


    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Linear(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[1] = {0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippLinear,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineLinearInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineLinear_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);




    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Nearest(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[3] = {0.0, 0.0, 0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippNearest,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineNearestInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);


    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Linear(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[3] = {0.0, 0.0, 0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippLinear,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineLinearInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineLinear_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
// argb
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Nearest(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[4] = {0.0, 0.0, 0.0, 0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippNearest,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineNearestInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);


    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_rotate::Rotate_Linear(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const double& angle
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
#endif
    // https://www.intel.com/content/www/us/en/docs/ipp/tutorial-image-blurring-rotation/2020/rotating-an-image-using-intel-ipp-warp-functions.html

    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0;
    Ipp8u* buffer_ = NULL;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[4] = {0.0, 0.0, 0.0, 0.0};
    IppiWarpSpec* spec_ = NULL;
    IppStatus status_ = ippStsNoErr;



    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };

    double shift_x_ = 0, shift_y_ = 0;


	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    double coeffs_[2][3] = {0};
    double bound_[2][2] = {0};
    IppiRect roi_src_use_ = {roi_src.X1_, roi_src.Y1_, roi_src.Width(), roi_src.Height()};

    // 只對(0, 0)旋轉
	status_ = ippiGetRotateTransform(angle, 0, 0, coeffs_);

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    // 計算偏移量
    status_ = ippiGetAffineBound(roi_src_use_,
    	bound_,
		coeffs_
    );

    // 修正位移
    coeffs_[0][2] = -bound_[0][0];
    coeffs_[1][2] = -bound_[0][1];

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }


    /* Spec and init buffer sizes */
    status_ = ippiWarpAffineGetSize(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        ippLinear,
        direction_,
        border_type_,
        &spec_size_,
        &init_size_
    );

    if (status_ != ippStsNoErr)
    {

        // return status;
        return halib_def::result::FAILURE;
    }

    /* Allocate memory */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);

    if (spec_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Affine transform data initialization */
    status_ = ippiWarpAffineLinearInit(roi_size_src_,
    	roi_size_dst_,
        ipp8u,
        coeffs_,
        direction_,
        number_channels_,
        border_type_,
        border_value_,
        0,
        spec_
    );

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    /* Get work buffer size */
    status_ = ippiWarpGetBufferSize(spec_, roi_size_dst_, &buf_size_);

    buffer_ = ippsMalloc_8u(buf_size_);

    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        ippsFree(buffer_);
        // return status;
        return halib_def::result::FAILURE;
    }


    /* Affine transform processing */
    status_ = ippiWarpAffineLinear_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    /* Free memory */
    ippsFree(spec_);
    ippsFree(buffer_);


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // rotate
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------