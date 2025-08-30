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
	hahaha_image_view_action();
	~hahaha_image_view_action();

	hahaha_image_view_action(const hahaha_image_view_action& hiva);
    hahaha_image_view_action(hahaha_image_view_action&& hiva) noexcept;
	hahaha_image_view_action& operator=(const hahaha_image_view_action& hiva);
    hahaha_image_view_action& operator=(hahaha_image_view_action&& hiva) noexcept;
	void Copy(const hahaha_image_view_action& hiva);
    void Move(hahaha_image_view_action&& hiva) noexcept;
public:
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
