//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_direct_showH
#define hahaha_capture_webcam_direct_showH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <memory>
//---------------------------------------------------------------------------
#include <windows.h>
#include <dshow.h>
#include <strmif.h>
#include <control.h>
#include <uuids.h>
#include <amvideo.h>
#include <define\dshow\hahaha_define_dshow_qedit.h>  // ISampleGrabber, CLSID_SampleGrabber
//---------------------------------------------------------------------------
#include <define\hahaha_define_com.h>
#include <bitmap\hahaha_c_bitmap_alloc.h>


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_capture_webcam_direct_show_item;
//---------------------------------------------------------------------------

// 以 DirectShow 擷取攝影機畫面的封裝。
// 流程大致分成：建立 graph、選攝影機、設定格式、啟動串流、抓取 buffer、關閉資源。
class hahaha_capture_webcam_direct_show
{
public:
    // 建構物件並初始化預設狀態。
    hahaha_capture_webcam_direct_show();
    // 解構物件並釋放相關資源。
    ~hahaha_capture_webcam_direct_show();

    // 以既有物件內容建構新的物件實例。
    hahaha_capture_webcam_direct_show(const hahaha_capture_webcam_direct_show& hcwds);
    // 以移動方式建構物件並接手既有資源。
    hahaha_capture_webcam_direct_show(hahaha_capture_webcam_direct_show&& hcwds) noexcept;
    // 複製指派目前物件內容。
    hahaha_capture_webcam_direct_show& operator=(const hahaha_capture_webcam_direct_show& hcwds);
    // 移動指派目前物件內容。
    hahaha_capture_webcam_direct_show& operator=(hahaha_capture_webcam_direct_show&& hcwds) noexcept;

	// 複製來源物件的內部狀態。
	void Copy(const hahaha_capture_webcam_direct_show& hcwds);
    // 接手來源物件的內部資源。
    void Move(hahaha_capture_webcam_direct_show&& hcwds) noexcept;

public:
    // 重設內部狀態。
    int Reset();

	// 開啟指定資源或建立連線。
	int Open(int camera_index = 0, int width = 1920, int height = 1080, int fps = 30, GUID sub_type = MEDIASUBTYPE_YUY2);

	// 開始執行目前功能流程。
	int Start();
    // 停止目前功能流程。
    void Stop();
	// 擷取目前資料並輸出到目標物件。
	int Grab(hahahalib::bitmap_rgb& bitmap);
    // 擷取目前資料並輸出到目標物件。
    int Grab(hahahalib::bitmap_argb& bitmap);
    // 關閉並釋放目前持有的資源。
    void Close();
//    1. List_Format() 顯示的 FPS 是「能力」不是「實際運作 FPS」
//    2. YUY2 1080p 在 USB 2.0 上理論上跑不動，但驅動會做壓縮或降色深
//    3. 某些攝影機的 MinFrameInterval 填錯（非常常見）
//    4. DirectShow 會自動調整 FPS 以保持流暢度
//    5. 你看到的「實際畫面很快」才是真正的 FPS
	int List_Format(std::vector<std::wstring>& list);
    // 列出目前可用的項目資訊。
    int List_Format(std::vector<hahahalib::hahaha_capture_webcam_direct_show_item>& list);
	// 圓剛那隻只有MJPG
	//MEDIASUBTYPE_MJPG
	////MEDIASUBTYPE_RGB24
	int Set_Format(int width = 1920, int height = 1080, int fps = 30, GUID sub_type = MEDIASUBTYPE_YUY2);


public:
    // DirectShow graph 主要元件。
    halib_def::com_ptr<IGraphBuilder> Graph_;
    halib_def::com_ptr<ICaptureGraphBuilder2> Builder_;
    halib_def::com_ptr<IMediaControl> Media_Control_;
    halib_def::com_ptr<IBaseFilter> Camera_Filter_;
    halib_def::com_ptr<IBaseFilter> Sample_Grabber_Filter_;
    halib_def::com_ptr<ISampleGrabber> Sample_Grabber_;


    // 目前 graph 協商後的影像緩衝區大小與輸入格式資訊。
    long Buffer_Size_;

    int Width_;
    int Height_;
    int Camera_Index_;
    int Fps_;
    GUID Sub_Type_;

public:
    // 上下翻轉
    bool Flip_;
    bool Is_Open_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif