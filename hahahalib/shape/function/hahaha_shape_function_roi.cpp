//---------------------------------------------------------------------------

#pragma hdrstop
#include <bitmap\base\hahaha_bitmap.h>

#include "hahaha_shape_function_roi.h"
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
bool hahaha_shape_function_roi<T>::Is_Point_In(const hahahalib::hahaha_roi<T>& roi, const hahahalib::hahaha_point<T>& point)
{
    return point.X_ >= roi.X1_ && point.X_ <= roi.X2_ && point.Y_ >= roi.Y1_ && point.Y_ <= roi.Y2_;
}
//---------------------------------------------------------------------------
template <typename T>
int hahaha_shape_function_roi<T>::Fix_Roi_Fix_Bitmap_Ratio(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap, const double& dx, const double& dy, halib_def::shape_rectangle_control_point control_point)
{
    if(bitmap.Width_ == 0 || bitmap.Height_ == 0)
    {
        // 除0
        return -1;
    }

    if(control_point == halib_def::shape_rectangle_control_point::LEFT_TOP)
    {
        if(dx >= 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
        }
        else if(dx < 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
        }
        else if(dx < 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
        }
        else if(dx >= 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
        }
    }
    else if(control_point == halib_def::shape_rectangle_control_point::MIDDLE_TOP)
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        // 上下拖动为主
        roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);
        // 左右拖动为主
        roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);
    }
    else if(control_point == halib_def::shape_rectangle_control_point::RIGHT_TOP)
    {
        if(dx >= 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
        }
        else if(dx < 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
        }
        else if(dx < 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }
        }
        else if(dx >= 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y1_ = roi.Y2_ - (roi.Width() * ratio_ - 1);

            }
        }
    }
    else if(control_point == halib_def::shape_rectangle_control_point::LEFT_MIDDLE)
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        // 左右拖动为主
        roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);
        // 上下拖动为主
        roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

    }
    else if(control_point == halib_def::shape_rectangle_control_point::RIGHT_MIDDLE)
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        // 左右拖动为主
        roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);
        // 上下拖动为主
        roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

    }
    else if(control_point == halib_def::shape_rectangle_control_point::LEFT_BOTTOM)
    {
        if(dx >= 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }

        }
        else if(dx < 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }

        }
        else if(dx < 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }

        }
        else if(dx >= 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X1_ = roi.X2_ - (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }

        }
    }
    else if(control_point == halib_def::shape_rectangle_control_point::MIDDLE_BOTTOM)
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        // 上下拖动为主
        roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);
        // 左右拖动为主
        roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

    }
    else if(control_point == halib_def::shape_rectangle_control_point::RIGHT_BOTTOM)
    {
        if(dx >= 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }

        }
        else if(dx < 0 && dy >= 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }

        }
        else if(dx < 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 上下拖动为主
                roi.X2_ = roi.X1_ + (roi.Height() / ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
        }
        else if(dx >= 0 && dy < 0)
        {
            double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
            if (abs(dx * ratio_) > abs(dy))
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
            else
            {
                // 左右拖动为主
                roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);

            }
        }
    }

    return 0;
}

//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_shape_function_roi<int>;
template class hahaha_shape_function_roi<float>;
template class hahaha_shape_function_roi<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // shape
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
