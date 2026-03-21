//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <image_process\wrap_affine\hahaha_image_process_wrap_affine_rotate.h>
#include <image_process\copy\hahaha_image_process_copy.h>
#include <capture\webcam\direct_show\hahaha_capture_webcam_direct_show_item.h>
//---------------------------------------------------------------------------
#include "hahaha_capture_webcam_direct_show_origin.h"
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
// 直接取yuy2，用執行緒跑
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin::hahaha_capture_webcam_direct_show_origin()
{
    Reset();
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin::~hahaha_capture_webcam_direct_show_origin()
{

}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin::hahaha_capture_webcam_direct_show_origin(const hahaha_capture_webcam_direct_show_origin& hcwdso)
{
    Reset();
    Copy(hcwdso);
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin::hahaha_capture_webcam_direct_show_origin(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept
{
    Move(std::move(hcwdso));
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin& hahaha_capture_webcam_direct_show_origin::operator=(const hahaha_capture_webcam_direct_show_origin& hcwdso)
{
    Copy(hcwdso);
    return *this;
}
//---------------------------------------------------------------------------
hahaha_capture_webcam_direct_show_origin& hahaha_capture_webcam_direct_show_origin::operator=(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept
{
    if (this != &hcwdso)
    {
        Move(std::move(hcwdso));
    }

    return *this;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin::Copy(const hahaha_capture_webcam_direct_show_origin& hcwdso)
{
    // 不複製 DirectShow 狀態
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin::Move(hahaha_capture_webcam_direct_show_origin&& hcwdso) noexcept
{
    Graph_ = std::move(hcwdso.Graph_);
    Builder_ = std::move(hcwdso.Builder_);
    Media_Control_ = std::move(hcwdso.Media_Control_);
    Camera_Filter_ = std::move(hcwdso.Camera_Filter_);
    Sample_Grabber_Filter_ = std::move(hcwdso.Sample_Grabber_Filter_);
    Sample_Grabber_ = std::move(hcwdso.Sample_Grabber_);

    Buffer_Size_ = hcwdso.Buffer_Size_;

    Width_ = hcwdso.Width_;
    Height_ = hcwdso.Height_;
    Camera_Index_ = hcwdso.Camera_Index_;

    Flip_ = hcwdso.Flip_;
    Is_Open_ = hcwdso.Is_Open_;
    Sub_Type_ = hcwdso.Sub_Type_;

    hcwdso.Buffer_Size_ = 0;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_origin::Reset()
{
    Graph_.reset();
    Builder_.reset();
    Media_Control_.reset();
    Camera_Filter_.reset();
    Sample_Grabber_Filter_.reset();
    Sample_Grabber_.reset();

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
int hahaha_capture_webcam_direct_show_origin::Open(int camera_index, int width, int height)
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
    if (!Set_Format(width, height))
    {
        return -1;
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

    // ----------------------
    // ★ 在這裡加入 Callback
    // ----------------------
    Callback_ = std::make_shared<hahaha_capture_webcam_direct_show_origin_callback_grabber>();
    Sample_Grabber_->SetCallback(Callback_.get(), 1); // 1 = BufferCB
    Callback_->On_Frame = [&](double time, BYTE* buffer, long len)
    {
        // buffer = YUY2 frame
        // len = Width_ * Height_ * 2

        this->Callback_Grabber(time, buffer, len);
    };


    // 7) SampleGrabber 設成 MEDIASUBTYPE_YUY2
    AM_MEDIA_TYPE mt_ = {};
    ZeroMemory(&mt_, sizeof(mt_));
    mt_.majortype = MEDIATYPE_Video;
    mt_.subtype = MEDIASUBTYPE_YUY2;
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
    Sub_Type_ = MEDIASUBTYPE_YUY2;

    return hr_;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin::Callback_Grabber(double time, BYTE* buffer, long len)
{

}

//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_origin::Start()
{
	HRESULT hr_ = Media_Control_->Run();
    if (hr_ == S_OK || hr_ == S_FALSE)
    {
        // 等一點點時間讓第一個 frame 進來
        // 或在外面 Sleep(100~200ms) 再呼叫這段
        long size_ = 0;
        if (SUCCEEDED(Sample_Grabber_->GetCurrentBuffer(&size_, NULL)))
        {
            Buffer_Size_ = size_;
        }
    }
    return hr_;
}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_origin::Grab(hahahalib::bitmap_yuy2& bitmap)
{
    if(!Is_Open_)
    {
        return -1;
    }



    if(bitmap.Size_ != Buffer_Size_)
    {
        return -1;
    }



    Sample_Grabber_->GetCurrentBuffer(&Buffer_Size_, (long*)bitmap.Image_Ptr_);

    return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin::Stop()
{
    if (Media_Control_)
    {
        Media_Control_->Stop();
    }


}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_direct_show_origin::Close()
{
    Sample_Grabber_.reset();
    Sample_Grabber_Filter_.reset();
    Camera_Filter_.reset();
    Builder_.reset();
    Graph_.reset();

    Buffer_Size_ = 0;

    Is_Open_ = false;

}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_direct_show_origin::List_Format(std::vector<std::wstring>& list)
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

                if (sub_type_ == MEDIASUBTYPE_YUY2)
                {
                    fmt_ = L"YUY2";
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
int hahaha_capture_webcam_direct_show_origin::List_Format(std::vector<hahahalib::hahaha_capture_webcam_direct_show_item>& list)
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

                double fps_ = (int)(10000000.0 / vih_->AvgTimePerFrame);

                int width_ = vih_->bmiHeader.biWidth;
                int height_ = vih_->bmiHeader.biHeight;
                int bit_ = vih_->bmiHeader.biBitCount;

                GUID sub_type_ = mt_->subtype;



                std::wstring fmt_;

                if (sub_type_ == MEDIASUBTYPE_YUY2)
                {
                    fmt_ = L"YUY2";
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
int hahaha_capture_webcam_direct_show_origin::Set_Format(int width, int height)
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
        // 我的相機不能設反的

        // 如果你真的一定要指定 subtype，可以試著改這裡
        // 但有些驅動不喜歡被改 subtype，會直接失敗
        mt_->subtype = MEDIASUBTYPE_YUY2;

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
    Sub_Type_ = MEDIASUBTYPE_YUY2;

    return SUCCEEDED(hr_);
}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------