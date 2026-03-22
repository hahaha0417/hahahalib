//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
//---------------------------------------------------------------------------
#include "hahaha_capture_webcam_direct_show.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// 手動執行一次
//CoInitializeEx(NULL, COINIT_MULTITHREADED);
//
//CoUninitialize();

//CoInitializeEx(NULL, COINIT_MULTITHREADED);
//
//hahahalib::hahaha_capture_webcam_direct_show capture_webcam_direct_show_;
//capture_webcam_direct_show_.Open(0, 1920, 1080);
////	SetFormat(1920, 1080, GUID subtype)
//{
//    std::vector<std::wstring> list;
//    capture_webcam_direct_show_.List_Format(list);
//    list_box_webcam->Items->BeginUpdate();
//    list_box_webcam->Clear();
//    for(int i = 0; i < list.size(); i++)
//    {
//        list_box_webcam->Items->Add(list[i].c_str());
//    }
//    list_box_webcam->Items->EndUpdate();
//}
//capture_webcam_direct_show_.Start();
//Sleep(5000);
//hahahalib::bitmap_alloc_rgb bitmap_rgb_;
//bitmap_rgb_.Resize(1920, 1080);
//capture_webcam_direct_show_.Flip_ = true;
//capture_webcam_direct_show_.Grab(bitmap_rgb_);
//f_lib::bmp::Save(L"D:\\Desktop\\ttt\\webcam.bmp", bitmap_rgb_);
//capture_webcam_direct_show_.Stop();
//capture_webcam_direct_show_.Close();
//CoUninitialize();
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show::hahaha_capture_webcam_direct_show()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show::~hahaha_capture_webcam_direct_show()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show::hahaha_capture_webcam_direct_show(const hahaha_capture_webcam_direct_show& hcwds)
{
    Reset();
    Copy(hcwds);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show::hahaha_capture_webcam_direct_show(hahaha_capture_webcam_direct_show&& hcwds) noexcept
{
    Move(std::move(hcwds));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show& hahaha_capture_webcam_direct_show::operator=(const hahaha_capture_webcam_direct_show& hcwds)
{
    Copy(hcwds);
    return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show& hahaha_capture_webcam_direct_show::operator=(hahaha_capture_webcam_direct_show&& hcwds) noexcept
{
    if (this != &hcwds)
    {
        Move(std::move(hcwds));
    }

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show::Copy(const hahaha_capture_webcam_direct_show& hcwds)
{
    // 不複製 DirectShow 狀態
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show::Move(hahaha_capture_webcam_direct_show&& hcwds) noexcept
{
    Graph_ = std::move(hcwds.Graph_);
    Builder_ = std::move(hcwds.Builder_);
    Media_Control_ = std::move(hcwds.Media_Control_);
    Camera_Filter_ = std::move(hcwds.Camera_Filter_);
    Sample_Grabber_Filter_ = std::move(hcwds.Sample_Grabber_Filter_);
    Sample_Grabber_ = std::move(hcwds.Sample_Grabber_);

    Buffer_Size_ = hcwds.Buffer_Size_;

    Width_ = hcwds.Width_;
    Height_ = hcwds.Height_;
    Camera_Index_ = hcwds.Camera_Index_;

    Flip_ = hcwds.Flip_;
    Is_Open_ = hcwds.Is_Open_;
    Sub_Type_ = hcwds.Sub_Type_;

    hcwds.Buffer_Size_ = 0;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Reset()
{
    // 1) 停止 Graph（一定要最先做）
//    if (Media_Control_)
//    {
//        Media_Control_->Stop();
//    }
    // 2) 停止 callback（避免 DirectShow 再呼叫它）
    if (Sample_Grabber_)
    {
        Sample_Grabber_->SetCallback(NULL, 1);
    }

//    Callback_.reset();

    // 3) 釋放 MediaControl
    Media_Control_.reset();

    // 4) 釋放 SampleGrabber
    Sample_Grabber_.reset();
    Sample_Grabber_Filter_.reset();

    // 5) 釋放 Camera Filter
    Camera_Filter_.reset();

    // 6) 釋放 Builder
    Builder_.reset();

    // 7) 最後釋放 Graph（必須最後）
    Graph_.reset();

    // 8) 重設狀態
    Buffer_Size_ = 0;
    Width_ = 640;
    Height_ = 480;
    Camera_Index_ = 0;
    Sub_Type_ = MEDIASUBTYPE_None;
    Flip_ = false;
    Is_Open_ = false;

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Open(int camera_index, int width, int height, int fps, GUID sub_type)
{
    if(Is_Open_)
    {
        return -1;
    }

    // 1) 建立 Graph
    IGraphBuilder* g_ = nullptr;
    HRESULT hr_ = CoCreateInstance(CLSID_FilterGraph,
    	NULL,
        CLSCTX_INPROC_SERVER,
        IID_IGraphBuilder,
        (void**)&g_
    );

    if (FAILED(hr_) || !g_)
    {
        return hr_;
    }
    Graph_.reset(g_);

    // 2) 建立 CaptureGraphBuilder2
    ICaptureGraphBuilder2* b_ = nullptr;
    hr_ = CoCreateInstance(CLSID_CaptureGraphBuilder2,
    	NULL,
        CLSCTX_INPROC_SERVER,
        IID_ICaptureGraphBuilder2,
        (void**)&b_
    );

    if (FAILED(hr_) || !b_)
    {
        return hr_;
    }

    Builder_.reset(b_);

    Builder_->SetFiltergraph(Graph_.get());

    // 3) 取得攝影機 Filter
    ICreateDevEnum* dev_enum_ = nullptr;
    IEnumMoniker* enum_moniker_ = nullptr;

    hr_ = CoCreateInstance(CLSID_SystemDeviceEnum,
    	NULL,
        CLSCTX_INPROC_SERVER,
        IID_ICreateDevEnum,
        (void**)&dev_enum_
    );

    if (FAILED(hr_) || !dev_enum_)
    {
        return hr_;
    }

    hr_ = dev_enum_->CreateClassEnumerator(CLSID_VideoInputDeviceCategory,
    	&enum_moniker_,
        0
    );

    if (FAILED(hr_) || !enum_moniker_)
    {
        return hr_;
    }

    ULONG fetched_;
    IMoniker* moniker_ = nullptr;
    int index_ = 0;

    while (enum_moniker_->Next(1,
    	&moniker_,
        &fetched_
    ) == S_OK)
    {
        if (index_ == Camera_Index_)
        {
            IBaseFilter* camera_filter_ = nullptr;
            moniker_->BindToObject(0,
            	0,
                IID_IBaseFilter,
                (void**)&camera_filter_
            );

            Camera_Filter_.reset(camera_filter_);
            moniker_->Release();
            break;
        }
        index_++;
        moniker_->Release();
    }

    if (!Camera_Filter_)
    {
        return -1;
    }

    Graph_->AddFilter(Camera_Filter_.get(), L"Video Capture");

    // 4) 設定攝影機格式（必須在加入 SampleGrabber 之前）
    if (!Set_Format(width, height, fps, sub_type))
    {
        // 若失敗，可考慮 fallback MJPEG
        // Set_Format(width_, height_, MEDIASUBTYPE_MJPG);
    }

    // 5) 建立 SampleGrabber Filter
    IBaseFilter* samble_grabber_filter_ = nullptr;
    hr_ = CoCreateInstance(CLSID_SampleGrabber,
    	NULL,
        CLSCTX_INPROC_SERVER,
        IID_IBaseFilter,
        (void**)&samble_grabber_filter_
    );

    if (FAILED(hr_) || !samble_grabber_filter_)
    {
        return hr_;
    }

    Sample_Grabber_Filter_.reset(samble_grabber_filter_);

    Graph_->AddFilter(Sample_Grabber_Filter_.get(),
    	L"Sample Grabber"
    );

    // 6) 取得 ISampleGrabber
    ISampleGrabber* samble_grabber_ = nullptr;
    Sample_Grabber_Filter_->QueryInterface(IID_ISampleGrabber,
    	(void**)&samble_grabber_
    );

    Sample_Grabber_.reset(samble_grabber_);

    // 7) SampleGrabber 設成 MEDIASUBTYPE_RGB24
    AM_MEDIA_TYPE mt_ = {};
    ZeroMemory(&mt_, sizeof(mt_));
    mt_.majortype = MEDIATYPE_Video;
    mt_.subtype = MEDIASUBTYPE_RGB24;
    Sample_Grabber_->SetMediaType(&mt_);

    // 8) RenderStream（建立整個 Graph）
    hr_ = Builder_->RenderStream(&PIN_CATEGORY_CAPTURE,
    	&MEDIATYPE_Video,
        Camera_Filter_.get(),
        Sample_Grabber_Filter_.get(),
        NULL
    );

    if (FAILED(hr_))
    {
        return hr_;
    }

    // 9) 關閉 ActiveMovie 視窗
    IVideoWindow* vw_ = nullptr;
    Graph_->QueryInterface(IID_IVideoWindow, (void**)&vw_);
    if (vw_)
    {
        vw_->put_Visible(OAFALSE);
        vw_->put_AutoShow(OAFALSE);
        vw_->put_Owner(NULL);
        vw_->Release();
    }

    // 10) 啟用 SampleGrabber buffer 模式
    Sample_Grabber_->SetBufferSamples(TRUE);

    // 11) 取得 MediaControl
    IMediaControl* mc_ = nullptr;
    Graph_->QueryInterface(IID_IMediaControl, (void**)&mc_);
    Media_Control_.reset(mc_);

    Is_Open_ = true;

    Camera_Index_ = camera_index;
    Width_ = width;
    Height_ = height;
    Fps_ = fps;
    Sub_Type_ = sub_type;

    return hr_;
}

//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Start()
{
	HRESULT hr_ = Media_Control_->Run();
    if (FAILED(hr_))
    {
        return hr_;
    }

    // 等待第一個 frame
    long size_ = 0;
    const int max_wait_ms_ = 200;
    int waited_ = 0;

    while (waited_ < max_wait_ms_)
    {
        if (SUCCEEDED(Sample_Grabber_->GetCurrentBuffer(&size_, NULL)) && size_ > 0)
        {
            Buffer_Size_ = size_;
            return S_OK;
        }

        Sleep(10);
        waited_ += 10;
    }

    // 超時
    return E_FAIL;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Grab(hahahalib::bitmap_rgb& bitmap)
{
    if(!Is_Open_)
    {
        return -1;
    }

    if(bitmap.Size_ != Buffer_Size_)
    {
        return -1;
    }



    if(Flip_)
    {
    	hahahalib::bitmap_alloc_rgb bitmap_temp_;
        bitmap_temp_.Resize(bitmap.Width_, bitmap.Height_);
        Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, (long*)bitmap_temp_.Image_Ptr_);

        halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
            bitmap_temp_,
			halib::roi(0, 0, bitmap_temp_.Width_ - 1, bitmap_temp_.Height_ - 1),
            bitmap,
            halib::roi(0, 0, bitmap.Width_ - 1, bitmap.Height_ - 1)
        );
    }
    else
    {
        Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, (long*)bitmap.Image_Ptr_);
    }

    return 0;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Grab(hahahalib::bitmap_argb& bitmap)
{
    if(!Is_Open_)
    {
        return -1;
    }

    HRESULT hr_ = Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, NULL);

    if(bitmap.Size_ != Buffer_Size_ / 3 * 4)
    {
        return -1;
    }



    if(Flip_)
    {
    	hahahalib::bitmap_alloc_rgb bitmap_temp_;
        bitmap_temp_.Resize(bitmap.Width_, bitmap.Height_);
        HRESULT hr_ = Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, (long*)bitmap_temp_.Image_Ptr_);

        hahahalib::bitmap_alloc_rgb bitmap_temp2_;
        bitmap_temp2_.Resize(bitmap.Width_, bitmap.Height_);

        halib_image::warp_affine_rotate::Rotate_Nearest_Vertical_Flip(
            bitmap_temp_,
			halib::roi(0, 0, bitmap_temp_.Width_ - 1, bitmap_temp_.Height_ - 1),
            bitmap_temp2_,
            halib::roi(0, 0, bitmap_temp2_.Width_ - 1, bitmap_temp2_.Height_ - 1)
        );

        halib_image::copy::Copy(
            bitmap_temp2_,
			halib::roi(0, 0, bitmap_temp2_.Width_ - 1, bitmap_temp2_.Height_ - 1),
            bitmap,
            halib::roi(0, 0, bitmap.Width_ - 1, bitmap.Height_ - 1)
        );
    }
    else
    {
        hahahalib::bitmap_alloc_rgb bitmap_temp_;
        bitmap_temp_.Resize(bitmap.Width_, bitmap.Height_);
        HRESULT hr_ = Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, (long*)bitmap_temp_.Image_Ptr_);

        halib_image::copy::Copy(
            bitmap_temp_,
			halib::roi(0, 0, bitmap_temp_.Width_ - 1, bitmap_temp_.Height_ - 1),
            bitmap,
            halib::roi(0, 0, bitmap.Width_ - 1, bitmap.Height_ - 1)
        );
    }

    return 0;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show::Stop()
{
    if (Media_Control_)
    {
        Media_Control_->Stop();
    }


}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show::Close()
{
    // 1) 停止 Graph（一定要最先做）
//    if (Media_Control_)
//    {
//        Media_Control_->Stop();
//    }
    // 2) 停止 callback（避免 DirectShow 再呼叫它）
    if (Sample_Grabber_)
    {
        Sample_Grabber_->SetCallback(NULL, 1);
    }

//    Callback_.reset();

    // 3) 釋放 MediaControl
    Media_Control_.reset();

    // 4) 釋放 SampleGrabber
    Sample_Grabber_.reset();
    Sample_Grabber_Filter_.reset();

    // 5) 釋放 Camera Filter
    Camera_Filter_.reset();

    // 6) 釋放 Builder
    Builder_.reset();

    // 7) 最後釋放 Graph（必須最後）
    Graph_.reset();

    // 8) 重設狀態
    Buffer_Size_ = 0;
    Width_ = 640;
    Height_ = 480;
    Camera_Index_ = 0;
    Sub_Type_ = MEDIASUBTYPE_None;
    Flip_ = false;
    Is_Open_ = false;

}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::List_Format(std::vector<std::wstring>& list)
{
	if (!Camera_Filter_)
    {
        return -1;
    }


    IAMStreamConfig* config_ = nullptr;

    HRESULT hr_ = Builder_->FindInterface(
        &PIN_CATEGORY_CAPTURE,
        &MEDIATYPE_Video,
        Camera_Filter_.get(),
        IID_IAMStreamConfig,
        (void**)&config_
    );

    if (FAILED(hr_) || !config_)
    {
        return hr_;
    }

    int count_ = 0, size_ = 0;
    config_->GetNumberOfCapabilities(&count_, &size_);

    BYTE* caps_ = new BYTE[size_];

    for (int i = 0; i < count_; i++)
    {
        AM_MEDIA_TYPE* mt_ = nullptr;

        if (SUCCEEDED(config_->GetStreamCaps(i, &mt_, caps_)))
        {
            if (mt_->formattype == FORMAT_VideoInfo)
            {
                VIDEOINFOHEADER* vih_ = (VIDEOINFOHEADER*)mt_->pbFormat;

                int width_ = vih_->bmiHeader.biWidth;
                int height_ = vih_->bmiHeader.biHeight;
                int bit_ = vih_->bmiHeader.biBitCount;

                GUID sub_type_ = mt_->subtype;

                std::wstring fmt_;

                if (sub_type_ == MEDIASUBTYPE_RGB24)
                {
                    fmt_ = L"RGB24";
                }
                else if (sub_type_ == MEDIASUBTYPE_YUY2)
                {
                    fmt_ = L"YUY2";
                }
                else if (sub_type_ == MEDIASUBTYPE_MJPG)
                {
                    fmt_ = L"MJPEG";
                }
                else if (sub_type_ == MEDIASUBTYPE_NV12)
                {
                    fmt_ = L"NV12";
                }
                else
                {
                    fmt_ = L"OTHER";
                }

                wchar_t buf_[128];
                swprintf(buf_, 128, L"%dx%d %s %d-bit", width_, height_, fmt_.c_str(), bit_);

                list.push_back(buf_);
            }

            // 釋放 MediaType
            if (mt_->cbFormat != 0)
            {
                CoTaskMemFree((PVOID)mt_->pbFormat);
                mt_->cbFormat = 0;
                mt_->pbFormat = NULL;
            }
            if (mt_->pUnk != NULL)
            {
                mt_->pUnk->Release();
                mt_->pUnk = NULL;
            }
            CoTaskMemFree(mt_);
        }
    }

    delete[] caps_;
    config_->Release();

    return hr_;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::List_Format(std::vector<hahahalib::hahaha_capture_webcam_direct_show_item>& list)
{
    if (!Camera_Filter_)
    {
        return -1;
    }


    IAMStreamConfig* config_ = nullptr;

    HRESULT hr_ = Builder_->FindInterface(
        &PIN_CATEGORY_CAPTURE,
        &MEDIATYPE_Video,
        Camera_Filter_.get(),
        IID_IAMStreamConfig,
        (void**)&config_
    );

    if (FAILED(hr_) || !config_)
    {
        return hr_;
    }

    int count_ = 0, size_ = 0;
    config_->GetNumberOfCapabilities(&count_, &size_);


    BYTE* caps_ = new BYTE[size_];

    for (int i = 0; i < count_; i++)
    {
        AM_MEDIA_TYPE* mt_ = nullptr;

        if (SUCCEEDED(config_->GetStreamCaps(i, &mt_, caps_)))
        {
            if (mt_->formattype == FORMAT_VideoInfo)
            {
                VIDEOINFOHEADER* vih_ = (VIDEOINFOHEADER*)mt_->pbFormat;

                VIDEO_STREAM_CONFIG_CAPS* c_ = (VIDEO_STREAM_CONFIG_CAPS*)caps_;

                double fps_ = 0.0;
                if (c_->MinFrameInterval > 0)
                {
                    fps_ = 10000000.0 / (double)c_->MinFrameInterval;
                }

                int width_ = vih_->bmiHeader.biWidth;
                int height_ = vih_->bmiHeader.biHeight;
                int bit_ = vih_->bmiHeader.biBitCount;

                GUID sub_type_ = mt_->subtype;



                std::wstring fmt_;

                if (sub_type_ == MEDIASUBTYPE_RGB24)
                {
                    fmt_ = L"RGB24";
                }
                else if (sub_type_ == MEDIASUBTYPE_YUY2)
                {
                    fmt_ = L"YUY2";
                }
                else if (sub_type_ == MEDIASUBTYPE_MJPG)
                {
                    fmt_ = L"MJPEG";
                }
                else if (sub_type_ == MEDIASUBTYPE_NV12)
                {
                    fmt_ = L"NV12";
                }
                else
                {
                    fmt_ = L"OTHER";
                }

                wchar_t description_[128];
                swprintf(description_, 128, L"%dx%d %s %d-bit", width_, height_, fmt_.c_str(), bit_);

                hahahalib::hahaha_capture_webcam_direct_show_item item_;
                item_.Fps_ = fps_;
                item_.Width_ = width_;
                item_.Height_ = height_;
                item_.Sub_Type_ = sub_type_;
                item_.Format_ = fmt_;
                item_.Description_ = description_;

                list.emplace_back(
                    item_
                );

            }

            // 釋放 MediaType
            if (mt_->cbFormat != 0)
            {
                CoTaskMemFree((PVOID)mt_->pbFormat);
                mt_->cbFormat = 0;
                mt_->pbFormat = NULL;
            }
            if (mt_->pUnk != NULL)
            {
                mt_->pUnk->Release();
                mt_->pUnk = NULL;
            }
            CoTaskMemFree(mt_);
        }
    }

    delete[] caps_;
    config_->Release();

    return hr_;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show::Set_Format(int width, int height, int fps, GUID sub_type)
{
    if (!Camera_Filter_ || !Builder_)
    {
        return -1;
    }

    IAMStreamConfig* config_ = nullptr;

    HRESULT hr_ = Builder_->FindInterface(
        &PIN_CATEGORY_CAPTURE,
        &MEDIATYPE_Video,
        Camera_Filter_.get(),
        IID_IAMStreamConfig,
        (void**)&config_
    );
    if (FAILED(hr_) || !config_)
    {
        return hr_;
    }

    AM_MEDIA_TYPE* mt_ = nullptr;
    hr_ = config_->GetFormat(&mt_);
    if (FAILED(hr_) || !mt_)
    {
        config_->Release();
        return hr_;
    }

    if (mt_->formattype == FORMAT_VideoInfo)
    {
        VIDEOINFOHEADER* vih_ = (VIDEOINFOHEADER*)mt_->pbFormat;

        // 改解析度
        vih_->bmiHeader.biWidth  = width;
        vih_->bmiHeader.biHeight = height;   // 如果畫面倒立，再改成 -h 試試
        vih_->AvgTimePerFrame = (int)(10000000.0 / fps);
        // 我的相機不能設反的

        // 如果你真的一定要指定 subtype，可以試著改這裡
        // 但有些驅動不喜歡被改 subtype，會直接失敗
        if (IsEqualGUID(sub_type, MEDIASUBTYPE_YUY2) ||
            IsEqualGUID(sub_type, MEDIASUBTYPE_MJPG))
        {
            mt_->subtype = sub_type;
        }
    }

    hr_ = config_->SetFormat(mt_);

    // 釋放 MediaType
    if (mt_->cbFormat)
    {
        CoTaskMemFree(mt_->pbFormat);
        mt_->pbFormat = NULL;
    }
    if (mt_->pUnk)
    {
        mt_->pUnk->Release();
        mt_->pUnk = NULL;
    }
    CoTaskMemFree(mt_);
    config_->Release();

    Width_ = width;
    Height_ = height;
    Fps_ = fps;
    Sub_Type_ = sub_type;

    return SUCCEEDED(hr_);
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------