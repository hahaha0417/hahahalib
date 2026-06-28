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
// 建構物件並初始化預設狀態。
hahaha_c_bitmap<T, U>::hahaha_c_bitmap()
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 解構物件並釋放相關資源。
hahaha_c_bitmap<T, U>::~hahaha_c_bitmap()
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 建構物件並初始化預設狀態。
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
// 移動指派目前物件內容。
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
// 依索引存取內部資料。
T*& hahaha_c_bitmap<T, U>::operator[](const int& y)
{
   return Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
// 依索引存取內部資料。
T*& hahaha_c_bitmap<T, U>::operator[](const int& y) const
{
   return Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
// 複製來源物件的內部狀態。
void hahaha_c_bitmap<T, U>::Copy(const hahaha_c_bitmap<T, U>& hcb)
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 接手來源物件的內部資源。
void hahaha_c_bitmap<T, U>::Move(hahaha_c_bitmap<T, U>&& hcb) noexcept
{
    // 轉移底層指標擁有權後，來源物件立即 Reset，
    // 避免之後析構時重複釋放。
    Image_Ptr_ = hcb.Image_Ptr_;
	Image_Scanline_ = hcb.Image_Scanline_;

    hcb.Reset();

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 重設內部狀態。
int hahaha_c_bitmap<T, U>::Reset()
{
	// 這個基底類別本身不做實際釋放，留給擁有記憶體的衍生類別處理。

	return 0;

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 依指定尺寸重新配置內部資料。
int hahaha_c_bitmap<T, U>::Resize(const int& width, const int& height)
{
	// 單純保留介面，實際配置策略由衍生類別決定。

    return 0;

}
//---------------------------------------------------------------------------
template <typename T, int U>
// 清空目前資料內容。
int hahaha_c_bitmap<T, U>::Clear()
{
	// 單純保留介面，實際清空策略由衍生類別決定。

    return 0;

}
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_c_bitmap<unsigned char, 1>;
template class hahaha_c_bitmap<unsigned char, 2>;
template class hahaha_c_bitmap<unsigned char, 3>;
template class hahaha_c_bitmap<unsigned char, 4>;
template class hahaha_c_bitmap<float, 1>;
template class hahaha_c_bitmap<double, 1>;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
