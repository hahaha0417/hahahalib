//---------------------------------------------------------------------------

#ifndef hahaha_function_vectorH
#define hahaha_function_vectorH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>
//---------------------------------------------------------------------------
//https://en.cppreference.com/w/cpp/algorithm/copy
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <function\hahaha_function_vector.h>
//std::vector<int> from_ = {5, 4, 3};
//std::vector<int> to_;
//hahahalib::Vector_Copy(from_, to_);
template<typename T>
void Vector_Copy(const std::vector<T>& from, std::vector<T>& to)
{
	std::copy(from.begin(), from.end(),
		std::back_inserter(to));

}
//---------------------------------------------------------------------------
//#include <function\hahaha_function_vector.h>
//std::vector<int> from_ = {5, 4, 3};
//std::vector<int> to_ = {3, 4, 5};
//to_.reserve(from_.size() + to_.size());
//hahahalib::Vector_Insert(from_, to_);
template<typename T>
void Vector_Insert(const std::vector<T>& from, std::vector<T>& to)
{
	// 因為本來就會reverse好，這邊只做插入
	std::copy(from.begin(), from.end(),
		std::back_inserter(to));
}
//---------------------------------------------------------------------------

template<typename T>
void Vector_Unique_Ptr_Copy(const std::vector<std::unique_ptr<T>>& from, std::vector<std::unique_ptr<T>>& to)
{
	// iterator好像不行
	std::vector<std::unique_ptr<T>>().swap(to);
	to.reserve(from.size());
	int n = from.size();
	for(int i = 0; i < n; i++)
	{
		std::unique_ptr<T> t_(new T(*from[i]));
		to.emplace_back(std::move(t_));

	}

}
//---------------------------------------------------------------------------

template<typename T>
void Vector_Unique_Ptr_Insert(const std::vector<std::unique_ptr<T>>& from, std::vector<std::unique_ptr<T>>& to)
{
	// iterator好像不行
	// 因為本來就會reverse好，這邊只做插入
	int n = from.size();
	for(int i = 0; i < n; i++)
	{
		std::unique_ptr<T> t_(new T(*from[i]));
		to.emplace_back(std::move(t_));

	}

}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------


#endif
