//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_commandH
#define hahaha_thread_pool_commandH
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

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_mutex;
class hahaha_thread_pool_command_command;
//---------------------------------------------------------------------------

class hahaha_thread_pool_command
{
public:
	hahaha_thread_pool_command();
	~hahaha_thread_pool_command();

	hahaha_thread_pool_command(const hahaha_thread_pool_command& htpc);
    hahaha_thread_pool_command(hahaha_thread_pool_command&& htpc) noexcept;
	hahaha_thread_pool_command& operator=(const hahaha_thread_pool_command& htpc);
	hahaha_thread_pool_command& operator=(hahaha_thread_pool_command&& htpc) noexcept;
	void Copy(const hahaha_thread_pool_command& htpc);
    void Move(hahaha_thread_pool_command&& htpc) noexcept;
public:
	int Reset();

public:
public:
	static DWORD WINAPI Thread_Start(void* parameter);
	virtual int Thread_Proc();
public:
	virtual int Handle(hahahalib::hahaha_thread_pool_command_command* p);
public:
	virtual int Create(const int& thread_count = 4);
	virtual int Close();
    virtual int Wait();
public:
    virtual int Add_Command();
    virtual int On_Command();
public:
//    危險，小心使用
	int Terminate();
public:
	std::vector<DWORD> Thread_Ids_;
	std::vector<HANDLE> Threads_;
    HANDLE Event_Run_;
    HANDLE Event_Wait_;
	HANDLE Event_Exit_;
public:
	std::queue<std::unique_ptr<hahaha_thread_pool_command_command>> Queue_Command_;
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
