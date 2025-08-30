//---------------------------------------------------------------------------

#ifndef hahaha_semaphoreH
#define hahaha_semaphoreH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_sync.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// https://learn.microsoft.com/en-us/windows/win32/sync/using-semaphore-objects
class hahaha_semaphore
{
public:
	hahaha_semaphore();
	~hahaha_semaphore();

	hahaha_semaphore(const hahaha_semaphore& ht);
    hahaha_semaphore(hahaha_semaphore&& ht) noexcept;
	hahaha_semaphore& operator=(const hahaha_semaphore& ht);
    hahaha_semaphore& operator=(hahaha_semaphore&& ht) noexcept;
	void Copy(const hahaha_semaphore& ht);
    void Move(hahaha_semaphore&& ht) noexcept;
public:
	int Reset();

	int Create(const std::wstring& name = L"",const int& count_initial = 4, const int& count_max = 4);
	int Close();



	hahaha_define_sync Lock(const DWORD& milliseconds = INFINITE);
	int Un_Lock();
public:
	HANDLE Semaphore_;
	std::wstring Name_;
	int Count_Initial_;
	int Count_Max_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
