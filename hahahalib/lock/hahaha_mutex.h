//---------------------------------------------------------------------------

#ifndef hahaha_mutexH
#define hahaha_mutexH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
//---------------------------------------------------------------------------
#include <define\hahaha_define_sync.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// https://learn.microsoft.com/en-us/windows/win32/sync/using-mutex-objects
class hahaha_mutex
{
public:
	hahaha_mutex();
	~hahaha_mutex();

	hahaha_mutex(const hahaha_mutex& hm);
    hahaha_mutex(hahaha_mutex&& hm) noexcept;
	hahaha_mutex& operator=(const hahaha_mutex& hm);
    hahaha_mutex& operator=(hahaha_mutex&& hm) noexcept;
	void Copy(const hahaha_mutex& hm);
    void Move(hahaha_mutex&& hm) noexcept;
public:
	int Reset();

	int Create(const std::wstring& name = L"", BOOL lock = FALSE);
	int Close();



	hahaha_define_sync Lock(const DWORD& milliseconds = INFINITE);
	int Un_Lock();
public:
	HANDLE Mutex_;
    std::wstring Name_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
