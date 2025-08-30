//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_process.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//https://learn.microsoft.com/zh-tw/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa
#define MAX_LENGTH 767
//---------------------------------------------------------------------------
//#include <process\hahaha_process.h>
//hahahalib::hahaha_process process_;
//process_.Create(L"C:\\Windows\\system32\\mspaint.exe");
//process_.Wait();


//---------------------------------------------------------------------------
hahaha_process::hahaha_process()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_process::~hahaha_process()
{
    Close();
}
//---------------------------------------------------------------------------
hahaha_process::hahaha_process(const hahaha_process& hp)
{
	Reset();
	Copy(hp);
}
//---------------------------------------------------------------------------
hahaha_process::hahaha_process(hahaha_process&& hp)
{
	Move(std::move(hp));

}
//---------------------------------------------------------------------------
hahaha_process& hahaha_process::operator=(const hahaha_process& hp)
{
	Copy(hp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_process& hahaha_process::operator=(hahaha_process&& hp)
{
	if (this != &hp)
    {
        Move(std::move(hp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_process::Copy(const hahaha_process& hp)
{

}
//---------------------------------------------------------------------------
void hahaha_process::Move(hahaha_process&& hp)
{
    Start_Up_Info_ = std::move(hp.Start_Up_Info_);
	Process_Information_ = std::move(hp.Process_Information_);
    Command_Line_ = std::move(hp.Command_Line_);

}
//---------------------------------------------------------------------------
int hahaha_process::Reset()
{
	if(Start_Up_Info_.get() == NULL)
	{
		Start_Up_Info_.reset(new STARTUPINFO);
	}

	if(Process_Information_.get() == NULL)
	{
		Process_Information_.reset(new PROCESS_INFORMATION);
	}

	ZeroMemory(Start_Up_Info_.get(), sizeof(*Start_Up_Info_.get()));
	Start_Up_Info_->cb = sizeof(*Start_Up_Info_.get());
	ZeroMemory(Process_Information_.get(), sizeof(*Process_Information_.get()));


	return 0;
}
//---------------------------------------------------------------------------
int hahaha_process::Create(const std::wstring& command_line)
{
	Command_Line_ = command_line;

	// Start the child process.
	if( !CreateProcessW( NULL,   // No module name (use command line)
		(wchar_t*)Command_Line_.c_str(),        // Command line
        NULL,           // Process handle not inheritable
        NULL,           // Thread handle not inheritable
        FALSE,          // Set handle inheritance to FALSE
        0,              // No creation flags
        NULL,           // Use parent's environment block
        NULL,           // Use parent's starting directory
		(LPSTARTUPINFOW)&*Start_Up_Info_.get(),            // Pointer to STARTUPINFO structure
		(LPPROCESS_INFORMATION)&*Process_Information_.get()           // Pointer to PROCESS_INFORMATION structure
	))
	{
		Command_Line_ = L"";
		OutputDebugStringW(std::to_wstring(GetLastError()).c_str());
		return -1;
	}

	return 0;
}
//---------------------------------------------------------------------------
// 這不會關閉
int hahaha_process::Close()
{
	CloseHandle(Process_Information_->hProcess);
	CloseHandle(Process_Information_->hThread);

	ZeroMemory(Start_Up_Info_.get(), sizeof(*Start_Up_Info_.get()));
	Start_Up_Info_->cb = sizeof(*Start_Up_Info_.get());
	ZeroMemory(Process_Information_.get(), sizeof(*Process_Information_.get()));

	return 0;
}
//---------------------------------------------------------------------------
// 關閉要用這個
int hahaha_process::Terminate()
{
//	https://blog.csdn.net/bzhxuexi/article/details/23950701
//	终止子进程
	TerminateProcess(Process_Information_->hProcess, 300);

    CloseHandle(Process_Information_->hProcess);
	CloseHandle(Process_Information_->hThread);

	ZeroMemory(Start_Up_Info_.get(), sizeof(*Start_Up_Info_.get()));
	Start_Up_Info_->cb = sizeof(*Start_Up_Info_.get());
	ZeroMemory(Process_Information_.get(), sizeof(*Process_Information_.get()));

    return 0;
}
//---------------------------------------------------------------------------
hahaha_define_sync hahaha_process::Wait(const DWORD& milliseconds)
{
	DWORD result = WaitForSingleObject(
		Process_Information_->hProcess,    // handle to mutex
		milliseconds
	);  // no time-out interval

	switch (result)
	{
		// The thread got ownership of the mutex
		case WAIT_OBJECT_0:

			break;
		case WAIT_TIMEOUT:
			return hahaha_define_sync::TIMEOUT;
		// The thread got ownership of an abandoned mutex
		// The database is in an indeterminate state
		case WAIT_ABANDONED:
			return hahaha_define_sync::ABANDONED;
	}

	return hahaha_define_sync::OK;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------