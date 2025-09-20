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
	if (str.empty()) return {};
    int needed = ::MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                                       str.data(), static_cast<int>(str.size()),
                                       nullptr, 0);
    if (needed <= 0) return {};
    std::wstring out(static_cast<size_t>(needed), L'\0');
    ::MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS,
                          str.data(), static_cast<int>(str.size()),
                          out.data(), needed);
    return out;


}
//---------------------------------------------------------------------------
inline int narrow_size(size_t n) {
    return n > static_cast<size_t>(INT_MAX) ? INT_MAX : static_cast<int>(n);
}
//---------------------------------------------------------------------------
// convert wstring to UTF-8 string
std::string wstring_to_utf8(const std::wstring& str)
{
	if (str.empty()) return {};
    int needed = ::WideCharToMultiByte(CP_UTF8, 0,
                                       str.data(), narrow_size(str.size()),
                                       nullptr, 0, nullptr, nullptr);
    if (needed <= 0) return {};
    std::string out(needed, '\0');
    ::WideCharToMultiByte(CP_UTF8, 0,
                          str.data(), narrow_size(str.size()),
                          out.data(), needed, nullptr, nullptr);
    return out;



}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------