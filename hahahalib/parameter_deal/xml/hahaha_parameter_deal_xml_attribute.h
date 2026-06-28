//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_attributeH
#define hahaha_parameter_deal_xml_attributeH
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_xml_attribute
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_attribute();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_xml_attribute();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_xml_attribute(const hahaha_parameter_deal_xml_attribute& hpdxa);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_xml_attribute(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_xml_attribute& operator=(const hahaha_parameter_deal_xml_attribute& hpdxa);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_xml_attribute& operator=(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_xml_attribute& hpdxa);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
	std::wstring Name_;
	halib_def::type_variable Type_;
	void* Value_;
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif