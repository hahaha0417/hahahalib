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
	// 建構物件並初始化預設狀態。
	hahaha_semaphore();
	// 解構物件並釋放相關資源。
	~hahaha_semaphore();

	// 以既有物件內容建構新的物件實例。
	hahaha_semaphore(const hahaha_semaphore& ht);
    // 以移動方式建構物件並接手既有資源。
    hahaha_semaphore(hahaha_semaphore&& ht) noexcept;
	// 複製指派目前物件內容。
	hahaha_semaphore& operator=(const hahaha_semaphore& ht);
    // 移動指派目前物件內容。
    hahaha_semaphore& operator=(hahaha_semaphore&& ht) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_semaphore& ht);
    // 接手來源物件的內部資源。
    void Move(hahaha_semaphore&& ht) noexcept;
public:
	// 重設內部狀態。
	int Reset();

	// 建立所需資源並完成初始化。
	int Create(const std::wstring& name = L"",const int& count_initial = 4, const int& count_max = 4);
	// 關閉並釋放目前持有的資源。
	int Close();



	// 取得同步鎖或等待資源可用。
	hahaha_define_sync Lock(const DWORD& milliseconds = INFINITE);
	// 釋放同步鎖或歸還資源。
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
