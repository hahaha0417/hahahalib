//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include <convert\hahaha_convert_string.h>
//---------------------------------------------------------------------------
#include "hahaha_rs232.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_rs232::hahaha_rs232()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_rs232::~hahaha_rs232()
{
	Close();
}
//---------------------------------------------------------------------------
hahaha_rs232::hahaha_rs232(const hahaha_rs232& hr)
{
    Reset();
	Copy(hr);
}
//---------------------------------------------------------------------------
hahaha_rs232::hahaha_rs232(hahaha_rs232&& hr) noexcept
{
    Move(std::move(hr));
}
//---------------------------------------------------------------------------
hahaha_rs232& hahaha_rs232::operator=(const hahaha_rs232& hr)
{
	Copy(hr);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_rs232& hahaha_rs232::operator=(hahaha_rs232&& hr) noexcept
{
	if (this != &hr)
    {
        Move(std::move(hr));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_rs232::Copy(const hahaha_rs232& hr)
{
	if (this == &hr)
	{
		return;
	}

	Close();

	Port_Name_ = hr.Port_Name_;
	Dcb_ = hr.Dcb_;
	Timeouts_ = hr.Timeouts_;
	Handle_ = nullptr;
}
//---------------------------------------------------------------------------
void hahaha_rs232::Move(hahaha_rs232&& hr) noexcept
{
	if (this == &hr)
	{
		return;
	}

	Close();

	Handle_ = hr.Handle_;
	Port_Name_ = std::move(hr.Port_Name_);
	Dcb_ = hr.Dcb_;
	Timeouts_ = hr.Timeouts_;

	hr.Handle_ = nullptr;
	hr.Port_Name_.clear();
	ZeroMemory(&hr.Dcb_, sizeof(DCB));
	hr.Dcb_.DCBlength = sizeof(DCB);
	ZeroMemory(&hr.Timeouts_, sizeof(COMMTIMEOUTS));
}
//---------------------------------------------------------------------------
int hahaha_rs232::Reset()
{
	Handle_ = nullptr;
	Port_Name_.clear();
	ZeroMemory(&Dcb_, sizeof(DCB));
	Dcb_.DCBlength = sizeof(DCB);
	ZeroMemory(&Timeouts_, sizeof(COMMTIMEOUTS));

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Open(const std::wstring& port_name,
             DWORD baud_rate,
             BYTE byte_size,
             BYTE parity,
             BYTE stop_bits)
{
	if(Handle_ != nullptr && Handle_ != INVALID_HANDLE_VALUE)
	{
		Close();
	}

	std::wstring full_name_ = port_name;
	if (!full_name_.empty())
	{
		if (full_name_.rfind(L"\\\\.\\", 0) != 0)
		{
			if (full_name_.size() >= 3 &&
				(full_name_[0] == L'C' || full_name_[0] == L'c') &&
				(full_name_[1] == L'O' || full_name_[1] == L'o') &&
				(full_name_[2] == L'M' || full_name_[2] == L'm'))
			{
				full_name_ = L"\\\\.\\" + full_name_;
			}
		}
	}

	Handle_ = CreateFileW(
		full_name_.c_str(),
		GENERIC_READ | GENERIC_WRITE,
		0,
		nullptr,
		OPEN_EXISTING,
		0,
		nullptr
	);

	if (Handle_ == INVALID_HANDLE_VALUE)
	{
		Handle_ = nullptr;
		return -1;
	}

	if (!SetupComm(Handle_, 4096, 4096))
	{
		Close();
		return -6;
	}

	DCB dcb_ = {0};
	dcb_.DCBlength = sizeof(DCB);
	if (!GetCommState(Handle_, &dcb_))
	{
		Close();
		return -2;
	}

	dcb_.BaudRate = baud_rate;
	dcb_.ByteSize = byte_size;
	dcb_.Parity = parity;
	dcb_.StopBits = stop_bits;

	dcb_.fBinary = TRUE;
	dcb_.fParity = (parity != NOPARITY) ? TRUE : FALSE;
	dcb_.fOutxCtsFlow = FALSE;
	dcb_.fOutxDsrFlow = FALSE;
	dcb_.fDtrControl = DTR_CONTROL_ENABLE;
	dcb_.fDsrSensitivity = FALSE;
	dcb_.fTXContinueOnXoff = TRUE;
	dcb_.fOutX = FALSE;
	dcb_.fInX = FALSE;
	dcb_.fErrorChar = FALSE;
	dcb_.fNull = FALSE;
	dcb_.fRtsControl = RTS_CONTROL_ENABLE;
	dcb_.fAbortOnError = FALSE;

	if (!SetCommState(Handle_, &dcb_))
	{
		Close();
		return -3;
	}

	Dcb_ = dcb_;

	COMMTIMEOUTS timeouts_ = {0};
	if (!GetCommTimeouts(Handle_, &timeouts_))
	{
		Close();
		return -4;
	}

	if (!SetCommTimeouts(Handle_, &timeouts_))
	{
		Close();
		return -5;
	}

	Timeouts_ = timeouts_;
	Port_Name_ = port_name;

	PurgeComm(Handle_, PURGE_RXCLEAR | PURGE_TXCLEAR);

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Close()
{
	if(Handle_ != nullptr && Handle_ != INVALID_HANDLE_VALUE)
	{
		CloseHandle(Handle_);
		Handle_ = nullptr;
	}

	return 0;
}
//---------------------------------------------------------------------------
bool hahaha_rs232::Is_Open() const
{
	return Handle_ != nullptr && Handle_ != INVALID_HANDLE_VALUE;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Set_BaudRate(DWORD baud_rate)
{
	if (!Is_Open())
	{
		return -1;
	}

	DCB dcb_ = {0};
	dcb_.DCBlength = sizeof(DCB);
	if (!GetCommState(Handle_, &dcb_))
	{
		return -2;
	}

	dcb_.BaudRate = baud_rate;

	if (!SetCommState(Handle_, &dcb_))
	{
		return -3;
	}

	Dcb_ = dcb_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Set_Timeouts(DWORD read_interval,
                     DWORD read_total_multiplier,
                     DWORD read_total_constant,
                     DWORD write_total_multiplier,
                     DWORD write_total_constant)
{
	if (!Is_Open())
	{
		return -1;
	}

	COMMTIMEOUTS timeouts_ = {0};
	if (!GetCommTimeouts(Handle_, &timeouts_))
	{
		return -2;
	}

	timeouts_.ReadIntervalTimeout = read_interval;
	timeouts_.ReadTotalTimeoutMultiplier = read_total_multiplier;
	timeouts_.ReadTotalTimeoutConstant = read_total_constant;
	timeouts_.WriteTotalTimeoutMultiplier = write_total_multiplier;
	timeouts_.WriteTotalTimeoutConstant = write_total_constant;

	if (!SetCommTimeouts(Handle_, &timeouts_))
	{
		return -3;
	}

	Timeouts_ = timeouts_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Flush()
{
	if (!Is_Open())
	{
		return -1;
	}

	if (!PurgeComm(Handle_, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT))
	{
		return -2;
	}

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Write(const void* data, std::size_t size, DWORD& bytes_written)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (data == nullptr || size == 0)
	{
		bytes_written = 0;
		return 0;
	}

	DWORD written_ = 0;
	if (!WriteFile(Handle_, data, static_cast<DWORD>(size), &written_, nullptr))
	{
		return -2;
	}

	bytes_written = written_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Write(const std::vector<unsigned char>& data, DWORD& bytes_written)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (data.empty())
	{
		bytes_written = 0;
		return 0;
	}

	DWORD written_ = 0;
	if (!WriteFile(Handle_, data.data(), static_cast<DWORD>(data.size()), &written_, nullptr))
	{
		bytes_written = 0;
		return -2;
	}

	bytes_written = written_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Write(const std::string& data, DWORD& bytes_written)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (data.empty())
	{
		bytes_written = 0;
		return 0;
	}

	DWORD written_ = 0;
	if (!WriteFile(Handle_, data.data(), static_cast<DWORD>(data.size()), &written_, nullptr))
	{
		bytes_written = 0;
		return -2;
	}

	bytes_written = written_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Write(const std::wstring& data, DWORD& bytes_written)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (data.empty())
	{
		bytes_written = 0;
		return 0;
	}

	std::string s_ = hahahalib::wstring_to_utf8(data);
	if (s_.empty())
	{
		bytes_written = 0;
		return 0;
	}

	DWORD written_ = 0;
	if (!WriteFile(Handle_, s_.data(), static_cast<DWORD>(s_.size()), &written_, nullptr))
	{
		bytes_written = 0;
		return -2;
	}

	bytes_written = written_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Read(void* buffer, std::size_t size, DWORD& bytes_read)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (buffer == nullptr || size == 0)
	{
		bytes_read = 0;
		return 0;
	}

	DWORD read_ = 0;
	if (!ReadFile(Handle_, buffer, static_cast<DWORD>(size), &read_, nullptr))
	{
		return -2;
	}

	bytes_read = read_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Read(std::vector<unsigned char>& data, std::size_t max_size, DWORD& bytes_read)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (max_size == 0)
	{
		data.clear();
		bytes_read = 0;
		return 0;
	}

	data.resize(max_size);
	DWORD read_ = 0;
	if (!ReadFile(Handle_, data.data(), static_cast<DWORD>(max_size), &read_, nullptr))
	{
		data.clear();
		bytes_read = 0;
		return -2;
	}

	data.resize(read_);
	bytes_read = read_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Read(std::wstring& data, std::size_t max_wchars, DWORD& bytes_read_bytes)
{
	if (!Is_Open())
	{
		return -1;
	}

	if (max_wchars == 0)
	{
		data.clear();
		bytes_read_bytes = 0;
		return 0;
	}

	std::string buffer_;
	buffer_.resize(max_wchars * sizeof(wchar_t));

	DWORD read_bytes_ = 0;
	if (!ReadFile(Handle_, &buffer_[0], static_cast<DWORD>(buffer_.size()), &read_bytes_, nullptr))
	{
		data.clear();
		bytes_read_bytes = 0;
		return -2;
	}

	buffer_.resize(read_bytes_);
	data = hahahalib::s2ws(buffer_);

	bytes_read_bytes = read_bytes_;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_rs232::Read_Line(std::string& line)
{
    if (!Is_Open())
    {
        return -1;
    }

    DWORD mask_ = 0;

    // 等待 RS232 有資料可讀
    if (!WaitCommEvent(Handle_, &mask_, nullptr))
    {
        return -1;
    }

    if (!(mask_ & EV_RXCHAR))
    {
        return -1;
    }

    char ch_ = 0;
    DWORD bytes_read_ = 0;

    while (true)
    {
        // 等待資料可讀
        DWORD wait_ = WaitForSingleObject(Handle_, INFINITE);
        if (wait_ != WAIT_OBJECT_0)
            return -1;

        BOOL ok_ = ReadFile(
            Handle_,
            &ch_,
            1,
            &bytes_read_,
            nullptr
        );

        if (!ok_)
        {
            return -1;
        }

        if (bytes_read_ == 0)
        {
            continue;
        }

        if (ch_ == '\n')
        {
            break;
        }

        if (ch_ != '\r')
        {
            line.push_back(ch_);
        }
    }

    return 0;
}

//---------------------------------------------------------------------------
int hahaha_rs232::Read_Line(std::wstring& line)
{
    std::string tmp_;
    int ret_ = Read_Line(tmp_);
    if (ret_ != 0)
    {
        return ret_;
    }

    line = hahahalib::utf8_to_wstring(tmp_);
    return 0;
}

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
