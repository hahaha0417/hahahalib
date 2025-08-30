//---------------------------------------------------------------------------

#ifndef hahaha_capture_desktop_gdiH
#define hahaha_capture_desktop_gdiH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_desktop_gdi
{
public:
	hahaha_capture_desktop_gdi();
	~hahaha_capture_desktop_gdi();

	hahaha_capture_desktop_gdi(const hahaha_capture_desktop_gdi& hcdg);
    hahaha_capture_desktop_gdi(hahaha_capture_desktop_gdi&& hcdg) noexcept;
	hahaha_capture_desktop_gdi& operator=(const hahaha_capture_desktop_gdi& hcdg);
	hahaha_capture_desktop_gdi& operator=(hahaha_capture_desktop_gdi&& hcdg) noexcept;
	void Copy(const hahaha_capture_desktop_gdi& hcdg);
    void Move(hahaha_capture_desktop_gdi&& hcdg) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
