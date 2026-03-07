//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_media_foundationH
#define hahaha_capture_webcam_media_foundationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
// Windows / Media Foundation
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <vector>
#include <memory>
#include <string>

#include <define\hahaha_define_com.h>
#include <bitmap\hahaha_c_bitmap_alloc.h>

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

class hahaha_capture_webcam_media_foundation
{
public:
    hahaha_capture_webcam_media_foundation();
    ~hahaha_capture_webcam_media_foundation();

    hahaha_capture_webcam_media_foundation(const hahaha_capture_webcam_media_foundation& hcwmf);
    hahaha_capture_webcam_media_foundation(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;
    hahaha_capture_webcam_media_foundation& operator=(const hahaha_capture_webcam_media_foundation& hcwmf);
    hahaha_capture_webcam_media_foundation& operator=(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;

    void Copy(const hahaha_capture_webcam_media_foundation& hcwmf);
    void Move(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;

public:
    // 仿 DirectShow 版本的介面
    int  Reset();

	// camera_index / width / height / sub_type 介面與 DirectShow 版相同
	// 相機有支援RGB24才能開啟，不能自動轉換
	int  Open(int camera_index = 0,
              int width        = 1920,
              int height       = 1080,
			  GUID sub_type    = MFVideoFormat_YUY2);


    // 直接抓到 bitmap_rgb（會自動檢查大小是否正確）
    int  Grab(hahahalib::bitmap_rgb& bitmap);

    void Close();

    // 列出裝置支援的格式（解析度 + subtype），字串格式類似 DirectShow 版
    int  List_Format(std::vector<std::wstring>& list);

public:
    // Media Foundation 元件
    halib_def::com_ptr<IMFSourceReader> Source_Reader_;
    halib_def::com_ptr<IMFMediaSource>  Media_Source_;

    int   Width_;
    int   Height_;
    int   Camera_Index_;
    int   Channels_;          // 3 for RGB24, 4 for RGB32
    GUID  Sub_Type_;



    // 上下翻轉
    bool  Flip_;
    bool  Is_Open_;
    bool  Is_Initial_;

public:
    bool Initial();
    void Shut_Down();

    // 內部使用：列出 native media type
    bool Enum_Native_Types(std::vector<IMFMediaType*>& types);
};

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

#endif

