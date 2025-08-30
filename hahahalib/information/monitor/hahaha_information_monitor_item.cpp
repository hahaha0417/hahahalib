//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>

//---------------------------------------------------------------------------
#include "hahaha_information_monitor_item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_monitor_item::hahaha_information_monitor_item()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_monitor_item::~hahaha_information_monitor_item()
{

}
//---------------------------------------------------------------------------
hahaha_information_monitor_item::hahaha_information_monitor_item(const hahaha_information_monitor_item& himi)
{
    Reset();
	Copy(himi);
}
//---------------------------------------------------------------------------
hahaha_information_monitor_item::hahaha_information_monitor_item(hahaha_information_monitor_item&& himi) noexcept
{
    Move(std::move(himi));
}
//---------------------------------------------------------------------------
hahaha_information_monitor_item& hahaha_information_monitor_item::operator=(const hahaha_information_monitor_item& himi)
{
	Copy(himi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_monitor_item& hahaha_information_monitor_item::operator=(hahaha_information_monitor_item&& himi) noexcept
{
	if (this != &himi)
    {
        Move(std::move(himi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_monitor_item::Copy(const hahaha_information_monitor_item& himi)
{
    Handle_Monitor_ = himi.Handle_Monitor_;
	*Region_Monitor_ = *himi.Region_Monitor_;
    *Region_Work_ = *himi.Region_Work_;
    Flag_ = himi.Flag_;
    Name_Device_ = himi.Name_Device_;
    Name_Product_ = himi.Name_Product_;
}
//---------------------------------------------------------------------------
void hahaha_information_monitor_item::Move(hahaha_information_monitor_item&& himi) noexcept
{
    Handle_Monitor_ = himi.Handle_Monitor_;
	Region_Monitor_ = std::move(himi.Region_Monitor_);
    Region_Work_ = std::move(himi.Region_Work_);
    Flag_ = himi.Flag_;
    Name_Device_ = std::move(himi.Name_Device_);
    Name_Product_ = std::move(himi.Name_Product_);

    himi.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_monitor_item::Reset()
{
    Handle_Monitor_ = NULL;
    if(Region_Monitor_.get() == NULL)
    {
        Region_Monitor_.reset(new halib::rect());
    }
    if(Region_Work_.get() == NULL)
    {
        Region_Work_.reset(new halib::rect());
    }
    Flag_ = 0;
    Name_Device_ = L"";
    Name_Product_ = L"";

	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------