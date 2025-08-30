//---------------------------------------------------------------------------

#ifndef hahaha_parameter_mappingH
#define hahaha_parameter_mappingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <define\parameter_mapping\hahaha_define_parameter_mapping_type.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_mapping_item;
//---------------------------------------------------------------------------

class hahaha_parameter_mapping
{
public:
	hahaha_parameter_mapping();
	~hahaha_parameter_mapping();

	hahaha_parameter_mapping(const hahaha_parameter_mapping& hpm);
    hahaha_parameter_mapping(hahaha_parameter_mapping&& hpm) noexcept;
	hahaha_parameter_mapping& operator=(const hahaha_parameter_mapping& hpm);
    hahaha_parameter_mapping& operator=(hahaha_parameter_mapping&& hpm) noexcept;
	void Copy(const hahaha_parameter_mapping& hpm);
    void Move(hahaha_parameter_mapping&& hpm) noexcept;
public:
	int Reset();

public:
    virtual halib_def::result Deal(const std::vector<hahaha_parameter_mapping_item>& items, halib_def::parameter_mapping_type type);
public:
    virtual halib_def::result Parameter_To_Field(const std::vector<hahaha_parameter_mapping_item>& items);
	virtual halib_def::result Field_To_Parameter(const std::vector<hahaha_parameter_mapping_item>& items);
public:
public:
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
