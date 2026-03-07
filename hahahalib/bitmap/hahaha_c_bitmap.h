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
template <typename T, int U>
class hahaha_c_bitmap : public hahaha_bitmap
{
public:
	hahaha_c_bitmap();
	virtual ~hahaha_c_bitmap();

	hahaha_c_bitmap(const hahaha_c_bitmap& hcb);
    hahaha_c_bitmap(hahaha_c_bitmap&& hcb) noexcept;
	hahaha_c_bitmap& operator=(const hahaha_c_bitmap& hcb);
	hahaha_c_bitmap& operator=(hahaha_c_bitmap&& hcb) noexcept;
	virtual T*& operator[](const int& y);
    virtual T*& operator[](const int& y) const;
	void Copy(const hahaha_c_bitmap& hcb);
    void Move(hahaha_c_bitmap&& hcb) noexcept;
public:
	virtual int Reset();

public:
	virtual int Resize(const int& width, const int& height);
    virtual int Clear();

public:

public:

public:
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
