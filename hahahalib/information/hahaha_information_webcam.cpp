//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
#include <information\webcam\hahaha_information_webcam_item.h>

#include <mfapi.h>
#include <mfidl.h>
#include <mfobjects.h>
#include <mfreadwrite.h>
#include <shlwapi.h>
#include <string>
#include <vector>


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include "hahaha_information_webcam.h"
#if defined(__WIN32)
    #pragma comment(lib, "mfplat.lib")
    #pragma comment(lib, "mf.lib")
    #pragma comment(lib, "mfreadwrite.lib")
    #pragma comment(lib, "mfuuid.lib")
#elif defined(__WIN64)
    #pragma comment(lib, "mfplat.a")
    #pragma comment(lib, "mf.a")
    #pragma comment(lib, "mfreadwrite.a")
    #pragma comment(lib, "mfuuid.a")
#elif defined(__WIN64_MODERN)
    #pragma comment(lib, "mfplat.lib")
    #pragma comment(lib, "mf.lib")
    #pragma comment(lib, "mfreadwrite.lib")
    #pragma comment(lib, "mfuuid.lib")
#endif

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_webcam::hahaha_information_webcam()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_webcam::~hahaha_information_webcam()
{

}
//---------------------------------------------------------------------------
hahaha_information_webcam::hahaha_information_webcam(const hahaha_information_webcam& hiw)
{
    Reset();
	Copy(hiw);
}
//---------------------------------------------------------------------------
hahaha_information_webcam::hahaha_information_webcam(hahaha_information_webcam&& hiw) noexcept
{
    Move(std::move(hiw));
}
//---------------------------------------------------------------------------
hahaha_information_webcam& hahaha_information_webcam::operator=(const hahaha_information_webcam& hiw)
{
	Copy(hiw);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_webcam& hahaha_information_webcam::operator=(hahaha_information_webcam&& hiw) noexcept
{
	if (this != &hiw)
    {
        Move(std::move(hiw));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_webcam::Copy(const hahaha_information_webcam& hiw)
{
    hahahalib::Vector_Copy(hiw.Webcams_, Webcams_);
}
//---------------------------------------------------------------------------
void hahaha_information_webcam::Move(hahaha_information_webcam&& hiw) noexcept
{
    Webcams_ = std::move(hiw.Webcams_);

    hiw.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_webcam::Reset()
{
    std::vector<hahaha_information_webcam_item>().swap(Webcams_);

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_information_webcam::Get_All()
{
    std::vector<hahaha_information_webcam_item>().swap(Webcams_);

    IMFAttributes* ptr_attributes_ = nullptr;
    IMFActivate** ptr_ptr_devices_ = nullptr;
    UINT32 count_ = 0;

    HRESULT hr = MFStartup(MF_VERSION);
    if (FAILED(hr))
    {
        return -1;
    }



    hr = MFCreateAttributes(&ptr_attributes_, 1);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = ptr_attributes_->SetGUID(
        MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE,
        MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = MFEnumDeviceSources(ptr_attributes_, &ptr_ptr_devices_, &count_);
    if (FAILED(hr))
    {
        goto done;
    }

    Webcams_.reserve(count_);
    for (UINT32 i = 0; i < count_; i++)
    {
        WCHAR* sz_friendly_name = nullptr;
        UINT32 cch_bame;

        hr = ptr_ptr_devices_[i]->GetAllocatedString(
            MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME,
            &sz_friendly_name,
            &cch_bame);

        if (SUCCEEDED(hr))
        {
            hahaha_information_webcam_item wi_;
            wi_.Name_Device_ = sz_friendly_name;

            Webcams_.emplace_back(wi_);
            CoTaskMemFree(sz_friendly_name);
        }

        ptr_ptr_devices_[i]->Release();
    }

done:
    if (ptr_attributes_)
        ptr_attributes_->Release();

    if (ptr_ptr_devices_)
        CoTaskMemFree(ptr_ptr_devices_);

    MFShutdown();

    return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------