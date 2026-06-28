//---------------------------------------------------------------------------

#pragma hdrstop
#include <math.h>
#include <iostream>
#include <algorithm>
#include "hahaha_shape_function_line.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace shape
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
// 計算線段或直線的斜率。
double hahaha_shape_function_line<T>::Slope(const hahahalib::hahaha_line<T>& line)
{
    if (line.B_ == 0)
    {
        throw std::runtime_error("垂直直線無斜率");
    }

    return -line.A_ / line.B_;

}
//---------------------------------------------------------------------------
template <typename T>
// 回傳目前狀態判斷結果。
bool hahaha_shape_function_line<T>::Is_On_Line(const hahahalib::hahaha_line<T>& line, const hahahalib::hahaha_point<T>& point)
{
    return std::fabs(line.A_ * point.X_ + line.B_ * point.Y_ + line.C_) < 1e-9;  // 允许小数误差

}
//---------------------------------------------------------------------------
template <typename T>
// 回傳目前狀態判斷結果。
bool hahaha_shape_function_line<T>::Is_Parallel(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2)
{
    return std::fabs(line1.A_ * line2.B_ - line1.B_ * line2.A_) < 1e-9;

}
//---------------------------------------------------------------------------
template <typename T>
// 回傳目前狀態判斷結果。
bool hahaha_shape_function_line<T>::Is_Coincident(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2)
{
    return Is_Parallel(line1, line2) && std::fabs(line1.A_ * line2.C_ - line1.C_ * line2.A_) < 1e-9;

}
//---------------------------------------------------------------------------
template <typename T>
// 計算兩條直線的交點。
bool hahaha_shape_function_line<T>::Intersection_Point(const hahahalib::hahaha_line<T>& line1, const hahahalib::hahaha_line<T>& line2, hahahalib::hahaha_point<T>& intersection)
{
    double det_ = line1.A_ * line2.B_ - line2.A_ * line1.B_;
    if (std::fabs(det_) < 1e-9)
    {
        return false;  // 平行或重合，无交点
    }

    intersection.X_ = (line1.B_ * line2.C_ - line2.B_ * line1.C_) / det_;
    intersection.Y_ = (line1.C_ * line2.A_ - line2.C_ * line1.A_) / det_;
    return true;

}
//---------------------------------------------------------------------------
template <typename T>
// 回傳目前狀態判斷結果。
bool hahaha_shape_function_line<T>::Is_On_Line_With_Tolerance(const hahahalib::hahaha_line<T>& line, const hahahalib::hahaha_point<T>& point, double tolerance)
{
    double distance_ = std::fabs(line.A_ * point.X_ + line.B_ * point.Y_ + line.C_) / std::sqrt(line.A_ * line.A_ + line.B_ * line.B_);
    return distance_ <= tolerance;

}

//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_shape_function_line<int>;
template class hahaha_shape_function_line<float>;
template class hahaha_shape_function_line<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // shape
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
