#ifndef hahaha_name_pipelineH
#define hahaha_name_pipelineH
#pragma once

#include <windows.h>
#include <string>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_name_pipeline
{
public:
    hahaha_name_pipeline();
    ~hahaha_name_pipeline();

    hahaha_name_pipeline(const hahaha_name_pipeline& hpp);
    hahaha_name_pipeline(hahaha_name_pipeline&& hpp) noexcept;
    hahaha_name_pipeline& operator=(const hahaha_name_pipeline& hpp);
    hahaha_name_pipeline& operator=(hahaha_name_pipeline&& hpp) noexcept;

public:
    void Copy(const hahaha_name_pipeline& hpp);
    void Move(hahaha_name_pipeline&& hpp) noexcept;

public:
    int Reset();

    // Named Pipe Server
    int Create(const std::wstring& name);
    int Wait();

    // Named Pipe Client
    int Connect(const std::wstring& name);

    // Close pipe
    int Close();

    // Text communication
    int Write_Line(const std::wstring& text);
    int Read_Line(std::wstring& text, DWORD timeout = INFINITE);

public:
    bool Is_Open_;
    bool Is_Connect_;
    HANDLE Pipeline_;
    std::wstring Name_;
};
//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------
#endif

