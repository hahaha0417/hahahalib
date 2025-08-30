//---------------------------------------------------------------------------

#pragma hdrstop

#include <function\hahaha_function_vector.h>

#include "hahaha_token_string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_string_token::hahaha_string_token()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_string_token::~hahaha_string_token()
{

}
//---------------------------------------------------------------------------
hahaha_string_token::hahaha_string_token(const hahaha_string_token& hst)
{
    Copy(hst);


}
//---------------------------------------------------------------------------
hahaha_string_token::hahaha_string_token(hahaha_string_token&& hst) noexcept
{
    Move(std::move(hst));

}
//---------------------------------------------------------------------------
hahaha_string_token& hahaha_string_token::operator=(const hahaha_string_token& hst)
{
    Copy(hst);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_string_token& hahaha_string_token::operator=(hahaha_string_token&& hst) noexcept
{
	if (this != &hst)
    {
        Move(std::move(hst));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_string_token::Copy(const hahaha_string_token& hst)
{
	Reset();
	hahahalib::Vector_Copy(hst.Tokens_, Tokens_);
	hahahalib::Vector_Unique_Ptr_Copy(hst.String_Tokens_, String_Tokens_);

}
//---------------------------------------------------------------------------
void hahaha_string_token::Move(hahaha_string_token&& hst) noexcept
{
	Tokens_.swap(hst.Tokens_);
	String_Tokens_.swap(hst.String_Tokens_);

    hst.Reset();

}
//---------------------------------------------------------------------------
int hahaha_string_token::Reset()
{
	std::vector<std::string>().swap(Tokens_);

	std::vector<std::unique_ptr<hahahalib::hahaha_string_token>>().swap(String_Tokens_);

	return 0;
}
//---------------------------------------------------------------------------
//hahahalib::hahaha_string_token token_;
//int n = token_.Parser_Delimiter(" ; test ; test1 ; test2 ; ", " ; ");
//std::string s1 = token_.Tokens_[0];
//std::string s2 = token_.Tokens_[1];
//std::string s3 = token_.Tokens_[2];
//std::string s4 = token_.Tokens_[3];
//std::string s5 = token_.Tokens_[4];
int hahaha_string_token::Parser_Delimiter(
	const std::string& str,
	const std::string& delimiter
)
{
	// https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
	size_t pos_start_ = 0;
	size_t pos_end_ = -1;
	size_t delimiter_length_ = delimiter.length();
	std::string token_;

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
//hahahalib::hahaha_string_token token_;
//int n = token_.Parser_Interval("[] ; [test] ;][ test1 ]; [tes]t2 ; [] ", "[", "]");
//std::string s1 = token_.Tokens_[0];
//std::string s2 = token_.Tokens_[1];
//std::string s3 = token_.Tokens_[2];
//std::string s4 = token_.Tokens_[3];
//std::string s5 = token_.Tokens_[4];
int hahaha_string_token::Parser_Interval(
	const std::string& str,
	const std::string& delimiter_front,
	const std::string& delimiter_end
)
{
	size_t pos_start_ = 0;
	size_t pos_end_ = -1;
	size_t delimiter_front_length_ = delimiter_front.length();
	size_t delimiter_end_length_ = delimiter_end.length();
	std::string token_;

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