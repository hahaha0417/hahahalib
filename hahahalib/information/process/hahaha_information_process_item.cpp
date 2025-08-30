//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_information_process_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_process_item::hahaha_information_process_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_process_item::~hahaha_information_process_item()
{

}
//---------------------------------------------------------------------------
hahaha_information_process_item::hahaha_information_process_item(const hahaha_information_process_item& hipi)
{
    Reset();
	Copy(hipi);
}
//---------------------------------------------------------------------------
hahaha_information_process_item::hahaha_information_process_item(hahaha_information_process_item&& hipi) noexcept
{
    Move(std::move(hipi));
}
//---------------------------------------------------------------------------
hahaha_information_process_item& hahaha_information_process_item::operator=(const hahaha_information_process_item& hipi)
{
	Copy(hipi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_process_item& hahaha_information_process_item::operator=(hahaha_information_process_item&& hipi) noexcept
{
	if (this != &hipi)
    {
        Move(std::move(hipi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_process_item::Copy(const hahaha_information_process_item& hipi)
{
    Id_Process_ = hipi.Id_Process_;
    Title_Window_ = hipi.Title_Window_;
    Name_Exe_ = hipi.Name_Exe_;
}
//---------------------------------------------------------------------------
void hahaha_information_process_item::Move(hahaha_information_process_item&& hipi) noexcept
{
    Id_Process_ = hipi.Id_Process_;
    Title_Window_ = std::move(hipi.Title_Window_);
    Name_Exe_ = std::move(hipi.Name_Exe_);

    hipi.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_process_item::Reset()
{
    Id_Process_ = 0;
    Title_Window_ = L"";
    Name_Exe_ = L"";

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------