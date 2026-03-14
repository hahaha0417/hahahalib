//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_ui_message.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//#define MESSAGE_UI (WM_USER + 1000)
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
hahaha_ui_message::hahaha_ui_message()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_ui_message::~hahaha_ui_message()
{

}
//---------------------------------------------------------------------------
hahaha_ui_message::hahaha_ui_message(const hahaha_ui_message& hum)
{
    Reset();
	Copy(hum);
}
//---------------------------------------------------------------------------
hahaha_ui_message::hahaha_ui_message(hahaha_ui_message&& hum) noexcept
{
    Move(std::move(hum));
}
//---------------------------------------------------------------------------
hahaha_ui_message& hahaha_ui_message::operator=(const hahaha_ui_message& hum)
{
    Copy(hum);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_ui_message& hahaha_ui_message::operator=(hahaha_ui_message&& hum) noexcept
{
    if (this != &hum)
    {
        Move(std::move(hum));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_ui_message::Copy(const hahaha_ui_message& hum)
{
    Handle_ = hum.Handle_;
}
//---------------------------------------------------------------------------
void hahaha_ui_message::Move(hahaha_ui_message&& hum) noexcept
{
    Handle_ = hum.Handle_;

    hum.Reset();
}
//---------------------------------------------------------------------------
int hahaha_ui_message::Reset()
{
    Handle_ = NULL;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_ui_message::Send_Message(
    unsigned int message,
    int command,
    void* parameter
)
{
    SendMessageW(Handle_, message, (WPARAM)command, (LPARAM)parameter);

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_ui_message::Post_Message(
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