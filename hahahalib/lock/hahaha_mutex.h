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
	// 建構物件並初始化預設狀態。
	hahaha_mutex();
	// 解構物件並釋放相關資源。
	~hahaha_mutex();

	// 以既有物件內容建構新的物件實例。
	hahaha_mutex(const hahaha_mutex& hm);
    // 以移動方式建構物件並接手既有資源。
    hahaha_mutex(hahaha_mutex&& hm) noexcept;
	// 複製指派目前物件內容。
	hahaha_mutex& operator=(const hahaha_mutex& hm);
    // 移動指派目前物件內容。
    hahaha_mutex& operator=(hahaha_mutex&& hm) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_mutex& hm);
    // 接手來源物件的內部資源。
    void Move(hahaha_mutex&& hm) noexcept;
public:
	// 重設內部狀態。
	int Reset();

	// 建立所需資源並完成初始化。
	int Create(const std::wstring& name = L"", BOOL lock = FALSE);
	// 關閉並釋放目前持有的資源。
	int Close();



	// 取得同步鎖或等待資源可用。
	hahaha_define_sync Lock(const DWORD& milliseconds = INFINITE);
	// 釋放同步鎖或歸還資源。
	int Un_Lock();
public:
	HANDLE Mutex_;
    std::wstring Name_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------




#endif
