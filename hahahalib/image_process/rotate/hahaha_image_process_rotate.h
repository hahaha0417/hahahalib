//---------------------------------------------------------------------------

#ifndef hahaha_image_process_rotateH
#define hahaha_image_process_rotateH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\image_process\rotate\hahaha_define_image_process_rotate.h>
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
namespace rotate
{
//---------------------------------------------------------------------------

class hahaha_image_process_rotate
{
public:
    //---------------------------------------------------------------------------
    // base
    //---------------------------------------------------------------------------
    // 旋轉後目標roi
    static halib_def::result Rotate_Roi(
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const double& angle  // 旋轉角度。
    );


	//---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle,  // 旋轉角度。
        const halib_def_image::rotate& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle,  // 旋轉角度。
        const halib_def_image::rotate& method  // 指定要使用的插值或處理方法。

    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle,  // 旋轉角度。
        const halib_def_image::rotate& method  // 指定要使用的插值或處理方法。

    );


    //---------------------------------------------------------------------------
    // gray
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const double& angle  // 旋轉角度。
    );

    // 使用線性插值旋轉影像。
    static halib_def::result Rotate_Linear(const halib::bitmap_gray& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_gray& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
        const double& angle  // 旋轉角度。
    );

    //---------------------------------------------------------------------------
    // color
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle  // 旋轉角度。
    );

    // 使用線性插值旋轉影像。
    static halib_def::result Rotate_Linear(const halib::bitmap_rgb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_rgb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle  // 旋轉角度。
    );

    //---------------------------------------------------------------------------
    // argb
    //---------------------------------------------------------------------------
    static halib_def::result Rotate_Nearest(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle  // 旋轉角度。
    );

    // 使用線性插值旋轉影像。
    static halib_def::result Rotate_Linear(const halib::bitmap_argb& src,  // 來源影像。
        const halib::roi& roi_src,  // 來源影像中要讀取的區域。
        halib::bitmap_argb& dst,  // 輸出結果的目標影像。
        const halib::roi& roi_dst,  // 目標影像中要寫入的區域。
    	const double& angle  // 旋轉角度。
    );

    //---------------------------------------------------------------------------
    //
    //---------------------------------------------------------------------------

public:

};



//---------------------------------------------------------------------------
} // rotate
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

typedef hahahalib::image_process::rotate::hahaha_image_process_rotate rotate;



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_image
//---------------------------------------------------------------------------

#endif
