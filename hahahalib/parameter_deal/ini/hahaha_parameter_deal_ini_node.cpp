//---------------------------------------------------------------------------

#pragma hdrstop
#include <parameter_deal\ini\hahaha_parameter_deal_ini_item.h>

#include "hahaha_parameter_deal_ini_node.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node::hahaha_parameter_deal_ini_node()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node::~hahaha_parameter_deal_ini_node()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node::hahaha_parameter_deal_ini_node(const hahaha_parameter_deal_ini_node& hpdin)
{
	Copy(hpdin);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node::hahaha_parameter_deal_ini_node(hahaha_parameter_deal_ini_node&& hpdin) noexcept
{
	Move(std::move(hpdin));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node& hahaha_parameter_deal_ini_node::operator=(const hahaha_parameter_deal_ini_node& hpdin)
{
	Copy(hpdin);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini_node& hahaha_parameter_deal_ini_node::operator=(hahaha_parameter_deal_ini_node&& hpdin) noexcept
{
	if (this != &hpdin)
    {
        Move(std::move(hpdin));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini_node::Copy(const hahaha_parameter_deal_ini_node& hpdin)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini_node::Move(hahaha_parameter_deal_ini_node&& hpdin) noexcept
{
    Items_.swap(hpdin.Items_);

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_ini_node::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini_node::Add(std::vector<hahaha_parameter_deal_ini_item>& list)
{
	size_t n = list.size();

	for(size_t i = 0; i < n; i++) {
		std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item> item_;
		item_.reset(new hahahalib::hahaha_parameter_deal_ini_item(list[i]));
		Items_.emplace_back(
			std::move(item_)
		);
	}

	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini_node::Add(const std::vector<hahaha_parameter_deal_ini_item>& list)
{
	size_t n = list.size();

	for(size_t i = 0; i < n; i++) {
		std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item> item_;
		item_.reset(new hahahalib::hahaha_parameter_deal_ini_item(list[i]));
		Items_.emplace_back(
			std::move(item_)
		);
	}

	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------