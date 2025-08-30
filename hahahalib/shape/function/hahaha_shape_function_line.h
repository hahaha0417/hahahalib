//---------------------------------------------------------------------------

#ifndef hahaha_shape_function_lineH
#define hahaha_shape_function_lineH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
#include <shape\hahaha_line.h>
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
class hahaha_shape_function_line
{


public:
    // 获取斜率（如果是垂直线，返回 "inf"）
    static double Slope(const hahahalib::hahaha_line<T>& line);

    // 判断点 p 是否在直线上
    static bool Is_On_Line(const hahahalib::hahaha_line<T>& line, const hahahalib::hahaha_point<T>& point);

    // 判断两条直线是否平行（斜率相同）
    static bool Is_Parallel(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2);

    // 判断两条直线是否重合
    static bool Is_Coincident(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2);

    // 计算两条直线的交点（如果存在）
    static bool Intersection_Point(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2, hahahalib::hahaha_point<T>& intersection);
    // 判断点 P 是否在直线附近（±5像素误差）
    static bool Is_On_Line_With_Tolerance(const hahahalib::hahaha_line<T>& line, const hahahalib::hahaha_point<T>& point, double tolerance = 5.0);
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

typedef hahahalib::shape::hahaha_shape_function_line<int> line;
typedef hahahalib::shape::hahaha_shape_function_line<float> line_float;
typedef hahahalib::shape::hahaha_shape_function_line<double> line_double;

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_shape
//---------------------------------------------------------------------------

#endif
