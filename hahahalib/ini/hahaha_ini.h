//---------------------------------------------------------------------------

#ifndef hahaha_iniH
#define hahaha_iniH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <memory>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
// https://learn.microsoft.com/zh-tw/windows/win32/api/winbase/nf-winbase-getprofilesectionw
// 這裡不用string，只做寬字元版
// 不能用日文
class hahaha_ini
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_ini();
	// 解構物件並釋放相關資源。
	~hahaha_ini();

	// 以既有物件內容建構新的物件實例。
	hahaha_ini(const hahaha_ini& hi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_ini(hahaha_ini&& hi) noexcept;
	// 複製指派目前物件內容。
	hahaha_ini& operator=(const hahaha_ini& hi);
	// 移動指派目前物件內容。
	hahaha_ini& operator=(hahaha_ini&& hi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_ini& hi);
    // 接手來源物件的內部資源。
    void Move(hahaha_ini&& hi) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 設定指定參數或狀態。
	int Set_File_Name(const std::wstring& file_name);
	// 取得指定資料或狀態。
	int Get_File_Name(std::wstring& file_name);

	//---------------------------------------------------------------------------
	int Set_Bool(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const bool& value
	);
	// 設定指定參數或狀態。
	int Set_Int(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const int& value
	);
	// 設定指定參數或狀態。
	int Set_Float(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const float& value
	);
	// 設定指定參數或狀態。
	int Set_Double(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const double& value
	);
	// 設定指定參數或狀態。
	int Set_Wstring(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const std::wstring& value
	);
	//
	int Get_Bool(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const bool& default_value,  // 查詢失敗時要回傳的預設值。
		bool& value  // 讀取成功後輸出的布林值。
	);
	// 取得指定資料或狀態。
	int Get_Int(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const int& default_value,  // 查詢失敗時要回傳的預設值。
		int& value  // 讀取成功後輸出的整數值。
	);
	// 取得指定資料或狀態。
	int Get_Float(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const float& default_value,  // 查詢失敗時要回傳的預設值。
		float& value  // 讀取成功後輸出的浮點值。
	);
	// 取得指定資料或狀態。
	int Get_Double(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const double& default_value,  // 查詢失敗時要回傳的預設值。
		double& value  // 讀取成功後輸出的 double 值。
	);
	// 取得指定資料或狀態。
	int Get_Wstring(const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const std::wstring& default_value,  // 查詢失敗時要回傳的預設字串。
		std::wstring& value  // 讀取成功後輸出的字串內容。
	);
	//---------------------------------------------------------------------------
public:
	std::wstring Ini_File_Name_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
