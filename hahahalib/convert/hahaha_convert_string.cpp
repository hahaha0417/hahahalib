//---------------------------------------------------------------------------

#pragma hdrstop

#if defined(__WIN64_MODERN)
    #include <string>
    #include <cstdlib>
    #include <iostream>
#else
    #include <codecvt>
#endif



#include "hahaha_convert_string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

std::string ws2s(const std::wstring& str)
{
    // support chinese
	std::string res_;
	int len_ = WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), nullptr, 0, nullptr, nullptr);
	if (len_ <= 0){
		return res_;
	}
	char* buffer_ = new char[len_ + 1];
	if (buffer_ == nullptr){
		return res_;
	}
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), str.size(), buffer_, len_, nullptr, nullptr);
	buffer_[len_] = '\0';
	res_.append(buffer_);
	delete[] buffer_;
	return res_;
}
//---------------------------------------------------------------------------
std::wstring s2ws(const std::string& str)
{
	std::wstring res_;
	int len_ = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), nullptr, 0);
	if( len_ < 0 ){
		return res_;
	}
	wchar_t* buffer_ = new wchar_t[len_ + 1];
	if( buffer_ == nullptr){
		return res_;
	}
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer_, len_);
	buffer_[len_] = '\0';
	res_.append(buffer_);
	delete[] buffer_;
    return res_;
}
//---------------------------------------------------------------------------
// convert UTF-8 string to wstring
std::wstring utf8_to_wstring(const std::string& str)
{
#if defined(__WIN64_MODERN)
    std::mbstate_t state_ = std::mbstate_t();
    const char* src_ = reinterpret_cast<const char*>(str.data());
    size_t len_ = std::mbsrtowcs(nullptr, &src_, 0, &state_);
    std::wstring wide_(len_, L'\0');
    std::mbsrtowcs(&wide_[0], &src_, len_, &state_);
    return wide_;
#else
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv_;
    return conv_.from_bytes(str);
    //	std::wstring_convert< std::codecvt_utf8_utf16<wchar_t> > conv_;
    //	return conv_.from_bytes(str);
#endif


}
//---------------------------------------------------------------------------
// convert wstring to UTF-8 string
std::string wstring_to_utf8(const std::wstring& str)
{
#if defined(__WIN64_MODERN)
    std::mbstate_t state_ = std::mbstate_t();
    const wchar_t* src_ = str.c_str();
    size_t len_ = std::wcsrtombs(nullptr, &src_, 0, &state_);
    std::string utf8_(len_, '\0');
    std::wcsrtombs(&utf8_[0], &src_, len_, &state_);
    return utf8_;
#else
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv_;
    return conv_.to_bytes(str);
    //	std::wstring_convert< std::codecvt_utf8_utf16<wchar_t> > conv_;
    //	return conv_.to_bytes(str);
#endif



}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------