//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippcc.h>
#include <ippi.h>

#include <image_process\color\hahaha_isa_image_process_color.h>
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
halib_def::result hahaha_image_process_color::RGB_To_YUV422(const halib::bitmap_rgb& src,
    const halib::roi& roi_src,
    halib::bitmap_yuv422& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 3;
    Ipp8u number_channels_dst_ = 2;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiRGBToYUV422_8u_C3C2R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::YUV422_To_RGB(const halib::bitmap_yuv422& src,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 3;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiYUV422ToRGB_8u_C2C3R(ptr_src_, src.Stride_, ptr_dst_, dst.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}

//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::YUY2_To_UYVY(const halib::bitmap_yuy2& src,
    const halib::roi& roi_src,
    halib::bitmap_uyvy& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 2;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

	int width_ = roi_src.Width();
    int height_ = roi_src.Height();
    for (int y = 0; y < height_; ++y)
    {
        unsigned char* s_ = ptr_src_ + y * src.Stride_;
        unsigned char* d_ = ptr_dst_ + y * dst.Stride_;

        for (int x = 0; x < width_; x += 2)
        {
            // Y0 U0 Y1 V0 -> U0 Y0 V0 Y1
            d_[0] = s_[1];
            d_[1] = s_[0];
            d_[2] = s_[3];
            d_[3] = s_[2];

            s_ += 4;
            d_ += 4;
        }
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::UYVY_To_YUY2(const halib::bitmap_uyvy& src,
    const halib::roi& roi_src,
    halib::bitmap_yuy2& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 2;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    int width_ = roi_src.Width();
    int height_ = roi_src.Height();
    for (int y = 0; y < height_; ++y)
    {
        unsigned char* s_ = ptr_src_ + y * src.Stride_;
        unsigned char* d_ = ptr_dst_ + y * dst.Stride_;

        for (int x = 0; x < width_; x += 2)
        {
            // U0 Y0 V0 Y1 -> Y0 U0 Y1 V0
            d_[0] = s_[1];
            d_[1] = s_[0];
            d_[2] = s_[3];
            d_[3] = s_[2];

            s_ += 4;
            d_ += 4;
        }
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::YUY2_To_YVYU(const halib::bitmap_yuy2& src,
    const halib::roi& roi_src,
    halib::bitmap_yvyu& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 2;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

	int width_ = roi_src.Width();
    int height_ = roi_src.Height();
    for (int y = 0; y < height_; ++y)
    {
        unsigned char* s_ = ptr_src_ + y * src.Stride_;
        unsigned char* d_ = ptr_dst_ + y * dst.Stride_;

        for (int x = 0; x < width_; x += 2)
        {
            // Y0 U0 Y1 V0 -> Y1 V0 Y0 U0
            d_[0] = s_[2];
            d_[1] = s_[3];
            d_[2] = s_[0];
            d_[3] = s_[1];

            s_ += 4;
            d_ += 4;
        }
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::YVYU_To_YUY2(const halib::bitmap_uyvy& src,
    const halib::roi& roi_src,
    halib::bitmap_yvyu& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 2;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    int width_ = roi_src.Width();
    int height_ = roi_src.Height();
    for (int y = 0; y < height_; ++y)
    {
        unsigned char* s_ = ptr_src_ + y * src.Stride_;
        unsigned char* d_ = ptr_dst_ + y * dst.Stride_;

        for (int x = 0; x < width_; x += 2)
        {
            // Y1 V0 Y0 U0    -> Y0 U0 Y1 V0
            d_[0] = s_[2];
            d_[1] = s_[3];
            d_[2] = s_[0];
            d_[3] = s_[1];

            s_ += 4;
            d_ += 4;
        }
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::ARGB_To_YUV422(const halib::bitmap_argb& src,
    const halib::roi& roi_src,
    halib::bitmap_yuv422& dst,
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
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
    halib_def::result result_ = halib_def::result::SUCCESS;
//
//
//
//    result_ = haISAlib_image::color::RGB_To_YUV422(temp_,
//        halib::roi(0, 0, roi_src.Width() - 1, roi_src.Height() - 1),
//        dst,
//        roi_dst
//    );

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_color::YUV422_To_ARGB(const halib::bitmap_yuv422& src,
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
    assert(roi_src.Width() == roi_dst.Width() &&
    	roi_src.Height() == roi_dst.Height()
    );
    assert((roi_src.Width() & 1) == 0);
    assert((roi_dst.Width() & 1) == 0);
#endif
	Ipp8u number_channels_src_ = 2;
    Ipp8u number_channels_dst_ = 4;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_src_ = &src[roi_src.Y1_][roi_src.X1_ * number_channels_src_]; // RGB image has 1 channels
	Ipp8u* ptr_dst_ = &dst[roi_dst.Y1_][roi_dst.X1_ * number_channels_dst_]; // Grayscale image has 1 channel

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi_src.Width(), roi_src.Height() };

    halib_def::result result_ = halib_def::result::SUCCESS;

    haISAlib_image::color::Convert(
        ptr_src_,
        src.Stride_,
        ptr_dst_,
        dst.Stride_,
        roi_src.Width(),
        roi_src.Height()
	);


    return result_;
}

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