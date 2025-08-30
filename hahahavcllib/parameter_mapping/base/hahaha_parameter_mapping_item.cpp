//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_mapping_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_mapping_item::hahaha_parameter_mapping_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping_item::hahaha_parameter_mapping_item(
    void* object,
    halib_def::vcl_field field,
    void* variable,
    halib_def::type_variable type
)
{
    Object_ = object;
    Field_ = field;
    Variable_ = variable;
    Type_ = type;

}
//---------------------------------------------------------------------------

hahaha_parameter_mapping_item::~hahaha_parameter_mapping_item()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_mapping_item::hahaha_parameter_mapping_item(const hahaha_parameter_mapping_item& hpmi)
{
    // Reset();
	Copy(hpmi);
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping_item::hahaha_parameter_mapping_item(hahaha_parameter_mapping_item&& hpmi) noexcept
{
    Move(std::move(hpmi));

}
//---------------------------------------------------------------------------
hahaha_parameter_mapping_item& hahaha_parameter_mapping_item::operator=(const hahaha_parameter_mapping_item& hpmi)
{
	Copy(hpmi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping_item& hahaha_parameter_mapping_item::operator=(hahaha_parameter_mapping_item&& hpmi) noexcept
{
	if (this != &hpmi)
    {
        Move(std::move(hpmi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_mapping_item::Copy(const hahaha_parameter_mapping_item& hpmi)
{
    Object_ = hpmi.Object_;
    Field_ = hpmi.Field_;
    Variable_ = hpmi.Variable_;
    Type_ = hpmi.Type_;
}
//---------------------------------------------------------------------------
void hahaha_parameter_mapping_item::Move(hahaha_parameter_mapping_item&& hpmi) noexcept
{
    Object_ = hpmi.Object_;
    Field_ = hpmi.Field_;
    Variable_ = hpmi.Variable_;
    Type_ = hpmi.Type_;

    hpmi.Reset();
}
//---------------------------------------------------------------------------
int hahaha_parameter_mapping_item::Reset()
{
    Object_ = nullptr;
    Field_ = halib_def::vcl_field::NONE;
    Variable_ = nullptr;
    Type_ = halib_def::type_variable::NONE;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------