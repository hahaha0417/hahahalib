//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_ini_itemH
#define hahaha_parameter_deal_ini_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_ini_item
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_ini_item();
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_ini_item(
		const std::wstring& section,  // INI 或設定檔中的區段名稱。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::type_variable& type,
		void* variable
	);
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_ini_item();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_ini_item(const hahaha_parameter_deal_ini_item& hpdii);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_ini_item(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_ini_item& operator=(const hahaha_parameter_deal_ini_item& hpdii);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_ini_item& operator=(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_ini_item& hpdii);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
	std::wstring Section_;
	std::wstring Name_;
	halib_def::type_variable Type_;
	void* Variable_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
