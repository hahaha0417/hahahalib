//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <fstream>
#include <windows.h>
#include <function\hahaha_function_vector.h>

#include "hahaha_parameter_deal_xml_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	void* variable
)
{
	hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

//    if(type == hadef::type_variable::BOOL)
//	{
//
//	}
//	else
//	{
//		OutputDebugStringW(L"Void類型錯誤");
//	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	bool* variable
)
{
	hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::BOOL)
	{

	}
	else
	{
		OutputDebugStringW(L"Bool類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	int* variable
)
{
	hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::INT)
	{

	}
	else
	{
		OutputDebugStringW(L"Int類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	float* variable
)
{
    hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::FLOAT)
	{

	}
	else
	{
		OutputDebugStringW(L"Float類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	double* variable
)
{
    hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::DOUBLE)
	{

	}
	else
	{
		OutputDebugStringW(L"Double類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	std::string* variable
)
{
    hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::STRING)
	{

	}
	else
	{
		OutputDebugStringW(L"String類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(
	const std::vector<std::wstring>& node_names,
	const std::wstring& name,
	const halib_def::xml_type xml_type,
	const halib_def::type_variable type,
	std::wstring* variable
)
{
    hahahalib::Vector_Copy(node_names, Node_Names_);
	Name_ = name;
	Xml_Type_ = xml_type;
	Type_ = type;
	Variable_ = variable;

	if(type == halib_def::type_variable::WSTRING)
	{

	}
	else
	{
		OutputDebugStringW(L"Wstring類型錯誤");
	}

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::~hahaha_parameter_deal_xml_item()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(const hahaha_parameter_deal_xml_item& hpdxi)
{
    Reset();
	Copy(hpdxi);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item::hahaha_parameter_deal_xml_item(hahaha_parameter_deal_xml_item&& hpdxi) noexcept
{
    Move(std::move(hpdxi));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item& hahaha_parameter_deal_xml_item::operator=(const hahaha_parameter_deal_xml_item& hpdxi)
{
	Copy(hpdxi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_item& hahaha_parameter_deal_xml_item::operator=(hahaha_parameter_deal_xml_item&& hpdxi) noexcept
{
	if (this != &hpdxi)
    {
        Move(std::move(hpdxi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_item::Copy(const hahaha_parameter_deal_xml_item& hpdxi)
{
	hahahalib::Vector_Copy(hpdxi.Node_Names_, Node_Names_);
	Name_ = hpdxi.Name_;
	Xml_Type_ = hpdxi.Xml_Type_;
	Type_ = hpdxi.Type_;
	Variable_ = hpdxi.Variable_;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_item::Move(hahaha_parameter_deal_xml_item&& hpdxi) noexcept
{
	Node_Names_.swap(hpdxi.Node_Names_);
	Name_.swap(hpdxi.Name_);
	Xml_Type_ = hpdxi.Xml_Type_;
	Type_ = hpdxi.Type_;
	Variable_ = hpdxi.Variable_;


}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_xml_item::Reset()
{
	std::vector<std::wstring>().swap(Node_Names_);
	Name_ = L"";
    Xml_Type_ = halib_def::xml_type::NONE;
	Type_ = halib_def::type_variable::NONE;
	Variable_ = nullptr;

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------