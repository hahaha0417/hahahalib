//---------------------------------------------------------------------------

#ifndef hahaha_capture_desktop_desktop_duplicationH
#define hahaha_capture_desktop_desktop_duplicationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_desktop_desktop_duplication
{
public:
	hahaha_capture_desktop_desktop_duplication();
	~hahaha_capture_desktop_desktop_duplication();

	hahaha_capture_desktop_desktop_duplication(const hahaha_capture_desktop_desktop_duplication& hcddd);
    hahaha_capture_desktop_desktop_duplication(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
	hahaha_capture_desktop_desktop_duplication& operator=(const hahaha_capture_desktop_desktop_duplication& hcddd);
	hahaha_capture_desktop_desktop_duplication& operator=(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
	void Copy(const hahaha_capture_desktop_desktop_duplication& hcddd);
    void Move(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
public:
	int Reset();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
