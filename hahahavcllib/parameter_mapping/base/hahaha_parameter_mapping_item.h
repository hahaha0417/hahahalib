//---------------------------------------------------------------------------

#ifndef hahaha_parameter_mapping_itemH
#define hahaha_parameter_mapping_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <memory>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <define\vcl\hahaha_define_vcl_field.h>
#include <define\hahaha_define_type_variable.h>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_mapping_item
{
public:
	hahaha_parameter_mapping_item();
    hahaha_parameter_mapping_item(
        void* object,
        halib_def::vcl_field field,
        void* variable,
        halib_def::type_variable type
    );


public:
	~hahaha_parameter_mapping_item();

	hahaha_parameter_mapping_item(const hahaha_parameter_mapping_item& hpmi);
    hahaha_parameter_mapping_item(hahaha_parameter_mapping_item&& hpmi) noexcept;
	hahaha_parameter_mapping_item& operator=(const hahaha_parameter_mapping_item& hpmi);
    hahaha_parameter_mapping_item& operator=(hahaha_parameter_mapping_item&& hpmi) noexcept;
	void Copy(const hahaha_parameter_mapping_item& hpmi);
    void Move(hahaha_parameter_mapping_item&& hpmi) noexcept;
public:
	int Reset();

public:
    void* Object_;
    halib_def::vcl_field Field_;
    void* Variable_;
    halib_def::type_variable Type_;

public:

public:




};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
