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

class hahaha_capture_webcam_direct_show
{
public:
    hahaha_capture_webcam_direct_show();
    ~hahaha_capture_webcam_direct_show();

    hahaha_capture_webcam_direct_show(const hahaha_capture_webcam_direct_show& hcwds);
    hahaha_capture_webcam_direct_show(hahaha_capture_webcam_direct_show&& hcwds) noexcept;
    hahaha_capture_webcam_direct_show& operator=(const hahaha_capture_webcam_direct_show& hcwds);
    hahaha_capture_webcam_direct_show& operator=(hahaha_capture_webcam_direct_show&& hcwds) noexcept;

	void Copy(const hahaha_capture_webcam_direct_show& hcwds);
    void Move(hahaha_capture_webcam_direct_show&& hcwds) noexcept;

public:
    int Reset();

	int Open(int camera_index = 0, int width = 1920, int height = 1080, GUID sub_type = MEDIASUBTYPE_YUY2);

	int Start();
    void Stop();
	int Grab(hahahalib::bitmap_rgb& bitmap);
    void Close();
	int List_Format(std::vector<std::wstring>& list);
	// 圓剛那隻只有MJPG
	//MEDIASUBTYPE_MJPG
	////MEDIASUBTYPE_RGB24
	int Set_Format(int width = 1920, int height = 1080, GUID sub_type = MEDIASUBTYPE_YUY2);


public:
    halib_def::com_ptr<IGraphBuilder> Graph_;
    halib_def::com_ptr<ICaptureGraphBuilder2> Builder_;
    halib_def::com_ptr<IMediaControl> Media_Control_;
    halib_def::com_ptr<IBaseFilter> Camera_Filter_;
    halib_def::com_ptr<IBaseFilter> Sample_Grabber_Filter_;
    halib_def::com_ptr<ISampleGrabber> Sample_Grabber_;


    long Buffer_Size_;

    int Width_;
    int Height_;
    int Camera_Index_;
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
