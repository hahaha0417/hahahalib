//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_direct_show_originH
#define hahaha_capture_webcam_direct_show_originH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include <memory>
#include <functional>

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

class hahaha_capture_webcam_direct_show_origin
{
    class hahaha_capture_webcam_direct_show_origin_callback_grabber : public ISampleGrabberCB
    {
    public:
        std::function<void(double, BYTE*, long)> On_Frame;

        STDMETHODIMP BufferCB(double time, BYTE* buffer, long len)
        {
            if (On_Frame)
            {
                On_Frame(time, buffer, len);
            }
            return S_OK;
        }

        STDMETHODIMP SampleCB(double, IMediaSample*) { return E_NOTIMPL; }
        STDMETHODIMP QueryInterface(REFIID, void**) { return E_NOINTERFACE; }
        STDMETHODIMP_(ULONG) AddRef() { return 1; }
        STDMETHODIMP_(ULONG) Release() { return 2; }
    };
public:
    hahaha_capture_webcam_direct_show_origin();
    ~hahaha_capture_webcam_direct_show_origin();

    hahaha_capture_webcam_direct_show_origin(const hahaha_capture_webcam_direct_show_origin& hcwdso);
    hahaha_capture_webcam_direct_show_origin(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept;
    hahaha_capture_webcam_direct_show_origin& operator=(const hahaha_capture_webcam_direct_show_origin& hcwdso);
    hahaha_capture_webcam_direct_show_origin& operator=(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept;

	void Copy(const hahaha_capture_webcam_direct_show_origin& hcwdso);
    void Move(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept;

public:
    int Reset();

	int Open(int camera_index = 0, int width = 1920, int height = 1080, int fps = 30);

	int Start();
    void Stop();
	int Grab(hahahalib::bitmap_yuy2& bitmap);
    void Close();
//    1. List_Format() 顯示的 FPS 是「能力」不是「實際運作 FPS」
//    2. YUY2 1080p 在 USB 2.0 上理論上跑不動，但驅動會做壓縮或降色深
//    3. 某些攝影機的 MinFrameInterval 填錯（非常常見）
//    4. DirectShow 會自動調整 FPS 以保持流暢度
//    5. 你看到的「實際畫面很快」才是真正的 FPS
	int List_Format(std::vector<std::wstring>& list);
    int List_Format(std::vector<hahahalib::hahaha_capture_webcam_direct_show_item>& list);
	// 圓剛那隻只有MJPG
	//MEDIASUBTYPE_MJPG
	////MEDIASUBTYPE_RGB24
	int Set_Format(int width = 1920, int height = 1080, int fps = 30);

    virtual void Callback_Grabber(double time, BYTE* buffer, long len);
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
    int Fps_;
    GUID Sub_Type_;

public:
    // 上下翻轉
    bool Flip_;
    bool Is_Open_;

//    DirectShow 的 ISampleGrabber::SetCallback() 不會 AddRef，也就是說：
//
//    它只存「裸指標」
//
//    不會幫你管理生命週期
//
//    如果你的物件被移動、複製、釋放 → DirectShow 會拿到壞掉的指標 → Crash
//
//    而你的類別：
//
//    有 Copy constructor
//
//    有 Move constructor
//
//    有 Copy assignment
//
//    有 Move assignment
//
//    這代表：
//
//    👉 Callback 不能用 unique_ptr（會被 move 破壞）
//    👉 Callback 必須用 shared_ptr（生命週期穩定）
    std::shared_ptr<hahaha_capture_webcam_direct_show_origin_callback_grabber> Callback_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
