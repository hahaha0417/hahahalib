//---------------------------------------------------------------------------

#pragma hdrstop
#include <bitmap\base\hahaha_bitmap.h>

#include "hahaha_bitmap_function_bitmap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace bitmap
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>::hahaha_bitmap_function_bitmap()
{
	Reset();
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>::~hahaha_bitmap_function_bitmap()
{

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>::hahaha_bitmap_function_bitmap(const hahaha_bitmap_function_bitmap<T>& hsfr)
{
    Reset();
	Copy(hsfr);
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>::hahaha_bitmap_function_bitmap(hahaha_bitmap_function_bitmap<T>&& hsfr) noexcept
{
    Move(std::move(hsfr));
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>& hahaha_bitmap_function_bitmap<T>::operator=(const hahaha_bitmap_function_bitmap<T>& hsfr)
{
	Copy(hsfr);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_bitmap_function_bitmap<T>& hahaha_bitmap_function_bitmap<T>::operator=(hahaha_bitmap_function_bitmap<T>&& hsfr) noexcept
{
    if (this != &hsfr)
    {
        Move(std::move(hsfr));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_bitmap_function_bitmap<T>::Copy(const hahaha_bitmap_function_bitmap<T>& hsfr)
{

}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_bitmap_function_bitmap<T>::Move(hahaha_bitmap_function_bitmap<T>&& hsfr) noexcept
{

}
//---------------------------------------------------------------------------
template <typename T>
int hahaha_bitmap_function_bitmap<T>::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_bitmap_function_bitmap<T>::Fix_Roi(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap, bool normalize)
{
    if(normalize)
    {
        roi.Normalize();
    }

    if(roi.X1_ < 0)
    {
        roi.X1_ = 0;
    }
    if(roi.Y1_ < 0)
    {
        roi.Y1_ = 0;
    }

    if(roi.X2_ > bitmap.Width_ - 1)
    {
        roi.X2_ = bitmap.Width_ - 1;
    }
    if(roi.Y2_ > bitmap.Height_ - 1)
    {
        roi.Y2_ = bitmap.Height_ - 1;
    }

    return true;
}

//---------------------------------------------------------------------------
template <typename T>
bool hahaha_bitmap_function_bitmap<T>::Fix_Rectangle(hahahalib::hahaha_rectangle<T>& rectangle, const hahaha_bitmap& bitmap, bool normalize)
{
    if(normalize)
    {
        rectangle.Normalize();
    }

    if(rectangle.X1_ < 0)
    {
        rectangle.X1_ = 0;
    }
    if(rectangle.Y1_ < 0)
    {
        rectangle.Y1_ = 0;
    }

    if(rectangle.X2_ > bitmap.Width_)
    {
        rectangle.X2_ = bitmap.Width_;
    }
    if(rectangle.Y2_ > bitmap.Height_)
    {
        rectangle.Y2_ = bitmap.Height_;
    }

    return true;
}

//---------------------------------------------------------------------------
template <typename T>
bool hahaha_bitmap_function_bitmap<T>::Is_In_Image(const hahahalib::hahaha_point<T>& point, const hahaha_bitmap& bitmap)
{
    if(0 <= point.X_ && point.X_ < bitmap.Width_ &&
        0 <= point.Y_ && point.Y_ < bitmap.Height_
    )
    {
        return true;
    }

    return false;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_bitmap_function_bitmap<T>::Fix_Roi_Bitmap_Ratio(hahahalib::hahaha_roi<T>& roi, const hahaha_bitmap& bitmap)
{
    if(bitmap.Width_ >= bitmap.Height_)
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        if(bitmap.Width_ == 0)
        {
            return false;
        }
        // 以圖長邊為主，fit roi對應邊
        roi.Y2_ = roi.Y1_ + (roi.Width() * ratio_ - 1);
    }
    else
    {
        double ratio_ = (double)bitmap.Height_ / bitmap.Width_;
        if(bitmap.Height_ == 0)
        {
            return false;
        }
        // 以圖長邊為主，fit roi對應邊
        roi.X2_ = roi.X1_ + (roi.Height() * ratio_ - 1);
    }


    return true;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_bitmap_function_bitmap<int>;
template class hahaha_bitmap_function_bitmap<float>;
template class hahaha_bitmap_function_bitmap<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // bitmap
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
