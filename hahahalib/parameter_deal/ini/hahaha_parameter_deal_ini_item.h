//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_ini_itemH
#define hahaha_parameter_deal_ini_itemH
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
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_ini_item
{
public:
	hahaha_parameter_deal_ini_item();
	hahaha_parameter_deal_ini_item(
		const std::wstring& section,
		const std::wstring& name,
		const halib_def::type_variable& type,
		void* variable
	);
	~hahaha_parameter_deal_ini_item();

	hahaha_parameter_deal_ini_item(const hahaha_parameter_deal_ini_item& hpdii);
    hahaha_parameter_deal_ini_item(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
	hahaha_parameter_deal_ini_item& operator=(const hahaha_parameter_deal_ini_item& hpdii);
    hahaha_parameter_deal_ini_item& operator=(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
	void Copy(const hahaha_parameter_deal_ini_item& hpdii);
    void Move(hahaha_parameter_deal_ini_item&& hpdii) noexcept;
public:
	int Reset();

public:
	std::wstring Section_;
	std::wstring Name_;
	halib_def::type_variable Type_;
	void* Variable_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
