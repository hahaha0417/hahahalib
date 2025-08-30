//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_c_bitmap_ptr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>::hahaha_c_bitmap_ptr(T* image_ptr)
{
    this->Image_Ptr_ = image_ptr;
	this->Image_Scanline_ = nullptr;

	Reset();

	this->Channel_ = U;
	this->Depth_ = sizeof(T);
	this->Bits_ = this->Channel_ * this->Depth_ << 3;



}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>::~hahaha_c_bitmap_ptr()
{


	if(this->Image_Scanline_ != nullptr)
	{
		delete[] this->Image_Scanline_;
		this->Image_Scanline_ = nullptr;
	}
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>::hahaha_c_bitmap_ptr(const hahaha_c_bitmap_ptr<T, U>& hcbp)
{
    Reset();
	Copy(hcbp);
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>::hahaha_c_bitmap_ptr(hahaha_c_bitmap_ptr<T, U>&& hcbp) noexcept
{
    hahaha_bitmap::Move(std::move(hcbp));
    hahaha_c_bitmap<T, U>::Move(std::move(hcbp));
    Move(std::move(hcbp));
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>& hahaha_c_bitmap_ptr<T, U>::operator=(const hahaha_c_bitmap_ptr<T, U>& hcbp)
{
	Copy(hcbp);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_ptr<T, U>& hahaha_c_bitmap_ptr<T, U>::operator=(hahaha_c_bitmap_ptr<T, U>&& hcbp) noexcept
{
	if (this != &hcbp)
    {
        hahaha_bitmap::Move(std::move(hcbp));
        hahaha_c_bitmap<T, U>::Move(std::move(hcbp));
    	Move(std::move(hcbp));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_ptr<T, U>::operator[](const int& y)
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_ptr<T, U>::operator[](const int& y) const
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_ptr<T, U>::Copy(const hahaha_c_bitmap_ptr<T, U>& hcbp)
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_ptr<T, U>::Move(hahaha_c_bitmap_ptr<T, U>&& hcbp) noexcept
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_ptr<T, U>::Reset()
{
	hahaha_c_bitmap<T, U>::Reset();


	if(this->Image_Scanline_ != nullptr)
	{
		delete[] this->Image_Scanline_;
		this->Image_Scanline_ = nullptr;
	}

	return 0;
}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_ptr<T, U>::Resize(const int& width, const int& height)
{

//    https://learn.microsoft.com/zh-tw/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader
	int stride_ = ((((width * this->Bits_) + 31) & ~31) >> 3);
	int size_ = stride_ * height;

	if(size_ != 0 && size_ != this->Size_)
	{

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
int hahaha_c_bitmap_ptr<T, U>::Clear()
{
    memset(this->Image_Ptr_, 0, this->Size_);

    return 0;

}
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_c_bitmap_ptr<unsigned char, 1>;
template class hahaha_c_bitmap_ptr<unsigned char, 3>;
template class hahaha_c_bitmap_ptr<unsigned char, 4>;
template class hahaha_c_bitmap_ptr<float, 1>;
template class hahaha_c_bitmap_ptr<double, 1>;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------