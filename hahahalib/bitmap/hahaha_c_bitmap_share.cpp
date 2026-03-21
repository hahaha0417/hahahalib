//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_c_bitmap_share.h"
//---------------------------------------------------------------------------
#include <memory_mapping\hahaha_memory_mapping.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_share<T, U>::hahaha_c_bitmap_share(const std::wstring& name_mapping, const int& width, const int& height)
{

	Reset();

	this->Channel_ = U;
	this->Depth_ = sizeof(T);
	this->Bits_ = this->Channel_ * this->Depth_ << 3;

    int stride_ = ((((width * this->Bits_) + 31) & ~31) >> 3);
	int size_ = stride_ * height;

    if(Memory_Mapping_->Open(name_mapping) != 0)
    {
        Memory_Mapping_->Create(name_mapping, size_);
    }


    Name_Mapping_ = name_mapping;

    this->Image_Ptr_ = (T*)Memory_Mapping_->Pointer_;
	this->Image_Scanline_ = nullptr;

}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_share<T, U>::~hahaha_c_bitmap_share()
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
hahaha_c_bitmap_share<T, U>::hahaha_c_bitmap_share(const hahaha_c_bitmap_share<T, U>& hcbs)
{
    Reset();
	Copy(hcbs);
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_share<T, U>::hahaha_c_bitmap_share(hahaha_c_bitmap_share<T, U>&& hcbs) noexcept
{
    hahaha_bitmap::Move(std::move(hcbs));
    hahaha_c_bitmap<T, U>::Move(std::move(hcbs));
    Move(std::move(hcbs));
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_share<T, U>& hahaha_c_bitmap_share<T, U>::operator=(const hahaha_c_bitmap_share<T, U>& hcbs)
{
	Copy(hcbs);

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
hahaha_c_bitmap_share<T, U>& hahaha_c_bitmap_share<T, U>::operator=(hahaha_c_bitmap_share<T, U>&& hcbs) noexcept
{
    if (this != &hcbs)
    {
        hahaha_bitmap::Move(std::move(hcbs));
        hahaha_c_bitmap<T, U>::Move(std::move(hcbs));
    	Move(std::move(hcbs));
    }

	return *this;
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_share<T, U>::operator[](const int& y)
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
T*& hahaha_c_bitmap_share<T, U>::operator[](const int& y) const
{
   return this->Image_Scanline_[y];
}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_share<T, U>::Copy(const hahaha_c_bitmap_share<T, U>& hcbs)
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
void hahaha_c_bitmap_share<T, U>::Move(hahaha_c_bitmap_share<T, U>&& hcbs) noexcept
{

}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_share<T, U>::Reset()
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

    if(Memory_Mapping_.get() != nullptr)
    {
        Memory_Mapping_.reset(new hahaha_memory_mapping());
    }

	return 0;
}
//---------------------------------------------------------------------------
template <typename T, int U>
int hahaha_c_bitmap_share<T, U>::Resize(const int& width, const int& height)
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
int hahaha_c_bitmap_share<T, U>::Clear()
{
    memset(this->Image_Ptr_, 0, this->Size_);

    return 0;

}
//---------------------------------------------------------------------------
//https://blog.csdn.net/qq_30835655/article/details/76850894
// template 實例化
template class hahaha_c_bitmap_share<unsigned char, 1>;
template class hahaha_c_bitmap_share<unsigned char, 2>;
template class hahaha_c_bitmap_share<unsigned char, 3>;
template class hahaha_c_bitmap_share<unsigned char, 4>;
template class hahaha_c_bitmap_share<float, 1>;
template class hahaha_c_bitmap_share<double, 1>;
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
