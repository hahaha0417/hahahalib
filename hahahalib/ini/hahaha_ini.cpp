//---------------------------------------------------------------------------

#pragma hdrstop
#include <windows.h>
#include <wchar.h>

#include <convert\hahaha_convert_string.h>
#include "hahaha_ini.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// 不能用日文

//#include <ini\hahaha_ini.h>
//hahahalib::hahaha_ini ini_;
//
//ini_.Set_File_Name(L"E:\\桌面\\sss\\ccc.ini");
//
//ini_.Set_Bool(L"ddd", L"dddd", true);
//ini_.Set_Int(L"ddds", L"ssse", 123);
//ini_.Set_Float(L"ddds", L"ssss", 123.5);
//ini_.Set_Double(L"ddds", L"sssa", 123.6);
//ini_.Set_Wstring(L"dddsx", L"sssx", L"日文");
//
//bool s1 = false;
//ini_.Get_Bool(L"ddd", L"dddd", true, s1);
//int s2 = 0;
//ini_.Get_Int(L"ddds", L"ssse", 1234, s2);
//float s3 = 0;
//ini_.Get_Float(L"ddds", L"ssss", 2123.5, s3);
//double s4 = 0;
//ini_.Get_Double(L"ddds", L"sssa", 6123.6, s4);
//std::wstring s5 = L"";
//ini_.Get_Wstring(L"dddsx", L"sssx", L"vvv", s5);
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
#define MAX_LENGTH 1024
//---------------------------------------------------------------------------
hahaha_ini::hahaha_ini()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_ini::~hahaha_ini()
{

}
//---------------------------------------------------------------------------
hahaha_ini::hahaha_ini(const hahaha_ini& hi)
{
	Copy(hi);
}
//---------------------------------------------------------------------------
hahaha_ini::hahaha_ini(hahaha_ini&& hi) noexcept
{
	Move(std::move(hi));

}
//---------------------------------------------------------------------------
hahaha_ini& hahaha_ini::operator=(const hahaha_ini& hi)
{
	Copy(hi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_ini& hahaha_ini::operator=(hahaha_ini&& hi) noexcept
{
	if (this != &hi)
    {
        Move(std::move(hi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_ini::Copy(const hahaha_ini& hi)
{

}
//---------------------------------------------------------------------------
void hahaha_ini::Move(hahaha_ini&& hi) noexcept
{
    Ini_File_Name_ = std::move(Ini_File_Name_);

}
//---------------------------------------------------------------------------
int hahaha_ini::Reset()
{
	Ini_File_Name_ = L"";

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_ini::Set_File_Name(const std::wstring& file_name)
{
	Ini_File_Name_ = file_name;

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Get_File_Name(std::wstring& file_name)
{
	file_name = Ini_File_Name_;

	return 0;

}

//---------------------------------------------------------------------------
int hahaha_ini::Set_Bool(const std::wstring& section,
	const std::wstring& name,
	const bool& value
)
{
	WritePrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  value ? L"true" : L"false",
	  Ini_File_Name_.c_str()
	);

	return 0;

}

//---------------------------------------------------------------------------
int hahaha_ini::Set_Int(const std::wstring& section,
	const std::wstring& name,
	const int& value
)
{
	WritePrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(value).c_str(),
	  Ini_File_Name_.c_str()
	);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Set_Float(const std::wstring& section,
	const std::wstring& name,
	const float& value
)
{
    WritePrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(value).c_str(),
	  Ini_File_Name_.c_str()
	);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Set_Double(const std::wstring& section,
	const std::wstring& name,
	const double& value
)
{
    WritePrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(value).c_str(),
	  Ini_File_Name_.c_str()
	);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Set_Wstring(const std::wstring& section,
	const std::wstring& name,
	const std::wstring& value
)
{
    WritePrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  value.c_str(),
	  Ini_File_Name_.c_str()
	);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Get_Bool(const std::wstring& section,
	const std::wstring& name,
	const bool& default_value,
	bool& value
)
{
	wchar_t str_[MAX_LENGTH] = L"\0";
	GetPrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  default_value ? L"true" : L"false",
	  str_,
	  MAX_LENGTH,
	  Ini_File_Name_.c_str()
	);

	std::wstring t_ = str_;
	if(t_ == L"true")
	{
		value = true;
	}
	else if(t_ == L"false")
	{
        value = false;
	}

	return 0;

}

//---------------------------------------------------------------------------
int hahaha_ini::Get_Int(const std::wstring& section,
	const std::wstring& name,
	const int& default_value,
	int& value
)
{
	wchar_t str_[MAX_LENGTH] = L"\0";
	GetPrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(default_value).c_str(),
	  str_,
	  MAX_LENGTH,
	  Ini_File_Name_.c_str()
	);

	value = _wtoi(str_);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Get_Float(const std::wstring& section,
	const std::wstring& name,
	const float& default_value,
	float& value
)
{
	wchar_t str_[MAX_LENGTH] = L"\0";
	GetPrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(default_value).c_str(),
	  str_,
	  MAX_LENGTH,
	  Ini_File_Name_.c_str()
	);

	value = _wtof(str_);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Get_Double(const std::wstring& section,
	const std::wstring& name,
	const double& default_value,
	double& value
)
{
	wchar_t str_[MAX_LENGTH] = L"\0";
	GetPrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  std::to_wstring(default_value).c_str(),
	  str_,
	  MAX_LENGTH,
	  Ini_File_Name_.c_str()
	);

	wchar_t* stopwcs_;
	value = std::wcstod(str_, &stopwcs_);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_ini::Get_Wstring(const std::wstring& section,
	const std::wstring& name,
	const std::wstring& default_value,
	std::wstring& value
)
{
	wchar_t str_[MAX_LENGTH] = L"\0";
	GetPrivateProfileStringW(
	  section.c_str(),
	  name.c_str(),
	  default_value.c_str(),
	  str_,
	  MAX_LENGTH,
	  Ini_File_Name_.c_str()
	);

	value = str_;

	return 0;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------