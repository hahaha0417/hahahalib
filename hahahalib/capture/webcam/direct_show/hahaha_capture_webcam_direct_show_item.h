//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_direct_show_itemH
#define hahaha_capture_webcam_direct_show_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <Windows.h>
#include <vector>
#include <string>
#include <memory>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_capture_webcam_direct_show_item
{
public:
	hahaha_capture_webcam_direct_show_item();
	~hahaha_capture_webcam_direct_show_item();

	hahaha_capture_webcam_direct_show_item(const hahaha_capture_webcam_direct_show_item& hcwdsi);
    hahaha_capture_webcam_direct_show_item(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
	hahaha_capture_webcam_direct_show_item& operator=(const hahaha_capture_webcam_direct_show_item& hcwdsi);
	hahaha_capture_webcam_direct_show_item& operator=(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
	void Copy(const hahaha_capture_webcam_direct_show_item& hcwdsi);
    void Move(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept;
public:
	int Reset();
public:
public:
public:
public:
public:
public:
    int Fps_;
    int Width_;
    int Height_;
    int Bits_;
    GUID Sub_Type_;
    std::wstring Format_;
    std::wstring Description_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
