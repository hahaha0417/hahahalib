//---------------------------------------------------------------------------

#ifndef hahaha_pipeline_processH
#define hahaha_pipeline_processH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <windows.h>
#include <string>
//---------------------------------------------------------------------------

namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_pipeline_process
{
public:
    hahaha_pipeline_process();
    ~hahaha_pipeline_process();

    hahaha_pipeline_process(const hahaha_pipeline_process& hpp);
    hahaha_pipeline_process(hahaha_pipeline_process&& hpp) noexcept;
    hahaha_pipeline_process& operator=(const hahaha_pipeline_process& hpp);
    hahaha_pipeline_process& operator=(hahaha_pipeline_process&& hpp) noexcept;

public:
    void Copy(const hahaha_pipeline_process& hpp);
    void Move(hahaha_pipeline_process&& hpp) noexcept;

public:
    // 建立有 pipe 的子行程
    // command 例如：L"\"C:\\Path\\Child.exe\" -arg1 -arg2"
    int Create(const std::wstring& command);

    // 關閉所有 handle（不強制 TerminateProcess）
    int Close();

    // 強制結束子行程（如果還在）
    int Terminate(DWORD exit_code = 0);

    int Reset();


public:
    // ★ 新增：跨進程文字通訊
    int Write_Line(const std::wstring& text);
    int Read_Line(std::wstring& text, DWORD timeout = INFINITE);
public:


    bool Is_Open() const { return Is_Open_; }

public:
    PROCESS_INFORMATION Information_Process_;
    STARTUPINFOW        Information_Startup_;

    // pipe：父進程持有的端點
    // 寫入子行程 stdin 的 handle（父進程持有）
    HANDLE Child_Std_IN_W_;   // parent write → child stdin
    // 讀取子行程 stdout 的 handle（父進程持有）
    HANDLE Child_Std_OUT_R_;  // parent read  ← child stdout

    // 這兩個是只給子行程用的端點（CreatePipe 時暫時用，之後在父進程關掉）
    HANDLE Child_Std_IN_R_;
    HANDLE Child_Std_OUT_W_;

    bool Is_Open_;
    std::wstring Command_;
};

//---------------------------------------------------------------------------
} // namespace hahahalib
//---------------------------------------------------------------------------

#endif

