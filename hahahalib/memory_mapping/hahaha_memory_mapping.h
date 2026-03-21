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
    hahaha_memory_mapping();
    ~hahaha_memory_mapping();

    hahaha_memory_mapping(const hahaha_memory_mapping& hmm);
    hahaha_memory_mapping(hahaha_memory_mapping&& hmm) noexcept;
    hahaha_memory_mapping& operator=(const hahaha_memory_mapping& hmm);
    hahaha_memory_mapping& operator=(hahaha_memory_mapping&& hmm) noexcept;
public:
    void Copy(const hahaha_memory_mapping& hmm);
    void Move(hahaha_memory_mapping&& hmm) noexcept;
public:

    int Create(const std::wstring& name, size_t size);
    int Open(const std::wstring& name);
    int Close();

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
