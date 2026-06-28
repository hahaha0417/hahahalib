//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_mappingH
#define hahaha_parameter_deal_xml_mappingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <libxml\parser.h>
#include <libxml\tree.h>
#include <iconv\iconv.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml;
class hahaha_parameter_deal_xml_node;
class hahaha_parameter_deal_xml_attribute;
class hahaha_parameter_deal_xml_item;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_mapping
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_mapping();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_xml_mapping();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_xml_mapping(const hahaha_parameter_deal_xml_mapping& hpdxm);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_xml_mapping(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_xml_mapping& operator=(const hahaha_parameter_deal_xml_mapping& hpdxm);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_xml_mapping& operator=(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_xml_mapping& hpdxm);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_xml_mapping&& hpdxm) noexcept;
public:
	// 重設內部狀態。
	int Reset();
public:
    // 預先建立 XML node 對映資訊。
    virtual halib_def::result Prepare_Node(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
    // 預先建立 XML attribute 對映資訊。
    virtual halib_def::result Prepare_Attribute(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
	// 預先建立 XML value 對映資訊。
	virtual halib_def::result Prepare_Value(
		hahahalib::hahaha_parameter_deal_xml& xml,
		std::vector<std::wstring>& node_names,
        hahahalib::hahaha_parameter_deal_xml_node& root,
        hahahalib::hahaha_parameter_deal_xml_node& node,
        hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
        xmlDocPtr xml_doc,
        xmlNodePtr xml_node_root,
        xmlNodePtr xml_node_cur,
        std::wstring & xml_wstring,
        const halib_def::type_variable& type,
        void* value
	);
    // 預先整理資料結構，供後續 mapping 或輸出使用。
    virtual halib_def::result Prepare(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& node  // 目前正在處理的 XML 節點。
	);
	// 依目前規則執行資料欄位對映。
	virtual halib_def::result Mapping(
		hahahalib::hahaha_parameter_deal_xml& xml,
        std::vector<std::wstring>& node_names,
		hahahalib::hahaha_parameter_deal_xml_node& node  // 目前正在處理的 XML 節點。
	);
public:

public:

public:
	// 載入外部資料。
	virtual halib_def::result Load(const std::wstring& file_name);
	// 儲存目前資料。
	virtual halib_def::result Save(const std::wstring& file_name);
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
