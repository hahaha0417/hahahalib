//---------------------------------------------------------------------------

#ifndef hahaha_image_view_actionH
#define hahaha_image_view_actionH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_image_view_action
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_image_view_action();
	// 解構物件並釋放相關資源。
	~hahaha_image_view_action();

	// 以既有物件內容建構新的物件實例。
	hahaha_image_view_action(const hahaha_image_view_action& hiva);
    // 以移動方式建構物件並接手既有資源。
    hahaha_image_view_action(hahaha_image_view_action&& hiva) noexcept;
	// 複製指派目前物件內容。
	hahaha_image_view_action& operator=(const hahaha_image_view_action& hiva);
    // 移動指派目前物件內容。
    hahaha_image_view_action& operator=(hahaha_image_view_action&& hiva) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_image_view_action& hiva);
    // 接手來源物件的內部資源。
    void Move(hahaha_image_view_action&& hiva) noexcept;
public:
	// 重設內部狀態。
	int Reset();

public:
    // 啟用
    bool Enabled_;
    // 可見
    bool Visibled_;
    // 動作
    bool Action_;

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif