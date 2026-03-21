#pragma hdrstop
#include <utility>
#include <convert\hahaha_convert_string.h>
#include "hahaha_name_pipeline.h"
#pragma package(smart_init)

//CreateFile(L"\\\\.\\pipe\\HahahaPipe", ...)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
hahaha_name_pipeline::hahaha_name_pipeline()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_name_pipeline::~hahaha_name_pipeline()
{
    Close();
}
//---------------------------------------------------------------------------
hahaha_name_pipeline::hahaha_name_pipeline(const hahaha_name_pipeline& hpp)
{
    Reset();
    Copy(hpp);
}
//---------------------------------------------------------------------------
hahaha_name_pipeline::hahaha_name_pipeline(hahaha_name_pipeline&& hpp) noexcept
{
    Move(std::move(hpp));
}
//---------------------------------------------------------------------------
hahaha_name_pipeline& hahaha_name_pipeline::operator=(const hahaha_name_pipeline& hpp)
{
    Copy(hpp);
    return *this;
}
//---------------------------------------------------------------------------
hahaha_name_pipeline& hahaha_name_pipeline::operator=(hahaha_name_pipeline&& hpp) noexcept
{
    if (this != &hpp)
        Move(std::move(hpp));
    return *this;
}
//---------------------------------------------------------------------------
void hahaha_name_pipeline::Copy(const hahaha_name_pipeline& /*hpp*/)
{
    // Named Pipe 不允許複製
}
//---------------------------------------------------------------------------
void hahaha_name_pipeline::Move(hahaha_name_pipeline&& hpp) noexcept
{
    Pipeline_      = hpp.Pipeline_;
    Is_Open_   = hpp.Is_Open_;
    Is_Connect_ = hpp.Is_Connect_;
    Name_  = std::move(hpp.Name_);

    hpp.Pipeline_ = INVALID_HANDLE_VALUE;
    hpp.Is_Open_ = false;
    hpp.Is_Connect_ = false;
    hpp.Name_.clear();
}
//---------------------------------------------------------------------------
int hahaha_name_pipeline::Reset()
{
    Pipeline_ = INVALID_HANDLE_VALUE;
    Is_Open_ = false;
    Is_Connect_ = false;
    Name_.clear();

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_name_pipeline::Close()
{
    if (Pipeline_ != INVALID_HANDLE_VALUE)
    {
        CloseHandle(Pipeline_);
        Pipeline_ = INVALID_HANDLE_VALUE;
    }
    Is_Connect_ = false;
    Is_Open_ = false;
    Name_ = L"";

    return 0;
}
//---------------------------------------------------------------------------
//------------------------------------------------------------
// Server: Create Named Pipe
//------------------------------------------------------------
int hahaha_name_pipeline::Create(const std::wstring& name)
{


    Pipeline_ = CreateNamedPipeW(
        name.c_str(),
        PIPE_ACCESS_DUPLEX,
        PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
        1,
        4096,
        4096,
        0,
        nullptr
    );

    if (Pipeline_ == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    Name_ = name;
    Is_Open_ = true;
    Is_Connect_ = false;

    return 0;
}
//---------------------------------------------------------------------------
//------------------------------------------------------------
// Server: Wait for client
//------------------------------------------------------------
int hahaha_name_pipeline::Wait()
{
    if (!Is_Open_ || Pipeline_ == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    BOOL ok_ = ConnectNamedPipe(Pipeline_, nullptr);
    if (!ok_)
    {
        if (GetLastError() == ERROR_PIPE_CONNECTED)
        {
            Is_Open_ = true;
            return 0;
        }
        return -1;
    }

    Is_Connect_ = true;


    return 0;
}
//---------------------------------------------------------------------------
//------------------------------------------------------------
// Client: Connect to Named Pipe
//------------------------------------------------------------
int hahaha_name_pipeline::Connect(const std::wstring& name)
{

    Name_ = name;

    Pipeline_ = CreateFileW(
        Name_.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (Pipeline_ == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    Is_Open_ = true;
    Is_Connect_ = true;

    return 0;
}
//---------------------------------------------------------------------------
//------------------------------------------------------------
// WriteLine
//------------------------------------------------------------
int hahaha_name_pipeline::Write_Line(const std::wstring& text)
{
    if (Pipeline_ == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    std::string line_ = hahahalib::wstring_to_utf8(text + L"\n");

    DWORD written_ = 0;
    BOOL ok_ = WriteFile(Pipeline_,
    	line_.data(),
        (DWORD)line_.size(),
        &written_,
        nullptr
    );

    return ok_ ? 0 : -1;
}
//---------------------------------------------------------------------------
//------------------------------------------------------------
// ReadLine
//------------------------------------------------------------
int hahaha_name_pipeline::Read_Line(std::wstring& text, DWORD timeout)
{
    if (Pipeline_ == INVALID_HANDLE_VALUE)
    {
        return -1;
    }

    std::string buffer_;
    buffer_.reserve(4096);

    char ch_;
    DWORD read_ = 0;

    while (true)
    {
        // 等待管道有資料可讀
        DWORD wait_ = WaitForSingleObject(Pipeline_, timeout);

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
            Pipeline_,
            &ch_,
            1,
            &read_,
            nullptr
        );

        if (!ok_)
        {
            DWORD err_ = GetLastError();

            // 管道已經被關閉 → EOF
            if (err_ == ERROR_BROKEN_PIPE)
            {
                return -1;
            }

            return -1;
        }

        // 沒讀到資料（理論上不會發生，因為 Wait 已保證可讀）
        if (read_ == 0)
        {
            continue;
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
} // namespace hahahalib
//---------------------------------------------------------------------------



