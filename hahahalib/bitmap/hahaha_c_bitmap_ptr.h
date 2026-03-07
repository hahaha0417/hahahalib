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
	hahaha_c_bitmap_ptr(T* image_ptr);
	~hahaha_c_bitmap_ptr();

	hahaha_c_bitmap_ptr(const hahaha_c_bitmap_ptr& hcbp);
    hahaha_c_bitmap_ptr(hahaha_c_bitmap_ptr&& hcbp) noexcept;
	hahaha_c_bitmap_ptr& operator=(const hahaha_c_bitmap_ptr& hcbp);
	hahaha_c_bitmap_ptr& operator=(hahaha_c_bitmap_ptr&& hcbp) noexcept;
	virtual T*& operator[](const int& y);
    virtual T*& operator[](const int& y) const;
	void Copy(const hahaha_c_bitmap_ptr& hcbp);
	void Move(hahaha_c_bitmap_ptr&& hcbp) noexcept;
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
