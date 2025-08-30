//---------------------------------------------------------------------------

#ifndef hahaha_token_wstringH
#define hahaha_token_wstringH
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

class hahaha_wstring_token
{
public:
	hahaha_wstring_token();
	~hahaha_wstring_token();

	hahaha_wstring_token(const hahaha_wstring_token& hwt);
    hahaha_wstring_token(hahaha_wstring_token&& hwt) noexcept;
	hahaha_wstring_token& operator=(const hahaha_wstring_token& hwt);
    hahaha_wstring_token& operator=(hahaha_wstring_token&& hwt) noexcept;
	void Copy(const hahaha_wstring_token& hwt);
    void Move(hahaha_wstring_token&& hwt) noexcept;
public:
	int Reset();
public:
	int Parser_Delimiter(
		const std::wstring& str,
		const std::wstring& delimiter
	);
	int Parser_Interval(
		const std::wstring& str,
		const std::wstring& delimiter_front,
		const std::wstring& delimiter_end
	);
public:
	std::vector<std::wstring> Tokens_;

	std::vector<std::unique_ptr<hahahalib::hahaha_wstring_token>> Wstring_Tokens_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
#endif
