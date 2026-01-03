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
	bool Initialize();
	bool Start(const hahaha_capture_form_desktop_duplication_options& options = {});
	void Stop();
	bool Is_Capturing() const noexcept;
	bool Capture_Frame(hahaha_capture_desktop_desktop_duplication_frame& frame);
	RECT Get_Capture_Desktop_Rect() const noexcept;
	HWND Get_Window() const noexcept;

private:
	bool Update_Capture_Rect();

private:
	std::unique_ptr<hahaha_capture_desktop_desktop_duplication> Capture_;
	hahaha_capture_form_desktop_duplication_options Options_;
	RECT Capture_Desktop_Rect_{};

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
