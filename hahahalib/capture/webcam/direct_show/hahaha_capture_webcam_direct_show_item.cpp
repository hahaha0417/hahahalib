//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <dshow.h>
//---------------------------------------------------------------------------
#include "hahaha_capture_webcam_direct_show_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item::hahaha_capture_webcam_direct_show_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item::~hahaha_capture_webcam_direct_show_item()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item::hahaha_capture_webcam_direct_show_item(const hahaha_capture_webcam_direct_show_item& hcwdsi)
{
    Reset();
	Copy(hcwdsi);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item::hahaha_capture_webcam_direct_show_item(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept
{
    Move(std::move(hcwdsi));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item& hahaha_capture_webcam_direct_show_item::operator=(const hahaha_capture_webcam_direct_show_item& hcwdsi)
{
	Copy(hcwdsi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_item& hahaha_capture_webcam_direct_show_item::operator=(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept
{
	if (this != &hcwdsi)
    {
        Move(std::move(hcwdsi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_item::Copy(const hahaha_capture_webcam_direct_show_item& hcwdsi)
{
    Fps_ = hcwdsi.Fps_;
    Width_ = hcwdsi.Width_;
    Height_ = hcwdsi.Height_;
    Bits_ = hcwdsi.Bits_;
    Sub_Type_ = hcwdsi.Sub_Type_;
    Format_ = hcwdsi.Format_;
    Description_ = hcwdsi.Description_;

}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_item::Move(hahaha_capture_webcam_direct_show_item&& hcwdsi) noexcept
{
    Fps_ = hcwdsi.Fps_;
    Width_ = hcwdsi.Width_;
    Height_ = hcwdsi.Height_;
    Bits_ = hcwdsi.Bits_;
    Sub_Type_ = hcwdsi.Sub_Type_;
    Format_ = hcwdsi.Format_;
    Description_ = hcwdsi.Description_;

    // 這不能設，sort會出問題
    //hcwdsi.Reset();
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_item::Reset()
{
    Fps_ = 0;
    Width_ = 0;
    Height_ = 0;
    Bits_ = 0;
    Sub_Type_ = MEDIASUBTYPE_YUY2;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------