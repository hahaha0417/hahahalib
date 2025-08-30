//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_ui_messenge.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//#define MESSAGE_UI (WM_USER + 1000)
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
hahaha_ui_messenge::hahaha_ui_messenge()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_ui_messenge::~hahaha_ui_messenge()
{

}
//---------------------------------------------------------------------------
hahaha_ui_messenge::hahaha_ui_messenge(const hahaha_ui_messenge& hum)
{
    Reset();
	Copy(hum);
}
//---------------------------------------------------------------------------
hahaha_ui_messenge::hahaha_ui_messenge(hahaha_ui_messenge&& hum) noexcept
{
    Move(std::move(hum));
}
//---------------------------------------------------------------------------
hahaha_ui_messenge& hahaha_ui_messenge::operator=(const hahaha_ui_messenge& hum)
{
    Copy(hum);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_ui_messenge& hahaha_ui_messenge::operator=(hahaha_ui_messenge&& hum) noexcept
{
    if (this != &hum)
    {
        Move(std::move(hum));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_ui_messenge::Copy(const hahaha_ui_messenge& hum)
{
    Handle_ = hum.Handle_;
}
//---------------------------------------------------------------------------
void hahaha_ui_messenge::Move(hahaha_ui_messenge&& hum) noexcept
{
    Handle_ = hum.Handle_;

    hum.Reset();
}
//---------------------------------------------------------------------------
int hahaha_ui_messenge::Reset()
{
    Handle_ = NULL;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_ui_messenge::Send_Message(
    unsigned int message,
    int command,
    void* parameter
)
{
    SendMessageW(Handle_, message, (WPARAM)command, (LPARAM)parameter);

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_ui_messenge::Post_Message(
    unsigned int message,
    int command,
    void* parameter
)
{
    PostMessageW(Handle_, message, (WPARAM)command, (LPARAM)parameter);

    return 0;
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------