//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_xml_attribute.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute::hahaha_parameter_deal_xml_attribute()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute::~hahaha_parameter_deal_xml_attribute()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute::hahaha_parameter_deal_xml_attribute(const hahaha_parameter_deal_xml_attribute& hpdxa)
{
	Reset();
	Copy(hpdxa);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute::hahaha_parameter_deal_xml_attribute(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept
{
	Move(std::move(hpdxa));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute& hahaha_parameter_deal_xml_attribute::operator=(const hahaha_parameter_deal_xml_attribute& hpdxa)
{
	Copy(hpdxa);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_attribute& hahaha_parameter_deal_xml_attribute::operator=(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept
{
	if (this != &hpdxa)
    {
        Move(std::move(hpdxa));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_attribute::Copy(const hahaha_parameter_deal_xml_attribute& hpdxa)
{
    Name_ = hpdxa.Name_;
    Type_ = hpdxa.Type_;
	Value_ = hpdxa.Value_;

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_attribute::Move(hahaha_parameter_deal_xml_attribute&& hpdxa) noexcept
{
    Name_ = std::move(hpdxa.Name_);
    Type_ = hpdxa.Type_;
	Value_ = hpdxa.Value_;

    
}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_xml_attribute::Reset()
{
    Name_ = L"";
    Type_ = halib_def::type_variable::NONE;
	Value_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------