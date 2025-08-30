//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippi.h>
#include <ipps.h>
#include <ippcore.h>
#include "hahaha_image_process_wrap_affine_rotate.h"
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

//---------------------------------------------------------------------------
// base
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst,
    const halib_def_image::warp_affine_rotate& rotate,
    const halib_def_image::warp_affine_rotate_method& method

)
{
    return halib_def::result::SUCCESS;

}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst,
    const halib_def_image::warp_affine_rotate& rotate,
    const halib_def_image::warp_affine_rotate_method& method

)
{
    return halib_def::result::SUCCESS;

}

//---------------------------------------------------------------------------
// argb
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const halib_def_image::warp_affine_rotate& rotate,
    const halib_def_image::warp_affine_rotate_method& method

)
{
    return halib_def::result::SUCCESS;

}

//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
// nearest
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_90(const halib::bitmap_gray& src,
	const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},


	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_180(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_270(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},
        {(double)0, (double)roi_dst.Height() - 1},
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Vertical_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// linear
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_90(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_180(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_270(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Horizontal_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Vertical_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// cubic
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_90(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_180(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_270(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Vertical_Flip(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
// nearest
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_90(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},


	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_180(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_270(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},
        {(double)0, (double)roi_dst.Height() - 1},
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Vertical_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 3;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// linear
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_90(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_180(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_270(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Horizontal_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Vertical_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// cubic
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_90(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_180(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_270(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Vertical_Flip(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
// nearest
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_90(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},


	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_180(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_270(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)0, (double)0},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Horizontal_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},
        {(double)0, (double)roi_dst.Height() - 1},
    	{(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Nearest_Vertical_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    IppiWarpSpec* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buf_size_ = 0; Ipp8u* buffer_ = 0;
    const Ipp32u number_channels_ = 4;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;
    IppiBorderType border_type_ = ippBorderConst;
    IppiWarpDirection direction_ = ippWarpForward;
    Ipp64f border_value_[number_channels_];

    for (int i = 0; i < number_channels_; ++i)
    {
        border_value_[i] = 255.0;
    }

    IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };


    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel


    // 因為指標指向目的位置，所以是(0, 0)
    IppiRect src_roi_;
	src_roi_.x = 0;
	src_roi_.y = 0;
	src_roi_.width = roi_src.Width();
    src_roi_.height = roi_src.Height();

    double coeffs_[2][3] = {0};

	// 因為指標指向目的位置，所以是(0, 0)
    double quad_[4][2] = {
        {(double)0, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)roi_dst.Height() - 1},
        {(double)roi_dst.Width() - 1, (double)0},
        {(double)0, (double)0},

	};

	status_ = ippiGetAffineTransform(
        src_roi_,
        quad_,
        coeffs_
    );



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

    /* Memory allocation */
    spec_ = (IppiWarpSpec*)ippsMalloc_8u(spec_size_);
    if (spec_ == NULL)
    {
//    	return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Filter initialization */
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

    /* work buffer size */
    status_ = ippiWarpGetBufferSize(spec_,
    	roi_size_dst_,
        &buf_size_
    );
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }

    buffer_ = ippsMalloc_8u(buf_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }

    /* Resize processing */
    status_ = ippiWarpAffineNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
    	spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// linear
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_90(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_180(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_270(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Horizontal_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Linear_Vertical_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//-------------------------
// cubic
//-------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_90(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_180(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_270(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Horizontal_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_warp_affine_rotate::Rotate_Cubic_Vertical_Flip(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst
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
    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------

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
