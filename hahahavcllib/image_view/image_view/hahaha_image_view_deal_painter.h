//---------------------------------------------------------------------------

#ifndef hahaha_image_view_deal_painterH
#define hahaha_image_view_deal_painterH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_image_view_painter;
//---------------------------------------------------------------------------
class hahaha_image_view_deal_painter
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_image_view_deal_painter();
	// 解構物件並釋放相關資源。
	~hahaha_image_view_deal_painter();

	// 以既有物件內容建構新的物件實例。
	hahaha_image_view_deal_painter(const hahaha_image_view_deal_painter& hivdp);
    // 以移動方式建構物件並接手既有資源。
    hahaha_image_view_deal_painter(hahaha_image_view_deal_painter&& hivdp) noexcept;
	// 複製指派目前物件內容。
	hahaha_image_view_deal_painter& operator=(const hahaha_image_view_deal_painter& hivdp);
    // 移動指派目前物件內容。
    hahaha_image_view_deal_painter& operator=(hahaha_image_view_deal_painter&& hivdp) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_image_view_deal_painter& hivdp);
    // 接手來源物件的內部資源。
    void Move(hahaha_image_view_deal_painter&& hivdp) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 加入新的項目或工作。
    halib_def::result Add_Painter(hahaha_image_view_painter* painter);
    // 移除指定項目。
    halib_def::result Delete_Painter(const hahaha_image_view_painter* painter);
    // 清空目前掛載的 painter 清單。
    halib_def::result Clear_Painter();
public:
    std::vector<hahaha_image_view_painter*> Painters_;
public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
