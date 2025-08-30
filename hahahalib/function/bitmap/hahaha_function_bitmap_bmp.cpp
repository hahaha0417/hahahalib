//---------------------------------------------------------------------------

#pragma hdrstop

#include <windows.h>

#include "hahaha_function_bitmap_bmp.h"
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
//---------------------------------------------------------------------------
halib_def::result hahaha_function_bitmap_bmp::Load(const std::wstring& filename, halib::bitmap_gray& bitmap_gray)
{
    FILE* file_ = _wfopen(filename.c_str(), L"rb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

	BITMAPFILEHEADER bitmap_file_header_;                         // Other BMP header
	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header


	fread(&bitmap_file_header_, sizeof(BITMAPFILEHEADER), 1, file_);

    //verify that this is a bmp file by check bitmap id
	if (bitmap_file_header_.bfType != 0x4D42)
	{
		fclose(file_);
		return halib_def::result::FAILURE;
	}

	//read the bitmap info header
	fread(&bitmap_info_header_, sizeof(BITMAPINFOHEADER), 1, file_);

	if(bitmap_info_header_.biBitCount != bitmap_gray.Bits_)
	{
        // 位元數不同
		fclose(file_);
		return halib_def::result::FAILURE;
	}



	int width_ = 0;
	int height_ = 0;
	if(bitmap_info_header_.biHeight < 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 正向
		width_ = bitmap_info_header_.biWidth;
		height_ = -1 * bitmap_info_header_.biHeight;
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 反向
		width_ = bitmap_info_header_.biWidth;
		height_ = bitmap_info_header_.biHeight;
	}

	bitmap_gray.Resize(width_, height_);

    //move file point to the begging of bitmap data
	fseek(file_, bitmap_file_header_.bfOffBits, SEEK_SET);

	if(bitmap_info_header_.biHeight < 0)
	{
		//read in the bitmap image data
		fread(bitmap_gray.Image_Ptr_, bitmap_info_header_.biSizeImage, 1, file_);
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		//read in the bitmap image data
		for(int i = 0; i < height_; i++)
		{
			fread(bitmap_gray[height_ - 1 - i], bitmap_gray.Stride_, 1, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;

}
//---------------------------------------------------------------------------
//https://www.vbforums.com/showthread.php?261522-C-C-Loading-Bitmap-Files-(Manually)
halib_def::result hahaha_function_bitmap_bmp::Load(const std::wstring& filename, halib::bitmap_rgb& bitmap_rgb)
{
	FILE* file_ = _wfopen(filename.c_str(), L"rb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

	BITMAPFILEHEADER bitmap_file_header_;                         // Other BMP header
	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header


	fread(&bitmap_file_header_, sizeof(BITMAPFILEHEADER), 1, file_);

    //verify that this is a bmp file by check bitmap id
	if (bitmap_file_header_.bfType != 0x4D42)
	{
		fclose(file_);
		return halib_def::result::FAILURE;
	}

	//read the bitmap info header
	fread(&bitmap_info_header_, sizeof(BITMAPINFOHEADER), 1, file_);

	if(bitmap_info_header_.biBitCount != bitmap_rgb.Bits_)
	{
        // 位元數不同
		fclose(file_);
		return halib_def::result::FAILURE;
	}



	int width_ = 0;
	int height_ = 0;
	if(bitmap_info_header_.biHeight < 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 正向
		width_ = bitmap_info_header_.biWidth;
		height_ = -1 * bitmap_info_header_.biHeight;
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 反向
		width_ = bitmap_info_header_.biWidth;
		height_ = bitmap_info_header_.biHeight;
	}

	bitmap_rgb.Resize(width_, height_);

    //move file point to the begging of bitmap data
	fseek(file_, bitmap_file_header_.bfOffBits, SEEK_SET);

	if(bitmap_info_header_.biHeight < 0)
	{
		//read in the bitmap image data
		fread(bitmap_rgb.Image_Ptr_, bitmap_info_header_.biSizeImage, 1, file_);
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		//read in the bitmap image data
		for(int i = 0; i < height_; i++)
		{
			fread(bitmap_rgb[height_ - 1 - i], bitmap_rgb.Stride_, 1, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;


}
//---------------------------------------------------------------------------
//chatgpt
//Load Bitmap c++ 32bit
//raw
halib_def::result hahaha_function_bitmap_bmp::Load(const std::wstring& filename, halib::bitmap_argb& bitmap_argb)
{
	FILE* file_ = _wfopen(filename.c_str(), L"rb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

	BITMAPFILEHEADER bitmap_file_header_;                         // Other BMP header
	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header


	fread(&bitmap_file_header_, sizeof(BITMAPFILEHEADER), 1, file_);

    //verify that this is a bmp file by check bitmap id
	if (bitmap_file_header_.bfType != 0x4D42)
	{
		fclose(file_);
		return halib_def::result::FAILURE;
	}

	//read the bitmap info header
	fread(&bitmap_info_header_, sizeof(BITMAPINFOHEADER), 1, file_);

	if(bitmap_info_header_.biBitCount != bitmap_argb.Bits_)
	{
        // 位元數不同
		fclose(file_);
		return halib_def::result::FAILURE;
	}



	int width_ = 0;
	int height_ = 0;
	if(bitmap_info_header_.biHeight < 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 正向
		width_ = bitmap_info_header_.biWidth;
		height_ = -1 * bitmap_info_header_.biHeight;
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		// 反向
		width_ = bitmap_info_header_.biWidth;
		height_ = bitmap_info_header_.biHeight;
	}

	bitmap_argb.Resize(width_, height_);

    //move file point to the begging of bitmap data
	fseek(file_, bitmap_file_header_.bfOffBits, SEEK_SET);

	if(bitmap_info_header_.biHeight < 0)
	{
		//read in the bitmap image data
		fread(bitmap_argb.Image_Ptr_, bitmap_info_header_.biSizeImage, 1, file_);
	}
	else if(bitmap_info_header_.biHeight >= 0)
	{
		//read in the bitmap image data
		for(int i = 0; i < height_; i++)
		{
			fread(bitmap_argb[height_ - 1 - i], bitmap_argb.Stride_, 1, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;


}
//---------------------------------------------------------------------------
//https://stackoverflow.com/questions/27707407/how-to-add-color-palette-to-bitmapinfo
halib_def::result hahaha_function_bitmap_bmp::Save(const std::wstring& filename, const halib::bitmap_gray& bitmap_gray, const halib_def::bitmap_direction& direction)
{
    FILE* file_ = _wfopen(filename.c_str(), L"wb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

    // 調色盤
	int number_of_colors_ = 256;
	int color_palette_size_ = number_of_colors_ * sizeof(RGBQUAD);
	RGBQUAD quad_[number_of_colors_];

    // create the color palette
	for (int i = 0; i < number_of_colors_; i++)
	{
		quad_[i].rgbBlue = i;
		quad_[i].rgbGreen = i;
		quad_[i].rgbRed = i;
		quad_[i].rgbReserved = 0;
	}


	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header

	memset(&bitmap_info_header_, 0, sizeof(BITMAPINFOHEADER));

	// Create the bitmap for this OpenGL context
	bitmap_info_header_.biSize = sizeof(BITMAPINFOHEADER);
	bitmap_info_header_.biWidth = bitmap_gray.Width_;

	if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = -1 * bitmap_gray.Height_;
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = bitmap_gray.Height_;
	}

	bitmap_info_header_.biPlanes = 1;
	bitmap_info_header_.biBitCount = bitmap_gray.Bits_;
	bitmap_info_header_.biCompression = BI_RGB;
	bitmap_info_header_.biSizeImage = bitmap_gray.Size_;
	bitmap_info_header_.biXPelsPerMeter = 0;               // Preferred resolution in pixels per meter
	bitmap_info_header_.biYPelsPerMeter = 0;               // Preferred resolution in pixels per meter
	bitmap_info_header_.biClrUsed = number_of_colors_;      // Number of entries in the color map that are actually used
	bitmap_info_header_.biClrImportant = 0;                // Number of significant colors (All colors = 0)


	BITMAPFILEHEADER bitmap_file_header_;

	memset(&bitmap_file_header_, 0, sizeof(bitmap_file_header_));
						 // Other BMP header
	int bits_offset_ = sizeof(BITMAPFILEHEADER) + bitmap_info_header_.biSize + color_palette_size_;
	LONG image_size_ = bitmap_info_header_.biSizeImage;
	LONG file_size_ = bits_offset_ + image_size_;
	bitmap_file_header_.bfType = 'B' + ('M' << 8);
	bitmap_file_header_.bfOffBits = bits_offset_;
	bitmap_file_header_.bfSize = file_size_;
	bitmap_file_header_.bfReserved1 = bitmap_file_header_.bfReserved2 = 0;





    // Write the bitmap file header               // Saving the first header to file
	unsigned int write_file_header_size_ = fwrite(&bitmap_file_header_, 1, sizeof(BITMAPFILEHEADER), file_);

	// And then the bitmap info header            // Saving the second header to file
	unsigned int write_info_header_size_ = fwrite(&bitmap_info_header_, 1, sizeof(BITMAPINFOHEADER), file_);

	// write palette
	unsigned int write_color_palette_size_ = fwrite(&quad_, 1, color_palette_size_, file_);



    if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// Finally, write the image data itself
		//-- the data represents our drawing          // Saving the file content in lpBits to file
		unsigned int write_dib_data_size_ = fwrite(bitmap_gray.Image_Ptr_, 1, bitmap_gray.Size_, file_);
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		for(int i = bitmap_gray.Height_ - 1; i >= 0; i--)
		{
            // Finally, write the image data itself
			//-- the data represents our drawing          // Saving the file content in lpBits to file
			unsigned int write_dib_data_size_ = fwrite(bitmap_gray.Image_Scanline_[i], 1, bitmap_gray.Stride_, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;


}
//---------------------------------------------------------------------------
// https://stackoverflow.com/questions/24944168/c-saving-a-bitmap-file
halib_def::result hahaha_function_bitmap_bmp::Save(const std::wstring& filename, const halib::bitmap_rgb& bitmap_rgb, const halib_def::bitmap_direction& direction)
{
	FILE* file_ = _wfopen(filename.c_str(), L"wb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header

	memset(&bitmap_info_header_, 0, sizeof(BITMAPINFOHEADER));

	// Create the bitmap for this OpenGL context
	bitmap_info_header_.biSize = sizeof(BITMAPINFOHEADER);
	bitmap_info_header_.biWidth = bitmap_rgb.Width_;

	if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = -1 * bitmap_rgb.Height_;
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = bitmap_rgb.Height_;
	}

	bitmap_info_header_.biPlanes = 1;
	bitmap_info_header_.biBitCount = bitmap_rgb.Bits_;
	bitmap_info_header_.biCompression = BI_RGB;
	bitmap_info_header_.biSizeImage = bitmap_rgb.Size_;

	BITMAPFILEHEADER bitmap_file_header_;                         // Other BMP header

	memset(&bitmap_file_header_, 0, sizeof(BITMAPFILEHEADER));

	int bits_offset_ = sizeof(BITMAPFILEHEADER) + bitmap_info_header_.biSize;
	LONG image_size_ = bitmap_info_header_.biSizeImage;
	LONG file_size_ = bits_offset_ + image_size_;
	bitmap_file_header_.bfType = 'B' + ('M' << 8);
	bitmap_file_header_.bfOffBits = bits_offset_;
	bitmap_file_header_.bfSize = file_size_;
	bitmap_file_header_.bfReserved1 = bitmap_file_header_.bfReserved2 = 0;

    // Write the bitmap file header               // Saving the first header to file
	unsigned int write_file_header_size_ = fwrite(&bitmap_file_header_, 1, sizeof(BITMAPFILEHEADER), file_);

	// And then the bitmap info header            // Saving the second header to file
	unsigned int write_info_header_size_ = fwrite(&bitmap_info_header_, 1, sizeof(BITMAPINFOHEADER), file_);



    if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// Finally, write the image data itself
		//-- the data represents our drawing          // Saving the file content in lpBits to file
		unsigned int write_dib_data_size_ = fwrite(bitmap_rgb.Image_Ptr_, 1, bitmap_rgb.Size_, file_);
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		for(int i = bitmap_rgb.Height_ - 1; i >= 0; i--)
		{
            // Finally, write the image data itself
			//-- the data represents our drawing          // Saving the file content in lpBits to file
			unsigned int write_dib_data_size_ = fwrite(bitmap_rgb.Image_Scanline_[i], 1, bitmap_rgb.Stride_, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;


}
//---------------------------------------------------------------------------
halib_def::result hahaha_function_bitmap_bmp::Save(const std::wstring& filename, const halib::bitmap_argb& bitmap_argb, const halib_def::bitmap_direction& direction)
{
	FILE* file_ = _wfopen(filename.c_str(), L"wb");

	if(file_ == NULL)
	{
		// 失敗
		return halib_def::result::FAILURE;
	}

	BITMAPINFOHEADER bitmap_info_header_;                         // BMP header

	memset(&bitmap_info_header_, 0, sizeof(BITMAPINFOHEADER));

	// Create the bitmap for this OpenGL context
	bitmap_info_header_.biSize = sizeof(BITMAPINFOHEADER);
	bitmap_info_header_.biWidth = bitmap_argb.Width_;

	if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = -1 * bitmap_argb.Height_;
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		bitmap_info_header_.biHeight = bitmap_argb.Height_;
	}

	bitmap_info_header_.biPlanes = 1;
	bitmap_info_header_.biBitCount = bitmap_argb.Bits_;
	bitmap_info_header_.biCompression = BI_RGB;
	bitmap_info_header_.biSizeImage = bitmap_argb.Size_;

	BITMAPFILEHEADER bitmap_file_header_;                         // Other BMP header

	memset(&bitmap_file_header_, 0, sizeof(BITMAPFILEHEADER));

	int bits_offset_ = sizeof(BITMAPFILEHEADER) + bitmap_info_header_.biSize;
	LONG image_size_ = bitmap_info_header_.biSizeImage;
	LONG file_size_ = bits_offset_ + image_size_;
	bitmap_file_header_.bfType = 'B' + ('M' << 8);
	bitmap_file_header_.bfOffBits = bits_offset_;
	bitmap_file_header_.bfSize = file_size_;
	bitmap_file_header_.bfReserved1 = bitmap_file_header_.bfReserved2 = 0;

    // Write the bitmap file header               // Saving the first header to file
	unsigned int write_file_header_size_ = fwrite(&bitmap_file_header_, 1, sizeof(BITMAPFILEHEADER), file_);

	// And then the bitmap info header            // Saving the second header to file
	unsigned int write_info_header_size_ = fwrite(&bitmap_info_header_, 1, sizeof(BITMAPINFOHEADER), file_);



    if(direction == hahaha_define_bitmap_direction::FORWARD)
	{
		// Finally, write the image data itself
		//-- the data represents our drawing          // Saving the file content in lpBits to file
		unsigned int write_dib_data_size_ = fwrite(bitmap_argb.Image_Ptr_, 1, bitmap_argb.Size_, file_);
	}
	else if(direction == hahaha_define_bitmap_direction::REVERSE)
	{
		// https://crazycat1130.pixnet.net/blog/post/1345538
		for(int i = bitmap_argb.Height_ - 1; i >= 0; i--)
		{
            // Finally, write the image data itself
			//-- the data represents our drawing          // Saving the file content in lpBits to file
			unsigned int write_dib_data_size_ = fwrite(bitmap_argb.Image_Scanline_[i], 1, bitmap_argb.Stride_, file_);
		}

	}

	fclose(file_); // closing the file.

	return halib_def::result::SUCCESS;


}
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