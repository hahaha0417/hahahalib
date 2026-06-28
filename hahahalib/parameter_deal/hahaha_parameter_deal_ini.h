//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_iniH
#define hahaha_parameter_deal_iniH
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
class hahaha_parameter_deal_ini_node;
class hahaha_parameter_deal_ini_ini;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_ini
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_ini();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_ini();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_ini(const hahaha_parameter_deal_ini& hpdi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_ini(hahaha_parameter_deal_ini&& hpdi) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_ini& operator=(const hahaha_parameter_deal_ini& hpdi);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_ini& operator=(hahaha_parameter_deal_ini&& hpdi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_ini& hpdi);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_ini&& hpdi) noexcept;
public:
	// 重設內部狀態。
	virtual int Reset();
public:
	// 預先整理資料結構，供後續 mapping 或輸出使用。
	virtual halib_def::result Prepare();
	// 依目前規則執行資料欄位對映。
	virtual halib_def::result Mapping();
public:
	// 讀取指定資料。
	virtual halib_def::result Read();
	// 寫入指定資料。
	virtual halib_def::result Write();
public:
	// 載入外部資料。
	virtual halib_def::result Load(const std::wstring& file_name);
	// 儲存目前資料。
	virtual halib_def::result Save(const std::wstring& file_name);

	// 載入外部資料。
	virtual halib_def::result Load(hahahalib::hahaha_parameter_deal_ini& ini);
	// 儲存目前資料。
	virtual halib_def::result Save(hahahalib::hahaha_parameter_deal_ini& ini);
public:
	std::wstring File_Name_;

	std::unique_ptr<hahaha_parameter_deal_ini_node> Node_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
