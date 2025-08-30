//---------------------------------------------------------------------------

#pragma hdrstop

#include <lock\hahaha_mutex.h>

#include "hahaha_thread_pool_command_command.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_pool_command_command::hahaha_thread_pool_command_command()
{
    Reset();

}

//---------------------------------------------------------------------------
hahaha_thread_pool_command_command::~hahaha_thread_pool_command_command()
{

}

//---------------------------------------------------------------------------

hahaha_thread_pool_command_command::hahaha_thread_pool_command_command(const hahaha_thread_pool_command_command& htpcc)
{
    Reset();

	Copy(htpcc);
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command_command::hahaha_thread_pool_command_command(hahaha_thread_pool_command_command&& htpcc) noexcept
{
    Move(std::move(htpcc));
}

//---------------------------------------------------------------------------
hahaha_thread_pool_command_command& hahaha_thread_pool_command_command::operator=(const hahaha_thread_pool_command_command& htpcc)
{
    Copy(htpcc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command_command& hahaha_thread_pool_command_command::operator=(hahaha_thread_pool_command_command&& htpcc) noexcept
{
    if (this != &htpcc)
    {
        Move(std::move(htpcc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_command_command::Copy(const hahaha_thread_pool_command_command& htpcc)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_pool_command_command::Move(hahaha_thread_pool_command_command&& htpcc) noexcept
{
    Command_ = htpcc.Command_;
    Parameter_ = htpcc.Parameter_;

    htpcc.Reset();
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command_command::Reset()
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