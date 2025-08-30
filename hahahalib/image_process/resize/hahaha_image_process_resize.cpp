//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippi.h>
#include <ipps.h>
#include <ippcore.h>
#include "hahaha_image_process_resize.h"
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
namespace resize
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_gray& dst,
    const halib::roi& roi_dst,
    const halib_def_image::resize& method

)
{
    // 用if else 簡單寫就好

    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_rgb& dst,
    const halib::roi& roi_dst,
    const halib_def_image::resize& method

)
{
    // 用if else 簡單寫就好

	return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// argb
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const halib_def_image::resize& method

)
{
    // 用if else 簡單寫就好

	return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// gray
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize_Nearest(const halib::bitmap_gray& src,
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
    IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippNearest, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeNearestInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
    status_ = ippiResizeNearest_8u_C1R(ptr_src_,
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
halib_def::result hahaha_image_process_resize::Resize_Linear(const halib::bitmap_gray& src,
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
    IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 1;
    IppiPoint dst_offset_ = {0, 0};
    // 看手冊，沒有ippBorderConst
    IppiBorderType border_type_ = ippBorderRepl;
//    Ipp8u border_value_[1] = {0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippLinear, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeLinearInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
    status_ = ippiResizeLinear_8u_C1R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        dst_offset_,
        roi_size_dst_,
        border_type_,
        NULL,
        spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);





    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
// color
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize_Nearest(const halib::bitmap_rgb& src,
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
	IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 3;
    IppiPoint offset_dst_ = {0, 0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippNearest, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeNearestInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
	status_ = ippiResizeNearest_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        offset_dst_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize_Linear(const halib::bitmap_rgb& src,
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
	IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 3;
    IppiPoint offset_dst_ = {0, 0};
    // 看手冊，沒有ippBorderConst
    IppiBorderType border_type_ = ippBorderRepl;
//    Ipp8u border_value_[3] = {0, 0, 0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippLinear, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeLinearInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
	status_ = ippiResizeLinear_8u_C3R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        offset_dst_,
        roi_size_dst_,
        border_type_,
        NULL,
        spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
// argb
//---------------------------------------------------------------------------
// 這好像有bug，顏色怪怪的
halib_def::result hahaha_image_process_resize::Resize_Nearest(const halib::bitmap_argb& src,
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
	IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 4;
    IppiPoint offset_dst_ = {0, 0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippNearest, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeNearestInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
	status_ = ippiResizeNearest_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        offset_dst_,
        roi_size_dst_,
        spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_resize::Resize_Linear(const halib::bitmap_argb& src,
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
	IppiResizeSpec_32f* spec_ = 0;
    int spec_size_ = 0, init_size_ = 0, buffer_size_ = 0;
    Ipp8u* buffer_  = 0;
    Ipp8u* init_buf_ = 0;
    Ipp32u number_channels_ = 4;
    IppiPoint offset_dst_ = {0, 0};
    // 看手冊，沒有ippBorderConst
	IppiBorderType border_type_ = ippBorderRepl;
	// Ipp8u border_value_[4] = {0, 0, 0, 0};
    IppStatus status_ = ippStsNoErr;

	IppiSize roi_size_src_ = { roi_src.Width(), roi_src.Height() };
	IppiSize roi_size_dst_ = { roi_dst.Width(), roi_dst.Height() };



	Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_]; // RGB image has 3 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_]; // Grayscale image has 1 channel

    /* Spec and init buffer sizes */
    status_ = ippiResizeGetSize_8u(roi_size_src_, roi_size_dst_, ippLinear, 0, &spec_size_, &init_size_);

    if (status_ != ippStsNoErr)
    {
    	// return status;
		return halib_def::result::FAILURE;
    }

    /* Memory allocation */
    init_buf_ = ippsMalloc_8u(init_size_);
    spec_    = (IppiResizeSpec_32f*)ippsMalloc_8u(spec_size_);
    if (init_buf_ == NULL || spec_ == NULL)
    {
        ippsFree(init_buf_);
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Filter initialization */
    status_ =  ippiResizeLinearInit_8u(roi_size_src_, roi_size_dst_, spec_);
    ippsFree(init_buf_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    /* work buffer size */
    status_ = ippiResizeGetBufferSize_8u(spec_, roi_size_dst_, number_channels_, &buffer_size_);
    if (status_ != ippStsNoErr)
    {
        ippsFree(spec_);
        // return status;
        return halib_def::result::FAILURE;
    }
    buffer_ = ippsMalloc_8u(buffer_size_);
    if (buffer_ == NULL)
    {
        ippsFree(spec_);
        // return ippStsNoMemErr;
        return halib_def::result::FAILURE;
    }
    /* Resize processing */
	status_ = ippiResizeLinear_8u_C4R(ptr_src_,
    	src.Stride_,
        ptr_dst_,
        dst.Stride_,
        offset_dst_,
        roi_size_dst_,
        border_type_,
        NULL,
        spec_,
        buffer_
    );

    ippsFree(spec_);
    ippsFree(buffer_);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//  antialiasing
//---------------------------------------------------------------------------
// ipp手冊 1391
// 因為不是全部都有反鋸齒
// 所以分開寫
//-----------------------------

//---------------------------------------------------------------------------
} // resize
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------