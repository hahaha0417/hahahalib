//---------------------------------------------------------------------------

#ifndef hahaha_define_dshow_qeditH
#define hahaha_define_dshow_qeditH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------

#include <dshow.h>

EXTERN_C const CLSID CLSID_SampleGrabber;
EXTERN_C const CLSID CLSID_NullRenderer;

EXTERN_C const IID IID_ISampleGrabberCB;
EXTERN_C const IID IID_ISampleGrabber;

interface ISampleGrabberCB : public IUnknown
{
    // 提供 DirectShow 的 sample callback 介面。
    virtual STDMETHODIMP SampleCB(double SampleTime, IMediaSample *pSample) = 0;
    // 提供 DirectShow 的 buffer callback 介面。
    virtual STDMETHODIMP BufferCB(double SampleTime, BYTE *pBuffer, long BufferLen) = 0;
};

interface ISampleGrabber : public IUnknown
{
    // 設定 SampleGrabber 是否只抓取一次資料。
    virtual STDMETHODIMP SetOneShot(BOOL OneShot) = 0;
    // 設定 SampleGrabber 預期接收的媒體格式。
    virtual STDMETHODIMP SetMediaType(const AM_MEDIA_TYPE *pType) = 0;
    // 取得目前已連線的媒體格式。
    virtual STDMETHODIMP GetConnectedMediaType(AM_MEDIA_TYPE *pType) = 0;
    // 設定是否啟用內部 buffer 樣本保存。
    virtual STDMETHODIMP SetBufferSamples(BOOL BufferThem) = 0;
    // 讀取目前 buffer 內的原始資料。
    virtual STDMETHODIMP GetCurrentBuffer(long *pBufferSize, long *pBuffer) = 0;
    // 取得目前的 sample 物件。
    virtual STDMETHODIMP GetCurrentSample(IMediaSample **ppSample) = 0;
    // 註冊 SampleGrabber 使用的 callback 物件。
    virtual STDMETHODIMP SetCallback(ISampleGrabberCB *pCallback, long WhichMethodToCallback) = 0;
};


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace halib_def
{
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib_def
//---------------------------------------------------------------------------
#endif
