//---------------------------------------------------------------------------

#pragma hdrstop

#include <lock\hahaha_mutex.h>

#include "hahaha_thread_command_command.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_command_command::hahaha_thread_command_command()
{
    Reset();

}

//---------------------------------------------------------------------------
hahaha_thread_command_command::~hahaha_thread_command_command()
{

}

//---------------------------------------------------------------------------

hahaha_thread_command_command::hahaha_thread_command_command(const hahaha_thread_command_command& htcc)
{
    Reset();

	Copy(htcc);
}
//---------------------------------------------------------------------------
hahaha_thread_command_command::hahaha_thread_command_command(hahaha_thread_command_command&& htcc) noexcept
{
    Move(std::move(htcc));
}

//---------------------------------------------------------------------------
hahaha_thread_command_command& hahaha_thread_command_command::operator=(const hahaha_thread_command_command& htcc)
{
    Copy(htcc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_command& hahaha_thread_command_command::operator=(hahaha_thread_command_command&& htcc) noexcept
{
    if (this != &htcc)
    {
        Move(std::move(htcc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_command::Copy(const hahaha_thread_command_command& htcc)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_command::Move(hahaha_thread_command_command&& htcc) noexcept
{
    Command_ = htcc.Command_;
    Parameter_ = htcc.Parameter_;

    htcc.Reset();
}
//---------------------------------------------------------------------------
int hahaha_thread_command_command::Reset()
{
    Command_ = -999999;
    Parameter_ = nullptr;


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------