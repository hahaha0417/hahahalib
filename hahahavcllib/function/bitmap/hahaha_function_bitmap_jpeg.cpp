//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <memory>
#include <Vcl.Imaging.jpeg.hpp>
#include "hahaha_function_bitmap_jpeg.h"
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
halib_def::result hahaha_function_bitmap_jpeg::Load(const std::wstring& filename, halib::bitmap_rgb& bitmap_rgb)
{
	std::unique_ptr<TJPEGImage> jpeg_;
	jpeg_.reset(new TJPEGImage);

    std::unique_ptr<TBitmap> bmp_;
    bmp_.reset(new TBitmap);

    jpeg_->LoadFromFile(filename.c_str());  // Load the JPEG from file
    bmp_->Assign(jpeg_.get());  // Assign the JPEG to the TBitmap

	TPixelFormat format_ = bmp_->PixelFormat;

	if(format_ != pf24bit)
	{
		return halib_def::result::FAILURE;
	}

	bitmap_rgb.Resize(bmp_->Width, bmp_->Height);

    // Manipulate the pixels using ScanLine
	for (int y = 0; y < bmp_->Height; y++)
	{
		// Get the pointer to the scanline for row 'y'
		unsigned char* scanline_ = (unsigned char*)bmp_->ScanLine[y];
		unsigned char* ptr_ = (unsigned char*)bitmap_rgb[y];

		for (int x = 0; x < bmp_->Width; x++)
		{
			// Each pixel in a 24-bit bitmap is represented by 3 bytes (RGB)
			// Set pixel (x, y) to red
			ptr_[x * 3] = scanline_[x * 3];   // Blue
			ptr_[x * 3 + 1] = scanline_[x * 3 + 1];   // Green
			ptr_[x * 3 + 2] = scanline_[x * 3 + 2]; // Red
		}
	}

	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
halib_def::result hahaha_function_bitmap_jpeg::Save(const std::wstring& filename, halib::bitmap_rgb& bitmap_rgb, int quality)
{
    std::unique_ptr<TJPEGImage> jpeg_;
	jpeg_.reset(new TJPEGImage);

    std::unique_ptr<TBitmap> bmp_;
    bmp_.reset(new TBitmap);




	bmp_->PixelFormat = pf24bit;
	bmp_->Width = bitmap_rgb.Width_;
	bmp_->Height = bitmap_rgb.Height_;



	// Manipulate the pixels using ScanLine
	for (int y = 0; y < bitmap_rgb.Height_; y++)
	{
		// Get the pointer to the scanline for row 'y'
		unsigned char* scanline_ = (unsigned char*)bmp_->ScanLine[y];
		unsigned char* ptr_ = (unsigned char*)bitmap_rgb[y];

		for (int x = 0; x < bitmap_rgb.Width_; x++)
		{
			// Each pixel in a 24-bit bitmap is represented by 3 bytes (RGB)
			// Set pixel (x, y) to red
			scanline_[x * 3] = ptr_[x * 3];   // Blue
			scanline_[x * 3 + 1] = ptr_[x * 3 + 1];   // Green
			scanline_[x * 3 + 2] = ptr_[x * 3 + 2]; // Red
		}
	}

	jpeg_->Assign(bmp_.get());  // Assign the JPEG to the TBitmap

    // Set the JPEG compression quality (1 = low, 100 = high)
	jpeg_->CompressionQuality = quality;

	jpeg_->SaveToFile(filename.c_str());  // Load the JPEG from file

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
