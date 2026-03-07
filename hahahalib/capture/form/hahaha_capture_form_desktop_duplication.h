//---------------------------------------------------------------------------

#ifndef hahaha_capture_form_desktop_duplicationH
#define hahaha_capture_form_desktop_duplicationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

#include <memory>
#include <windows.h>

#include "../desktop/hahaha_capture_desktop_desktop_duplication.h"

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

	struct hahaha_capture_form_desktop_duplication_options
	{
		HWND Window_ = nullptr;
		bool Client_Area_Only_ = true;
		bool Use_Window_Monitor_ = true;
		int Monitor_Index_ = 0;
		int Timeout_Ms_ = 0;
	};

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
