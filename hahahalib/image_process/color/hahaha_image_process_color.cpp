//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippcc.h>


#include "hahaha_image_process_color.h"
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
namespace color
{
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::RGB_To_Gray(const halib::bitmap_rgb& src,
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
    assert(roi_src.Width() == roi_dst.Width() &&
    	roi_src.Height() == roi_dst.Height()
    );
#endif
    Ipp8u number_channels_src_ = 3;
    Ipp8u number_channels_dst_ = 1;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiRGBToGray_8u_C3C1R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::Gray_To_RGB(const halib::bitmap_gray& src,
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
    assert(roi_src.Width() == roi_dst.Width() &&
    	roi_src.Height() == roi_dst.Height()
    );
#endif
    Ipp8u number_channels_src_ = 1;
    Ipp8u number_channels_dst_ = 3;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiGrayToRGB_8u_C1C3R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::ARGB_To_Gray(const halib::bitmap_argb& src,
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
    assert(roi_src.Width() == roi_dst.Width() &&
    	roi_src.Height() == roi_dst.Height()
    );
#endif
    Ipp8u number_channels_src_ = 4;
    Ipp8u number_channels_dst_ = 1;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiRGBToGray_8u_AC4C1R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::Gray_To_ARGB(const halib::bitmap_gray& src,
    const halib::roi& roi_src,
    halib::bitmap_argb& dst,
    const halib::roi& roi_dst,
    const unsigned char value_alpha
)
{
#if defined(_DEBUG)
    assert(roi_src.X1_ >= 0 && roi_src.Y1_ >= 0 &&
        roi_src.X2_ < src.Width_ && roi_src.Y2_ < src.Height_
    );
    assert(roi_dst.X1_ >= 0 && roi_dst.Y1_ >= 0 &&
        roi_dst.X2_ < dst.Width_ && roi_dst.Y2_ < dst.Height_
    );
    assert(roi_src.Width() == roi_dst.Width() &&
    	roi_src.Height() == roi_dst.Height()
    );
#endif
    Ipp8u number_channels_src_ = 1;
    Ipp8u number_channels_dst_ = 4;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    Ipp8u value_alpha_ = value_alpha;

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiGrayToRGB_8u_C1C4R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_, value_alpha_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
} // color
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------