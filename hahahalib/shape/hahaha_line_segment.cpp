//---------------------------------------------------------------------------

#pragma hdrstop
#include <math.h>
#include <iostream>
#include <algorithm>
#include "hahaha_line_segment.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_line_segment<T>::hahaha_line_segment(const hahahalib::hahaha_point<T>& p1,
    const hahahalib::hahaha_point<T>& p2
)
{
	Reset();
    P1_ = p1;
    P2_ = p2;
}
//---------------------------------------------------------------------------
template <typename T>
// 解構物件並釋放相關資源。
hahaha_line_segment<T>::~hahaha_line_segment()
{

}
//---------------------------------------------------------------------------
template <typename T>
// 建構物件並初始化預設狀態。
hahaha_line_segment<T>::hahaha_line_segment(const hahaha_line_segment<T>& hls)
{
    Reset();
	Copy(hls);
}
//---------------------------------------------------------------------------
template <typename T>
// 以移動方式建構物件並接手既有資源。
hahaha_line_segment<T>::hahaha_line_segment(hahaha_line_segment<T>&& hls) noexcept
{
    Move(std::move(hls));

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line_segment<T>& hahaha_line_segment<T>::operator=(const hahaha_line_segment<T>& hls)
{
	Copy(hls);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 移動指派目前物件內容。
hahaha_line_segment<T>& hahaha_line_segment<T>::operator=(hahaha_line_segment<T>&& hls) noexcept
{
	if (this != &hls)
    {
        Move(std::move(hls));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
// 複製來源物件的內部狀態。
void hahaha_line_segment<T>::Copy(const hahaha_line_segment& hls)
{
    P1_ = hls.P1_;
    P2_ = hls.P2_;
}
//---------------------------------------------------------------------------
template <typename T>
// 接手來源物件的內部資源。
void hahaha_line_segment<T>::Move(hahaha_line_segment&& hls) noexcept
{
    P1_ = hls.P1_;
    P2_ = hls.P2_;

    hls.Reset();
}
//---------------------------------------------------------------------------
template <typename T>
// 重設內部狀態。
int hahaha_line_segment<T>::Reset()
{
    P1_.Reset();
    P2_.Reset();

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_line_segment<int>;
template class hahaha_line_segment<float>;
template class hahaha_line_segment<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
