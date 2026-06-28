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
	// 建構物件並初始化預設狀態。
	hahaha_string_token();
	// 解構物件並釋放相關資源。
	~hahaha_string_token();

	// 以既有物件內容建構新的物件實例。
	hahaha_string_token(const hahaha_string_token& hst);
    // 以移動方式建構物件並接手既有資源。
    hahaha_string_token(hahaha_string_token&& hst) noexcept;
	// 複製指派目前物件內容。
	hahaha_string_token& operator=(const hahaha_string_token& hst);
    // 移動指派目前物件內容。
    hahaha_string_token& operator=(hahaha_string_token&& hst) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_string_token& hst);
    // 接手來源物件的內部資源。
    void Move(hahaha_string_token&& hst) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 解析輸入內容並更新結果。
	int Parser_Delimiter(
		const std::string& str,  // 要解析的原始字串。
		const std::string& delimiter  // 用來分割字串的界定符。
	);
	// 解析輸入內容並更新結果。
	int Parser_Interval(
		const std::string& str,  // 要解析的原始字串。
		const std::string& delimiter_front,  // 區間起始界定符。
		const std::string& delimiter_end  // 區間結束界定符。
	);
public:
	std::vector<std::string> Tokens_;

	std::vector<std::unique_ptr<hahahalib::hahaha_string_token>> String_Tokens_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
