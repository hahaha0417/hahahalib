//---------------------------------------------------------------------------

#ifndef hahaha_thread_poolH
#define hahaha_thread_poolH
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
//https://learn.microsoft.com/en-us/windows/win32/procthread/thread-pool-api
//https://www.cnblogs.com/Super-biscuits/p/16199336.html
//https://blog.csdn.net/baidu_16370559/article/details/126954011 * 有空再做其他款
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_thread_pool
{
public:
	hahaha_thread_pool();
	~hahaha_thread_pool();

	hahaha_thread_pool(const hahaha_thread_pool& htp);
    hahaha_thread_pool(hahaha_thread_pool&& htp) noexcept;
	hahaha_thread_pool& operator=(const hahaha_thread_pool& htp);
    hahaha_thread_pool& operator=(hahaha_thread_pool&& htp) noexcept;
	void Copy(const hahaha_thread_pool& htp);
    void Move(hahaha_thread_pool&& htp) noexcept;
public:
	int Reset();
public:
	int Create(const DWORD& thread_max = 4, const DWORD& thread_min = 1);
	int Close();
	BOOL Is_Open();
public:
	static void WINAPI CallBack_Task(PTP_CALLBACK_INSTANCE instance, PVOID parameter);
	int Add_Task();
	virtual int Handle();
public:

public:
	// 線程池
	PTP_POOL Thread_Pool_;
	TP_CALLBACK_ENVIRON Thread_Pool_Environment_;
	DWORD Thread_Max_;
	DWORD Thread_Min_;
	BOOL Is_Open_;




};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
