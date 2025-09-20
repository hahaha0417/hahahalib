//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include <function\hahaha_function_vector.h>
#include <information\monitor\hahaha_information_monitor_item.h>
//---------------------------------------------------------------------------
#include "hahaha_information_monitor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_information_monitor::hahaha_information_monitor()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_information_monitor::~hahaha_information_monitor()
{

}
//---------------------------------------------------------------------------
hahaha_information_monitor::hahaha_information_monitor(const hahaha_information_monitor& him)
{
    Reset();
	Copy(him);
}
//---------------------------------------------------------------------------
hahaha_information_monitor::hahaha_information_monitor(hahaha_information_monitor&& him) noexcept
{
    Move(std::move(him));
}
//---------------------------------------------------------------------------
hahaha_information_monitor& hahaha_information_monitor::operator=(const hahaha_information_monitor& him)
{
	Copy(him);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_information_monitor& hahaha_information_monitor::operator=(hahaha_information_monitor&& him) noexcept
{
	if (this != &him)
    {
        Move(std::move(him));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_information_monitor::Copy(const hahaha_information_monitor& him)
{
    hahahalib::Vector_Copy(him.Monitors_, Monitors_);
}
//---------------------------------------------------------------------------
void hahaha_information_monitor::Move(hahaha_information_monitor&& him) noexcept
{
    Monitors_ = std::move(him.Monitors_);

    him.Reset();
}
//---------------------------------------------------------------------------
int hahaha_information_monitor::Reset()
{
    std::vector<hahaha_information_monitor_item>().swap(Monitors_);

	return 0;
}
//---------------------------------------------------------------------------
BOOL CALLBACK hahaha_information_monitor::Procedure_Enum(HMONITOR handle_monitor, HDC hdc_monitor, LPRECT lprect_monitor, LPARAM dw_data) {
    hahaha_information_monitor& Information_Monitor_ = *(hahaha_information_monitor*)dw_data;

    MONITORINFOEXW monitor_;
    monitor_.cbSize = sizeof(monitor_);
    if (GetMonitorInfoW(handle_monitor, &monitor_)) {
        hahaha_information_monitor_item item_;
        item_.Handle_Monitor_ = handle_monitor;
        *item_.Region_Monitor_ = halib::rect(
            monitor_.rcMonitor.left,
            monitor_.rcMonitor.top,
            monitor_.rcMonitor.right,
            monitor_.rcMonitor.bottom
        );
        *item_.Region_Work_ = halib::rect(
            monitor_.rcWork.left,
            monitor_.rcWork.top,
            monitor_.rcWork.right,
            monitor_.rcWork.bottom
        );
        item_.Flag_ = monitor_.dwFlags;
        item_.Name_Device_ = monitor_.szDevice;



        item_.Name_Product_ = Information_Monitor_.Get_Monitor_Model_From_HMonitor(handle_monitor);

        Information_Monitor_.Monitors_.emplace_back(item_);

    }
    return TRUE;
}
//---------------------------------------------------------------------------
int hahaha_information_monitor::Get_All()
{
    std::vector<hahaha_information_monitor_item>().swap(Monitors_);
    EnumDisplayMonitors(nullptr, nullptr, Procedure_Enum, (LPARAM)this);

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_information_monitor::Get_Monitor_Primary_Index()
{
    int n = Monitors_.size();
    for(int i = 0; i < n; i++)
    {
        if(Monitors_[i].Flag_ & MONITORINFOF_PRIMARY)
        {
        	return i;
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
std::wstring hahaha_information_monitor::Get_Monitor_Model_From_HMonitor(HMONITOR hmonitor)
{
    MONITORINFOEXW mi = {};
    mi.cbSize = sizeof(mi);
    if (!GetMonitorInfoW(hmonitor, &mi))
        return L"";

    // 取得 DISPLAYx 名稱
    DISPLAY_DEVICEW dd = {};
    dd.cb = sizeof(dd);
    if (!EnumDisplayDevicesW(mi.szDevice, 0, &dd, 0))
        return L"";

    // 解析 dd.DeviceID 中的 VEN+PID（MONITOR\DEL40A9\xxxxx）
    std::wstring deviceID = dd.DeviceID;
    size_t slash1 = deviceID.find(L'\\');
    size_t slash2 = deviceID.find(L'\\', slash1 + 1);
    if (slash1 == std::wstring::npos || slash2 == std::wstring::npos)
        return L"";

    std::wstring regKey = L"SYSTEM\\CurrentControlSet\\Enum\\DISPLAY\\" +
                          deviceID.substr(slash1 + 1, slash2 - slash1 - 1);

    // 打開 registry 找 EDID
    HKEY hKey;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, regKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return L"";

    wchar_t subKey[256];
    DWORD subLen = 256;
    if (RegEnumKeyExW(hKey, 0, subKey, &subLen, NULL, NULL, NULL, NULL) != ERROR_SUCCESS)
    {
        RegCloseKey(hKey);
        return L"";
    }
    RegCloseKey(hKey);

    std::wstring edidPath = regKey + L"\\" + subKey + L"\\Device Parameters";

    HKEY hEDID;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, edidPath.c_str(), 0, KEY_READ, &hEDID) != ERROR_SUCCESS)
        return L"";

    BYTE edid_data[1024] = {};
    DWORD edid_size = sizeof(edid_data);
    DWORD type = 0;
    std::wstring model;

    if (RegQueryValueExW(hEDID, L"EDID", NULL, &type, edid_data, &edid_size) == ERROR_SUCCESS && type == REG_BINARY)
    {
        model = Parse_Edid_Model(edid_data, edid_size); // 使用前面提到的 EDID 解碼函式
    }

    RegCloseKey(hEDID);
    return model;
}
//---------------------------------------------------------------------------
std::wstring hahaha_information_monitor::Parse_Edid_Model(const BYTE* edid_data, DWORD data_size)
{
    if (data_size < 128) return L"";

    for (DWORD i = 54; i <= 125; i += 18)
    {
        if (edid_data[i] == 0x00 && edid_data[i + 1] == 0x00 &&
            edid_data[i + 2] == 0x00 && edid_data[i + 3] == 0xFC)
        {
            // 找到 monitor name descriptor
            wchar_t name[14] = { 0 };
            for (int j = 0; j < 13; ++j)
            {
                BYTE ch = edid_data[i + 5 + j];
                if (ch == 0x0A || ch == 0x00) break; // 結尾或 padding
                name[j] = ch;
            }
            return std::wstring(name);
        }
    }

    return L"Unknown";
}
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------