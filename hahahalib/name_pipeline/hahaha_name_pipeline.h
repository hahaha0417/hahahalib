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
    // 建構物件並初始化預設狀態。
    hahaha_name_pipeline();
    // 解構物件並釋放相關資源。
    ~hahaha_name_pipeline();

    // 以既有物件內容建構新的物件實例。
    hahaha_name_pipeline(const hahaha_name_pipeline& hpp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_name_pipeline(hahaha_name_pipeline&& hpp) noexcept;
    // 複製指派目前物件內容。
    hahaha_name_pipeline& operator=(const hahaha_name_pipeline& hpp);
    // 移動指派目前物件內容。
    hahaha_name_pipeline& operator=(hahaha_name_pipeline&& hpp) noexcept;

public:
    // 複製來源物件的內部狀態。
    void Copy(const hahaha_name_pipeline& hpp);
    // 接手來源物件的內部資源。
    void Move(hahaha_name_pipeline&& hpp) noexcept;

public:
    // 重設內部狀態。
    int Reset();

    // Named Pipe Server
    int Create(const std::wstring& name);
    // 等待背景工作、事件或外部程序完成。
    int Wait();

    // Named Pipe Client
    int Connect(const std::wstring& name);

    // Close pipe
    int Close();

    // Text communication
    int Write_Line(const std::wstring& text);
    // 持續讀取一行文字資料。
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
