//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_iniH
#define hahaha_parameter_deal_iniH
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
class hahaha_parameter_deal_ini_node;
class hahaha_parameter_deal_ini_ini;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_ini
{
public:
	hahaha_parameter_deal_ini();
	~hahaha_parameter_deal_ini();

	hahaha_parameter_deal_ini(const hahaha_parameter_deal_ini& hpdi);
    hahaha_parameter_deal_ini(hahaha_parameter_deal_ini&& hpdi) noexcept;
	hahaha_parameter_deal_ini& operator=(const hahaha_parameter_deal_ini& hpdi);
    hahaha_parameter_deal_ini& operator=(hahaha_parameter_deal_ini&& hpdi) noexcept;
	void Copy(const hahaha_parameter_deal_ini& hpdi);
    void Move(hahaha_parameter_deal_ini&& hpdi) noexcept;
public:
	virtual int Reset();
public:
	virtual halib_def::result Prepare();
	virtual halib_def::result Mapping();
public:
	virtual halib_def::result Read();
	virtual halib_def::result Write();
public:
	virtual halib_def::result Load(const std::wstring& file_name);
	virtual halib_def::result Save(const std::wstring& file_name);

	virtual halib_def::result Load(hahahalib::hahaha_parameter_deal_ini& ini);
	virtual halib_def::result Save(hahahalib::hahaha_parameter_deal_ini& ini);
public:
	std::wstring File_Name_;

	std::unique_ptr<hahaha_parameter_deal_ini_node> Node_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
