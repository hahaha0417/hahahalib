//---------------------------------------------------------------------------

#pragma hdrstop

#include <function\hahaha_function_vector.h>

#include "hahaha_token_wstring.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_wstring_token::hahaha_wstring_token()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_wstring_token::~hahaha_wstring_token()
{

}
//---------------------------------------------------------------------------
hahaha_wstring_token::hahaha_wstring_token(const hahaha_wstring_token& hwt)
{
	Copy(hwt);
}
//---------------------------------------------------------------------------
hahaha_wstring_token::hahaha_wstring_token(hahaha_wstring_token&& hwt) noexcept
{
	Move(std::move(hwt));

}
//---------------------------------------------------------------------------
hahaha_wstring_token& hahaha_wstring_token::operator=(const hahaha_wstring_token& hwt)
{
	Copy(hwt);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_wstring_token& hahaha_wstring_token::operator=(hahaha_wstring_token&& hwt) noexcept
{
	if (this != &hwt)
    {
        Move(std::move(hwt));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_wstring_token::Copy(const hahaha_wstring_token& hwt)
{
	Reset();
	hahahalib::Vector_Copy(hwt.Tokens_, Tokens_);
	hahahalib::Vector_Unique_Ptr_Copy(hwt.Wstring_Tokens_, Wstring_Tokens_);

}
//---------------------------------------------------------------------------
void hahaha_wstring_token::Move(hahaha_wstring_token&& hwt) noexcept
{
	Tokens_.swap(hwt.Tokens_);
	Wstring_Tokens_.swap(hwt.Wstring_Tokens_);

    hwt.Reset();

}
//---------------------------------------------------------------------------
int hahaha_wstring_token::Reset()
{
	std::vector<std::wstring>().swap(Tokens_);

	std::vector<std::unique_ptr<hahahalib::hahaha_wstring_token>>().swap(Wstring_Tokens_);

	return 0;
}
//---------------------------------------------------------------------------
//hahahalib::hahaha_wstring_token token_;
//int n = token_.Parser_Delimiter(L" ; test ; test1 ; test2 ; ", L" ; ");
//std::wstring s1 = token_.Tokens_[0];
//std::wstring s2 = token_.Tokens_[1];
//std::wstring s3 = token_.Tokens_[2];
//std::wstring s4 = token_.Tokens_[3];
//std::wstring s5 = token_.Tokens_[4];
int hahaha_wstring_token::Parser_Delimiter(
	const std::wstring& str,
	const std::wstring& delimiter
)
{
	// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	size_t pos_start_ = 0;
	size_t pos_end_ = -1;
	size_t delimiter_length_ = delimiter.length();
	std::wstring token_;

	while ((pos_end_ = str.find(delimiter, pos_start_)) != std::string::npos)
	{
		token_ = str.substr (pos_start_, pos_end_ - pos_start_);
		pos_start_ = pos_end_ + delimiter_length_;
		Tokens_.emplace_back(token_);
    }

	Tokens_.emplace_back(str.substr(pos_start_));

	return Tokens_.size();

}
//---------------------------------------------------------------------------
//hahahalib::hahaha_wstring_token token_;
//int n = token_.Parser_Interval(L"[] ; [test] ;][ test1 ]; [tes]t2 ; [] ", L"[", L"]");
//std::wstring s1 = token_.Tokens_[0];
//std::wstring s2 = token_.Tokens_[1];
//std::wstring s3 = token_.Tokens_[2];
//std::wstring s4 = token_.Tokens_[3];
//std::wstring s5 = token_.Tokens_[4];
int hahaha_wstring_token::Parser_Interval(
	const std::wstring& str,
	const std::wstring& delimiter_front,
	const std::wstring& delimiter_end
)
{
	size_t pos_start_ = 0;
	size_t pos_end_ = -1;
	size_t delimiter_front_length_ = delimiter_front.length();
	size_t delimiter_end_length_ = delimiter_end.length();
	std::wstring token_;

	if((pos_start_ = str.find(delimiter_front, pos_start_)) == std::string::npos)
	{
		return Tokens_.size();
	}

    pos_start_ = pos_start_ + delimiter_front_length_;

	while ((pos_end_ = str.find(delimiter_end, pos_start_)) != std::string::npos)
	{
		token_ = str.substr (pos_start_, pos_end_ - pos_start_);
		pos_start_ = pos_end_ + delimiter_end_length_;
		Tokens_.emplace_back (token_);

		if((pos_start_ = str.find(delimiter_front, pos_start_)) == std::string::npos)
		{
			return Tokens_.size();
		}
		pos_start_ = pos_start_ + delimiter_front_length_;
    }

	Tokens_.emplace_back (str.substr(pos_start_));

	return Tokens_.size();

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
