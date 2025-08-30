//---------------------------------------------------------------------------

#pragma hdrstop

#include <parameter_deal\hahaha_parameter_deal_xml.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>

#include "hahaha_parameter_deal_xml_mapping.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping::hahaha_parameter_deal_xml_mapping()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping::~hahaha_parameter_deal_xml_mapping()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping::hahaha_parameter_deal_xml_mapping(const hahaha_parameter_deal_xml_mapping& hpdxm)
{
    Reset();
	Copy(hpdxm);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping::hahaha_parameter_deal_xml_mapping(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept
{
    Move(std::move(hpdxm));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping& hahaha_parameter_deal_xml_mapping::operator=(const hahaha_parameter_deal_xml_mapping& hpdxm)
{
	Copy(hpdxm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_mapping& hahaha_parameter_deal_xml_mapping::operator=(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept
{
	if (this != &hpdxm)
    {
        Move(std::move(hpdxm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_mapping::Copy(const hahaha_parameter_deal_xml_mapping& hpdxm)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_mapping::Move(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_xml_mapping::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Prepare_Node(
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
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Prepare_Attribute(
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
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Prepare_Value(
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
)
{


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Prepare(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& node
)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Mapping(
    hahahalib::hahaha_parameter_deal_xml& xml,
    std::vector<std::wstring>& node_names,
    hahahalib::hahaha_parameter_deal_xml_node& node
)
{
    return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Load(const std::wstring& file_name)
{
	hahahalib::hahaha_parameter_deal_xml hpdx_;
    hpdx_.File_Name_ = file_name;

	halib_def::result result_ = hpdx_.Load(*this);

	return result_;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_mapping::Save(const std::wstring& file_name)
{
	hahahalib::hahaha_parameter_deal_xml hpdx_;
	hpdx_.File_Name_ = file_name;

	halib_def::result result_ = hpdx_.Save(*this);

	return result_;

}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------