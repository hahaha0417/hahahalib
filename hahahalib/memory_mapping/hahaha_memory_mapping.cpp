//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_memory_mapping.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//hahahalib::hahaha_memory_mapping memory_mapping_;
//memory_mapping_.Create(L"Global\\Hahaha", 1024);
//
//char* buf = (char*)memory_mapping_.Pointer_;

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
hahaha_memory_mapping::hahaha_memory_mapping()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_memory_mapping::~hahaha_memory_mapping()
{

}
//---------------------------------------------------------------------------
hahaha_memory_mapping::hahaha_memory_mapping(const hahaha_memory_mapping& hmm)
{
    Reset();
    Copy(hmm);
}
//---------------------------------------------------------------------------
hahaha_memory_mapping::hahaha_memory_mapping(hahaha_memory_mapping&& hmm) noexcept
{
    Move(std::move(hmm));
}
//---------------------------------------------------------------------------
hahaha_memory_mapping& hahaha_memory_mapping::operator=(const hahaha_memory_mapping& hmm)
{
    Copy(hmm);
    return *this;
}
//---------------------------------------------------------------------------
hahaha_memory_mapping& hahaha_memory_mapping::operator=(hahaha_memory_mapping&& hmm) noexcept
{
    if (this != &hmm)
    {
        Move(std::move(hmm));
    }

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_memory_mapping::Copy(const hahaha_memory_mapping& hmm)
{
    // 共享記憶體不能直接複製 → 禁止 Copy
    // 你可以選擇 throw 或保持空實作
}
//---------------------------------------------------------------------------
void hahaha_memory_mapping::Move(hahaha_memory_mapping&& hmm) noexcept
{
    Handle_ = hmm.Handle_;
    Pointer_ = hmm.Pointer_;
    Size_ = hmm.Size_;
    Is_Open_ = hmm.Is_Open_;
    Name_ = hmm.Name_;

    hmm.Reset();
}
//---------------------------------------------------------------------------
int hahaha_memory_mapping::Reset()
{

    Handle_ = nullptr;
    Pointer_ = nullptr;
    Size_ = 0;
    Is_Open_ = false;
    Name_ = L"";

    return 0;
}
//---------------------------------------------------------------------------

int hahaha_memory_mapping::Create(const std::wstring& name, size_t size)
{
    if(Is_Open_)
    {
        return 0;
    }

    Handle_ = CreateFileMappingW(
        INVALID_HANDLE_VALUE,
        nullptr,
        PAGE_READWRITE,
        0,
        (DWORD)size,
        name.c_str()
    );

    if (!Handle_)
    {
        return -1;
    }

    Pointer_ = MapViewOfFile(Handle_,
    	FILE_MAP_ALL_ACCESS,
        0,
        0,
        size
    );
    if (!Pointer_)
    {
        CloseHandle(Handle_);
        Handle_ = nullptr;
        return -1;
    }

    Name_ = name;
    Size_ = size;


    Is_Open_ = true;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_memory_mapping::Open(const std::wstring& name)
{
    Reset();

    Handle_ = OpenFileMappingW(FILE_MAP_ALL_ACCESS,
    	FALSE,
        name.c_str()
    );

    if (!Handle_)
    {
        return -1;
    }

    Pointer_ = MapViewOfFile(Handle_,
    	FILE_MAP_ALL_ACCESS,
        0,
        0,
        0
    );

    Name_ = name;

    Is_Open_ = true;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_memory_mapping::Close()
{
	if (Pointer_)
    {
        UnmapViewOfFile(Pointer_);
        Pointer_ = nullptr;
    }
    if (Handle_)
    {
        CloseHandle(Handle_);
        Handle_ = nullptr;
    }

    Is_Open_ = false;

    return 0;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------