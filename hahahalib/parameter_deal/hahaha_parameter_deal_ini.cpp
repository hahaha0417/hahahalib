//---------------------------------------------------------------------------

#pragma hdrstop

#include <filesystem>

#include <ini\hahaha_ini.h>
#include <parameter_deal\ini\hahaha_parameter_deal_ini_node.h>
#include <parameter_deal\ini\hahaha_parameter_deal_ini_item.h>

#include "hahaha_parameter_deal_ini.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_ini::hahaha_parameter_deal_ini()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini::~hahaha_parameter_deal_ini()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini::hahaha_parameter_deal_ini(const hahaha_parameter_deal_ini& hpdi)
{
	Copy(hpdi);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini::hahaha_parameter_deal_ini(hahaha_parameter_deal_ini&& hpdi) noexcept
{
	Move(std::move(hpdi));
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini& hahaha_parameter_deal_ini::operator=(const hahaha_parameter_deal_ini& hpdi)
{
	Copy(hpdi);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_ini& hahaha_parameter_deal_ini::operator=(hahaha_parameter_deal_ini&& hpdi) noexcept
{
	if (this != &hpdi)
    {
        Move(std::move(hpdi));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini::Copy(const hahaha_parameter_deal_ini& hpdi)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_ini::Move(hahaha_parameter_deal_ini&& hpdi) noexcept
{
    File_Name_ = hpdi.File_Name_;

	Node_.swap(hpdi.Node_);

    hpdi.Reset();

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_ini::Reset()
{
	if(Node_.get() == NULL)
	{
        Node_.reset(new hahahalib::hahaha_parameter_deal_ini_node);
	}

	return 0;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Prepare()
{
//	預處理
//	如有Vector，在這邊先初始化數量
//	hahahalib::hahaha_ini ini_;
//	ini_.Set_File_Name(File_Name_);
//	int count = 0;
//	ini_.Get_Int(L"xxx", "xxxx", &count);
//	vector.resize(count);
	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Mapping()
{
	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Read()
{
	hahahalib::hahaha_ini ini_;
	ini_.Set_File_Name(File_Name_);

    size_t n = Node_->Items_.size();
	for(size_t i = 0; i < n; i++)
	{
		if(Node_->Items_[i]->Type_ == halib_def::type_variable::BOOL)
		{
			ini_.Get_Bool(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const bool*)Node_->Items_[i]->Variable_, *(bool*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::INT)
		{
			ini_.Get_Int(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const int*)Node_->Items_[i]->Variable_, *(int*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::FLOAT)
		{
			ini_.Get_Float(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const float*)Node_->Items_[i]->Variable_, *(float*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::DOUBLE)
		{
			ini_.Get_Double(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const double*)Node_->Items_[i]->Variable_, *(double*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::WSTRING)
		{
			ini_.Get_Wstring(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const std::wstring*)Node_->Items_[i]->Variable_, *(std::wstring*)Node_->Items_[i]->Variable_);
		}
	}

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Write()
{
	hahahalib::hahaha_ini ini_;
	ini_.Set_File_Name(File_Name_);

	size_t n = Node_->Items_.size();
	for(size_t i = 0; i < n; i++)
	{
		if(Node_->Items_[i]->Type_ == halib_def::type_variable::BOOL)
		{
			ini_.Set_Bool(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const bool*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::INT)
		{
			ini_.Set_Int(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const int*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::FLOAT)
		{
			ini_.Set_Float(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const float*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::DOUBLE)
		{
			ini_.Set_Double(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const double*)Node_->Items_[i]->Variable_);
		}
		else if(Node_->Items_[i]->Type_ == halib_def::type_variable::WSTRING)
		{
			ini_.Set_Wstring(Node_->Items_[i]->Section_, Node_->Items_[i]->Name_, *(const std::wstring*)Node_->Items_[i]->Variable_);
		}
	}

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Load(hahahalib::hahaha_parameter_deal_ini& ini)
{
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item>>().swap(Node_->Items_);

	Prepare();
	Mapping();
	Read();


	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Save(hahahalib::hahaha_parameter_deal_ini& ini)
{
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item>>().swap(Node_->Items_);

	Mapping();
    Write();


	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Load(const std::wstring& file_name)
{
//	if(!std::filesystem::exists(file_name))
//	{
//		return hadef::result::FAILURE;
//	}
//
//	File_Name_ = file_name;
//
//	hadef::result result_ = hahahalib::hahaha_parameter_deal_ini::Load(*this);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_ini::Save(const std::wstring& file_name)
{

//
//	std::wstring dir = std::filesystem::path(File_Name_).parent_path();
//
//	if(!std::filesystem::is_directory(dir))
//	{
//		std::filesystem::create_directories(dir);
//	}
//
//	File_Name_ = file_name;
//
//	Save(*this);

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
