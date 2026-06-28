//---------------------------------------------------------------------------

#ifndef hahaha_memory_mappingH
#define hahaha_memory_mappingH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_memory_mapping
{
public:
    // 建構物件並初始化預設狀態。
    hahaha_memory_mapping();
    // 解構物件並釋放相關資源。
    ~hahaha_memory_mapping();

    // 以既有物件內容建構新的物件實例。
    hahaha_memory_mapping(const hahaha_memory_mapping& hmm);
    // 以移動方式建構物件並接手既有資源。
    hahaha_memory_mapping(hahaha_memory_mapping&& hmm) noexcept;
    // 複製指派目前物件內容。
    hahaha_memory_mapping& operator=(const hahaha_memory_mapping& hmm);
    // 移動指派目前物件內容。
    hahaha_memory_mapping& operator=(hahaha_memory_mapping&& hmm) noexcept;
public:
    // 複製來源物件的內部狀態。
    void Copy(const hahaha_memory_mapping& hmm);
    // 接手來源物件的內部資源。
    void Move(hahaha_memory_mapping&& hmm) noexcept;
public:

    // 建立所需資源並完成初始化。
    int Create(const std::wstring& name, size_t size);
    // 開啟指定資源或建立連線。
    int Open(const std::wstring& name);
    // 關閉並釋放目前持有的資源。
    int Close();

    // 重設內部狀態。
    int Reset();



public:
    HANDLE Handle_;
    // 映射指標
    void*  Pointer_;
    // Create大小，Open沒大小
    size_t Size_;
    bool Is_Open_;
    std::wstring Name_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif