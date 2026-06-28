//---------------------------------------------------------------------------

#ifndef hahaha_c_bitmap_allocH
#define hahaha_c_bitmap_allocH
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
// 擁有像素記憶體的 bitmap 實作。
// 與 hahaha_c_bitmap 的差別在於：這個類別會真的 new/delete 影像資料。
template <typename T, int U>
class hahaha_c_bitmap_alloc : public hahaha_c_bitmap<T, U>
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_c_bitmap_alloc();
	// 解構物件並釋放相關資源。
	~hahaha_c_bitmap_alloc();

	// 以既有物件內容建構新的物件實例。
	hahaha_c_bitmap_alloc(const hahaha_c_bitmap_alloc& hcba);
    // 以移動方式建構物件並接手既有資源。
    hahaha_c_bitmap_alloc(hahaha_c_bitmap_alloc&& hcba) noexcept;
	// 複製指派目前物件內容。
	hahaha_c_bitmap_alloc& operator=(const hahaha_c_bitmap_alloc& hcba);
	// 移動指派目前物件內容。
	hahaha_c_bitmap_alloc& operator=(hahaha_c_bitmap_alloc&& hcba) noexcept;
	// 依索引存取內部資料。
	virtual T*& operator[](const int& y);
    // 依索引存取內部資料。
    virtual T*& operator[](const int& y) const;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_c_bitmap_alloc& hcba);
    // 接手來源物件的內部資源。
    void Move(hahaha_c_bitmap_alloc&& hcba) noexcept;
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

// 常用配置型 bitmap 別名，通常是實際建立影像緩衝區時使用的型別。
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 1> bitmap_alloc_gray;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yuv422;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 3> bitmap_alloc_rgb;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 4> bitmap_alloc_argb;
typedef hahahalib::hahaha_c_bitmap_alloc<float, 1> bitmap_alloc_float;
typedef hahahalib::hahaha_c_bitmap_alloc<double, 1> bitmap_alloc_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yuy2;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_uyvy;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yvyu;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 1> bitmap_alloc_gray;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yuv422;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 3> bitmap_alloc_rgb;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 4> bitmap_alloc_argb;
typedef hahahalib::hahaha_c_bitmap_alloc<float, 1> bitmap_alloc_float;
typedef hahahalib::hahaha_c_bitmap_alloc<double, 1> bitmap_alloc_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yuy2;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_uyvy;
typedef hahahalib::hahaha_c_bitmap_alloc<unsigned char, 2> bitmap_alloc_yvyu;


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
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_alloc_gray;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_alloc_u8c1;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_alloc_rgb;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_alloc_argb;
//typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_alloc_float;
//typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_alloc_double;
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