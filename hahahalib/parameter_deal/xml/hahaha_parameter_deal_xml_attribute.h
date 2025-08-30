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
	hahaha_parameter_deal_xml_attribute();
	~hahaha_parameter_deal_xml_attribute();

	hahaha_parameter_deal_xml_attribute(const hahaha_parameter_deal_xml_attribute& hpdxa);
    hahaha_parameter_deal_xml_attribute(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
	hahaha_parameter_deal_xml_attribute& operator=(const hahaha_parameter_deal_xml_attribute& hpdxa);
    hahaha_parameter_deal_xml_attribute& operator=(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
	void Copy(const hahaha_parameter_deal_xml_attribute& hpdxa);
    void Move(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept;
public:
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
