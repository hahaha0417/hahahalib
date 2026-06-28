//---------------------------------------------------------------------------

#ifndef hahaha_image_process_resizeH
#define hahaha_image_process_resizeH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\resize\hahaha_define_image_process_resize.h>
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
namespace resize
{
//---------------------------------------------------------------------------

class hahaha_image_process_resize
{
public:
	//---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::resize& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::resize& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Resize(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const halib_def_image::resize& method  // 指定要使用的插值或處理方法。

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 使用線性插值縮放影像。
    static halib_def::result Resize_Linear(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 使用線性插值縮放影像。
    static halib_def::result Resize_Linear(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Resize_Nearest(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

    // 使用線性插值縮放影像。
    static halib_def::result Resize_Linear(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst
    );

public:

};



//---------------------------------------------------------------------------
} // resize
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

typedef hahahalib::image_process::resize::hahaha_image_process_resize resize;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------

#endif
