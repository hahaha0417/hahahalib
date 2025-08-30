//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_c_bitmap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>::hahaha_c_bitmap()
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>::~hahaha_c_bitmap()
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>::hahaha_c_bitmap(const hahaha_c_bitmap<T, U>& hcb)
{
    Reset();
	Copy(hcb);
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>::hahaha_c_bitmap(hahaha_c_bitmap<T, U>&& hcb) noexcept
{
    Move(std::move(hcb));
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>& hahaha_c_bitmap<T, U>::operator=(const hahaha_c_bitmap<T, U>& hcb)
{
    hahaha_bitmap::Copy(hcb);
	Copy(hcb);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap<T, U>& hahaha_c_bitmap<T, U>::operator=(hahaha_c_bitmap<T, U>&& hcb) noexcept
{
	if (this != &hcb)
    {
        hahaha_bitmap::Move(std::move(hcb));
		Move(std::move(hcb));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap<T, U>::operator[](const int& y)
{
   return Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap<T, U>::operator[](const int& y) const
{
   return Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap<T, U>::Copy(const hahaha_c_bitmap<T, U>& hcb)
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap<T, U>::Move(hahaha_c_bitmap<T, U>&& hcb) noexcept
{
    Image_Ptr_ = hcb.Image_Ptr_;
	Image_Scanline_ = hcb.Image_Scanline_;

    hcb.Reset();

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap<T, U>::Reset()
{

	return 0;

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap<T, U>::Resize(const int& width, const int& height)
{

    return 0;

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap<T, U>::Clear()
{

    return 0;

}
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_c_bitmap<unsigned char, 1>;
template class hahaha_c_bitmap<unsigned char, 3>;
template class hahaha_c_bitmap<unsigned char, 4>;
template class hahaha_c_bitmap<float, 1>;
template class hahaha_c_bitmap<double, 1>;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------