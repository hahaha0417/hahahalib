//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Vcl.Imaging.gifimg.hpp>
#include <Vcl.Graphics.hpp>
#include "hahaha_function_bitmap_gif.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace function
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace bitmap
{
//---------------------------------------------------------------------------
// 這是錯的，GIF是8bit
// 找不到資源，有需要用c#轉png
halib_def::result hahaha_function_bitmap_gif::Load(const std::wstring& filename, std::vector<std::unique_ptr<halib::bitmap_argb>>& bitmap_argb)
{
//    std::unique_ptr<TGIFImage> gif_;
//	gif_.reset(new TGIFImage);
//
//    std::unique_ptr<TBitmap> bmp_;
//    bmp_.reset(new TBitmap);
//
//    gif_->LoadFromFile(filename.c_str());  // Load the JPEG from file
//
//    image_argb.resize(gif_->Images->Count);
//
//    for (int i = 0; i < gif_->Images->Count; i++)
//    {
//        image_argb[i].reset(new halib_image::image_argb);
//
//    }
//
//    for (int i = 0; i < gif_->Images->Count; i++)
//    {
//
//
//        // Copy pixel data from GIF to Bitmap for each frame
//
//
//        bmp_->Assign(gif_->Images->Frames[i]->Image);
//
//        TPixelFormat format_ = bmp_->PixelFormat;

//
////        if(format_ != pf32bit)
////        {
////            return halib_def::result::FAILURE;
////        }

//
//        image_argb[i]->Resize(bmp_->Width, bmp_->Height);

//
//        // Manipulate the pixels using ScanLine
//        for (int y = 0; y < bmp_->Height; y++)
//        {
//            // Get the pointer to the scanline for row 'y'
//            unsigned char* scanline_ = (unsigned char*)bmp_->ScanLine[y];
//            unsigned char* ptr_ = (unsigned char*)(*image_argb[i])[y];
//
//            for (int x = 0; x < bmp_->Width; x++)
//            {
//                // Each pixel in a 24-bit bitmap is represented by 3 bytes (RGB)
//                // Set pixel (x, y) to red
//                ptr_[x * 4] = scanline_[x * 4];   // Blue
//                ptr_[x * 4 + 1] = scanline_[x * 4 + 1];   // Green
//                ptr_[x * 4 + 2] = scanline_[x * 4 + 2]; // Red
//                ptr_[x * 4 + 3] = scanline_[x * 4 + 3]; // Alpha
//            }
//        }
//    }
//






    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
// 存gif，有用到再補
halib_def::result hahaha_function_bitmap_gif::Save(const std::wstring& filename, std::vector<std::unique_ptr<halib::bitmap_argb>>& bitmap_argb)
{

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // bitmap
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // function
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
