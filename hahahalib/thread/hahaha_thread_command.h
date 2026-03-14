//---------------------------------------------------------------------------

#ifndef hahaha_thread_commandH
#define hahaha_thread_commandH
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
class hahaha_thread_command_command;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

class hahaha_thread_command
{
public:
	hahaha_thread_command();
	~hahaha_thread_command();

	hahaha_thread_command(const hahaha_thread_command& htc);
    hahaha_thread_command(hahaha_thread_command&& htc) noexcept;
	hahaha_thread_command& operator=(const hahaha_thread_command& htc);
    hahaha_thread_command& operator=(hahaha_thread_command&& htc) noexcept;
	void Copy(const hahaha_thread_command& htc);
    void Move(hahaha_thread_command&& htc) noexcept;
public:
	virtual int Reset();
public:
	static DWORD WINAPI Thread_Start(void* parameter);
	virtual int Thread_Proc();
public:
	virtual int Handle(std::unique_ptr<hahahalib::hahaha_thread_command_command>& command);

public:
	virtual int Create();
	virtual int Close();
    virtual int Wait();
public:
    virtual int Add_Command();
    virtual int On_Command();
public:
//    危險，小心使用
	int Terminate();
public:
	DWORD Thread_Id_;
	HANDLE Thread_;
    HANDLE Event_Run_;
    HANDLE Event_Wait_;
	HANDLE Event_Exit_;
public:
	std::queue<std::unique_ptr<hahahalib::hahaha_thread_command_command>> Queue_Command_;
    std::unique_ptr<hahaha_mutex> Mutex_;
public:
public:
    bool Is_Close_;
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
