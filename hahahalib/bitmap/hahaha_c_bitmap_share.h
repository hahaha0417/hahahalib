//---------------------------------------------------------------------------

#ifndef hahaha_c_bitmap_shareH
#define hahaha_c_bitmap_shareH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <stdlib.h>
#include <string>
#include <memory>
#include <windows.h>
//---------------------------------------------------------------------------
#include <bitmap\hahaha_c_bitmap.h>


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_memory_mapping;
//---------------------------------------------------------------------------
template <typename T, int U>
class hahaha_c_bitmap_share : public hahaha_c_bitmap<T, U>
{
public:
	// 以既有物件內容建構新的物件實例。
	hahaha_c_bitmap_share(const std::wstring& name_mapping, const int& width, const int& height);
	// 解構物件並釋放相關資源。
	~hahaha_c_bitmap_share();

	// 以既有物件內容建構新的物件實例。
	hahaha_c_bitmap_share(const hahaha_c_bitmap_share& hcbs);
    // 以移動方式建構物件並接手既有資源。
    hahaha_c_bitmap_share(hahaha_c_bitmap_share&& hcbs) noexcept;
	// 複製指派目前物件內容。
	hahaha_c_bitmap_share& operator=(const hahaha_c_bitmap_share& hcbs);
	// 移動指派目前物件內容。
	hahaha_c_bitmap_share& operator=(hahaha_c_bitmap_share&& hcbs) noexcept;
	// 依索引存取內部資料。
	virtual T*& operator[](const int& y);
    // 依索引存取內部資料。
    virtual T*& operator[](const int& y) const;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_c_bitmap_share& hcbs);
    // 接手來源物件的內部資源。
    void Move(hahaha_c_bitmap_share&& hcba) noexcept;
public:
	// 重設內部狀態。
	virtual int Reset();

public:
	// 依指定尺寸重新配置內部資料。
	virtual int Resize(const int& width, const int& height);
    // 清空目前資料內容。
    virtual int Clear();
public:
    std::wstring Name_Mapping_;
    std::unique_ptr<hahahalib::hahaha_memory_mapping> Memory_Mapping_;

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
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 1> bitmap_share_gray;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yuv422;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 3> bitmap_share_rgb;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 4> bitmap_share_argb;
typedef hahahalib::hahaha_c_bitmap_share<float, 1> bitmap_alloc_float;
typedef hahahalib::hahaha_c_bitmap_share<double, 1> bitmap_alloc_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yuy2;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_uyvy;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yvyu;


//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 1> bitmap_share_gray;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yuv422;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 3> bitmap_share_rgb;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 4> bitmap_share_argb;
typedef hahahalib::hahaha_c_bitmap_share<float, 1> bitmap_share_float;
typedef hahahalib::hahaha_c_bitmap_share<double, 1> bitmap_share_double;
//---------------------------------------------------------------------------
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yuy2;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_uyvy;
typedef hahahalib::hahaha_c_bitmap_share<unsigned char, 2> bitmap_share_yvyu;


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
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_share_gray;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 1> bitmap_share_u8c1;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 3> bitmap_share_rgb;
//typedef hahahalib::hahaha_c_bitmap<unsigned char, 4> bitmap_share_argb;
//typedef hahahalib::hahaha_c_bitmap<float, 1> bitmap_share_float;
//typedef hahahalib::hahaha_c_bitmap<double, 1> bitmap_share_double;
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