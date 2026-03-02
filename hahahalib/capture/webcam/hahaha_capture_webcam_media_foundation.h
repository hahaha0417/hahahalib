//---------------------------------------------------------------------------

#ifndef hahaha_capture_webcam_media_foundationH
#define hahaha_capture_webcam_media_foundationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
// Windows / Media Foundation
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <vector>
#include <mutex>
#include <memory>
#include <functional>
#include <string>

#include <define\hahaha_define_com.h>
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------




class hahaha_capture_webcam_media_foundation
{
public:
	hahaha_capture_webcam_media_foundation();
	~hahaha_capture_webcam_media_foundation();

	hahaha_capture_webcam_media_foundation(const hahaha_capture_webcam_media_foundation& hcwmf);
    hahaha_capture_webcam_media_foundation(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;
	hahaha_capture_webcam_media_foundation& operator=(const hahaha_capture_webcam_media_foundation& hcwmf);
	hahaha_capture_webcam_media_foundation& operator=(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;
	void Copy(const hahaha_capture_webcam_media_foundation& hcwmf);
    void Move(hahaha_capture_webcam_media_foundation&& hcwmf) noexcept;
    // List available video capture devices (names)
    static std::vector<std::wstring> List_Devices();
public:
	int Reset();

	// 初始化 Media Foundation（可多次呼叫）
    bool Initial();
	// 結束 Media Foundation（全程只呼叫一次）
	void Shut_Down();

	// 打開第一個 webcam（回傳 true 表成功）
    bool Open(UINT index = 0);
    // 關閉攝影機
    void Close();

    // 設定想要的解析度（在 OpenWebcam 前呼叫）。
    // 若未設定或驅動不支援，會使用裝置預設解析度。
    void Set_Resolution(int width, int height);

	// 取得一幀圖片（簡化示範，輸出為 RGB32 / 4 channels）
	// 'data' 必須至少為 width*height*4 bytes
	bool Get_Frame(unsigned char* data, int& width, int& height, int& channels);

	// 判斷 webcam 是否已打開
	bool Is_Open() const;

private:
	bool Is_Initial_ = false;
	bool Is_Open_ = false;

    // Media Foundation 元件 (wrapped in unique_ptr with COM releaser)


    halib_def::com_ptr<IMFSourceReader> Source_Reader_;
    halib_def::com_ptr<IMFMediaSource> Media_Source_;

    int Width_ = 0;
    int Height_ = 0;
    int Channels_ = 0; // will be 4 for RGB32
    // Desired resolution (0 = not set)
    int Desired_Width_ = 0;
    int Desired_Height_ = 0;

	void Release();

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
