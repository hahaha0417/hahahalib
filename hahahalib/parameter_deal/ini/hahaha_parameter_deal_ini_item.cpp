//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_ini_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item::hahaha_parameter_deal_ini_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item::hahaha_parameter_deal_ini_item(
	const std::wstring& section,
	const std::wstring& name,
	const halib_def::type_variable& type,
	void* variable
)
{
	Section_ = section;
	Name_ = name;
	Type_ = type;
	Variable_ = variable;

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item::~hahaha_parameter_deal_ini_item()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item::hahaha_parameter_deal_ini_item(const hahaha_parameter_deal_ini_item& hpdii)
{
	Reset();
	Copy(hpdii);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item::hahaha_parameter_deal_ini_item(hahaha_parameter_deal_ini_item&& hpdii) noexcept
{
	Reset();
	Copy(hpdii);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item& hahaha_parameter_deal_ini_item::operator=(const hahaha_parameter_deal_ini_item& hpdii)
{
	Copy(hpdii);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_item& hahaha_parameter_deal_ini_item::operator=(hahaha_parameter_deal_ini_item&& hpdii) noexcept
{
	if (this != &hpdii)
    {
        Move(std::move(hpdii));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini_item::Copy(const hahaha_parameter_deal_ini_item& hpdii)
{
	Section_ = hpdii.Section_;
	Name_ = hpdii.Name_;
	Type_ = hpdii.Type_;
	Variable_ = hpdii.Variable_;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini_item::Move(hahaha_parameter_deal_ini_item&& hpdii) noexcept
{
	Section_ = std::move(hpdii.Section_);
	Name_ = std::move(hpdii.Name_);
	Type_ = hpdii.Type_;
	Variable_ = hpdii.Variable_;

    hpdii.Reset();
}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_ini_item::Reset()
{
    Section_ = L"";
    Name_ = L"";
	Type_ = halib_def::type_variable::NONE;
	Variable_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------