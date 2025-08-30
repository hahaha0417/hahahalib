//---------------------------------------------------------------------------

#ifndef hahaha_bitmap_function_bitmapH
#define hahaha_bitmap_function_bitmapH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_roi.h>
#include <shape\hahaha_rectangle.h>
//---------------------------------------------------------------------------
#include <define\shape\hahaha_define_shape_rectangle_control_point.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_bitmap;

//---------------------------------------------------------------------------
namespace bitmap
{
//---------------------------------------------------------------------------
template <typename T>
class hahaha_bitmap_function_bitmap
{
public:
	hahaha_bitmap_function_bitmap();
	~hahaha_bitmap_function_bitmap();

	hahaha_bitmap_function_bitmap(const hahaha_bitmap_function_bitmap& hsfr);
    hahaha_bitmap_function_bitmap(hahaha_bitmap_function_bitmap&& hsfr) noexcept;
	hahaha_bitmap_function_bitmap& operator=(const hahaha_bitmap_function_bitmap& hsfr);
    hahaha_bitmap_function_bitmap& operator=(hahaha_bitmap_function_bitmap&& hsfr) noexcept;
	void Copy(const hahaha_bitmap_function_bitmap& he);
    void Move(hahaha_bitmap_function_bitmap&& he) noexcept;
public:
	int Reset();
public:
    static bool Fix_Roi(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap, bool normalize = false);
    static bool Fix_Rectangle(hahahalib::hahaha_rectangle<T>& rectangle, const hahaha_bitmap& bitmap, bool normalize = false);
    static bool Is_In_Image(const hahahalib::hahaha_point<T>& point, const hahaha_bitmap& bitmap);
    // 修正Roi固定比例
    static bool Fix_Roi_Bitmap_Ratio(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap);
public:

};
//---------------------------------------------------------------------------
} // bitmap
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib_bitmap
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

typedef hahahalib::bitmap::hahaha_bitmap_function_bitmap<int> bitmap;
typedef hahahalib::bitmap::hahaha_bitmap_function_bitmap<float> bitmap_float;
typedef hahahalib::bitmap::hahaha_bitmap_function_bitmap<double> bitmap_double;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_bitmap
//---------------------------------------------------------------------------

#endif
