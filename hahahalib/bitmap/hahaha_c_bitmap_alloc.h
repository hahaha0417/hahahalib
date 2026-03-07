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
template <typename T, int U>
class hahaha_c_bitmap_alloc : public hahaha_c_bitmap<T, U>
{
public:
	hahaha_c_bitmap_alloc();
	~hahaha_c_bitmap_alloc();

	hahaha_c_bitmap_alloc(const hahaha_c_bitmap_alloc& hcba);
    hahaha_c_bitmap_alloc(hahaha_c_bitmap_alloc&& hcba) noexcept;
	hahaha_c_bitmap_alloc& operator=(const hahaha_c_bitmap_alloc& hcba);
	hahaha_c_bitmap_alloc& operator=(hahaha_c_bitmap_alloc&& hcba) noexcept;
	virtual T*& operator[](const int& y);
    virtual T*& operator[](const int& y) const;
	void Copy(const hahaha_c_bitmap_alloc& hcba);
    void Move(hahaha_c_bitmap_alloc&& hcba) noexcept;
public:
	virtual int Reset();

public:
	virtual int Resize(const int& width, const int& height);
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
