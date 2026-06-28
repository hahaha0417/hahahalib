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
    // 建構物件並初始化預設狀態。
    hahaha_capture_webcam_media_foundation();
    // 解構物件並釋放相關資源。
    ~hahaha_capture_webcam_media_foundation();

    // 以既有物件內容建構新的物件實例。
    hahaha_capture_webcam_media_foundation(const hahaha_capture_webcam_media_foundation& hcwmf);
    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_webcam_media_foundation(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;
    // 複製指派目前物件內容。
    hahaha_capture_webcam_media_foundation& operator=(const hahaha_capture_webcam_media_foundation& hcwmf);
    // 移動指派目前物件內容。
    hahaha_capture_webcam_media_foundation& operator=(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;

    // 複製來源物件的內部狀態。
    void Copy(const hahaha_capture_webcam_media_foundation& hcwmf);
    // 接手來源物件的內部資源。
    void Move(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;

public:
    // 仿 DirectShow 版本的介面
    int Reset();

	// camera_index / width / height / sub_type 介面與 DirectShow 版相同
	// 相機有支援RGB24才能開啟，不能自動轉換
	int Open(int camera_index = 0,  // 要開啟的攝影機索引。
              int width        = 1920,  // 目標寬度。
              int height       = 1080,  // 目標高度。
			  GUID sub_type    = MFVideoFormat_YUY2);

    // 有空加另外grab roi(webcam) to roi(bitmap)，節省copy
    // 直接抓到 bitmap_rgb（會自動檢查大小是否正確）
    int Grab(hahahalib::bitmap_rgb& bitmap);

    // 關閉並釋放目前持有的資源。
    void Close();

    // 列出裝置支援的格式（解析度 + subtype），字串格式類似 DirectShow 版
    int List_Format(std::vector<std::wstring>& list);

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
    // 初始化相關設定。
    bool Initial();
    // 關閉 Media Foundation 並釋放初始化狀態。
    void Shut_Down();

    // 內部使用：列出 native media type
    bool Enum_Native_Types(std::vector<IMFMediaType*>& types);
};

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------

#endif
