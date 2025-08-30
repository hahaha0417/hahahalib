//---------------------------------------------------------------------------

#include <vcl.h>
//---------------------------------------------------------------------------

#pragma hdrstop
#include <parameter_mapping\base\hahaha_parameter_mapping_item.h>
#include "hahaha_parameter_mapping.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_mapping::hahaha_parameter_mapping()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping::~hahaha_parameter_mapping()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_mapping::hahaha_parameter_mapping(const hahaha_parameter_mapping& hpm)
{
    Reset();
	Copy(hpm);
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping::hahaha_parameter_mapping(hahaha_parameter_mapping&& hpm) noexcept
{
    Move(std::move(hpm));

}
//---------------------------------------------------------------------------
hahaha_parameter_mapping& hahaha_parameter_mapping::operator=(const hahaha_parameter_mapping& hpm)
{
	Copy(hpm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_mapping& hahaha_parameter_mapping::operator=(hahaha_parameter_mapping&& hpm) noexcept
{
	if (this != &hpm)
    {
        Move(std::move(hpm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_mapping::Copy(const hahaha_parameter_mapping& hpm)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_mapping::Move(hahaha_parameter_mapping&& hpm) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_parameter_mapping::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_mapping::Deal(const std::vector<hahaha_parameter_mapping_item>& items, halib_def::parameter_mapping_type type)
{
    if(type == halib_def::parameter_mapping_type::PARAMETER_TO_FIELD)
    {
        return Parameter_To_Field(items);
    }
    else if(type == halib_def::parameter_mapping_type::FIELD_TO_PARAMETER)
    {
        return Field_To_Parameter(items);
    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_mapping::Parameter_To_Field(const std::vector<hahaha_parameter_mapping_item>& items)
{
    int n = items.size();

    for(int i = 0; i < n; i++)
    {
        TObject* obj_ = (TObject*)items[i].Object_;
        if(obj_->ClassName() == L"TEdit")
        {
            if(items[i].Field_ == halib_def::vcl_field::TEXT)
            {
                TEdit* edit_ = (TEdit*)items[i].Object_;
                if(items[i].Type_ == halib_def::type_variable::INT)
                {
                    int& variable_ = *(int*)items[i].Variable_;
                    edit_->Text = variable_;
                }
                else if(items[i].Type_ == halib_def::type_variable::FLOAT)
                {
                    float& variable_ = *(float*)items[i].Variable_;
                    edit_->Text = variable_;
                }
                else if(items[i].Type_ == halib_def::type_variable::DOUBLE)
                {
                    double& variable_ = *(double*)items[i].Variable_;
                    edit_->Text = variable_;
                }
                else if(items[i].Type_ == halib_def::type_variable::WSTRING)
                {
                    std::wstring& variable_ = *(std::wstring*)items[i].Variable_;
                    edit_->Text = variable_.c_str();
                }
            }

        }
        else if(obj_->ClassName() == L"TComboBox")
        {
            if(items[i].Field_ == halib_def::vcl_field::ITEM_INDEX)
            {
                TComboBox* combo_box_ = (TComboBox*)items[i].Object_;
                if(items[i].Type_ == halib_def::type_variable::INT)
                {
                    int& variable_ = *(int*)items[i].Variable_;
                    combo_box_->ItemIndex = variable_;
                }
                else if(items[i].Type_ == halib_def::type_variable::WSTRING)
                {
                    std::wstring& variable_ = *(std::wstring*)items[i].Variable_;
                    int index_ = combo_box_->Items->IndexOf(variable_.c_str());
                    combo_box_->ItemIndex = index_;
                }
            }

        }


    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_mapping::Field_To_Parameter(const std::vector<hahaha_parameter_mapping_item>& items)
{
    int n = items.size();

    for(int i = 0; i < n; i++)
    {
        TObject* obj_ = (TObject*)items[i].Object_;
        if(obj_->ClassName() == L"TEdit")
        {
            if(items[i].Field_ == halib_def::vcl_field::TEXT)
            {
                TEdit* edit_ = (TEdit*)items[i].Object_;
                if(items[i].Type_ == halib_def::type_variable::INT)
                {
                    int& variable_ = *(int*)items[i].Variable_;
                    variable_ = edit_->Text.ToInt();
                }
                else if(items[i].Type_ == halib_def::type_variable::FLOAT)
                {
                    float& variable_ = *(float*)items[i].Variable_;
                    variable_ = edit_->Text.ToDouble();
                }
                else if(items[i].Type_ == halib_def::type_variable::DOUBLE)
                {
                    double& variable_ = *(double*)items[i].Variable_;
                    variable_ = edit_->Text.ToDouble();
                }
                else if(items[i].Type_ == halib_def::type_variable::WSTRING)
                {
                    std::wstring& variable_ = *(std::wstring*)items[i].Variable_;
                    variable_ = edit_->Text.c_str();
                }
            }

        }
        else if(obj_->ClassName() == L"TComboBox")
        {
            if(items[i].Field_ == halib_def::vcl_field::ITEM_INDEX)
            {
                TComboBox* combo_box_ = (TComboBox*)items[i].Object_;
                if(items[i].Type_ == halib_def::type_variable::INT)
                {
                    int& variable_ = *(int*)items[i].Variable_;
                    variable_ = combo_box_->ItemIndex;
                }
                else if(items[i].Type_ == halib_def::type_variable::WSTRING)
                {
                    std::wstring& variable_ = *(std::wstring*)items[i].Variable_;
                    variable_ = combo_box_->Text.c_str();
                }
            }
            else if(items[i].Type_ == halib_def::type_variable::WSTRING)
            {

            }
        }


    }

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------