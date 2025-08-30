//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_itemH
#define hahaha_parameter_deal_xml_itemH
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
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_xml_item
{
public:
	hahaha_parameter_deal_xml_item();
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		void* variable
	);
    hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		bool* variable
	);
    hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		int* variable
	);
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		float* variable
	);
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		double* variable
	);
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		std::string* variable
	);
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,
		const std::wstring& name,
		const halib_def::xml_type xml_type,
		const halib_def::type_variable type,
		std::wstring* variable
	);
	~hahaha_parameter_deal_xml_item();

	hahaha_parameter_deal_xml_item(const hahaha_parameter_deal_xml_item& hpdxi);
    hahaha_parameter_deal_xml_item(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
	hahaha_parameter_deal_xml_item& operator=(const hahaha_parameter_deal_xml_item& hpdxi);
    hahaha_parameter_deal_xml_item& operator=(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
	void Copy(const hahaha_parameter_deal_xml_item& hpdxi);
    void Move(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
public:
	int Reset();

public:
	std::vector<std::wstring> Node_Names_;
	std::wstring Name_;
    halib_def::xml_type Xml_Type_;
	halib_def::type_variable Type_;
	void* Variable_;



};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
