//---------------------------------------------------------------------------

#ifndef hahaha_shape_function_line_segmentH
#define hahaha_shape_function_line_segmentH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_line_segment.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace shape
{
//---------------------------------------------------------------------------

template <typename T>
class hahaha_shape_function_line_segment
{

public:
	// 计算线段长度
    static double Length(const hahaha_line_segment<T>& line_segment);
    // 计算斜率，避免除零
    static double Slope(const hahaha_line_segment<T>& line_segment);
    // 判断点 p 是否在线段上（使用叉积+范围检查）
    static bool Is_On_Line_Segment(const hahaha_line_segment<T>& line_segment, const hahahalib::hahaha_point<T>& point);
    // 判断两条线段是否相交
    static bool Intersect(const hahaha_line_segment<T>& line_segment1, const hahahalib::hahaha_line_segment<T>& line_segment2);
    // 判断点P是否在AB线段上，允许±5像素误差
    // 注意 : 好像要 * 500，不然只有線很細
    static bool Is_On_Line_Segment_With_Tolerance(const hahaha_line_segment<T>& line_segment, const hahahalib::hahaha_point<T>& point, double tolerance = 5.0);
public:

};


//---------------------------------------------------------------------------
} // shape
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib_shape
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

typedef hahahalib::shape::hahaha_shape_function_line_segment<int> line_segment;
typedef hahahalib::shape::hahaha_shape_function_line_segment<float> line_segment_float;
typedef hahahalib::shape::hahaha_shape_function_line_segment<double> line_segment_double;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_shape
//---------------------------------------------------------------------------


#endif
