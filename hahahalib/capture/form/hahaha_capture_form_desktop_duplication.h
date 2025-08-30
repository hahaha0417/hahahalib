//---------------------------------------------------------------------------

#ifndef hahaha_capture_form_desktop_duplicationH
#define hahaha_capture_form_desktop_duplicationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_form_desktop_duplication
{
public:
	hahaha_capture_form_desktop_duplication();
	~hahaha_capture_form_desktop_duplication();

	hahaha_capture_form_desktop_duplication(const hahaha_capture_form_desktop_duplication& hcfdd);
    hahaha_capture_form_desktop_duplication(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept;
	hahaha_capture_form_desktop_duplication& operator=(const hahaha_capture_form_desktop_duplication& hcfdd);
	hahaha_capture_form_desktop_duplication& operator=(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept;
	void Copy(const hahaha_capture_form_desktop_duplication& hcfdd);
    void Move(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
