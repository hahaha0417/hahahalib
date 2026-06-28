//---------------------------------------------------------------------------

#ifndef hahaha_parameter_deal_xml_itemH
#define hahaha_parameter_deal_xml_itemH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
#include <define\hahaha_define_type_variable.h>
#include <define\xml\hahaha_define_xml_type.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_parameter_deal_xml_item
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item();
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		void* variable  // 指向實際綁定變數的通用指標。
	);
    // 建構物件並初始化預設狀態。
    hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		bool* variable  // 指向實際綁定的布林變數。
	);
    // 建構物件並初始化預設狀態。
    hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		int* variable  // 指向實際綁定的整數變數。
	);
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		float* variable  // 指向實際綁定的浮點變數。
	);
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		double* variable  // 指向實際綁定的 double 變數。
	);
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		std::string* variable  // 指向實際綁定的窄字串變數。
	);
	// 建構物件並初始化預設狀態。
	hahaha_parameter_deal_xml_item(
		const std::vector<std::wstring>& node_names,  // 對應到 XML 階層的節點名稱路徑。
		const std::wstring& name,  // 欄位名稱、鍵值名稱或識別名稱。
		const halib_def::xml_type xml_type,  // 這個欄位在 XML 中的資料角色。
		const halib_def::type_variable type,  // 這個欄位對應的實際資料型別。
		std::wstring* variable  // 指向實際綁定的寬字串變數。
	);
	// 解構物件並釋放相關資源。
	~hahaha_parameter_deal_xml_item();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_deal_xml_item(const hahaha_parameter_deal_xml_item& hpdxi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_deal_xml_item(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_deal_xml_item& operator=(const hahaha_parameter_deal_xml_item& hpdxi);
    // 移動指派目前物件內容。
    hahaha_parameter_deal_xml_item& operator=(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_deal_xml_item& hpdxi);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_deal_xml_item&& hpdxi) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
	std::vector<std::wstring> Node_Names_;
	std::wstring Name_;
    halib_def::xml_type Xml_Type_;
	halib_def::type_variable Type_;
	void* Variable_;



};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
