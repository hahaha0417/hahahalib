#ifndef hahaha_capture_desktop_desktop_duplicationH
#define hahaha_capture_desktop_desktop_duplicationH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <cstdint>
#include <memory>
#include <mutex>
#include <utility>
#include <vector>
#include <windows.h>
#include <d3d11.h>
#include <dxgi1_2.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
	struct hahaha_capture_desktop_desktop_duplication_frame
	{
		std::vector<uint8_t> Data_;
		int Width_ = 0;
		int Height_ = 0;
		int Stride_ = 0;

		bool Is_Valid() const noexcept
		{
			return Width_ > 0 && Height_ > 0 && Stride_ >= Width_ * 4 && !Data_.empty();
		}
	};

	struct hahaha_capture_desktop_desktop_duplication_options
	{
		int Monitor_Index_ = 0;
		int Timeout_Ms_ = 0;
	};

	class hahaha_capture_desktop_desktop_duplication
	{
	public:
		hahaha_capture_desktop_desktop_duplication();
		~hahaha_capture_desktop_desktop_duplication();

		hahaha_capture_desktop_desktop_duplication(const hahaha_capture_desktop_desktop_duplication& hcddd) = delete;
		hahaha_capture_desktop_desktop_duplication(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
		hahaha_capture_desktop_desktop_duplication& operator=(const hahaha_capture_desktop_desktop_duplication& hcddd) = delete;
		hahaha_capture_desktop_desktop_duplication& operator=(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;
		void Move(hahaha_capture_desktop_desktop_duplication&& hcddd) noexcept;

	public:
		int Reset();

		bool Initialize();
		bool Start(const hahaha_capture_desktop_desktop_duplication_options& options = {});
		bool Start_By_Monitor(HMONITOR monitor, int timeoutMs = 0);
		void Stop();

		bool Is_Capturing() const noexcept;
		bool Capture_Frame(hahaha_capture_desktop_desktop_duplication_frame& frame);
		bool Capture_Region(const RECT& desktopRect, hahaha_capture_desktop_desktop_duplication_frame& frame);
		RECT Get_Output_Desktop_Rect() const noexcept;
		HMONITOR Get_Monitor() const noexcept;

	private:
		bool Ensure_Device();
		bool Create_Duplication(int monitor_index);
		bool Create_Duplication_By_Monitor(HMONITOR monitor);
		bool Ensure_Staging_Texture(const D3D11_TEXTURE2D_DESC& desc);
		bool Ensure_Staging_Texture(int width, int height, DXGI_FORMAT format);
		bool Copy_Frame_To_Snapshot(ID3D11Texture2D* frame_texture);

		template<typename T>
		struct com_release_deleter
		{
			void operator()(T* ptr) const noexcept
			{
				if (ptr)
				{
					ptr->Release();
				}
			}
		};

		template<typename T>
		using com_unique_ptr = std::unique_ptr<T, com_release_deleter<T>>;

		com_unique_ptr<ID3D11Device> Device_;
		com_unique_ptr<ID3D11DeviceContext> Context_;
		com_unique_ptr<IDXGIOutputDuplication> Duplication_;
		com_unique_ptr<ID3D11Texture2D> Staging_Texture_;
		int Staging_Width_ = 0;
		int Staging_Height_ = 0;
		DXGI_FORMAT Staging_Format_ = DXGI_FORMAT_UNKNOWN;
		hahaha_capture_desktop_desktop_duplication_options Options_;
		HMONITOR Monitor_ = nullptr;
		RECT Output_Desktop_Rect_{};
		bool Use_Monitor_Handle_ = false;

		bool Capturing_ = false;
		mutable std::mutex Frame_Mutex_;
		mutable std::mutex State_Mutex_;
		hahaha_capture_desktop_desktop_duplication_frame Frame_Snapshot_;
	};
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
#endif
