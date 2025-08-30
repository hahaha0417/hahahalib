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
	hahaha_ini();
	~hahaha_ini();

	hahaha_ini(const hahaha_ini& hi);
    hahaha_ini(hahaha_ini&& hi) noexcept;
	hahaha_ini& operator=(const hahaha_ini& hi);
	hahaha_ini& operator=(hahaha_ini&& hi) noexcept;
	void Copy(const hahaha_ini& hi);
    void Move(hahaha_ini&& hi) noexcept;
public:
	int Reset();
public:
	int Set_File_Name(const std::wstring& file_name);
	int Get_File_Name(std::wstring& file_name);

	//---------------------------------------------------------------------------
	int Set_Bool(const std::wstring& section,
		const std::wstring& name,
		const bool& value
	);
	int Set_Int(const std::wstring& section,
		const std::wstring& name,
		const int& value
	);
	int Set_Float(const std::wstring& section,
		const std::wstring& name,
		const float& value
	);
	int Set_Double(const std::wstring& section,
		const std::wstring& name,
		const double& value
	);
	int Set_Wstring(const std::wstring& section,
		const std::wstring& name,
		const std::wstring& value
	);
	//
	int Get_Bool(const std::wstring& section,
		const std::wstring& name,
		const bool& default_value,
		bool& value
	);
	int Get_Int(const std::wstring& section,
		const std::wstring& name,
		const int& default_value,
		int& value
	);
	int Get_Float(const std::wstring& section,
		const std::wstring& name,
		const float& default_value,
		float& value
	);
	int Get_Double(const std::wstring& section,
		const std::wstring& name,
		const double& default_value,
		double& value
	);
	int Get_Wstring(const std::wstring& section,
		const std::wstring& name,
		const std::wstring& default_value,
		std::wstring& value
	);
	//---------------------------------------------------------------------------
public:
	std::wstring Ini_File_Name_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
