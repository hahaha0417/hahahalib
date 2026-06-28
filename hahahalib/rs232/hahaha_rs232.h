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
	// 建構物件並初始化預設狀態。
	hahaha_rs232();
	// 解構物件並釋放相關資源。
	~hahaha_rs232();

	// 以既有物件內容建構新的物件實例。
	hahaha_rs232(const hahaha_rs232& hr);
    // 以移動方式建構物件並接手既有資源。
    hahaha_rs232(hahaha_rs232&& hr) noexcept;
	// 複製指派目前物件內容。
	hahaha_rs232& operator=(const hahaha_rs232& hr);
	// 移動指派目前物件內容。
	hahaha_rs232& operator=(hahaha_rs232&& hr) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_rs232& hr);
    // 接手來源物件的內部資源。
    void Move(hahaha_rs232&& hr) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 開啟指定資源或建立連線。
	int Open(const std::wstring& port_name,
             DWORD baud_rate = CBR_115200,  // 序列埠鮑率。
             BYTE byte_size = 8,  // 每個資料單位的位元數。
             BYTE parity = NOPARITY,  // 序列埠同位元設定。
             BYTE stop_bits = ONESTOPBIT  // 序列埠停止位元設定。
    );
	// 關閉並釋放目前持有的資源。
	int Close();
    // 回傳目前狀態判斷結果。
    bool Is_Open() const;
public:
    // 設定指定參數或狀態。
    int Set_BaudRate(DWORD baud_rate /* 序列埠鮑率。 */);
    // 設定指定參數或狀態。
    int Set_Timeouts(DWORD read_interval,
                     DWORD read_total_multiplier,  // 讀取逾時計算中的乘數。
                     DWORD read_total_constant,  // 讀取逾時計算中的常數值。
                     DWORD write_total_multiplier,  // 寫入逾時計算中的乘數。
                     DWORD write_total_constant  // 寫入逾時計算中的常數值。
    );
    // 清空序列埠或 I/O 緩衝區。
    int Flush();
public:
    // 寫入指定資料。
    int Write(const void* data, std::size_t size, DWORD& bytes_written);
    // 寫入指定資料。
    int Write(const std::vector<unsigned char>& data, DWORD& bytes_written);
    // 寫入指定資料。
    int Write(const std::string& data, DWORD& bytes_written);
    // 寫入指定資料。
    int Write(const std::wstring& data, DWORD& bytes_written);

    // 讀取指定資料。
    int Read(void* buffer, std::size_t size, DWORD& bytes_read);
    // 讀取指定資料。
    int Read(std::vector<unsigned char>& data, std::size_t max_size, DWORD& bytes_read);
    // 讀取指定資料。
    int Read(std::wstring& data, std::size_t max_wchars, DWORD& bytes_read_bytes);
    // 持續讀取一行文字資料。
    int Read_Line(std::string& line);
    // 持續讀取一行文字資料。
    int Read_Line(std::wstring& line);
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
