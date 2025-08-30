//---------------------------------------------------------------------------

#pragma hdrstop

#include <utility>

#include "hahaha_point.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>::hahaha_point()
{
	Reset();
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>::hahaha_point(
	const T& x,
    const T& y
)
{
    Reset();
    X_ = x;
    Y_ = y;
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>::~hahaha_point()
{

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>::hahaha_point(const hahaha_point<T>& hp)
{
    Reset();
	Copy(hp);
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>::hahaha_point(hahaha_point<T>&& hp) noexcept
{
    Move(std::move(hp));

}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>& hahaha_point<T>::operator=(const hahaha_point<T>& hp)
{
	Copy(hp);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
hahaha_point<T>& hahaha_point<T>::operator=(hahaha_point<T>&& hp) noexcept
{
	if (this != &hp)
    {
        Move(std::move(hp));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_point<T>::operator==(const hahaha_point<T>& hp)
{
    bool equal_ = true;

    equal_ &= X_ == hp.X_;
    equal_ &= Y_ == hp.Y_;

    return equal_;
}
//---------------------------------------------------------------------------
template <typename T>
bool hahaha_point<T>::operator!=(const hahaha_point<T>& hp)
{
    bool equal_ = true;

    equal_ &= X_ != hp.X_;
    equal_ &= Y_ != hp.Y_;

    return equal_;
}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_point<T>::Copy(const hahaha_point<T>& hp)
{
    X_ = hp.X_;
    Y_ = hp.Y_;
}
//---------------------------------------------------------------------------
template <typename T>
void hahaha_point<T>::Move(hahaha_point<T>&& hp) noexcept
{
    X_ = hp.X_;
    Y_ = hp.Y_;

    hp.Reset();
}
//---------------------------------------------------------------------------
template <typename T>
int hahaha_point<T>::Reset()
{
    X_ = 0;
    Y_ = 0;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_point<int>;
template class hahaha_point<float>;
template class hahaha_point<double>;
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------