//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_mappingH
#define hahaha_parameter_deal_xml_mappingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <libxml\parser.h>
#include <libxml\tree.h>
#include <iconv\iconv.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml;
class hahaha_parameter_deal_xml_node;
class hahaha_parameter_deal_xml_attribute;
class hahaha_parameter_deal_xml_item;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_mapping
{
public:
	hahaha_parameter_deal_xml_mapping();
	~hahaha_parameter_deal_xml_mapping();

	hahaha_parameter_deal_xml_mapping(const hahaha_parameter_deal_xml_mapping& hpdxm);
    hahaha_parameter_deal_xml_mapping(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
	hahaha_parameter_deal_xml_mapping& operator=(const hahaha_parameter_deal_xml_mapping& hpdxm);
    hahaha_parameter_deal_xml_mapping& operator=(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
	void Copy(const hahaha_parameter_deal_xml_mapping& hpdxm);
    void Move(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
public:
	int Reset();
public:
    virtual halib_def::result Prepare_Node(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
    virtual halib_def::result Prepare_Attribute(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
	virtual halib_def::result Prepare_Value(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
    virtual halib_def::result Prepare(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& node
	);
	virtual halib_def::result Mapping(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& node
	);
public:

public:

public:
	virtual halib_def::result Load(const std::wstring& file_name);
	virtual halib_def::result Save(const std::wstring& file_name);
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
