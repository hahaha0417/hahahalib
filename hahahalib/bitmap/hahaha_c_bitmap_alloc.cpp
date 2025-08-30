//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_c_bitmap_alloc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>::hahaha_c_bitmap_alloc()
{
    this->Image_Ptr_ = nullptr;
	this->Image_Scanline_ = nullptr;

	Reset();

    //---------------------------------------------------------------------------
    // chatGPT
    // c++ template 繼承
    // 變數繼承
    //---------------------------------------------------------------------------
	this->Channel_ = U;
	this->Depth_ = sizeof(T);
	this->Bits_ = this->Channel_ * this->Depth_ << 3;



}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>::~hahaha_c_bitmap_alloc()
{
    if(this->Image_Ptr_ != nullptr)
	{
		delete[] this->Image_Ptr_;
		this->Image_Ptr_ = nullptr;
	}

	if(this->Image_Scanline_ != nullptr)
	{
		delete[] this->Image_Scanline_;
		this->Image_Scanline_ = nullptr;
	}
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>::hahaha_c_bitmap_alloc(const hahaha_c_bitmap_alloc<T, U>& hcba)
{
    Reset();
	Copy(hcba);
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>::hahaha_c_bitmap_alloc(hahaha_c_bitmap_alloc<T, U>&& hcba) noexcept
{
    hahaha_bitmap::Move(std::move(hcba));
    hahaha_c_bitmap<T, U>::Move(std::move(hcba));
    Move(std::move(hcba));
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>& hahaha_c_bitmap_alloc<T, U>::operator=(const hahaha_c_bitmap_alloc<T, U>& hcba)
{
	Copy(hcba);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_alloc<T, U>& hahaha_c_bitmap_alloc<T, U>::operator=(hahaha_c_bitmap_alloc<T, U>&& hcba) noexcept
{
    if (this != &hcba)
    {
        hahaha_bitmap::Move(std::move(hcba));
        hahaha_c_bitmap<T, U>::Move(std::move(hcba));
    	Move(std::move(hcba));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_alloc<T, U>::operator[](const int& y)
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_alloc<T, U>::operator[](const int& y) const
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_alloc<T, U>::Copy(const hahaha_c_bitmap_alloc<T, U>& hcbp)
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_alloc<T, U>::Move(hahaha_c_bitmap_alloc<T, U>&& hcbp) noexcept
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_alloc<T, U>::Reset()
{
	hahaha_c_bitmap<T, U>::Reset();



	if(this->Image_Ptr_ != nullptr)
	{
		delete[] this->Image_Ptr_;
		this->Image_Ptr_ = nullptr;
	}

	if(this->Image_Scanline_ != nullptr)
	{
		delete[] this->Image_Scanline_;
		this->Image_Scanline_ = nullptr;
	}

	return 0;
}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_alloc<T, U>::Resize(const int& width, const int& height)
{

//    https://learn.microsoft.com/zh-tw/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
	int stride_ = ((((width * this->Bits_) + 31) & ~31) >> 3);
	int size_ = stride_ * height;

	if(size_ != 0 && size_ != this->Size_)
	{
		if(this->Image_Ptr_ != nullptr)
		{
			delete[] this->Image_Ptr_;
			this->Image_Ptr_ = nullptr;
		}

		this->Image_Ptr_ = new T[size_];

		if(this->Image_Scanline_ != nullptr)
		{
			delete[] this->Image_Scanline_;
			this->Image_Scanline_ = nullptr;
		}

//        https://www.geeksforgeeks.org/creating-array-of-pointers-in-cpp/
		this->Image_Scanline_ = new T * [height];

		T* ptr_ = this->Image_Ptr_;
		for(int i = 0; i < height; i++)
		{
			this->Image_Scanline_[i] = ptr_;
			ptr_ += stride_;
		}


		this->Width_ = width;
		this->Height_ = height;
		this->Stride_ = stride_;
		this->Size_ = size_;



        {
            // Create the bitmap for this OpenGL context
            this->Bmp_Info_Header_->biSize = sizeof(BITMAPINFOHEADER);
            this->Bmp_Info_Header_->biWidth = this->Width_;

            this->Bmp_Info_Header_->biHeight = this->Height_;

            this->Bmp_Info_Header_->biPlanes = U;
            this->Bmp_Info_Header_->biBitCount = this->Bits_;
            // 不用設這個
            // this->Bmp_Info_Header_->biCompression = BI_RGB;
            this->Bmp_Info_Header_->biSizeImage = this->Size_;
            this->Bmp_Info_Header_->biXPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            this->Bmp_Info_Header_->biYPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            // this->Bmp_Info_Header_->biClrUsed = number_of_colors_;      // Number of entries in the color map that are actually used
            this->Bmp_Info_Header_->biClrImportant = 0;                // Number of significant colors (All colors = 0)
        }

	}
	else if(size_ != 0 && size_ == this->Size_)
	{
		if(this->Image_Scanline_ != nullptr)
		{
			delete[] this->Image_Scanline_;
			this->Image_Scanline_ = nullptr;
		}

//        https://www.geeksforgeeks.org/creating-array-of-pointers-in-cpp/
		this->Image_Scanline_ = new T*[height];

		T* ptr_ = this->Image_Ptr_;
		for(int i = 0; i < height; i++)
		{
			this->Image_Scanline_[i] = ptr_;
			ptr_ += stride_;
		}


		this->Width_ = width;
		this->Height_ = height;
		this->Stride_ = stride_;
		this->Size_ = size_;

        {
            // Create the bitmap for this OpenGL context
            this->Bmp_Info_Header_->biSize = sizeof(BITMAPINFOHEADER);
            this->Bmp_Info_Header_->biWidth = this->Width_;

            this->Bmp_Info_Header_->biHeight = this->Height_;

            this->Bmp_Info_Header_->biPlanes = U;
            this->Bmp_Info_Header_->biBitCount = this->Bits_;
            // 不用設這個
            // this->Bmp_Info_Header_->biCompression = BI_RGB;
            this->Bmp_Info_Header_->biSizeImage = this->Size_;
            this->Bmp_Info_Header_->biXPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            this->Bmp_Info_Header_->biYPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            // this->Bmp_Info_Header_->biClrUsed = number_of_colors_;      // Number of entries in the color map that are actually used
            this->Bmp_Info_Header_->biClrImportant = 0;                // Number of significant colors (All colors = 0)
        }
	}
	else
	{
		Reset();
        this->Channel_ = U;
		this->Depth_ = sizeof(T);
		this->Bits_ = this->Channel_ * this->Depth_ << 3;

        {
            // Create the bitmap for this OpenGL context
            this->Bmp_Info_Header_->biSize = sizeof(BITMAPINFOHEADER);
            this->Bmp_Info_Header_->biWidth = this->Width_;

            this->Bmp_Info_Header_->biHeight = this->Height_;

            this->Bmp_Info_Header_->biPlanes = U;
            this->Bmp_Info_Header_->biBitCount = this->Bits_;
            // 不用設這個
            // this->Bmp_Info_Header_->biCompression = BI_RGB;
            this->Bmp_Info_Header_->biSizeImage = this->Size_;
            this->Bmp_Info_Header_->biXPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            this->Bmp_Info_Header_->biYPelsPerMeter = 0;               // Preferred resolution in pixels per meter
            // this->Bmp_Info_Header_->biClrUsed = number_of_colors_;      // Number of entries in the color map that are actually used
            this->Bmp_Info_Header_->biClrImportant = 0;                // Number of significant colors (All colors = 0)
        }
	}


    return 0;

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_alloc<T, U>::Clear()
{
    memset(this->Image_Ptr_, 0, this->Size_);

    return 0;

}
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_c_bitmap_alloc<unsigned char, 1>;
template class hahaha_c_bitmap_alloc<unsigned char, 3>;
template class hahaha_c_bitmap_alloc<unsigned char, 4>;
template class hahaha_c_bitmap_alloc<float, 1>;
template class hahaha_c_bitmap_alloc<double, 1>;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------