//---------------------------------------------------------------------------

#ifndef hahaha_thread_command_commandH
#define hahaha_thread_command_commandH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include <vector>
#include <memory>
#include <queue>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//https://learn.microsoft.com/en-us/windows/win32/sync/using-event-objects
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_mutex;
//---------------------------------------------------------------------------
class hahaha_thread_command_command
{

public:
    hahaha_thread_command_command();
    ~hahaha_thread_command_command();

	hahaha_thread_command_command(const hahaha_thread_command_command& htcc);
    hahaha_thread_command_command(hahaha_thread_command_command&& htcc) noexcept;
	hahaha_thread_command_command& operator=(const hahaha_thread_command_command& htcc);
    hahaha_thread_command_command& operator=(hahaha_thread_command_command&& htcc) noexcept;
    void Copy(const hahaha_thread_command_command& htcc);
    void Move(hahaha_thread_command_command&& htcc) noexcept;
public:
	virtual int Reset();
public:
    int Command_;
    void* Parameter_;
};
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
