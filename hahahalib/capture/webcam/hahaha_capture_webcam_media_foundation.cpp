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
#include <iostream>
#include <algorithm>


//Close();
//Shut_Down();
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
    // shallow copy only for non-COM members
    Is_Initial_ = hcwmf.Is_Initial_;
    Is_Open_ = hcwmf.Is_Open_; // do not copy open handles
    Width_ = hcwmf.Width_;
    Height_ = hcwmf.Height_;
    Channels_ = hcwmf.Channels_;
}
//---------------------------------------------------------------------------
void hahaha_capture_webcam_media_foundation::Move(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept
{
    Source_Reader_ = std::move(hcwmf.Source_Reader_);
    Media_Source_ = std::move(hcwmf.Media_Source_);
    Is_Initial_ = hcwmf.Is_Initial_;
    Is_Open_ = hcwmf.Is_Open_; // do not copy open handles
    Width_ = hcwmf.Width_;
    Height_ = hcwmf.Height_;
    Channels_ = hcwmf.Channels_;

    hcwmf.Source_Reader_ = nullptr;
    hcwmf.Media_Source_ = nullptr;

}
//---------------------------------------------------------------------------
int hahaha_capture_webcam_media_foundation::Reset()
{
//    Close();
//    Shut_Down();
    Source_Reader_.reset();
    Media_Source_.reset();
    Is_Open_ = false;
    Width_ = 0;
    Height_ = 0;
    Channels_ = 0;
    Is_Initial_ = false;
    Is_Open_ = false;

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
        std::cerr << "MFStartup failed: 0x" << std::hex << hr << "\n";
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

void hahaha_capture_webcam_media_foundation::Release()
{
    Source_Reader_.reset();
    Media_Source_.reset();
    Is_Open_ = false;
}
//---------------------------------------------------------------------------

void hahaha_capture_webcam_media_foundation::Set_Resolution(int width, int height)
{
    Desired_Width_ = width;
    Desired_Height_ = height;
}
//---------------------------------------------------------------------------

bool hahaha_capture_webcam_media_foundation::Open(UINT index)
{
    if (!Is_Initial_)
    {
        if (!Initial())
        {
            return false;
        }
    }

    Release();

    IMFAttributes* p_attributes_ = nullptr;
    HRESULT hr = MFCreateAttributes(&p_attributes_, 1);
    if (FAILED(hr) || !p_attributes_)
    {
        return false;
    }

    hr = p_attributes_->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
    if (FAILED(hr))
    {
    	p_attributes_->Release();
        return false;
    }

    IMFActivate** pp_devices_ = nullptr;
    UINT32 count = 0;
    hr = MFEnumDeviceSources(p_attributes_, &pp_devices_, &count);
    p_attributes_->Release();
    if (FAILED(hr) || count == 0)
    {
        if (pp_devices_)
        {
            CoTaskMemFree(pp_devices_);
        }

//        std::cerr << "No video capture devices found or MFEnumDeviceSources failed: 0x" << std::hex << hr << "\n";
        return false;
    }

    if (index >= count)
    {
        for (UINT32 i = 0; i < count; ++i)
        {
            pp_devices_[i]->Release();
        }
        CoTaskMemFree(pp_devices_);
//        std::cerr << "Requested deviceIndex >= device count\n";
        return false;
    }

    IMFMediaSource* p_source_ = nullptr;
    hr = pp_devices_[index]->ActivateObject(IID_PPV_ARGS(&p_source_));
    for (UINT32 i = 0; i < count; ++i)
    {
        pp_devices_[i]->Release();
    }
    CoTaskMemFree(p_source_);
    if (FAILED(hr) || !p_source_)
    {
//        std::cerr << "ActivateObject failed: 0x" << std::hex << hr << "\n";
        return false;
    }

    IMFSourceReader* p_reader_ = nullptr;
    IMFAttributes* p_reader_attrs_ = nullptr;
    hr = MFCreateAttributes(&p_reader_attrs_, 1);
    if (FAILED(hr))
    {
    	p_source_->Release();
        return false;
    }

    hr = MFCreateSourceReaderFromMediaSource(p_source_, p_reader_attrs_, &p_reader_);
    p_reader_attrs_->Release();
    if (FAILED(hr) || !p_reader_)
    {
        p_source_->Release();
//        std::cerr << "MFCreateSourceReaderFromMediaSource failed: 0x" << std::hex << hr << "\n";
        return false;
    }

    // request RGB32 output
    IMFMediaType* p_type_ = nullptr;
    hr = MFCreateMediaType(&p_type_);
    if (FAILED(hr))
    {
    	p_reader_->Release();
        p_source_->Release();
        return false;
    }
    hr = p_type_->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Video);
    hr = p_type_->SetGUID(MF_MT_SUBTYPE, MFVideoFormat_RGB32);
    if (Desired_Width_ > 0 && Desired_Height_ > 0) {
        hr = MFSetAttributeSize(p_type_, MF_MT_FRAME_SIZE, (UINT32)Desired_Width_, (UINT32)Desired_Height_);
        // ignore failure; reader may negotiate a different size
    }
    hr = p_reader_->SetCurrentMediaType((DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM, NULL, p_type_);
    p_type_->Release();
    if (FAILED(hr))
    {
    	p_reader_->Release();
        p_source_->Release();
//        std::cerr << "SetCurrentMediaType failed: 0x" << std::hex << hr << "\n";
        return false;
    }

    IMFMediaType* p_out_type_ = nullptr;
    hr = p_reader_->GetCurrentMediaType((DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM, &p_out_type_);
    if (FAILED(hr) || !p_out_type_)
    {
    	p_reader_->Release();
        p_source_->Release();
        return false;
    }

    UINT32 width_ = 0, height_ = 0;
    hr = MFGetAttributeSize(p_out_type_, MF_MT_FRAME_SIZE, &width_, &height_);
    p_out_type_->Release();
    if (FAILED(hr))
    {
    	p_reader_->Release();
        p_source_->Release();
        return false;
    }

    Width_ = static_cast<int>(width_);
    Height_ = static_cast<int>(height_);
    Channels_ = 4;

    Source_Reader_.reset(p_reader_);
    Media_Source_.reset(p_source_);
    Is_Open_ = true;

    return true;
}
//---------------------------------------------------------------------------

std::vector<std::wstring> hahaha_capture_webcam_media_foundation::List_Devices()
{
    std::vector<std::wstring> result;
    IMFAttributes* pAttributes = nullptr;
    HRESULT hr = MFCreateAttributes(&pAttributes, 1);
    if (FAILED(hr) || !pAttributes) return result;

    hr = pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
    if (FAILED(hr)) { pAttributes->Release(); return result; }

    IMFActivate** ppDevices = nullptr;
    UINT32 count = 0;
    hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
    pAttributes->Release();
    if (FAILED(hr) || count == 0) {
        if (ppDevices) CoTaskMemFree(ppDevices);
        return result;
    }

    for (UINT32 i = 0; i < count; ++i) {
        WCHAR* szName = nullptr;
        UINT32 cchName = 0;
        hr = ppDevices[i]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME, &szName, &cchName);
        if (SUCCEEDED(hr) && szName) {
            result.emplace_back(szName);
            CoTaskMemFree(szName);
        }
        ppDevices[i]->Release();
    }
    CoTaskMemFree(ppDevices);
    return result;
}
//---------------------------------------------------------------------------

void hahaha_capture_webcam_media_foundation::Close()
{
    Release();
}
//---------------------------------------------------------------------------

bool hahaha_capture_webcam_media_foundation::Get_Frame(unsigned char* data, int& width, int& height, int& channels)
{
    if (!Is_Open_ || !Source_Reader_)
    {
        return false;
    }

    DWORD dw_stream_index_ = 0, dw_flags_ = 0;
    LONGLONG ll_time_stamp_ = 0;
    IMFSample* p_sample_ = nullptr;

    HRESULT hr = Source_Reader_->ReadSample((DWORD)MF_SOURCE_READER_FIRST_VIDEO_STREAM, 0, &dw_stream_index_, &dw_flags_, &ll_time_stamp_, &p_sample_);
    if (FAILED(hr)) {
//        std::cerr << "ReadSample failed: 0x" << std::hex << hr << "\n";
        return false;
    }

    if (!p_sample_)
    {
        return false;
    }

    IMFMediaBuffer* p_buffer_ = nullptr;
    hr = p_sample_->ConvertToContiguousBuffer(&p_buffer_);
    if (FAILED(hr) || !p_buffer_)
    {
    	p_sample_->Release();
        return false;
    }

    BYTE* p_data_ = nullptr;
    DWORD max_len_ = 0, cur_len_ = 0;
    hr = p_buffer_->Lock(&p_data_, &max_len_, &cur_len_);
    if (SUCCEEDED(hr) && p_data_)
    {
        size_t need = static_cast<size_t>(Width_) * static_cast<size_t>(Height_) * 4;
        size_t copyLen = std::min<size_t>(cur_len_, need);
        memcpy(data, p_data_, copyLen);
        p_buffer_->Unlock();
        width = Width_;
        height = Height_;
        channels = Channels_;
        p_buffer_->Release();
        p_sample_->Release();
        return true;
    }

    if (p_buffer_)
    {
        p_buffer_->Release();
    }
    if (p_sample_)
    {
        p_sample_->Release();
    }
    return false;
}
//---------------------------------------------------------------------------

bool hahaha_capture_webcam_media_foundation::Is_Open() const
{
    return Is_Open_ && Source_Reader_ != nullptr;
}

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
