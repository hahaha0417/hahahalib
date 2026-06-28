//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_rectangle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_rectangle<T>::hahaha_rectangle()
{
	Reset();
}
//---------------------------------------------------------------------------
template <typename T>
// 以既有物件內容建構新的物件實例。
hahaha_rectangle<T>::hahaha_rectangle(
    const T& x1,
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
hahaha_rectangle<T>::~hahaha_rectangle()
{

}
//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_rectangle<T>::hahaha_rectangle(const hahaha_rectangle<T>& hr)
{
    Reset();
	Copy(hr);
}
//---------------------------------------------------------------------------
template <typename T>
// 以移動方式建構物件並接手既有資源。
hahaha_rectangle<T>::hahaha_rectangle(hahaha_rectangle<T>&& hr) noexcept
{
    Move(std::move(hr));

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_rectangle<T>& hahaha_rectangle<T>::operator=(const hahaha_rectangle<T>& hr)
{
	Copy(hr);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 移動指派目前物件內容。
hahaha_rectangle<T>& hahaha_rectangle<T>::operator=(hahaha_rectangle<T>&& hr) noexcept
{
	if (this != &hr)
    {
        Move(std::move(hr));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 複製來源物件的內部狀態。
void hahaha_rectangle<T>::Copy(const hahaha_rectangle<T>& hr)
{
    X1_ = hr.X1_;
    Y1_ = hr.Y1_;
    X1_ = hr.X1_;
    Y2_ = hr.Y2_;
}
//---------------------------------------------------------------------------
template <typename T>
// 接手來源物件的內部資源。
void hahaha_rectangle<T>::Move(hahaha_rectangle<T>&& hr) noexcept
{
    X1_ = hr.X1_;
    Y1_ = hr.Y1_;
    X1_ = hr.X1_;
    Y2_ = hr.Y2_;

    hr.Reset();
}
//---------------------------------------------------------------------------
template <typename T>
// 重設內部狀態。
int hahaha_rectangle<T>::Reset()
{
    X1_ = 0;
    Y1_ = 0;
    X1_ = 0;
    Y2_ = 0;

	return 0;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的寬度。
T hahaha_rectangle<T>::Width()
{
	return X2_ - X1_;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的高度。
T hahaha_rectangle<T>::Height()
{
	return Y2_ - Y1_;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的寬度。
T hahaha_rectangle<T>::Width() const
{
	return X2_ - X1_;
}
//---------------------------------------------------------------------------
template <typename T>
// 計算目前圖形的高度。
T hahaha_rectangle<T>::Height() const
{
	return Y2_ - Y1_;
}
//---------------------------------------------------------------------------
template <typename T>
// 整理座標順序，確保左上與右下定義正確。
void hahaha_rectangle<T>::Normalize()
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
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_rectangle<int>;
template class hahaha_rectangle<float>;
template class hahaha_rectangle<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
