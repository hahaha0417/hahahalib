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
    virtual STDMETHODIMP SampleCB(double SampleTime, IMediaSample *pSample) = 0;
    virtual STDMETHODIMP BufferCB(double SampleTime, BYTE *pBuffer, long BufferLen) = 0;
};

interface ISampleGrabber : public IUnknown
{
    virtual STDMETHODIMP SetOneShot(BOOL OneShot) = 0;
    virtual STDMETHODIMP SetMediaType(const AM_MEDIA_TYPE *pType) = 0;
    virtual STDMETHODIMP GetConnectedMediaType(AM_MEDIA_TYPE *pType) = 0;
    virtual STDMETHODIMP SetBufferSamples(BOOL BufferThem) = 0;
    virtual STDMETHODIMP GetCurrentBuffer(long *pBufferSize, long *pBuffer) = 0;
    virtual STDMETHODIMP GetCurrentSample(IMediaSample **ppSample) = 0;
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
