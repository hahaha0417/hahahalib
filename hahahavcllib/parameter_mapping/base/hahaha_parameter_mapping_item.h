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
	// 建構物件並初始化預設狀態。
	hahaha_parameter_mapping_item();
    // 建構物件並初始化預設狀態。
    hahaha_parameter_mapping_item(
        void* object,
        halib_def::vcl_field field,
        void* variable,
        halib_def::type_variable type  // 描述資料型別的列舉值。
    );


public:
	// 解構物件並釋放相關資源。
	~hahaha_parameter_mapping_item();

	// 以既有物件內容建構新的物件實例。
	hahaha_parameter_mapping_item(const hahaha_parameter_mapping_item& hpmi);
    // 以移動方式建構物件並接手既有資源。
    hahaha_parameter_mapping_item(hahaha_parameter_mapping_item&& hpmi) noexcept;
	// 複製指派目前物件內容。
	hahaha_parameter_mapping_item& operator=(const hahaha_parameter_mapping_item& hpmi);
    // 移動指派目前物件內容。
    hahaha_parameter_mapping_item& operator=(hahaha_parameter_mapping_item&& hpmi) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_parameter_mapping_item& hpmi);
    // 接手來源物件的內部資源。
    void Move(hahaha_parameter_mapping_item&& hpmi) noexcept;
public:
	// 重設內部狀態。
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
