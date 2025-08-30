//---------------------------------------------------------------------------

#ifndef hahaha_information_webcam_itemH
#define hahaha_information_webcam_itemH
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
class hahaha_information_webcam_item
{
public:
	hahaha_information_webcam_item();
	~hahaha_information_webcam_item();

	hahaha_information_webcam_item(const hahaha_information_webcam_item& hiwi);
    hahaha_information_webcam_item(hahaha_information_webcam_item&& hiwi) noexcept;
	hahaha_information_webcam_item& operator=(const hahaha_information_webcam_item& hiwi);
	hahaha_information_webcam_item& operator=(hahaha_information_webcam_item&& hiwi) noexcept;
	void Copy(const hahaha_information_webcam_item& hiwi);
    void Move(hahaha_information_webcam_item&& hiwi) noexcept;
public:
	int Reset();
public:
public:
public:
public:
public:
public:
    std::wstring Name_Device_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
