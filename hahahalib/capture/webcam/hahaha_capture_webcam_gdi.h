//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_gdiH
#define hahaha_capture_webcam_gdiH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_webcam_gdi
{
public:
	hahaha_capture_webcam_gdi();
	~hahaha_capture_webcam_gdi();

	hahaha_capture_webcam_gdi(const hahaha_capture_webcam_gdi& hcwg);
    hahaha_capture_webcam_gdi(hahaha_capture_webcam_gdi&& hcwg) noexcept;
	hahaha_capture_webcam_gdi& operator=(const hahaha_capture_webcam_gdi& hcwg);
	hahaha_capture_webcam_gdi& operator=(hahaha_capture_webcam_gdi&& hcwg) noexcept;
	void Copy(const hahaha_capture_webcam_gdi& hcwg);
    void Move(hahaha_capture_webcam_gdi&& hcwg) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
