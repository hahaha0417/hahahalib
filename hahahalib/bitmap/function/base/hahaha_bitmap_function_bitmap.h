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
	// 建構物件並初始化預設狀態。
	hahaha_bitmap_function_bitmap();
	// 解構物件並釋放相關資源。
	~hahaha_bitmap_function_bitmap();

	// 以既有物件內容建構新的物件實例。
	hahaha_bitmap_function_bitmap(const hahaha_bitmap_function_bitmap& hsfr);
    // 以移動方式建構物件並接手既有資源。
    hahaha_bitmap_function_bitmap(hahaha_bitmap_function_bitmap&& hsfr) noexcept;
	// 複製指派目前物件內容。
	hahaha_bitmap_function_bitmap& operator=(const hahaha_bitmap_function_bitmap& hsfr);
    // 移動指派目前物件內容。
    hahaha_bitmap_function_bitmap& operator=(hahaha_bitmap_function_bitmap&& hsfr) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_bitmap_function_bitmap& he);
    // 接手來源物件的內部資源。
    void Move(hahaha_bitmap_function_bitmap&& he) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
    // 修正 ROI 範圍，避免超出影像邊界。
    static bool Fix_Roi(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap, bool normalize = false);
    // 修正矩形範圍，避免超出影像邊界。
    static bool Fix_Rectangle(hahahalib::hahaha_rectangle<T>& rectangle, const hahaha_bitmap& bitmap, bool normalize = false);
    // 回傳目前狀態判斷結果。
    static bool Is_In_Image(const hahahalib::hahaha_point<T>& point, const hahaha_bitmap& bitmap);
    // 依影像長寬比修正 ROI 範圍。
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
