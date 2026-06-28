//---------------------------------------------------------------------------

#ifndef hahaha_c_bitmapH
#define hahaha_c_bitmapH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <stdlib.h>
//---------------------------------------------------------------------------
#include <bitmap\base\hahaha_bitmap.h>


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// 影像像素容器的模板基底。
// T 代表單一通道型別，U 代表通道數；此類別只描述資料指標結構，不決定是否擁有記憶體。
template <typename T, int U>
class hahaha_c_bitmap : public hahaha_bitmap
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_c_bitmap();
	// 解構物件並釋放相關資源。
	virtual ~hahaha_c_bitmap();

	// 以既有物件內容建構新的物件實例。
	hahaha_c_bitmap(const hahaha_c_bitmap& hcb);
    // 以移動方式建構物件並接手既有資源。
    hahaha_c_bitmap(hahaha_c_bitmap&& hcb) noexcept;
	// 複製指派目前物件內容。
	hahaha_c_bitmap& operator=(const hahaha_c_bitmap& hcb);
	// 移動指派目前物件內容。
	hahaha_c_bitmap& operator=(hahaha_c_bitmap&& hcb) noexcept;
	// 依索引存取內部資料。
	virtual T*& operator[](const int& y);
    // 依索引存取內部資料。
    virtual T*& operator[](const int& y) const;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_c_bitmap& hcb);
    // 接手來源物件的內部資源。
    void Move(hahaha_c_bitmap&& hcb) noexcept;
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
	// Image_Ptr_ 指向連續像素資料區塊；
	// Image_Scanline_ 提供每列快速索引，方便用 bitmap[y][x] 類似方式存取。
	T* Image_Ptr_;
	T** Image_Scanline_;

public:

};

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

// 常用像素格式別名，降低模板型別在呼叫端的使用成本。
typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_gray;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yuv422;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_rgb;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_argb;
typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_float;
typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yuy2;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_uyvy;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yvyu;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_gray;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yuv422;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_rgb;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_argb;
typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_float;
typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_double;

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yuy2;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_uyvy;
typedef hahahalib::hahaha_c_bitmap<unsigned char, 2> bitmap_yvyu;

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
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_gray;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_u8c1;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_rgb;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_argb;
//typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_float;
//typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_double;
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