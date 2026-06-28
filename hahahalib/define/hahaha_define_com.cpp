//---------------------------------------------------------------------------

#pragma hdrstop

#include <dshow.h>
#include <strmif.h>
#include <control.h>
#include <uuids.h>
#include <amvideo.h>
#include <define\dshow\hahaha_define_dshow_qedit.h>  // ISampleGrabber, CLSID_SampleGrabber
#include <d3d11.h>
#include <dxgi1_2.h>

#include "hahaha_define_com.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
template<typename T>
// 負責釋放 COM 物件並呼叫 Release。
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
//
template class hahaha_define_com_releaser<ID3D11Device>;
template class hahaha_define_com_releaser<ID3D11DeviceContext>;
template class hahaha_define_com_releaser<IDXGIOutput1>;
template class hahaha_define_com_releaser<IDXGIOutputDuplication>;
template class hahaha_define_com_releaser<ID3D11Texture2D>;
template class hahaha_define_com_releaser<IDXGIFactory1>;
template class hahaha_define_com_releaser<IDXGIAdapter1>;
template class hahaha_define_com_releaser<IDXGIOutput>;
template class hahaha_define_com_releaser<IDXGIResource>;



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------


