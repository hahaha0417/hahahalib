//---------------------------------------------------------------------------

#ifndef hahaha_image_view_painter_actionH
#define hahaha_image_view_painter_actionH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_image_view_painter_action
{
public:
	hahaha_image_view_painter_action();
	~hahaha_image_view_painter_action();

	hahaha_image_view_painter_action(const hahaha_image_view_painter_action& hivpa);
    hahaha_image_view_painter_action(hahaha_image_view_painter_action&& hivpa) noexcept;
	hahaha_image_view_painter_action& operator=(const hahaha_image_view_painter_action& hivpa);
    hahaha_image_view_painter_action& operator=(hahaha_image_view_painter_action&& hivpa) noexcept;
	void Copy(const hahaha_image_view_painter_action& hivpa);
    void Move(hahaha_image_view_painter_action&& hivpa) noexcept;
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
