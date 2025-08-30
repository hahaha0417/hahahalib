//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_parameter_deal_xml.h"

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <windows.h>

#include <convert\hahaha_convert_string.h>
#include <function\hahaha_function_vector.h>

#include <parameter_deal\xml\hahaha_parameter_deal_xml_node.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_attribute.h>
#include <parameter_deal\xml\hahaha_parameter_deal_xml_mapping.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)



//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_parameter_deal_xml::hahaha_parameter_deal_xml()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml::~hahaha_parameter_deal_xml()
{

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml::hahaha_parameter_deal_xml(const hahaha_parameter_deal_xml& hpdx)
{
	Copy(hpdx);
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml::hahaha_parameter_deal_xml(hahaha_parameter_deal_xml&& hpdx) noexcept
{
	Move(std::move(hpdx));

}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml& hahaha_parameter_deal_xml::operator=(const hahaha_parameter_deal_xml& hpdx)
{
	Copy(hpdx);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_parameter_deal_xml& hahaha_parameter_deal_xml::operator=(hahaha_parameter_deal_xml&& hpdx) noexcept
{
	if (this != &hpdx)
    {
        Move(std::move(hpdx));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml::Copy(const hahaha_parameter_deal_xml& hpdx)
{

}
//---------------------------------------------------------------------------
void hahaha_parameter_deal_xml::Move(hahaha_parameter_deal_xml&& hpdx) noexcept
{
    File_Name_ = std::move(hpdx.File_Name_);

	Node_ = std::move(hpdx.Node_);

    hpdx.Reset();

}
//---------------------------------------------------------------------------
int hahaha_parameter_deal_xml::Reset()
{
	if(Node_.get() == NULL)
	{
		Node_.reset(new hahahalib::hahaha_parameter_deal_xml_node);
	}

	return 0;
}

//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Read()
{
	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Write()
{
	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Value_To_Xml(std::wstring & xml_wstring,
	const halib_def::type_variable& type,
	void* value
)
{
	if(type == halib_def::type_variable::BOOL)
	{
		bool* data = (bool*)value;
        xml_wstring = (*data == true) ? L"true" : L"false";
	}
	else if(type == halib_def::type_variable::INT)
	{
		int* data = (int*)value;
		xml_wstring = std::to_wstring(*data);
	}
    else if(type == halib_def::type_variable::UNSIGNED_INT)
	{
		unsigned int* data = (unsigned int*)value;
		xml_wstring = std::to_wstring(*data);
	}
	else if(type == halib_def::type_variable::FLOAT)
	{
		float* data = (float*)value;
		xml_wstring = std::to_wstring(*data);
	}
	else if(type == halib_def::type_variable::DOUBLE)
	{
		double* data = (double*)value;
		xml_wstring = std::to_wstring(*data);
	}
	else if(type == halib_def::type_variable::STRING)
	{
		std::string* data = (std::string*)value;
		xml_wstring = hahahalib::s2ws(*data);
	}
	else if(type == halib_def::type_variable::WSTRING)
	{
		std::wstring* data = (std::wstring*)value;
		xml_wstring = *data;
	}



	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Xml_To_Value(std::wstring & xml_wstring,
	const halib_def::type_variable& type,
	void* value
)
{
    if(type == halib_def::type_variable::BOOL)
	{
		bool* data = (bool*)value;
		if(xml_wstring == L"true")
		{
			*data = true;
		}
		else if(xml_wstring == L"false")
		{
			*data = false;
		}
	}
	else if(type == halib_def::type_variable::INT)
	{
		int* data = (int*)value;
		*data = _wtoi(xml_wstring.c_str());
	}
    else if(type == halib_def::type_variable::UNSIGNED_INT)
	{
		unsigned int* data = (unsigned int*)value;
		*data = (unsigned int)std::stoul(xml_wstring.c_str());
	}
	else if(type == halib_def::type_variable::FLOAT)
	{
		float* data = (float*)value;
		*data = (float)_wtof(xml_wstring.c_str());
	}
	else if(type == halib_def::type_variable::DOUBLE)
	{
		double* data = (double*)value;
		*data = _wtof(xml_wstring.c_str());
	}
	else if(type == halib_def::type_variable::STRING)
	{
		std::string* data = (std::string*)value;
		*data = hahahalib::ws2s(xml_wstring);
	}
	else if(type == halib_def::type_variable::WSTRING)
	{
		std::wstring* data = (std::wstring*)value;
		*data = xml_wstring;
	}

	return halib_def::result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Load(hahahalib::hahaha_parameter_deal_xml_mapping& mapping)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

	if(!std::filesystem::exists(File_Name_))
	{
		return halib_def::result::FAILURE;
	}
	//
	xmlParserCtxtPtr xml_ctxt_;
	xmlDocPtr xml_doc_;
	xmlNodePtr xml_node_root_, xml_node_cur_;

    // 创建解析器上下文
	xml_ctxt_ = xmlNewParserCtxt();
	if (xml_ctxt_ == NULL) {
//        std::cerr << "Failed to create parser context" << std::endl;
		return halib_def::result::FAILURE;
	}

	// 加载 XML 文件
	xml_doc_ = xmlCtxtReadFile(xml_ctxt_, hahahalib::wstring_to_utf8(File_Name_).c_str(), NULL, XML_PARSE_NOBLANKS);
	if (xml_doc_ == NULL) {
//		std::cerr << "Failed to parse document" << std::endl;
		xmlFreeParserCtxt(xml_ctxt_);
		return halib_def::result::FAILURE;
	}

	// 获取根节点
	xml_node_root_ = xmlDocGetRootElement(xml_doc_);
	if (xml_node_root_ == NULL) {
//        std::cerr << "Empty document" << std::endl;
		xmlFreeParserCtxt(xml_ctxt_);
		xmlFreeDoc(xml_doc_);
		return halib_def::result::FAILURE;
	}

	hahaha_parameter_deal_xml_node& root_ = *Node_;

	// 準備node
    {
        std::vector<std::wstring> node_names_;

        mapping.Prepare(*this,
        	node_names_,
            root_
        );
    }
	// 對應node
    {
        std::vector<std::wstring> node_names_;

    	mapping.Mapping(*this,
        	node_names_,
            root_
        );
    }

	{
		std::vector<std::wstring> node_names_;

		result_ = hahahalib::hahaha_parameter_deal_xml::Prepare(
			node_names_,
			root_,
			root_,
			mapping,
			xml_doc_,
			xml_node_root_,
			xml_node_root_

		);
	}

	if(result_ == halib_def::result::FAILURE)
	{
		xmlFreeParserCtxt(xml_ctxt_);
		xmlFreeDoc(xml_doc_);
		return halib_def::result::FAILURE;
	}


	{
        std::vector<std::wstring> node_names_;

		result_ = hahahalib::hahaha_parameter_deal_xml::Load(
        	node_names_,
			root_,
			root_,
			mapping,
			xml_doc_,
			xml_node_root_,
			xml_node_root_

		);
	}

    if(result_ == halib_def::result::FAILURE)
	{
		xmlFreeParserCtxt(xml_ctxt_);
		xmlFreeDoc(xml_doc_);
		return halib_def::result::FAILURE;
	}



	// 释放资源
	xmlFreeParserCtxt(xml_ctxt_);
	xmlFreeDoc(xml_doc_);

	return result_;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Prepare(
	std::vector<std::wstring>& node_names,
	hahaha_parameter_deal_xml_node& root,
	hahaha_parameter_deal_xml_node& node,
	hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
	xmlDocPtr xml_doc,
	xmlNodePtr xml_node_root,
	xmlNodePtr xml_node_cur

)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

	xmlNodePtr xml_node_cur_;

	// 遍历子節點
	for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
    {
		if (xml_node_cur_->type == XML_ELEMENT_NODE)
		{
			std::vector<std::wstring> node_names_;
			hahahalib::Vector_Copy((std::vector<std::wstring>)node_names, node_names_);
			std::wstring xml_wstring = hahahalib::utf8_to_wstring(
				(const char *)xml_node_cur_->name
			);
			node_names_.emplace_back(xml_wstring);

            

            hahaha_parameter_deal_xml_node* node_target_ = &root;
			node_target_->Find(node_names_, node_target_);




            // 準備node
            mapping.Prepare_Node(*this,
                node_names_,
                root,
                *node_target_,
                mapping,
                xml_doc,
                xml_node_root,
                xml_node_cur_,
                xml_wstring,
                node_target_->Type_,
                node_target_->Value_
            );

			int n = node_target_->Attributes_.size();
			if(n != 0)
			{
				for(int i = 0; i < n; i++)
				{
					hahahalib::hahaha_parameter_deal_xml_attribute& attribute_ = *node_target_->Attributes_[i];

					// 获取元素的属性值
					xmlChar *xml_attribute_value;
					xml_attribute_value = xmlGetProp(xml_node_cur_, (const xmlChar *)hahahalib::wstring_to_utf8(attribute_.Name_).c_str());
					if (xml_attribute_value != NULL) {
						std::wstring xml_wstring = hahahalib::utf8_to_wstring(
							(const char *)xml_attribute_value
						);

                        // 準備node
                        mapping.Prepare_Attribute(*this,
                            node_names_,
                            root,
                            *node_target_,
                            mapping,
                            xml_doc,
                            xml_node_root,
                            xml_node_cur_,
                            xml_wstring,
                            attribute_.Type_,
                            attribute_.Value_
                        );
//						Xml_To_Value(xml_wstring, attribute_.Type_, attribute_.Value_);
						xmlFree(xml_attribute_value);
					}
				}

			}

            // dfs，因為要展開子節點
			result_ = hahahalib::hahaha_parameter_deal_xml::Prepare(
				node_names_,
				root,
				*node_target_,
				mapping,
				xml_doc,
				xml_node_root,
				xml_node_cur_

			);

            node_names_.pop_back();
		}
		else if (xml_node_cur_->type == XML_TEXT_NODE)
		{
			if(xml_node_cur_->content != NULL)
			{
				hahaha_parameter_deal_xml_node* node_target_ = &root;
				node_target_->Find(node_names, node_target_);
				std::wstring xml_wstring = hahahalib::utf8_to_wstring(
					(const char *)xml_node_cur_->content
				);

                // 準備node
                mapping.Prepare_Value(*this,
                    node_names,
                    root,
                    *node_target_,
                    mapping,
                    xml_doc,
                    xml_node_root,
                    xml_node_cur_,
                    xml_wstring,
                    node_target_->Type_,
                    node_target_->Value_
                );
//				Xml_To_Value(xml_wstring, node_target_->Type_, node_target_->Value_);
			}
		}



	}

	return result_;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Load(
	std::vector<std::wstring>& node_names,
	hahaha_parameter_deal_xml_node& root,
	hahaha_parameter_deal_xml_node& node,
	hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
	xmlDocPtr xml_doc,
	xmlNodePtr xml_node_root,
	xmlNodePtr xml_node_cur

)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

	xmlNodePtr xml_node_cur_;

	// 遍历子節點
	for (xml_node_cur_ = xml_node_cur->children; xml_node_cur_ != NULL; xml_node_cur_ = xml_node_cur_->next)
    {
		if (xml_node_cur_->type == XML_ELEMENT_NODE)
		{
			std::vector<std::wstring> node_names_;
			hahahalib::Vector_Copy((std::vector<std::wstring>)node_names, node_names_);
			std::wstring xml_wstring = hahahalib::utf8_to_wstring(
				(const char *)xml_node_cur_->name
			);
			node_names_.emplace_back(xml_wstring);

            hahaha_parameter_deal_xml_node* node_target_ = &root;
			node_target_->Find(node_names_, node_target_);


			// dfs，因為要展開子節點
			result_ = hahahalib::hahaha_parameter_deal_xml::Load(
				node_names_,
				root,
				*node_target_,
				mapping,
				xml_doc,
				xml_node_root,
				xml_node_cur_

			);


			int n = node_target_->Attributes_.size();
			if(n != 0)
			{
				for(int i = 0; i < n; i++)
				{
					hahahalib::hahaha_parameter_deal_xml_attribute& attribute_ = *node_target_->Attributes_[i];

					// 获取元素的属性值
					xmlChar *xml_attribute_value;
					xml_attribute_value = xmlGetProp(xml_node_cur_, (const xmlChar *)hahahalib::wstring_to_utf8(attribute_.Name_).c_str());
					if (xml_attribute_value != NULL) {
						std::wstring xml_wstring = hahahalib::utf8_to_wstring(
							(const char *)xml_attribute_value
						);
						Xml_To_Value(xml_wstring, attribute_.Type_, attribute_.Value_);
						xmlFree(xml_attribute_value);
					}
				}

			}

            node_names_.pop_back();
		}
		else if (xml_node_cur_->type == XML_TEXT_NODE)
		{
			if(xml_node_cur_->content != NULL)
			{
				hahaha_parameter_deal_xml_node* node_target_ = &root;
				node_target_->Find(node_names, node_target_);
				std::wstring xml_wstring = hahahalib::utf8_to_wstring(
					(const char *)xml_node_cur_->content
				);
				Xml_To_Value(xml_wstring, node_target_->Type_, node_target_->Value_);
			}
		}



	}

	return result_;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Save(hahahalib::hahaha_parameter_deal_xml_mapping& mapping)
{
	std::wofstream out_(File_Name_.c_str());

	halib_def::result result_ = halib_def::result::SUCCESS;

	if (out_.is_open())
	{
		std::wstring text_ =
				L"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>";
		out_ << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;

		hahaha_parameter_deal_xml_node& root_ = *Node_;

		// 準備node
        {
            std::vector<std::wstring> node_names_;

            mapping.Prepare(*this,
                node_names_,
                root_
            );
        }
        // 對應node
        {
            std::vector<std::wstring> node_names_;

            mapping.Mapping(*this,
                node_names_,
                root_
            );
        }

		int tab_ = 0;


		{
			text_ = L"";

			for(int j = 0; j < tab_; j++)
			{
				text_ += L"\t";
			}

			text_ += L"<";
			text_ += root_.Name_;
			text_ += L">";

			out_ << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
		}


		tab_++;
		result_ = Save(
			root_,
			root_,
			mapping,
			out_,
			tab_
		);
		tab_--;

		{
			text_ = L"";

			for(int j = 0; j < tab_; j++)
			{
				text_ += L"\t";
			}

			text_ += L"</";
			text_ += root_.Name_;
			text_ += L">";

			out_ << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
		}

        out_.close();
	}
	else
	{
//		std::cerr << "Error opening file for writing." << std::endl;
		return halib_def::result::FAILURE;
	}


	return result_;
}
//---------------------------------------------------------------------------
halib_def::result hahaha_parameter_deal_xml::Save(
	hahaha_parameter_deal_xml_node& root,
	hahaha_parameter_deal_xml_node& node,
	hahahalib::hahaha_parameter_deal_xml_mapping& mapping,
	std::wofstream& out,
	int& tab
)
{
	halib_def::result result_ = halib_def::result::SUCCESS;

	int n = node.Nodes_.size();

	for(int i = 0; i < n; i++)
	{
		hahaha_parameter_deal_xml_node& node_ = *(node.Nodes_[i]);

		std::wstring text_ = L"";

		for(int j = 0; j < tab; j++)
		{
			text_ += L"\t";
		}


		int m = node.Attributes_.size();
		if(m == 0)
		{
            text_ += L"<";
			text_ += node_.Name_;
			text_ += L">";

			if(node_.Xml_Type_ == halib_def::xml_type::NODE)
			{
				out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
			}
			else if(node_.Xml_Type_ == halib_def::xml_type::VALUE)
			{
				out << hahahalib::wstring_to_utf8(text_).c_str();
			}
		}
		else
		{
			text_ += L"<";
			text_ += node_.Name_;
			out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;

			tab++;
			for(int k = 0; k < m; k++)
			{

				text_ = L"";

				for(int j = 0; j < tab; j++)
				{
					text_ += L"\t";
				}

				text_ += L"";
				text_ += node.Attributes_[k]->Name_;
				text_ += L"=";
				text_ += L"\"";
				std::wstring xml_wstring = L"";
				Value_To_Xml(xml_wstring, node.Attributes_[k]->Type_, node.Attributes_[k]->Value_);
				text_ += xml_wstring;

				text_ += L"\"";
				out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;

			}
			tab--;

			text_ = L"";

            for(int j = 0; j < tab; j++)
			{
				text_ += L"\t";
			}

			text_ += L">";

			if(node_.Xml_Type_ == halib_def::xml_type::NODE)
			{
				out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
			}
			else if(node_.Xml_Type_ == halib_def::xml_type::VALUE)
			{
				out << hahahalib::wstring_to_utf8(text_).c_str();
			}
		}


		tab++;
		if(node_.Xml_Type_ == halib_def::xml_type::NODE)
		{
            result_ = Save(
				root,
				node_,
				mapping,
				out,
				tab
			);
		}
		else if(node_.Xml_Type_ == halib_def::xml_type::VALUE)
		{
//			text_ = L"";
//
//			for(int j = 0; j < tab; j++)
//			{
//				text_ += L"\t";
//			}
//			std::wstring xml_wstring = L"";
//			Value_To_Xml(xml_wstring, node_.Type_, node_.Value_);
//			text_ += xml_wstring;
//			out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;

		}

		tab--;

		text_ = L"";

//		for(int j = 0; j < tab; j++)
//		{
//			text_ += L"\t";
//		}
		std::wstring xml_wstring = L"";
		Value_To_Xml(xml_wstring, node_.Type_, node_.Value_);
		text_ += xml_wstring;
		out << hahahalib::wstring_to_utf8(text_).c_str();


        if(node_.Xml_Type_ == halib_def::xml_type::NODE)
		{
			text_ = L"";

			for(int j = 0; j < tab; j++)
			{
				text_ += L"\t";
			}

			text_ += L"</";
			text_ += node_.Name_;
			text_ += L">";

			out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
		}
		else if(node_.Xml_Type_ == halib_def::xml_type::VALUE)
		{
            text_ = L"";

//			for(int j = 0; j < tab; j++)
//			{
//				text_ += L"\t";
//			}

			text_ += L"</";
			text_ += node_.Name_;
			text_ += L">";

			out << hahahalib::wstring_to_utf8(text_).c_str() << std::endl;
		}



	}

	return result_;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------