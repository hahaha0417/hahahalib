//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Vcl.Imaging.pngimage.hpp>

#include "hahaha_function_bitmap_png.h"
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
halib_def::result hahaha_function_bitmap_png::Load(const std::wstring& filename, halib::bitmap_argb& bitmap_argb)
{
    std::unique_ptr<TPngImage> png_;
	png_.reset(new TPngImage);

    std::unique_ptr<TBitmap> bmp_;
    bmp_.reset(new TBitmap);

    png_->LoadFromFile(filename.c_str());  // Load the JPEG from file

    bmp_->Assign(png_.get());

	TPixelFormat format_ = bmp_->PixelFormat;

	if(format_ != pf32bit)
	{
		return halib_def::result::FAILURE;
	}

	bitmap_argb.Resize(bmp_->Width, bmp_->Height);

    // Manipulate the pixels using ScanLine
	for (int y = 0; y < bmp_->Height; y++)
	{
		// Get the pointer to the scanline for row 'y'
		unsigned char* scanline_ = (unsigned char*)bmp_->ScanLine[y];
		unsigned char* ptr_ = (unsigned char*)bitmap_argb[y];

		for (int x = 0; x < bmp_->Width; x++)
		{
			// Each pixel in a 24-bit bitmap is represented by 3 bytes (RGB)
			// Set pixel (x, y) to red
			ptr_[x * 4] = scanline_[x * 4];   // Blue
			ptr_[x * 4 + 1] = scanline_[x * 4 + 1];   // Green
			ptr_[x * 4 + 2] = scanline_[x * 4 + 2]; // Red
            ptr_[x * 4 + 3] = scanline_[x * 4 + 3]; // Alpha
		}
	}

    return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_function_bitmap_png::Save(const std::wstring& filename, halib::bitmap_argb& bitmap_argb, int compress_level)
{
    std::unique_ptr<TPngImage> png_;
	png_.reset(new TPngImage);

    std::unique_ptr<TBitmap> bmp_;
    bmp_.reset(new TBitmap);




	bmp_->PixelFormat = pf32bit;
	bmp_->Width = bitmap_argb.Width_;
	bmp_->Height = bitmap_argb.Height_;



	// Manipulate the pixels using ScanLine
	for (int y = 0; y < bitmap_argb.Height_; y++)
	{
		// Get the pointer to the scanline for row 'y'
		unsigned char* scanline_ = (unsigned char*)bmp_->ScanLine[y];
		unsigned char* ptr_ = (unsigned char*)bitmap_argb[y];

		for (int x = 0; x < bitmap_argb.Width_; x++)
		{
			// Each pixel in a 24-bit bitmap is represented by 3 bytes (RGB)
			// Set pixel (x, y) to red
			scanline_[x * 4] = ptr_[x * 4];   // Blue
			scanline_[x * 4 + 1] = ptr_[x * 4 + 1];   // Green
			scanline_[x * 4 + 2] = ptr_[x * 4 + 2]; // Red
            scanline_[x * 4 + 3] = ptr_[x * 4 + 3]; // Alpha
		}
	}

	png_->Assign(bmp_.get());
    png_->Transparent = true;
	png_->TransparentColor = (TColor)0x00000000;


	png_->CompressionLevel = compress_level;



	png_->SaveToFile(filename.c_str());  // Load the JPEG from file

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



