//---------------------------------------------------------------------------

#ifndef hahaha_capture_form_gdiH
#define hahaha_capture_form_gdiH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_form_gdi
{
public:
	hahaha_capture_form_gdi();
	~hahaha_capture_form_gdi();

	hahaha_capture_form_gdi(const hahaha_capture_form_gdi& hcfg);
    hahaha_capture_form_gdi(hahaha_capture_form_gdi&& hcfg) noexcept;
	hahaha_capture_form_gdi& operator=(const hahaha_capture_form_gdi& hcfg);
	hahaha_capture_form_gdi& operator=(hahaha_capture_form_gdi&& hcfg) noexcept;
	void Copy(const hahaha_capture_form_gdi& hcfg);
    void Move(hahaha_capture_form_gdi&& hcfg) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
