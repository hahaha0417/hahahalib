//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_xml_node.h"
#include <function\hahaha_function_vector.h>

#include <parameter_deal\hahaha_parameter_deal_xml.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_item.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node::hahaha_parameter_deal_xml_node()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node::~hahaha_parameter_deal_xml_node()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node::hahaha_parameter_deal_xml_node(const hahaha_parameter_deal_xml_node& hpdxn)
{
    Reset();
	Copy(hpdxn);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node::hahaha_parameter_deal_xml_node(hahaha_parameter_deal_xml_node&& hpdxn) noexcept
{
    Move(std::move(hpdxn));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node& hahaha_parameter_deal_xml_node::operator=(const hahaha_parameter_deal_xml_node& hpdxn)
{
	Copy(hpdxn);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml_node& hahaha_parameter_deal_xml_node::operator=(hahaha_parameter_deal_xml_node&& hpdxn) noexcept
{
	if (this != &hpdxn)
    {
        Move(std::move(hpdxn));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_node::Copy(const hahaha_parameter_deal_xml_node& hpdxn)
{
    // 這沒用到
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml_node::Move(hahaha_parameter_deal_xml_node&& hpdxn) noexcept
{
    Name_.swap(hpdxn.Name_);
    Xml_Type_ = hpdxn.Xml_Type_;
	Type_ = hpdxn.Type_;
	Value_ = hpdxn.Value_;

	Attributes_.swap(hpdxn.Attributes_);
	Nodes_.swap(hpdxn.Nodes_);



}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_xml_node::Reset()
{
	Xml_Type_ = halib_def::xml_type::NONE;
	Type_ = halib_def::type_variable::NONE;
	Value_ = NULL;

	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_attribute>>().swap(Attributes_);
	std::vector<std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_node>>().swap(Nodes_);

	return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_node::Add(
	const std::vector<hahahalib::hahaha_parameter_deal_xml_item>& items
)
{
	hahahalib::hahaha_parameter_deal_xml_node* node_target_ = NULL;
	node_target_ = this;
	const std::vector<std::wstring>* node_names_ = NULL;

	size_t n = items.size();

	// 外層已做過檢查，這邊可以直接放入
	// 節點內處理
	// 請到上層決定進入節點
	for(size_t i = 0; i < n; i++) {
		const hahahalib::hahaha_parameter_deal_xml_item& item_ = items[i];

		if(item_.Xml_Type_ == halib_def::xml_type::NODE)
		{
			// 切換節點
			node_target_ = this;
			node_names_ = &item_.Node_Names_;


			int m = node_names_->size();

			std::vector<std::wstring> node_names_target_;


			if(m != 0)
			{
				hahahalib::Vector_Copy(*node_names_, node_names_target_);
			}
			if(item_.Name_ != L"")
			{
				node_names_target_.emplace_back(item_.Name_);
			}
			int k = node_names_target_.size();
			if(k != 0)
			{

				Find(node_names_target_, node_target_);
				node_target_->Type_ = item_.Type_;
				node_target_->Value_ = item_.Variable_;
			}

		}
		else if(item_.Xml_Type_ == halib_def::xml_type::ATTRIBUTE)
		{
			// 切換節點



			int m = item_.Node_Names_.size();

			std::vector<std::wstring> node_names_target_;


			if(m != 0)
			{
				// 重找
				node_target_ = this;
				node_names_ = &item_.Node_Names_;
				hahahalib::Vector_Copy(*node_names_, node_names_target_);
			}

			// 找節點
			int k = node_names_target_.size();
			if(k != 0)
			{

				Find(node_names_target_, node_target_);
//				node_target_->Type_ = item_.Type_;
//				node_target_->Value_ = item_.Variable_;
			}

			if(item_.Name_ != L"")
			{
				hahahalib::hahaha_parameter_deal_xml_attribute* attribute_target_ = NULL;

				bool find_ = false;
				for(int j = 0; j < m; j++)
				{
					if(node_target_->Attributes_[j]->Name_ == (*node_names_)[i])
					{
						find_ = true;
						attribute_target_ = node_target_->Attributes_[j].get();
						break;

					}
				}
				if(find_)
				{
					// 下一層node
					continue;
				}
				else
				{
					std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_attribute> attribute_;
					attribute_.reset(new hahahalib::hahaha_parameter_deal_xml_attribute());
					attribute_->Name_ = item_.Name_;
//                    attribute_->Xml_Type_ = item.Xml_Type_;
					attribute_->Type_ = item_.Type_;
					attribute_->Value_ = item_.Variable_;
					//
					node_target_->Attributes_.emplace_back(
						std::move(attribute_)
					);

				}
			}
			else
			{
				// 格式不對
			}



		}
		else if(item_.Xml_Type_ == halib_def::xml_type::VALUE)
		{
			// 切換節點


			int m = item_.Node_Names_.size();

			std::vector<std::wstring> node_names_target_;


			if(m != 0)
			{
				// 重找
				node_target_ = this;
				node_names_ = &item_.Node_Names_;
				hahahalib::Vector_Copy(*node_names_, node_names_target_);
			}


			if(m != 0)
			{
				int k = node_names_target_.size();
                if(k != 0)
				{
					Find(node_names_target_, node_target_);
//					node_target_->Xml_Type_ = item_.Xml_Type_;
//					node_target_->Type_ = item_.Type_;
//					node_target_->Value_ = item_.Variable_;
                    // 清空
					std::vector<std::wstring>().swap(node_names_target_);
				}
				if(item_.Name_ != L"")
				{
					node_names_target_.emplace_back(item_.Name_);
				}
				k = node_names_target_.size();
				if(k != 0)
				{
                    hahahalib::hahaha_parameter_deal_xml_node* node_target_temp_ = node_target_;
					Find(node_names_target_, node_target_);
						node_target_->Xml_Type_ = item_.Xml_Type_;
						node_target_->Type_ = item_.Type_;
						node_target_->Value_ = item_.Variable_;

					   	node_target_ = node_target_temp_;

				}
			}
			else
			{

                if(item_.Name_ != L"")
				{
					node_names_target_.emplace_back(item_.Name_);
				}
				int k = node_names_target_.size();
				if(k != 0)
				{
					hahahalib::hahaha_parameter_deal_xml_node* node_target_temp_ = node_target_;
					Find(node_names_target_, node_target_);
						node_target_->Xml_Type_ = item_.Xml_Type_;
						node_target_->Type_ = item_.Type_;
						node_target_->Value_ = item_.Variable_;

						node_target_ = node_target_temp_;
				}
			}




		}
		else if(item_.Xml_Type_ == halib_def::xml_type::NONE)
		{
			// 不處理

		}

        int rrr = 0;

//		std::unique_ptr<hahahalib::hahaha_parameter_deal_ini_item> item_;
//		item_.reset(new hahahalib::hahaha_parameter_deal_ini_item(items[i]));
//		Items_.emplace_back(
//			std::move(item_)
//		);
	}


	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml_node::Find(
	const std::vector<std::wstring>& node_names,
	hahahalib::hahaha_parameter_deal_xml_node*& node_target
)
{
//	hahahalib::hahaha_parameter_deal_xml_node& node_ = *this;


	//
	int n = node_names.size();
	for(int i = 0; i < n; i++)
	{
		int m = node_target->Nodes_.size();
		// 找節點
		bool find_ = false;
		for(int j = 0; j < m; j++)
		{
			if(node_target->Nodes_[j]->Name_ == node_names[i])
			{
				find_ = true;
				node_target = node_target->Nodes_[j].get();
				break;

			}
		}
		if(find_)
		{
			// 下一層node
			continue;
		}
		else
		{
			std::unique_ptr<hahahalib::hahaha_parameter_deal_xml_node> node_;
			node_.reset(new hahahalib::hahaha_parameter_deal_xml_node());
			node_->Name_ = node_names[i];
			node_->Xml_Type_ = halib_def::xml_type::NODE;
//			node_->Type_ = ha_def::type_variable::NONE;
//			node_->Value_ = NULL;
			//
			node_target->Nodes_.emplace_back(
				std::move(node_)
			);
            node_target = node_target->Nodes_.back().get();


		}
	}

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------