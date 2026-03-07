//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma package(smart_init)
#include "hahaha_capture_webcam_media_foundation.h"

#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>
#include <cassert>
#include <algorithm>

#include <image_process\color\hahaha_image_process_color.h>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
#include <bitmap\hahaha_c_bitmap_alloc.h>
#include <bitmap\hahaha_c_bitmap_ptr.h>


//hahahalib::hahaha_capture_webcam_media_foundation capture_webcam_media_foundation_;
//capture_webcam_media_foundation_.Initial();
//capture_webcam_media_foundation_.Open(0, 1920, 1080);
//{
//    std::vector<std::wstring> list;
//    capture_webcam_media_foundation_.List_Format(list);
//    list_box_webcam->Items->BeginUpdate();
//    list_box_webcam->Clear();
//    for(int i = 0; i < list.size(); i++)
//    {
//        list_box_webcam->Items->Add(list[i].c_str());
//    }
//    list_box_webcam->Items->EndUpdate();
//}
//
//hahahalib::bitmap_alloc_rgb bitmap_rgb_;
//bitmap_rgb_.Resize(1920, 1080);
////	capture_webcam_media_foundation_.Flip_ = true;
//int rrr = 0;
//// 數張後畫面才會出來，一開始可能還在準備
//while(capture_webcam_media_foundation_.Grab(bitmap_rgb_) == -1 || rrr < 50){rrr++;};
//f_lib::bmp::Save(L"D:\\Desktop\\ttt\\webcam2.bmp", bitmap_rgb_);
//capture_webcam_media_foundation_.Close();
//capture_webcam_media_foundation_.Shut_Down();
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

hahaha_capture_webcam_media_foundation::hahaha_capture_webcam_media_foundation()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_media_foundation::~hahaha_capture_webcam_media_foundation()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_media_foundation::hahaha_capture_webcam_media_foundation(const hahaha_capture_webcam_media_foundation& hcwmf)
{
    Reset();
    Copy(hcwmf);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_media_foundation::hahaha_capture_webcam_media_foundation(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept
{
    Move(std::move(hcwmf));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_media_foundation& hahaha_capture_webcam_media_foundation::operator=(const hahaha_capture_webcam_media_foundation& hcwmf)
{
    if (this != &hcwmf)
    {
        Copy(hcwmf);
    }
    return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_media_foundation& hahaha_capture_webcam_media_foundation::operator=(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept
{
    if (this != &hcwmf)
    {
        Move(std::move(hcwmf));
    }
    return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_media_foundation::Copy(const hahaha_capture_webcam_media_foundation& hcwmf)
{
    // shallow copy only for non‑COM members（跟 DirectShow 版一樣，不複製狀態）
    Width_          = hcwmf.Width_;
    Height_         = hcwmf.Height_;
    Camera_Index_   = hcwmf.Camera_Index_;
    Channels_       = hcwmf.Channels_;
    Sub_Type_ 		= hcwmf.Sub_Type_;
    Flip_           = hcwmf.Flip_;
    Is_Open_        = false;      // 不複製開啟狀態
    Is_Initial_     = hcwmf.Is_Initial_;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_media_foundation::Move(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept
{
    Source_Reader_  = std::move(hcwmf.Source_Reader_);
    Media_Source_   = std::move(hcwmf.Media_Source_);

    Width_          = hcwmf.Width_;
    Height_         = hcwmf.Height_;
    Camera_Index_   = hcwmf.Camera_Index_;
    Channels_       = hcwmf.Channels_;
    Sub_Type_ 		= hcwmf.Sub_Type_;
    Flip_           = hcwmf.Flip_;
    Is_Open_        = hcwmf.Is_Open_;
    Is_Initial_     = hcwmf.Is_Initial_;

    hcwmf.Source_Reader_.reset();
    hcwmf.Media_Source_.reset();
    hcwmf.Is_Open_ = false;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_media_foundation::Reset()
{
    Source_Reader_.reset();
    Media_Source_.reset();

    Width_          = 0;
    Height_         = 0;
    Camera_Index_   = 0;
    Channels_       = 0;
	Sub_Type_ = MFVideoFormat_Base;

    Flip_       = false;
    Is_Open_    = false;
    Is_Initial_ = false;

    return 0;
}
//---------------------------------------------------------------------------
bool hahaha_capture_webcam_media_foundation::Initial()
{
    if (Is_Initial_)
    {
        return true;
    }

    HRESULT hr = MFStartup(MF_VERSION);
    if (FAILED(hr))
    {
        return false;
    }
    Is_Initial_ = true;
    return true;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_media_foundation::Shut_Down()
{
    if (Is_Initial_)
    {
        MFShutdown();
        Is_Initial_ = false;
    }
}

//---------------------------------------------------------------------------
int hahaha_capture_webcam_media_foundation::Open(int camera_index,
    int width,
    int height,
    GUID sub_type
)
{
    if (Is_Open_)
    {
        return -1;
    }

    IMFAttributes* p_attr_ = nullptr;
    MFCreateAttributes(&p_attr_, 1);
    p_attr_->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
		MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
    );

    IMFActivate** pp_devices_ = nullptr;
    UINT32 count_ = 0;
    MFEnumDeviceSources(p_attr_,
    	&pp_devices_,
        &count_
    );
    p_attr_->Release();

    if (count_ == 0 || camera_index >= (int)count_)
    {
        return -1;
    }


    IMFMediaSource* p_source_ = nullptr;
    pp_devices_[camera_index]->ActivateObject(IID_PPV_ARGS(&p_source_));

    for (UINT32 i = 0; i < count_; i++)
    {
        pp_devices_[i]->Release();
    }

    CoTaskMemFree(pp_devices_);

    IMFAttributes* p_reader_attr_ = nullptr;
    MFCreateAttributes(&p_reader_attr_, 1);

    // ★★★ 不啟用 Video Processing（避免自動轉成 RGB）★★★
    p_reader_attr_->SetUINT32(MF_READWRITE_DISABLE_CONVERTERS, TRUE);

    IMFSourceReader* p_reader_ = nullptr;
    MFCreateSourceReaderFromMediaSource(p_source_,
    	p_reader_attr_,
        &p_reader_
    );
    p_reader_attr_->Release();

    IMFMediaType* p_type_ = nullptr;
    MFCreateMediaType(&p_type_);

    p_type_->SetGUID(MF_MT_MAJOR_TYPE,
    	MFMediaType_Video
    );
    p_type_->SetGUID(MF_MT_SUBTYPE,
    	sub_type
    );
    MFSetAttributeSize(p_type_,
    	MF_MT_FRAME_SIZE,
        width,
        height
    );

    HRESULT hr_ = p_reader_->SetCurrentMediaType(
        MF_SOURCE_READER_FIRST_VIDEO_STREAM,
        NULL,
        p_type_
    );
    p_type_->Release();

    if (FAILED(hr_))
    {
        p_reader_->Release();
        p_source_->Release();
        return hr_;
    }

    IMFMediaType* p_out_ = nullptr;
    p_reader_->GetCurrentMediaType(MF_SOURCE_READER_FIRST_VIDEO_STREAM,
    	&p_out_
    );

    UINT32 w_ = 0, h_ = 0;
    MFGetAttributeSize(p_out_,
    	MF_MT_FRAME_SIZE,
        &w_,
        &h_
    );

    GUID out_subtype_;
    p_out_->GetGUID(MF_MT_SUBTYPE,
    	&out_subtype_
    );
    p_out_->Release();



    // ★★★ YUY2 = 2 bytes per pixel ★★★
    if(sub_type == MFVideoFormat_YUY2)
    {
        Channels_ = 2;
    }
	else if(sub_type == MFVideoFormat_RGB24)
    {
        Channels_ = 3;
    }


    Source_Reader_.reset(p_reader_);
    Media_Source_.reset(p_source_);

    Is_Open_ = true;
	Camera_Index_   = camera_index;
    Width_  = w_;
	Height_ = h_;

    Sub_Type_ = sub_type;

    return 0;
}

//---------------------------------------------------------------------------
int hahaha_capture_webcam_media_foundation::Grab(hahahalib::bitmap_rgb& bitmap)
{
    if (!Is_Open_ || !Source_Reader_)
    {
        return -1;
    }

    DWORD idx_ = 0, flags_ = 0;
    LONGLONG ts_ = 0;
    IMFSample* p_sample_ = nullptr;

    HRESULT hr_ = Source_Reader_->ReadSample(
        MF_SOURCE_READER_FIRST_VIDEO_STREAM,
        0,
        &idx_,
        &flags_,
        &ts_,
        &p_sample_
    );

    if (flags_ & MF_SOURCE_READERF_STREAMTICK)
    {
        return -1;
    }

    if (FAILED(hr_) || !p_sample_)
    {
        return -1;
    }

    IMFMediaBuffer* p_buffer_ = nullptr;
    p_sample_->ConvertToContiguousBuffer(&p_buffer_);
    p_sample_->Release();

    BYTE* p_data_ = nullptr;
    DWORD max_len_ = 0, cur_len_ = 0;
    p_buffer_->Lock(&p_data_,
    	&max_len_,
        &cur_len_
    );

    if(Sub_Type_ == MFVideoFormat_YUY2)
    {
    	if(Flip_)
		{
            hahahalib::bitmap_ptr_yuv422 bitmap_temp_(p_data_);
			bitmap_temp_.Resize(Width_, Height_);

			hahahalib::bitmap_alloc_yvyu bitmap_temp_yvyu_;
			bitmap_temp_yvyu_.Resize(Width_, Height_);

			hahahalib::bitmap_alloc_rgb bitmap_temp_rgb_;
			bitmap_temp_rgb_.Resize(Width_, Height_);

			halib_image::color::YUY2_To_YVYU(
				bitmap_temp_,
				halib::roi(0, 0, bitmap_temp_.Width_ - 1, bitmap_temp_.Height_ - 1),
				bitmap_temp_yvyu_,
				halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1)
			);

			halib_image::color::YUV422_To_RGB(
				bitmap_temp_yvyu_,
				halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1),
				bitmap_temp_rgb_,
				halib::roi(0, 0, bitmap_temp_rgb_.Width_ - 1, bitmap_temp_rgb_.Height_ - 1)
			);



            halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
				bitmap_temp_rgb_,
                halib::roi(0, 0, bitmap_temp_rgb_.Width_ - 1, bitmap_temp_rgb_.Height_ - 1),
                bitmap,
                halib::roi(0, 0, bitmap.Width_ - 1, bitmap.Height_ - 1)
			);
        }
        else
        {
			hahahalib::bitmap_ptr_yuv422 bitmap_temp_(p_data_);
			bitmap_temp_.Resize(Width_, Height_);

			hahahalib::bitmap_alloc_yvyu bitmap_temp_yvyu_;
			bitmap_temp_yvyu_.Resize(Width_, Height_);

			halib_image::color::YUY2_To_YVYU(
				bitmap_temp_,
				halib::roi(0, 0, bitmap_temp_.Width_ - 1, bitmap_temp_.Height_ - 1),
				bitmap_temp_yvyu_,
				halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1)
			);

			halib_image::color::YUV422_To_RGB(
				bitmap_temp_yvyu_,
				halib::roi(0, 0, bitmap_temp_yvyu_.Width_ - 1, bitmap_temp_yvyu_.Height_ - 1),
				bitmap,
				halib::roi(0, 0, bitmap.Width_ - 1, bitmap.Height_ - 1)
			);
        }

    }

    p_buffer_->Unlock();
    p_buffer_->Release();

    return true;
}


//---------------------------------------------------------------------------
void hahaha_capture_webcam_media_foundation::Close()
{
    Source_Reader_.reset();
    Media_Source_.reset();

    Is_Open_ = false;
}

//---------------------------------------------------------------------------
bool hahaha_capture_webcam_media_foundation::Enum_Native_Types(std::vector<IMFMediaType*>& types)
{
    types.clear();
    if (!Source_Reader_)
    {
        return false;
    }

    DWORD index = 0;
    while (true)
    {
        IMFMediaType* p_type = nullptr;
        HRESULT hr = Source_Reader_->GetNativeMediaType(
            (DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM,
            index,
            &p_type
        );
        if (FAILED(hr))
        {
            break;
        }
        types.push_back(p_type);
        ++index;
    }
    return !types.empty();
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_media_foundation::List_Format(std::vector<std::wstring>& list)
{
    list.clear();

    if (!Is_Open_ || !Source_Reader_)
    {
        return -1;
    }

    std::vector<IMFMediaType*> types;
    if (!Enum_Native_Types(types))
    {
        return -1;
    }

    for (auto* p_type : types)
    {
        UINT32 w = 0, h = 0;
        if (SUCCEEDED(MFGetAttributeSize(p_type, MF_MT_FRAME_SIZE, &w, &h)))
        {
            GUID subtype = { 0 };
            p_type->GetGUID(MF_MT_SUBTYPE, &subtype);

            std::wstring fmt;
            if (IsEqualGUID(subtype, MFVideoFormat_RGB24))
            {
                fmt = L"RGB24";
			}
            else if (IsEqualGUID(subtype, MFVideoFormat_RGB32))
            {
                fmt = L"RGB32";
            }
            else if (IsEqualGUID(subtype, MFVideoFormat_YUY2))
            {
                fmt = L"YUY2";
            }
            else if (IsEqualGUID(subtype, MFVideoFormat_MJPG))
            {
                fmt = L"MJPEG";
            }
            else if (IsEqualGUID(subtype, MFVideoFormat_NV12))
            {
                fmt = L"NV12";
            }
            else
            {
                fmt = L"OTHER";
            }

            wchar_t buf[128];
            swprintf(buf, 128, L"%dx%d %s", (int)w, (int)h, fmt.c_str());
            list.push_back(buf);
        }
        p_type->Release();
    }

    return 0;
}

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

