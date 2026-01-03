//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <windows.h>
//---------------------------------------------------------------------------
#include "hahaha_capture_form_desktop_duplication.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

namespace
{
	bool GetClientRectOnDesktop(HWND hwnd, RECT& rect) noexcept
	{
		if (!hwnd)
		{
			rect = RECT{};
			return false;
		}

		RECT client{};
		if (!::GetClientRect(hwnd, &client))
		{
			rect = RECT{};
			return false;
		}

		POINT topLeft{ client.left, client.top };
		POINT bottomRight{ client.right, client.bottom };
		if (!::ClientToScreen(hwnd, &topLeft) || !::ClientToScreen(hwnd, &bottomRight))
		{
			rect = RECT{};
			return false;
		}

		rect.left = topLeft.x;
		rect.top = topLeft.y;
		rect.right = bottomRight.x;
		rect.bottom = bottomRight.y;
		return true;
	}
}

//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::~hahaha_capture_form_desktop_duplication()
{
	Stop();
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication(const hahaha_capture_form_desktop_duplication& hcfdd)
{
    Reset();
	Copy(hcfdd);
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication::hahaha_capture_form_desktop_duplication(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{
    Move(std::move(hcfdd));
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication& hahaha_capture_form_desktop_duplication::operator=(const hahaha_capture_form_desktop_duplication& hcfdd)
{
	if (this == &hcfdd)
	{
		return *this;
	}

	Reset();
	Copy(hcfdd);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_form_desktop_duplication& hahaha_capture_form_desktop_duplication::operator=(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{
	if (this != &hcfdd)
    {
		Reset();
        Move(std::move(hcfdd));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Copy(const hahaha_capture_form_desktop_duplication& hcfdd)
{
	Options_ = hcfdd.Options_;
	Capture_Desktop_Rect_ = hcfdd.Capture_Desktop_Rect_;

	if (hcfdd.Capture_)
	{
		Capture_ = std::make_unique<hahaha_capture_desktop_desktop_duplication>();
	}
	else
	{
		Capture_.reset();
	}
}
//---------------------------------------------------------------------------
void hahaha_capture_form_desktop_duplication::Move(hahaha_capture_form_desktop_duplication&& hcfdd) noexcept
{
	if (this == &hcfdd)
	{
		return;
	}

	Options_ = hcfdd.Options_;
	Capture_Desktop_Rect_ = hcfdd.Capture_Desktop_Rect_;
	Capture_ = std::move(hcfdd.Capture_);

	hcfdd.Options_ = {};
	hcfdd.Capture_Desktop_Rect_ = {};
}
//---------------------------------------------------------------------------
int hahaha_capture_form_desktop_duplication::Reset()
{
	Stop();
	Options_ = {};
	Capture_Desktop_Rect_ = {};

	return 0;
}
//---------------------------------------------------------------------------

bool hahaha_capture_form_desktop_duplication::Initialize()
{
	if (!Capture_)
	{
		Capture_ = std::make_unique<hahaha_capture_desktop_desktop_duplication>();
	}
	return Capture_->Initialize();
}

bool hahaha_capture_form_desktop_duplication::Start(const hahaha_capture_form_desktop_duplication_options& options)
{
	Options_ = options;
	if (!Options_.Window_)
	{
		return false;
	}

	if (!Initialize())
	{
		return false;
	}

	if (!Update_Capture_Rect())
	{
		return false;
	}

	if (Options_.Use_Window_Monitor_)
	{
		const HMONITOR monitor_ = ::MonitorFromWindow(Options_.Window_, MONITOR_DEFAULTTONEAREST);
		return monitor_ ? Capture_->Start_By_Monitor(monitor_, Options_.Timeout_Ms_) : false;
	}

	hahaha_capture_desktop_desktop_duplication_options desktop_options_{};
	desktop_options_.Monitor_Index_ = Options_.Monitor_Index_;
	desktop_options_.Timeout_Ms_ = Options_.Timeout_Ms_;
	return Capture_->Start(desktop_options_);
}

void hahaha_capture_form_desktop_duplication::Stop()
{
	if (Capture_)
	{
		Capture_->Stop();
	}
}

bool hahaha_capture_form_desktop_duplication::Is_Capturing() const noexcept
{
	return Capture_ ? Capture_->Is_Capturing() : false;
}

bool hahaha_capture_form_desktop_duplication::Capture_Frame(hahaha_capture_desktop_desktop_duplication_frame& frame)
{
	if (!Capture_ || !Capture_->Is_Capturing())
	{
		return false;
	}

	if (!Update_Capture_Rect())
	{
		return false;
	}

	return Capture_->Capture_Region(Capture_Desktop_Rect_, frame);
}

RECT hahaha_capture_form_desktop_duplication::Get_Capture_Desktop_Rect() const noexcept
{
	return Capture_Desktop_Rect_;
}

HWND hahaha_capture_form_desktop_duplication::Get_Window() const noexcept
{
	return Options_.Window_;
}

bool hahaha_capture_form_desktop_duplication::Update_Capture_Rect()
{
	if (!Options_.Window_)
	{
		Capture_Desktop_Rect_ = {};
		return false;
	}

	RECT rect{};
	if (Options_.Client_Area_Only_)
	{
		if (!GetClientRectOnDesktop(Options_.Window_, rect))
		{
			Capture_Desktop_Rect_ = {};
			return false;
		}
	}
	else
	{
		if (!::GetWindowRect(Options_.Window_, &rect))
		{
			Capture_Desktop_Rect_ = {};
			return false;
		}
	}

	if (rect.left >= rect.right || rect.top >= rect.bottom)
	{
		Capture_Desktop_Rect_ = {};
		return false;
	}

	Capture_Desktop_Rect_ = rect;
	return true;
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
