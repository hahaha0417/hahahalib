//---------------------------------------------------------------------------

#ifndef hahaha_rectangleH
#define hahaha_rectangleH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
template <typename T>
class hahaha_rectangle
{
public:
	hahaha_rectangle();
    hahaha_rectangle(
        const T& x1,
        const T& y1,
        const T& x2,
        const T& y2,
    	bool normalize = false
    );
	~hahaha_rectangle();

	hahaha_rectangle(const hahaha_rectangle<T>& hr);
    hahaha_rectangle(hahaha_rectangle<T>&& hr) noexcept;
	hahaha_rectangle& operator=(const hahaha_rectangle<T>& hr);
    hahaha_rectangle& operator=(hahaha_rectangle<T>&& hr) noexcept;
	void Copy(const hahaha_rectangle<T>& hr);
    void Move(hahaha_rectangle<T>&& hr) noexcept;
public:
	int Reset();
public:
	T Width();
	T Height();
	T Width() const;
	T Height() const;

public:
    T X1_;
    T Y1_;
    T X2_;
    T Y2_;
public:
    void Normalize();
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
typedef hahahalib::hahaha_rectangle<int> rectangle;
typedef hahahalib::hahaha_rectangle<float> rectangle_float;
typedef hahahalib::hahaha_rectangle<double> rectangle_double;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef hahahalib::hahaha_rectangle<int> rect;
typedef hahahalib::hahaha_rectangle<float> rect_float;
typedef hahahalib::hahaha_rectangle<double> rect_double;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

#endif
