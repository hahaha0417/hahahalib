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
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_ini_node();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_ini_node();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_ini_node(const hahaha_parameter_deal_ini_node& hpdin);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_ini_node(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_ini_node& operator=(const hahaha_parameter_deal_ini_node& hpdin);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_ini_node& operator=(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_ini_node& hpdin);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_ini_node&& hpdin) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
	// 加入新的節點、屬性或資料項目。
	halib_def::result Add(std::vector<hahaha_parameter_deal_ini_item>& list);
	// 加入新的節點、屬性或資料項目。
	halib_def::result Add(const std::vector<hahaha_parameter_deal_ini_item>& list);
public:
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item>> Items_;
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
