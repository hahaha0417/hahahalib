//---------------------------------------------------------------------------

#ifndef hahaha_token_stringH
#define hahaha_token_stringH
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

class hahaha_string_token
{
public:
	hahaha_string_token();
	~hahaha_string_token();

	hahaha_string_token(const hahaha_string_token& hst);
    hahaha_string_token(hahaha_string_token&& hst) noexcept;
	hahaha_string_token& operator=(const hahaha_string_token& hst);
    hahaha_string_token& operator=(hahaha_string_token&& hst) noexcept;
	void Copy(const hahaha_string_token& hst);
    void Move(hahaha_string_token&& hst) noexcept;
public:
	int Reset();
public:
	int Parser_Delimiter(
		const std::string& str,
		const std::string& delimiter
	);
	int Parser_Interval(
		const std::string& str,
		const std::string& delimiter_front,
		const std::string& delimiter_end
	);
public:
	std::vector<std::string> Tokens_;

	std::vector<std::unique_ptr<hahahalib::hahaha_string_token>> String_Tokens_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
