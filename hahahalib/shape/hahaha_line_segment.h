//---------------------------------------------------------------------------

#ifndef hahaha_line_segmentH
#define hahaha_line_segmentH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <shape\hahaha_point.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// chatGpt
// 線段 class
//-----------------------------
template <typename T>
class hahaha_line_segment
{
public:
	hahaha_line_segment(const hahahalib::hahaha_point<T>& p1,
        const hahahalib::hahaha_point<T>& p2
    );
	~hahaha_line_segment();

	hahaha_line_segment(const hahaha_line_segment& hls);
    hahaha_line_segment(hahaha_line_segment&& hls) noexcept;
	hahaha_line_segment& operator=(const hahaha_line_segment& hls);
    hahaha_line_segment& operator=(hahaha_line_segment&& hls) noexcept;
	void Copy(const hahaha_line_segment& hls);
    void Move(hahaha_line_segment&& hls) noexcept;
public:
	int Reset();

public:

public:
public:
    hahahalib::hahaha_point<T> P1_;
    hahahalib::hahaha_point<T> P2_;
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
typedef hahahalib::hahaha_line_segment<int> line_segment;
typedef hahahalib::hahaha_line_segment<float> line_segment_float;
typedef hahahalib::hahaha_line_segment<double> line_segment_double;
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
typedef hahahalib::hahaha_line_segment<int> line_segment;
typedef hahahalib::hahaha_line_segment<float> line_segment_float;
typedef hahahalib::hahaha_line_segment<double> line_segment_double;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

#endif
