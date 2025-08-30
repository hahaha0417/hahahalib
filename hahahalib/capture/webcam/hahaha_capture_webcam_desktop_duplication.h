//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_desktop_duplicationH
#define hahaha_capture_webcam_desktop_duplicationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_webcam_desktop_duplication
{
public:
	hahaha_capture_webcam_desktop_duplication();
	~hahaha_capture_webcam_desktop_duplication();

	hahaha_capture_webcam_desktop_duplication(const hahaha_capture_webcam_desktop_duplication& hcwdd);
    hahaha_capture_webcam_desktop_duplication(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept;
	hahaha_capture_webcam_desktop_duplication& operator=(const hahaha_capture_webcam_desktop_duplication& hcwdd);
	hahaha_capture_webcam_desktop_duplication& operator=(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept;
	void Copy(const hahaha_capture_webcam_desktop_duplication& hcwdd);
    void Move(hahaha_capture_webcam_desktop_duplication&& hcwdd) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
