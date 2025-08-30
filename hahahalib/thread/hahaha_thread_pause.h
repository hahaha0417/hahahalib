//---------------------------------------------------------------------------

#ifndef hahaha_thread_pauseH
#define hahaha_thread_pauseH
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
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pause
{
public:
	hahaha_thread_pause();
	~hahaha_thread_pause();

	hahaha_thread_pause(const hahaha_thread_pause& htp);
    hahaha_thread_pause(hahaha_thread_pause&& htp) noexcept;
	hahaha_thread_pause& operator=(const hahaha_thread_pause& htp);
	hahaha_thread_pause& operator=(hahaha_thread_pause&& htp) noexcept;
	void Copy(const hahaha_thread_pause& htp);
    void Move(hahaha_thread_pause&& htp) noexcept;
public:
	virtual int Reset();
public:
	static DWORD WINAPI Thread_Start(void* parameter);
	virtual int Thread_Proc();
public:
	virtual int Handle();
public:
	virtual int Create();
	virtual int Close();
    virtual int Wait();
public:
    virtual int Enabled();
    virtual int Disabled();
public:
//    危險，小心使用
	virtual int Terminate();
public:
	DWORD Thread_Id_;
	HANDLE Thread_;
    HANDLE Event_Run_;
    HANDLE Event_Wait_;
	HANDLE Event_Exit_;
public:
    bool Is_Close_;
public:
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
