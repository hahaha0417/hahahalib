//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_bitmap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// 建構物件並初始化預設狀態。
hahaha_bitmap::hahaha_bitmap()
{
	Reset();
}
//---------------------------------------------------------------------------
// 解構物件並釋放相關資源。
hahaha_bitmap::~hahaha_bitmap()
{
    Bmp_Info_Header_.release();
}
//---------------------------------------------------------------------------
// 以既有物件內容建構新的物件實例。
hahaha_bitmap::hahaha_bitmap(const hahaha_bitmap& hb)
{
    Reset();
	Copy(hb);
}
//---------------------------------------------------------------------------
// 以移動方式建構物件並接手既有資源。
hahaha_bitmap::hahaha_bitmap(hahaha_bitmap&& hb) noexcept
{
    Move(std::move(hb));
}
//---------------------------------------------------------------------------
hahaha_bitmap& hahaha_bitmap::operator=(const hahaha_bitmap& hb)
{
	Copy(hb);

	return *this;
}

//---------------------------------------------------------------------------
hahaha_bitmap& hahaha_bitmap::operator=(hahaha_bitmap&& hb) noexcept
{
    if (this != &hb)
    {
        Move(std::move(hb));
    }

	return *this;
}
//---------------------------------------------------------------------------
// 複製來源物件的內部狀態。
void hahaha_bitmap::Copy(const hahaha_bitmap& hb)
{
	Name_ = hb.Name_;
	Type_ = hb.Type_;
	Channel_ = hb.Channel_;
	Depth_ = hb.Depth_;
    Bits_ = hb.Bits_;
	Width_ = hb.Width_;
	Height_ = hb.Height_;
	Stride_ = hb.Stride_;
	Size_ = hb.Size_;
}
//---------------------------------------------------------------------------
// 接手來源物件的內部資源。
void hahaha_bitmap::Move(hahaha_bitmap&& hb) noexcept
{
	Name_ = std::move(hb.Name_);
	Type_ = std::move(hb.Type_);
	Channel_ = hb.Channel_;
	Depth_ = hb.Depth_;
    Bits_ = hb.Bits_;
	Width_ = hb.Width_;
	Height_ = hb.Height_;
	Stride_ = hb.Stride_;
	Size_ = hb.Size_;

    Bmp_Info_Header_ = std::move(hb.Bmp_Info_Header_);
}
//---------------------------------------------------------------------------
// 重設內部狀態。
int hahaha_bitmap::Reset()
{
	// 將描述資訊重置為空狀態，但保留物件仍可被後續 Resize / Open 重用。
	Name_ = L"";
	Type_ = L"";
	Channel_ = 0;
	Depth_ = 0;
	Bits_ = 0;
	Width_ = 0;
	Height_ = 0;
	Stride_ = 0;
	Size_ = 0;

    Bmp_Info_Header_.release();
	if(Bmp_Info_Header_.get() == NULL)
	{
		Bmp_Info_Header_.reset(new BITMAPINFOHEADER);
	}



	return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
