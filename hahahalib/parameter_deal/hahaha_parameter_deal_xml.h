//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xmlH
#define hahaha_parameter_deal_xmlH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <libxml\parser.h>
#include <libxml\tree.h>
#include <iconv\iconv.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_node;
class hahaha_parameter_deal_xml_attribute;
class hahaha_parameter_deal_xml_mapping;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml
{
public:
	hahaha_parameter_deal_xml();
	~hahaha_parameter_deal_xml();

	hahaha_parameter_deal_xml(const hahaha_parameter_deal_xml& hpdx);
    hahaha_parameter_deal_xml(hahaha_parameter_deal_xml&& hpdx) noexcept;
	hahaha_parameter_deal_xml& operator=(const hahaha_parameter_deal_xml& hpdx);
    hahaha_parameter_deal_xml& operator=(hahaha_parameter_deal_xml&& hpdx) noexcept;
	void Copy(const hahaha_parameter_deal_xml& hpdx);
    void Move(hahaha_parameter_deal_xml&& hpdx) noexcept;
public:
	int Reset();

public:
	virtual halib_def::result Read();
	virtual halib_def::result Write();
public:
	halib_def::result Value_To_Xml(std::wstring & xml_wstring,
		const halib_def::type_variable& type,
		void* value
	);
	halib_def::result Xml_To_Value(std::wstring & xml_wstring,
		const halib_def::type_variable& type,
		void* value
	);
public:
	virtual halib_def::result Load(hahahalib::hahaha_parameter_deal_xml_mapping& mapping);
	virtual halib_def::result Save(hahahalib::hahaha_parameter_deal_xml_mapping& mapping);

	halib_def::result Prepare(
        std::vector<std::wstring>& node_names,
		hahaha_parameter_deal_xml_node& root,
		hahaha_parameter_deal_xml_node& node,
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
		xmlDocPtr xml_doc,
		xmlNodePtr xml_node_root,
		xmlNodePtr xml_node_cur

	);

	halib_def::result Load(
		std::vector<std::wstring>& node_names,
		hahaha_parameter_deal_xml_node& root,
		hahaha_parameter_deal_xml_node& node,
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
		xmlDocPtr xml_doc,
		xmlNodePtr xml_node_root,
		xmlNodePtr xml_node_cur

	);

	halib_def::result Save(
		hahaha_parameter_deal_xml_node& root,
		hahaha_parameter_deal_xml_node& node,
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
		std::ofstream& out,
		int& tab
	);
public:
	std::wstring File_Name_;

	std::unique_ptr<hahaha_parameter_deal_xml_node> Node_;

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
