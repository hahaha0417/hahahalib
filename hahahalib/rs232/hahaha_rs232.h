//---------------------------------------------------------------------------

#ifndef hahaha_rs232H
#define hahaha_rs232H
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
#include <vector>
#include <cstddef>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_rs232
{
public:
	hahaha_rs232();
	~hahaha_rs232();

	hahaha_rs232(const hahaha_rs232& hr);
    hahaha_rs232(hahaha_rs232&& hr) noexcept;
	hahaha_rs232& operator=(const hahaha_rs232& hr);
	hahaha_rs232& operator=(hahaha_rs232&& hr) noexcept;
	void Copy(const hahaha_rs232& hr);
    void Move(hahaha_rs232&& hr) noexcept;
public:
	int Reset();
public:
	int Open(const std::wstring& port_name,
             DWORD baud_rate = CBR_115200,
             BYTE byte_size = 8,
             BYTE parity = NOPARITY,
             BYTE stop_bits = ONESTOPBIT);
	int Close();
    bool Is_Open() const;
public:
    int Set_BaudRate(DWORD baud_rate);
    int Set_Timeouts(DWORD read_interval,
                     DWORD read_total_multiplier,
                     DWORD read_total_constant,
                     DWORD write_total_multiplier,
                     DWORD write_total_constant);
    int Flush();
public:
    int Write(const void* data, std::size_t size, DWORD& bytes_written);
    int Write(const std::vector<unsigned char>& data, DWORD& bytes_written);
    int Write(const std::string& data, DWORD& bytes_written);
    int Write(const std::wstring& data, DWORD& bytes_written);

    int Read(void* buffer, std::size_t size, DWORD& bytes_read);
    int Read(std::vector<unsigned char>& data, std::size_t max_size, DWORD& bytes_read);
    int Read(std::wstring& data, std::size_t max_wchars, DWORD& bytes_read_bytes);
public:
    HANDLE Handle_;
    std::wstring Port_Name_;
    DCB Dcb_;
    COMMTIMEOUTS Timeouts_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
