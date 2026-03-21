//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include <convert\hahaha_convert_string.h>
#include "hahaha_pipeline_process.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

hahaha_pipeline_process::hahaha_pipeline_process()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_pipeline_process::~hahaha_pipeline_process()
{
    Close();
}
//---------------------------------------------------------------------------
hahaha_pipeline_process::hahaha_pipeline_process(const hahaha_pipeline_process& hpp)
{
    Reset();
    Copy(hpp);
}
//---------------------------------------------------------------------------
hahaha_pipeline_process::hahaha_pipeline_process(hahaha_pipeline_process&& hpp) noexcept
{
    Move(std::move(hpp));
}
//---------------------------------------------------------------------------
hahaha_pipeline_process& hahaha_pipeline_process::operator=(const hahaha_pipeline_process& hpp)
{
    Copy(hpp);
    return *this;
}
//---------------------------------------------------------------------------
hahaha_pipeline_process& hahaha_pipeline_process::operator=(hahaha_pipeline_process&& hpp) noexcept
{
    if (this != &hpp)
    {
        Move(std::move(hpp));
    }
    return *this;
}
//---------------------------------------------------------------------------
void hahaha_pipeline_process::Copy(const hahaha_pipeline_process& /*hpp*/)
{
    // 不支援複製：process / handle 不適合被複製
    // 保持空實作或直接 assert
}
//---------------------------------------------------------------------------
void hahaha_pipeline_process::Move(hahaha_pipeline_process&& hpp) noexcept
{
    Information_Process_   = hpp.Information_Process_;
    Information_Startup_   = hpp.Information_Startup_;

    Child_Std_IN_W_  = hpp.Child_Std_IN_W_;
    Child_Std_OUT_R_ = hpp.Child_Std_OUT_R_;
    Child_Std_IN_R_  = hpp.Child_Std_IN_R_;
    Child_Std_OUT_W_ = hpp.Child_Std_OUT_W_;

    Is_Open_      = hpp.Is_Open_;
    Command_  = std::move(hpp.Command_);

    hpp.Reset();
}
//---------------------------------------------------------------------------
int hahaha_pipeline_process::Reset()
{
    ZeroMemory(&Information_Process_, sizeof(Information_Process_));
    ZeroMemory(&Information_Startup_, sizeof(Information_Startup_));
    Information_Startup_.cb = sizeof(Information_Startup_);

    Child_Std_IN_W_  = nullptr;
    Child_Std_OUT_R_ = nullptr;
    Child_Std_IN_R_  = nullptr;
    Child_Std_OUT_W_ = nullptr;

    Is_Open_ = false;
    Command_.clear();

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_pipeline_process::Read_Line(std::wstring& text, DWORD timeout)
{


    if (!Child_Std_OUT_R_)
    {
        return -1;
    }


    std::string buffer_;
    buffer_.reserve(4096);

    char ch_;
    DWORD bytes_read_ = 0;

    while (true)
    {
        // 等待 stdout pipe 有資料可讀
        DWORD wait_ = WaitForSingleObject(Child_Std_OUT_R_, timeout);
        if (wait_ == WAIT_TIMEOUT)
        {
            return -2; // timeout
        }
        if (wait_ != WAIT_OBJECT_0)
        {
            return -1; // error
        }
        // 讀一個字元
        BOOL ok_ = ReadFile(
            Child_Std_OUT_R_,
            &ch_,
            1,
            &bytes_read_,
            nullptr
        );

        if (!ok_ || bytes_read_ == 0)
        {
            return -1;
        }

        if (ch_ == '\n')
        {
            break;
        }

        if (ch_ != '\r')
        {
            buffer_.push_back(ch_);
        }
    }

    text = hahahalib::utf8_to_wstring(buffer_);

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_pipeline_process::Write_Line(const std::wstring& text)
{
    if (!Child_Std_IN_W_)
    {
        return -1;
	}

    std::string line_ = hahahalib::wstring_to_utf8(text + L"\n");

    DWORD written_ = 0;

    BOOL ok_ = WriteFile(
        Child_Std_IN_W_,
        line_.data(),
        (DWORD)line_.size(),
        &written_,
        nullptr
    );

    return ok_ ? 0 : -1;
}



//---------------------------------------------------------------------------
int hahaha_pipeline_process::Create(const std::wstring& command)
{

    Command_ = command;

    SECURITY_ATTRIBUTES saAttr;
    saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
    saAttr.bInheritHandle = TRUE;      // 讓子行程可以繼承
    saAttr.lpSecurityDescriptor = nullptr;

    // 建立 stdout pipe：child 寫 → parent 讀
    if (!CreatePipe(&Child_Std_OUT_R_, &Child_Std_OUT_W_, &saAttr, 0))
    {
        Reset();
        return -1;
    }

    // 父進程不需要繼承讀端，所以清掉繼承旗標
    if (!SetHandleInformation(Child_Std_OUT_R_, HANDLE_FLAG_INHERIT, 0))
    {
        Close();
        return -1;
    }

    // 建立 stdin pipe：parent 寫 → child 讀
    if (!CreatePipe(&Child_Std_IN_R_, &Child_Std_IN_W_, &saAttr, 0))
    {
        Close();
        return -1;
    }

    // 父進程不需要繼承寫端，所以清掉繼承旗標
    if (!SetHandleInformation(Child_Std_IN_W_, HANDLE_FLAG_INHERIT, 0))
    {
        Close();
        return -1;
    }

    ZeroMemory(&Information_Startup_, sizeof(Information_Startup_));
    Information_Startup_.cb = sizeof(Information_Startup_);
    Information_Startup_.hStdError  = Child_Std_OUT_W_;
    Information_Startup_.hStdOutput = Child_Std_OUT_W_;
    Information_Startup_.hStdInput  = Child_Std_IN_R_;
    Information_Startup_.dwFlags   |= STARTF_USESTDHANDLES;

    ZeroMemory(&Information_Process_, sizeof(Information_Process_));

    // CreateProcessW 會修改 command line buffer，所以要可寫
    std::wstring cmd_ = Command_;

    BOOL ok_ = CreateProcessW(
        nullptr,                 // lpApplicationName
        &cmd_[0],                 // lpCommandLine（可寫 buffer）
        nullptr,                 // lpProcessAttributes
        nullptr,                 // lpThreadAttributes
        TRUE,                    // bInheritHandles（一定要 TRUE 才能繼承 pipe）
        0,                       // dwCreationFlags
        nullptr,                 // lpEnvironment
        nullptr,                 // lpCurrentDirectory
        &Information_Startup_,
        &Information_Process_
    );

    if (!ok_)
    {
        Close();
        return -1;
    }

    // 父進程不需要這兩個端點了（只給 child 用）
    if (Child_Std_IN_R_)
    {
        CloseHandle(Child_Std_IN_R_);
        Child_Std_IN_R_ = nullptr;
    }
    if (Child_Std_OUT_W_)
    {
        CloseHandle(Child_Std_OUT_W_);
        Child_Std_OUT_W_ = nullptr;
    }

    Is_Open_ = true;
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_pipeline_process::Close()
{
    // 關閉父進程持有的 pipe 端點
    if (Child_Std_IN_W_)
    {
        CloseHandle(Child_Std_IN_W_);
        Child_Std_IN_W_ = nullptr;
    }
    if (Child_Std_OUT_R_)
    {
        CloseHandle(Child_Std_OUT_R_);
        Child_Std_OUT_R_ = nullptr;
    }

    // 關閉 child 專用端點（理論上在 Create 後就已經關掉，但保險）
    if (Child_Std_IN_R_)
    {
        CloseHandle(Child_Std_IN_R_);
        Child_Std_IN_R_ = nullptr;
    }
    if (Child_Std_OUT_W_)
    {
        CloseHandle(Child_Std_OUT_W_);
        Child_Std_OUT_W_ = nullptr;
    }

    // 關閉 process / thread handle
    if (Information_Process_.hProcess)
    {
        CloseHandle(Information_Process_.hProcess);
        Information_Process_.hProcess = nullptr;
    }
    if (Information_Process_.hThread)
    {
        CloseHandle(Information_Process_.hThread);
        Information_Process_.hThread = nullptr;
    }

    Is_Open_ = false;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_pipeline_process::Terminate(DWORD exit_code)
{
    if (Information_Process_.hProcess)
    {
        TerminateProcess(Information_Process_.hProcess, exit_code);
    }
    return 0;
}
//---------------------------------------------------------------------------

} // namespace hahahalib
//---------------------------------------------------------------------------


