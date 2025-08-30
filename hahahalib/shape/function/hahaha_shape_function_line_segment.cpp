//---------------------------------------------------------------------------

#pragma hdrstop
#include <math.h>
#include <iostream>
#include <algorithm>
#include "hahaha_shape_function_line_segment.h"
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
double hahaha_shape_function_line_segment<T>::Length(const hahaha_line_segment<T>& line_segment)
{
    return std::sqrt((line_segment.P2_.X_ - line_segment.P1_.X_) * (line_segment.P2_.X_ - line_segment.P1_.X_) + (line_segment.P2_.Y_ - line_segment.P1_.Y_) * (line_segment.P2_.Y_ - line_segment.P1_.Y_));

}
//---------------------------------------------------------------------------
template <typename T>
double hahaha_shape_function_line_segment<T>::Slope(const hahaha_line_segment<T>& line_segment)
{
    if (line_segment.P1_.X_ == line_segment.P2_.X_)
    {
        throw std::runtime_error("垂直線段無斜率");
    }

    return (double)(line_segment.P2_.Y_ - line_segment.P1_.Y_) / (line_segment.P2_.X_ - line_segment.P1_.X_);

}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_shape_function_line_segment<T>::Is_On_Line_Segment(const hahaha_line_segment<T>& line_segment, const hahahalib::hahaha_point<T>& point)
{
    int cross_product_ = (line_segment.P2_.X_ - line_segment.P1_.X_) * (point.Y_ - line_segment.P1_.Y_) - (line_segment.P2_.Y_ - line_segment.P1_.Y_) * (point.X_ - line_segment.P1_.X_);
    if (cross_product_ != 0)
    {
        return false; // 不在同一直线上
    }

    // 检查是否在范围内
    return (point.X_ >= std::min(line_segment.P1_.X_, line_segment.P2_.X_) && point.X_ <= std::max(line_segment.P1_.X_, line_segment.P2_.X_) &&
            point.Y_ >= std::min(line_segment.P1_.Y_, line_segment.P2_.Y_) && point.Y_ <= std::max(line_segment.P1_.Y_, line_segment.P2_.X_));
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_shape_function_line_segment<T>::Intersect(const hahaha_line_segment<T>& line_segment1, const hahahalib::hahaha_line_segment<T>& line_segment2)
{
    auto orientation_ = [](const hahahalib::hahaha_point<T>& a,
    	const hahahalib::hahaha_point<T>& b,
        const hahahalib::hahaha_point<T>& c
    )
    {
        int val_ = (b.Y_ - a.Y_) * (c.X_ - b.X_) - (b.X_ - a.X_) * (c.Y_ - b.Y_);
        if (val_ == 0)
        {
            return 0;  // 共线
        }
        return (val_ > 0) ? 1 : -1; // 顺时针 / 逆时针
    };

    int o1_ = orientation_(line_segment1.P1_, line_segment1.P2_, line_segment2.P1_);
    int o2_ = orientation_(line_segment1.P1_, line_segment1.P2_, line_segment2.P2_);
    int o3_ = orientation_(line_segment2.P1_, line_segment2.P2_, line_segment1.P1_);
    int o4_ = orientation_(line_segment2.P1_, line_segment2.P2_, line_segment1.P2_);

    // 一般情况，两个线段端点分别在对方的两侧
    if (o1_ != o2_ && o3_ != o4_)
    {
        return true;
    }

    // 特殊情况：共线且重叠
    auto on_segment_ = [](const hahahalib::hahaha_point<T>& a,
    	const hahahalib::hahaha_point<T>& b,
        const hahahalib::hahaha_point<T>& c
    ) {
        return c.X_ >= std::min(a.X_, b.X_) && c.X_ <= std::max(a.X_, b.X_) &&
               c.Y_ >= std::min(a.Y_, b.Y_) && c.Y_ <= std::max(a.Y_, b.Y_);
    };

    if (o1_ == 0 && on_segment_(line_segment1.P1_, line_segment1.P2_, line_segment2.P1_))
    {
         return true;
    }
    if (o2_ == 0 && on_segment_(line_segment1.P1_, line_segment1.P2_, line_segment2.P2_))
    {
        return true;
    }
    if (o3_ == 0 && on_segment_(line_segment2.P1_, line_segment2.P2_, line_segment1.P1_))
    {
        return true;
    }
    if (o4_ == 0 && on_segment_(line_segment2.P1_, line_segment2.P2_, line_segment1.P2_))
    {
        return true;
    }

    return false;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_shape_function_line_segment<T>::Is_On_Line_Segment_With_Tolerance(const hahaha_line_segment<T>& line_segment, const hahahalib::hahaha_point<T>& point, double tolerance)
{
    double x1_ = line_segment.P1_.X_;
    double y1_ = line_segment.P1_.Y_;
    double x2_ = line_segment.P2_.X_;
    double y2_ = line_segment.P2_.Y_;
    double px_ = point.X_;
    double py_ = point.Y_;

    // 计算叉积，检查点是否在直线上
    double cross_product_ = std::fabs((py_ - y1_) * (x2_ - x1_) - (px_ - x1_) * (y2_ - y1_));
    if (cross_product_ > tolerance)
    {
        return false; // 叉积不为 0，说明点不在直线上
    }

    // 计算点积，检查点是否在线段范围内
    double dot_product1_ = (px_ - x1_) * (x2_ - x1_) + (py_ - y1_) * (y2_ - y1_);
    double dot_product2_ = (px_ - x2_) * (x1_ - x2_) + (py_ - y2_) * (y1_ - y2_);

    return dot_product1_ >= -tolerance && dot_product2_ >= -tolerance;
}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_shape_function_line_segment<int>;
template class hahaha_shape_function_line_segment<float>;
template class hahaha_shape_function_line_segment<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // shape
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------