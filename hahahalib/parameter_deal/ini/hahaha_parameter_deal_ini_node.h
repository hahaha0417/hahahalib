//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_ini_nodeH
#define hahaha_parameter_deal_ini_nodeH
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
class hahaha_parameter_deal_ini_item;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_ini_node
{
public:
	hahaha_parameter_deal_ini_node();
	~hahaha_parameter_deal_ini_node();

	hahaha_parameter_deal_ini_node(const hahaha_parameter_deal_ini_node& hpdin);
    hahaha_parameter_deal_ini_node(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
	hahaha_parameter_deal_ini_node& operator=(const hahaha_parameter_deal_ini_node& hpdin);
    hahaha_parameter_deal_ini_node& operator=(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
	void Copy(const hahaha_parameter_deal_ini_node& hpdin);
    void Move(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
public:
	int Reset();
public:
	halib_def::result Add(std::vector<hahaha_parameter_deal_ini_item>& list);
	halib_def::result Add(const std::vector<hahaha_parameter_deal_ini_item>& list);
public:
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item>> Items_;
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
