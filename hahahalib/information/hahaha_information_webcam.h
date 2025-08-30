//---------------------------------------------------------------------------

#ifndef hahaha_information_webcamH
#define hahaha_information_webcamH
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
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_information_webcam_item;
//---------------------------------------------------------------------------
class hahaha_information_webcam
{
public:
	hahaha_information_webcam();
	~hahaha_information_webcam();

	hahaha_information_webcam(const hahaha_information_webcam& hiw);
    hahaha_information_webcam(hahaha_information_webcam&& hiw) noexcept;
	hahaha_information_webcam& operator=(const hahaha_information_webcam& hiw);
	hahaha_information_webcam& operator=(hahaha_information_webcam&& hiw) noexcept;
	void Copy(const hahaha_information_webcam& hiw);
    void Move(hahaha_information_webcam&& hiw) noexcept;
public:
	int Reset();

public:
    int Get_All();
public:
public:
public:
public:
    std::vector<hahaha_information_webcam_item> Webcams_;
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
