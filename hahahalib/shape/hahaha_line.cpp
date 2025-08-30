//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_line.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>::hahaha_line(const hahahalib::hahaha_point<T>& p1,
    const hahahalib::hahaha_point<T>& p2
)
{
	Reset();
    if (p1.X_ == p2.X_) {
        // 垂直直线，形如 x = c，即 A = 1, B = 0, C = -p1.x
        A_ = 1;
        B_ = 0;
        C_ = -p1.X_;
    } else {
        // 计算一般式 Ax + By + C = 0
        A_ = p1.Y_ - p2.Y_;
        B_ = p2.X_ - p1.X_;
        C_ = p1.X_ * p2.Y_ - p2.X_ * p1.Y_;
    }
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>::~hahaha_line()
{

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>::hahaha_line(const hahaha_line<T>& hl)
{
    Reset();
	Copy(hl);
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>::hahaha_line(hahaha_line<T>&& hl) noexcept
{
    Move(std::move(hl));

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>& hahaha_line<T>::operator=(const hahaha_line<T>& hl)
{
	Copy(hl);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_line<T>& hahaha_line<T>::operator=(hahaha_line<T>&& hl) noexcept
{
	if (this != &hl)
    {
        Move(std::move(hl));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_line<T>::Copy(const hahaha_line& hl)
{
    A_ = hl.A_;
    B_ = hl.B_;
    C_ = hl.C_;

}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_line<T>::Move(hahaha_line&& hl) noexcept
{
    A_ = hl.A_;
    B_ = hl.B_;
    C_ = hl.C_;

    hl.Reset();

}
//---------------------------------------------------------------------------
template <typename T>
int hahaha_line<T>::Reset()
{
    A_ = 0;
    B_ = 0;
    C_ = 0;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_line<int>;
template class hahaha_line<float>;
template class hahaha_line<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------