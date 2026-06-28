//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_nodeH
#define hahaha_parameter_deal_xml_nodeH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
#include <define\xml\hahaha_define_xml_type.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_attribute;
class hahaha_parameter_deal_xml_node;
class hahaha_parameter_deal_xml_item;
class hahaha_parameter_deal_xml;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_node
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_node();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_xml_node();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_xml_node(const hahaha_parameter_deal_xml_node& hpdxn);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_xml_node(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_xml_node& operator=(const hahaha_parameter_deal_xml_node& hpdxn);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_xml_node& operator=(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_xml_node& hpdxn);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 加入新的節點、屬性或資料項目。
	halib_def::result Add(
		const std::vector<hahahalib::hahaha_parameter_deal_xml_item>& items
	);
	// 搜尋符合條件的節點或資料項目。
	halib_def::result Find(
		const std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node*& node_target
	);
public:
	std::wstring Name_;
    halib_def::xml_type Xml_Type_;
	halib_def::type_variable Type_;
	void* Value_;
public:
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_attribute>> Attributes_;
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_node>> Nodes_;
public:

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
