//---------------------------------------------------------------------------

#pragma hdrstop

#include <dshow.h>
#include <strmif.h>
#include <control.h>
#include <uuids.h>
#include <amvideo.h>
#include <define\dshow\hahaha_define_dshow_qedit.h>  // ISampleGrabber, CLSID_SampleGrabber

#include "hahaha_define_com.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
template<typename T>
void hahaha_define_com_releaser<T>::operator()(T* p) const noexcept
{
    if (p)
    {
        p->Release();
    }
}





//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template class hahaha_define_com_releaser<IMFSourceReader>;
template class hahaha_define_com_releaser<IMFMediaSource>;
//
template class hahaha_define_com_releaser<IGraphBuilder>;
template class hahaha_define_com_releaser<ICaptureGraphBuilder2>;
template class hahaha_define_com_releaser<IMediaControl>;
template class hahaha_define_com_releaser<IBaseFilter>;
template class hahaha_define_com_releaser<ISampleGrabber>;

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------



