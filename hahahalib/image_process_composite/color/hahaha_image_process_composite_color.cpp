//---------------------------------------------------------------------------

#pragma hdrstop
#include <assert.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <image_process\color\hahaha_image_process_color.h>

#include "hahaha_image_process_composite_color.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace image_process_composite
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace color
{
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_composite_color::ARGB_To_YUV422(const halib::bitmap_argb& src,
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

    halib::bitmap_rgb temp_;
    temp_.Resize(roi_src.Width(), roi_src.Height());

    result_ = halib_image::copy::Copy(src,
        roi_src,
        temp_,
        halib::roi(0, 0, roi_src.Width() - 1, roi_src.Height() - 1)
    );

    if(result_ == halib_def::result::FAILURE)
    {
        return result_;
    }

    result_ = halib_image::color::RGB_To_YUV422(temp_,
        halib::roi(0, 0, roi_src.Width() - 1, roi_src.Height() - 1),
        dst,
        roi_dst
    );

    return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_image_process_composite_color::YUV422_To_ARGB(const halib::bitmap_yuv422& src,
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
    halib_def::result result_ = halib_def::result::SUCCESS;

    halib::bitmap_rgb temp_;
    temp_.Resize(roi_src.Width(), roi_src.Height());

    result_ = halib_image::color::YUV422_To_RGB(src,
        roi_src,
        temp_,
        halib::roi(0, 0, roi_src.Width() - 1, roi_src.Height() - 1)
    );

    if(result_ == halib_def::result::FAILURE)
    {
        return result_;
    }

    result_ = halib_image::copy::Copy(temp_,
        halib::roi(0, 0, roi_src.Width() - 1, roi_src.Height() - 1),
        dst,
        roi_dst
    );


    return result_;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
} // color
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // image_process_composite
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------