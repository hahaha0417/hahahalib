//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <windows.h>
#include <psapi.h>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
#include <information\process\hahaha_information_process_item.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_information_process.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_process::hahaha_information_process()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_process::~hahaha_information_process()
{

}
//---------------------------------------------------------------------------
hahaha_information_process::hahaha_information_process(const hahaha_information_process& hip)
{
    Reset();
	Copy(hip);
}
//---------------------------------------------------------------------------
hahaha_information_process::hahaha_information_process(hahaha_information_process&& hip) noexcept
{
    Move(std::move(hip));
}
//---------------------------------------------------------------------------
hahaha_information_process& hahaha_information_process::operator=(const hahaha_information_process& hip)
{
	Copy(hip);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_process& hahaha_information_process::operator=(hahaha_information_process&& hip) noexcept
{
	if (this != &hip)
    {
        Move(std::move(hip));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_process::Copy(const hahaha_information_process& hip)
{
    hahahalib::Vector_Copy(hip.Processes_, Processes_);
    Visible_Only_ = hip.Visible_Only_;
    Show_In_Taskbar_ = hip.Show_In_Taskbar_;

}
//---------------------------------------------------------------------------
void hahaha_information_process::Move(hahaha_information_process&& hip) noexcept
{
    Processes_ = std::move(hip.Processes_);
    Visible_Only_ = hip.Visible_Only_;
    Show_In_Taskbar_ = hip.Show_In_Taskbar_;

    hip.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_process::Reset()
{
    std::vector<hahaha_information_process_item>().swap(Processes_);
    Visible_Only_ = false;
    Show_In_Taskbar_ = false;

	return 0;
}
//---------------------------------------------------------------------------
BOOL CALLBACK hahaha_information_process::Enum_Windows_Procedure(HWND hwnd, LPARAM lparam)
{
    hahaha_information_process& Information_Process_ = *(hahaha_information_process*)lparam;

    if(Information_Process_.Show_In_Taskbar_)
    {
        if (!IsWindowVisible(hwnd))
        {
            return TRUE; // 只看可見視窗
        }

        HWND owner_ = GetWindow(hwnd, GW_OWNER);
    	if (owner_ != NULL)
        {
            return TRUE; // 被其他視窗擁有
        }

        LONG ex_style_ = GetWindowLong(hwnd, GWL_EXSTYLE);
    	if (ex_style_ & WS_EX_TOOLWINDOW)
        {
            return TRUE; // 工具視窗不在 taskbar
        }
    }
    else
    {
        if (Information_Process_.Visible_Only_ && !IsWindowVisible(hwnd))
        {
            return TRUE; // 只看可見視窗
        }
    }




    DWORD process_id_;
    GetWindowThreadProcessId(hwnd, &process_id_);

    wchar_t title_[256];
    GetWindowTextW(hwnd, title_, 256);
    if (wcslen(title_) == 0) return TRUE; // 忽略無標題視窗

    HANDLE handle_process_ = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, process_id_);
    wchar_t exe_name_[MAX_PATH] = L"";
    if (handle_process_) {
        HMODULE handle_mod_;
        DWORD cb_needed_;
        if (EnumProcessModules(handle_process_, &handle_mod_, sizeof(handle_mod_), &cb_needed_)) {
            GetModuleBaseNameW(handle_process_, handle_mod_, exe_name_, MAX_PATH);
        }
        CloseHandle(handle_process_);
    }

    hahaha_information_process_item item_;
    item_.Id_Process_ = process_id_;
    item_.Title_Window_ = title_;
    item_.Name_Exe_ = exe_name_;

    Information_Process_.Processes_.emplace_back(item_);


    return TRUE;
}
//---------------------------------------------------------------------------
int hahaha_information_process::Get_All()
{
    std::vector<hahaha_information_process_item>().swap(Processes_);
    EnumWindows(Enum_Windows_Procedure, (LPARAM)this);

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------