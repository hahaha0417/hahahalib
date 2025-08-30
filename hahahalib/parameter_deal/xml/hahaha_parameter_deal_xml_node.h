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
	hahaha_parameter_deal_xml_node();
	~hahaha_parameter_deal_xml_node();

	hahaha_parameter_deal_xml_node(const hahaha_parameter_deal_xml_node& hpdxn);
    hahaha_parameter_deal_xml_node(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
	hahaha_parameter_deal_xml_node& operator=(const hahaha_parameter_deal_xml_node& hpdxn);
    hahaha_parameter_deal_xml_node& operator=(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
	void Copy(const hahaha_parameter_deal_xml_node& hpdxn);
    void Move(hahaha_parameter_deal_xml_node&& hpdxn) noexcept;
public:
	int Reset();
public:
	halib_def::result Add(
		const std::vector<hahahalib::hahaha_parameter_deal_xml_item>& items
	);
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
