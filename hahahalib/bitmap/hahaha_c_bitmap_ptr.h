//---------------------------------------------------------------------------

#ifndef hahaha_c_bitmap_ptrH
#define hahaha_c_bitmap_ptrH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <stdlib.h>
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap.h>


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
template <typename T, int U>
class hahaha_c_bitmap_ptr : public hahaha_c_bitmap<T, U>
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_c_bitmap_ptr(T* image_ptr);
	// 解構物件並釋放相關資源。
	~hahaha_c_bitmap_ptr();

	// 以既有物件內容建構新的物件實例。
	hahaha_c_bitmap_ptr(const hahaha_c_bitmap_ptr& hcbp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_c_bitmap_ptr(hahaha_c_bitmap_ptr&& hcbp) noexcept;
	// 複製指派目前物件內容。
	hahaha_c_bitmap_ptr& operator=(const hahaha_c_bitmap_ptr& hcbp);
	// 移動指派目前物件內容。
	hahaha_c_bitmap_ptr& operator=(hahaha_c_bitmap_ptr&& hcbp) noexcept;
	// 依索引存取內部資料。
	virtual T*& operator[](const int& y);
    // 依索引存取內部資料。
    virtual T*& operator[](const int& y) const;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_c_bitmap_ptr& hcbp);
	// 接手來源物件的內部資源。
	void Move(hahaha_c_bitmap_ptr&& hcbp) noexcept;
public:
	// 重設內部狀態。
	virtual int Reset();

public:
	// 依指定尺寸重新配置內部資料。
	virtual int Resize(const int& width, const int& height);
    // 清空目前資料內容。
    virtual int Clear();
public:

public:

public:


public:

};

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 1> bitmap_ptr_gray;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yuv422;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 3> bitmap_ptr_rgb;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 4> bitmap_ptr_argb;
typedef hahahalib::hahaha_c_bitmap_ptr<float, 1> bitmap_ptr_float;
typedef hahahalib::hahaha_c_bitmap_ptr<double, 1> bitmap_ptr_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yuy2;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_uyvy;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yvyu;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 1> bitmap_ptr_gray;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yuv422;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 3> bitmap_ptr_rgb;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 4> bitmap_ptr_argb;
typedef hahahalib::hahaha_c_bitmap_ptr<float, 1> bitmap_ptr_float;
typedef hahahalib::hahaha_c_bitmap_ptr<double, 1> bitmap_ptr_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yuy2;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_uyvy;
typedef hahahalib::hahaha_c_bitmap_ptr<unsigned char, 2> bitmap_ptr_yvyu;

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

////---------------------------------------------------------------------------
//// 確定不變才取(夠common)
////---------------------------------------------------------------------------
//namespace h_lib or a_lib
//{
////---------------------------------------------------------------------------
////---------------------------------------------------------------------------
//
////---------------------------------------------------------------------------
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_ptr_gray;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_ptr_u8c1;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_ptr_rgb;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_ptr_argb;
//typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_ptr_float;
//typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_ptr_double;
////---------------------------------------------------------------------------
//
////---------------------------------------------------------------------------
//} // h_lib or a_lib
////---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#endif