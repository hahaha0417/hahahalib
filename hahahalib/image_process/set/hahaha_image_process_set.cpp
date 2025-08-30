//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <ippcc.h>
#include <ippi.h>

#include "hahaha_image_process_set.h"
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
namespace set
{
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_set::Set(halib::bitmap_gray& image,
    const halib::roi& roi,
    const unsigned char& value
)
{
#if defined(_DEBUG)
    assert(roi.X1_ >= 0 && roi.Y1_ >= 0 &&
        roi.X2_ < image.Width_ && roi.Y2_ < image.Height_
    );

#endif
    Ipp8u number_channels_ = 1;
    Ipp8u value_[number_channels_];
    value_[0] = value;



    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_ = &image[roi.Y1_][roi.X1_ * number_channels_]; // RGB image has 1 channels

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi.Width(), roi.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiSet_8u_C1R(*value_, ptr_, image.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_set::Set(halib::bitmap_rgb& image,
    const halib::roi& roi,
    const unsigned char& value_r,
    const unsigned char& value_g,
    const unsigned char& value_b
)
{
#if defined(_DEBUG)
    assert(roi.X1_ >= 0 && roi.Y1_ >= 0 &&
        roi.X2_ < image.Width_ && roi.Y2_ < image.Height_
    );

#endif
    Ipp8u number_channels_ = 3;
    Ipp8u value_[number_channels_];
    value_[0] = value_b;
    value_[1] = value_g;
    value_[2] = value_r;

    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_ = &image[roi.Y1_][roi.X1_ * number_channels_]; // RGB image has 1 channels

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi.Width(), roi.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiSet_8u_C3R(value_, ptr_, image.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_set::Set(halib::bitmap_argb& image,
    const halib::roi& roi,
    const unsigned char& value_r,
    const unsigned char& value_g,
    const unsigned char& value_b,
    const unsigned char& value_a
)
{
#if defined(_DEBUG)
    assert(roi.X1_ >= 0 && roi.Y1_ >= 0 &&
        roi.X2_ < image.Width_ && roi.Y2_ < image.Height_
    );

#endif
    Ipp8u number_channels_ = 4;
    Ipp8u value_[number_channels_];
    value_[0] = value_b;
    value_[1] = value_g;
    value_[2] = value_r;
    value_[3] = value_a;


    // Allocate memory for the source RGB image and destination grayscale image
    Ipp8u* ptr_ = &image[roi.Y1_][roi.X1_ * number_channels_]; // RGB image has 1 channels

    // Initialize your source image data here...

	// Define the size of the region of interest
    IppiSize roi_size_ = { roi.Width(), roi.Height() };

    // Convert the RGB image to grayscale
    IppStatus status = ippiSet_8u_C4R(value_, ptr_, image.Stride_, roi_size_);

    if (status == ippStsNoErr) {
        // Conversion was successful
    } else {
        // Handle the error
    }

    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
} // set
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // image_process
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------