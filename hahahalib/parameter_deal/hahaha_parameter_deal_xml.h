//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xmlH
#define hahaha_parameter_deal_xmlH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <libxml\parser.h>
#include <libxml\tree.h>
#include <iconv\iconv.h>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml_node;
class hahaha_parameter_deal_xml_attribute;
class hahaha_parameter_deal_xml_mapping;
//---------------------------------------------------------------------------
class hahaha_parameter_deal_xml
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml();
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_xml();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_xml(const hahaha_parameter_deal_xml& hpdx);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_xml(hahaha_parameter_deal_xml&& hpdx) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_xml& operator=(const hahaha_parameter_deal_xml& hpdx);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_xml& operator=(hahaha_parameter_deal_xml&& hpdx) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_xml& hpdx);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_xml&& hpdx) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
	// 讀取指定資料。
	virtual halib_def::result Read();
	// 寫入指定資料。
	virtual halib_def::result Write();
public:
	// 把一般值寫入 XML 結構。
	halib_def::result Value_To_Xml(std::wstring & xml_wstring,
		const halib_def::type_variable& type,  // 要轉換的資料型別。
		void* value  // 指向實際資料內容的指標。
	);
	// 從 XML 結構讀回一般值。
	halib_def::result Xml_To_Value(std::wstring & xml_wstring,
		const halib_def::type_variable& type,  // 要轉換的資料型別。
		void* value  // 指向要接收結果的資料指標。
	);
public:
	// 載入外部資料。
	virtual halib_def::result Load(hahahalib::hahaha_parameter_deal_xml_mapping& mapping);
	// 儲存目前資料。
	virtual halib_def::result Save(hahahalib::hahaha_parameter_deal_xml_mapping& mapping);

	// 預先整理資料結構，供後續 mapping 或輸出使用。
	halib_def::result Prepare(
        std::vector<std::wstring>& node_names,  // 目前處理到的 XML 節點路徑。
		hahaha_parameter_deal_xml_node& root,  // 整份 XML 的根節點資料。
		hahaha_parameter_deal_xml_node& node,  // 目前正在處理的節點資料。
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,  // 欄位與 XML 的對映設定。
		xmlDocPtr xml_doc,  // libxml 使用的文件物件。
		xmlNodePtr xml_node_root,  // libxml 的根節點指標。
		xmlNodePtr xml_node_cur  // 目前遞迴處理到的 XML 節點。

	);

	// 載入外部資料。
	halib_def::result Load(
		std::vector<std::wstring>& node_names,  // 目前處理到的 XML 節點路徑。
		hahaha_parameter_deal_xml_node& root,  // 整份 XML 的根節點資料。
		hahaha_parameter_deal_xml_node& node,  // 目前正在處理的節點資料。
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,  // 欄位與 XML 的對映設定。
		xmlDocPtr xml_doc,  // libxml 使用的文件物件。
		xmlNodePtr xml_node_root,  // libxml 的根節點指標。
		xmlNodePtr xml_node_cur  // 目前遞迴處理到的 XML 節點。

	);

	// 儲存目前資料。
	halib_def::result Save(
		hahaha_parameter_deal_xml_node& root,  // 整份 XML 的根節點資料。
		hahaha_parameter_deal_xml_node& node,  // 目前要輸出的節點資料。
		hahahalib::hahaha_parameter_deal_xml_mapping& mapping,  // 欄位與 XML 的對映設定。
		std::ofstream& out,  // 寫出 XML 文字的輸出串流。
		int& tab  // 目前輸出縮排層級。
	);
public:
	std::wstring File_Name_;

	std::unique_ptr<hahaha_parameter_deal_xml_node> Node_;

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
