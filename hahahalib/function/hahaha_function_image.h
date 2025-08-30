//---------------------------------------------------------------------------

#ifndef hahaha_function_imageH
#define hahaha_function_imageH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>

//---------------------------------------------------------------------------
#include <image\hahaha_i_image.h>
#include <define\bitmap\hahaha_define_bitmap.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

int Bitmap_Load_Bmp(const std::wstring& filename, halib_image::image_gray& image_gray);
//---------------------------------------------------------------------------
int Bitmap_Load_Bmp(const std::wstring& filename, halib_image::image_rgb& image_rgb);
//---------------------------------------------------------------------------
int Bitmap_Save_Bmp(const std::wstring& filename, const halib_image::image_gray& image_gray, const hahaha_define_bitmap_direction& direction = hahaha_define_bitmap_direction::REVERSE);
//---------------------------------------------------------------------------
//hahahalib::Bitmap_Save_Bmp(L"E:\\桌面\\ttt\\aaa.bmp", image_rgb_, hadef::bitmap_direction::FORWARD);
int Bitmap_Save_Bmp(const std::wstring& filename, const halib_image::image_rgb& image_rgb, const hahaha_define_bitmap_direction& direction = hahaha_define_bitmap_direction::REVERSE);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
