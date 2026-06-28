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
	// 以既有物件內容建構新的物件實例。
	hahaha_line_segment(const hahahalib::hahaha_point<T>& p1,
        const hahahalib::hahaha_point<T>& p2
    );
	// 解構物件並釋放相關資源。
	~hahaha_line_segment();

	// 以既有物件內容建構新的物件實例。
	hahaha_line_segment(const hahaha_line_segment& hls);
    // 以移動方式建構物件並接手既有資源。
    hahaha_line_segment(hahaha_line_segment&& hls) noexcept;
	// 複製指派目前物件內容。
	hahaha_line_segment& operator=(const hahaha_line_segment& hls);
    // 移動指派目前物件內容。
    hahaha_line_segment& operator=(hahaha_line_segment&& hls) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_line_segment& hls);
    // 接手來源物件的內部資源。
    void Move(hahaha_line_segment&& hls) noexcept;
public:
	// 重設內部狀態。
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