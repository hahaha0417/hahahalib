//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_roi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_roi<T>::hahaha_roi()
{
	Reset();
}
//---------------------------------------------------------------------------
template <typename T>
// 以既有物件內容建構新的物件實例。
hahaha_roi<T>::hahaha_roi(const T& x1,
	const T& y1,
	const T& x2,
	const T& y2,
    bool normalize
)
{
    X1_ = x1;
    Y1_ = y1;
    X2_ = x2;
    Y2_ = y2;
    if(normalize)
    {

        Normalize();
    }
    else
    {

    }

}
//---------------------------------------------------------------------------
template <typename T>
// 解構物件並釋放相關資源。
hahaha_roi<T>::~hahaha_roi()
{

}
//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_roi<T>::hahaha_roi(const hahaha_roi<T>& hr)
{
    Reset();
	Copy(hr);
}
//---------------------------------------------------------------------------
template <typename T>
// 以移動方式建構物件並接手既有資源。
hahaha_roi<T>::hahaha_roi(hahaha_roi<T>&& hr) noexcept
{
    Move(std::move(hr));

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_roi<T>& hahaha_roi<T>::operator=(const hahaha_roi<T>& hr)
{
	Copy(hr);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 移動指派目前物件內容。
hahaha_roi<T>& hahaha_roi<T>::operator=(hahaha_roi<T>&& hr) noexcept
{
	if (this != &hr)
    {
        Move(std::move(hr));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 複製指派目前物件內容。
bool hahaha_roi<T>::operator==(const hahaha_roi<T>& hr)
{
    bool equal_ = true;

    equal_ &= X1_ == hr.X1_;
    equal_ &= Y1_ == hr.Y1_;
    equal_ &= X2_ == hr.X2_;
    equal_ &= Y2_ == hr.Y2_;

    return equal_;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_roi<T>::operator!=(const hahaha_roi<T>& hr)
{
    bool equal_ = true;

    equal_ &= X1_ != hr.X1_;
    equal_ &= Y1_ != hr.Y1_;
    equal_ &= X2_ != hr.X2_;
    equal_ &= Y2_ != hr.Y2_;

    return equal_;
}
//---------------------------------------------------------------------------
template <typename T>
// 複製來源物件的內部狀態。
void hahaha_roi<T>::Copy(const hahaha_roi<T>& hr)
{
	X1_ = hr.X1_;
	Y1_ = hr.Y1_;
	X2_ = hr.X2_;
	Y2_ = hr.Y2_;

}
//---------------------------------------------------------------------------
template <typename T>
// 接手來源物件的內部資源。
void hahaha_roi<T>::Move(hahaha_roi<T>&& hr) noexcept
{
	X1_ = hr.X1_;
	Y1_ = hr.Y1_;
	X2_ = hr.X2_;
	Y2_ = hr.Y2_;

    hr.Reset();

}
//---------------------------------------------------------------------------
template <typename T>
// 重設內部狀態。
int hahaha_roi<T>::Reset()
{
	X1_ = 0;
	Y1_ = 0;
	X2_ = 0;
	Y2_ = 0;

	return 0;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的寬度。
T hahaha_roi<T>::Width()
{
	return X2_ - X1_ + 1;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的高度。
T hahaha_roi<T>::Height()
{
	return Y2_ - Y1_ + 1;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的寬度。
T hahaha_roi<T>::Width() const
{
	return X2_ - X1_ + 1;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的高度。
T hahaha_roi<T>::Height() const
{
	return Y2_ - Y1_ + 1;
}
//---------------------------------------------------------------------------
template <typename T>
// 整理座標順序，確保左上與右下定義正確。
void hahaha_roi<T>::Normalize()
{
    if(X1_ < X2_)
    {


    }
    else
    {
        T temp_ = X1_;
        X1_ = X2_;
        X2_ = temp_;

    }

    if(Y1_ < Y2_)
    {

    }
    else
    {
        T temp_ = Y1_;
        Y1_ = Y2_;
        Y2_ = temp_;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_roi<int>;
template class hahaha_roi<float>;
template class hahaha_roi<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
