//---------------------------------------------------------------------------

#ifndef hahaha_thread_pool_command_commandH
#define hahaha_thread_pool_command_commandH
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
class hahaha_thread_pool_command_command
{

public:
    // 建構物件並初始化預設狀態。
    hahaha_thread_pool_command_command();
    // 解構物件並釋放相關資源。
    ~hahaha_thread_pool_command_command();

	// 以既有物件內容建構新的物件實例。
	hahaha_thread_pool_command_command(const hahaha_thread_pool_command_command& htpcc);
    // 以移動方式建構物件並接手既有資源。
    hahaha_thread_pool_command_command(hahaha_thread_pool_command_command&& htpcc) noexcept;
	// 複製指派目前物件內容。
	hahaha_thread_pool_command_command& operator=(const hahaha_thread_pool_command_command& htpcc);
    // 移動指派目前物件內容。
    hahaha_thread_pool_command_command& operator=(hahaha_thread_pool_command_command&& htpcc) noexcept;
    // 複製來源物件的內部狀態。
    void Copy(const hahaha_thread_pool_command_command& htpcc);
    // 接手來源物件的內部資源。
    void Move(hahaha_thread_pool_command_command&& htpcc) noexcept;
public:
	// 重設內部狀態。
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