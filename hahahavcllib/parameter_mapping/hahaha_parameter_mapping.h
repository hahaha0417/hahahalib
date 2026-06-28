//---------------------------------------------------------------------------

#ifndef hahaha_parameter_mappingH
#define hahaha_parameter_mappingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\parameter_mapping\hahaha_define_parameter_mapping_type.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_mapping_item;
//---------------------------------------------------------------------------

class hahaha_parameter_mapping
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_mapping();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_mapping();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_mapping(const hahaha_parameter_mapping& hpm);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_mapping(hahaha_parameter_mapping&& hpm) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_mapping& operator=(const hahaha_parameter_mapping& hpm);
    // 移動指派目前物件內容。
    hahaha_parameter_mapping& operator=(hahaha_parameter_mapping&& hpm) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_mapping& hpm);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_mapping&& hpm) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 依目前 mapping 規則處理欄位同步。
    virtual halib_def::result Deal(const std::vector<hahaha_parameter_mapping_item>& items, halib_def::parameter_mapping_type type);
public:
    // 把參數值寫回 UI 欄位。
    virtual halib_def::result Parameter_To_Field(const std::vector<hahaha_parameter_mapping_item>& items);
	// 把 UI 欄位值回寫到參數。
	virtual halib_def::result Field_To_Parameter(const std::vector<hahaha_parameter_mapping_item>& items);
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
