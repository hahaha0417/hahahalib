//---------------------------------------------------------------------------

#ifndef hahaha_image_view_painter_eventH
#define hahaha_image_view_painter_eventH
//---------------------------------------------------------------------------
#pragma once
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.TitleBarCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include <image_view\define\hahaha_define_image_view_result.h>
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_image_view;
//---------------------------------------------------------------------------
// 因為編譯的關係，這裡不include hahaha_image_view
// 所以不能用halib::image_view
// 要用halib::image_view貼的，另外寫文件，不要寫在這裡
//---------------------------------------------------------------------------
class hahaha_image_view_painter_event
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_image_view_painter_event();
	// 解構物件並釋放相關資源。
	~hahaha_image_view_painter_event();

	// 以既有物件內容建構新的物件實例。
	hahaha_image_view_painter_event(const hahaha_image_view_painter_event& hivpe);
    // 以移動方式建構物件並接手既有資源。
    hahaha_image_view_painter_event(hahaha_image_view_painter_event&& hivpe);
	// 複製指派目前物件內容。
	hahaha_image_view_painter_event& operator=(const hahaha_image_view_painter_event& hivpe);
    // 移動指派目前物件內容。
    hahaha_image_view_painter_event& operator=(hahaha_image_view_painter_event&& hivpe);
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_image_view_painter_event& hivpe);
    // 接手來源物件的內部資源。
    void Move(hahaha_image_view_painter_event&& hivpe);
public:
	// 重設內部狀態。
	int Reset();

public:
    //---------------------------------------------------------------------------
    // event
    //---------------------------------------------------------------------------
    // 保持__fastcall快取乾淨，這裡不加__fastcall，因為painter會很多
    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    virtual halib_def::image_view_result On_Align_Insert_Before_Begin(hahahalib::hahaha_image_view& image_view,
        // event 回傳值
        bool& result,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *C1,  // 參與對齊判斷的第一個控制項。
        TControl *C2  // 參與對齊判斷的第二個控制項。
    );
    // 在 painter 前置階段處理控制項對齊定位事件，必要時可調整位置與尺寸。
    virtual halib_def::image_view_result On_Align_Position_Begin(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *Control,  // 目前正在對齊或處理的控制項。
        int &NewLeft,  // 可被調整的新左側座標。
        int &NewTop,  // 可被調整的新上方座標。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        TRect &AlignRect,  // 對齊計算使用的矩形範圍。
        const TAlignInfo &AlignInfo  // 對齊相關的額外資訊。
    );
    // 在 painter 前置階段處理尺寸變更前檢查事件，可決定是否允許縮放。
    virtual halib_def::image_view_result On_Can_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        bool &Resize  // 是否允許這次尺寸變更。
    );
    // 在 painter 前置階段處理點擊事件。
    virtual halib_def::image_view_result On_Click_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理縮放限制事件，可調整最小與最大尺寸。
    virtual halib_def::image_view_result On_Constrained_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &MinWidth,  // 最小允許寬度。
        int &MinHeight,  // 最小允許高度。
        int &MaxWidth,  // 最大允許寬度。
        int &MaxHeight
    );
    // 在 painter 前置階段處理右鍵選單事件，可決定是否自行接手。
    virtual halib_def::image_view_result On_Context_Popup_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 前置階段處理雙擊事件。
    virtual halib_def::image_view_result On_DblClick_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理 dock 放下事件。
    virtual halib_def::image_view_result On_Dock_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理 dock 拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Dock_Over_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 前置階段處理拖放完成事件。
    virtual halib_def::image_view_result On_Drag_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Drag_Over_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 前置階段處理 dock 結束事件。
    virtual halib_def::image_view_result On_End_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理拖曳結束事件。
    virtual halib_def::image_view_result On_End_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理圖形類別解析事件。
    virtual halib_def::image_view_result On_Find_Graphic_Class_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TFindGraphicClassContext &Context,  // 圖形類別查找所需的上下文資訊。
        TGraphicClass &GraphicClass  // 輸出的圖形類別型別。
    );
    // 在 painter 前置階段處理游標或焦點進入事件。
    virtual halib_def::image_view_result On_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理游標或焦點離開事件。
    virtual halib_def::image_view_result On_Exit_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理手勢事件，可決定是否標記為已處理。
    virtual halib_def::image_view_result On_Gesture_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TGestureEventInfo &EventInfo,  // 手勢事件的詳細資訊。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 前置階段處理 docking 站點資訊查詢事件。
    virtual halib_def::image_view_result On_Get_Site_Info_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *DockClient,  // 正在查詢 docking 資訊的控制項。
        TRect &InfluenceRect,  // 可影響 docking 判斷的區域。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &CanDock  // 是否允許停靠。
    );
    // 在 painter 前置階段處理滑鼠啟動事件，可決定視窗啟動方式。
    virtual halib_def::image_view_result On_Mouse_Activate_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        int HitTest,  // 滑鼠命中的區域代碼。
        TMouseActivate &MouseActivate  // 輸出的滑鼠啟動結果。
    );
    // 在 painter 前置階段處理滑鼠按下事件。
    virtual halib_def::image_view_result On_Mouse_Down_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理滑鼠進入事件。
    virtual halib_def::image_view_result On_Mouse_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理滑鼠離開事件。
    virtual halib_def::image_view_result On_Mouse_Leave_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理滑鼠移動事件。
    virtual halib_def::image_view_result On_Mouse_Move_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理滑鼠放開事件。
    virtual halib_def::image_view_result On_Mouse_Up_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 前置階段處理繪圖或載入進度通知事件。
    virtual halib_def::image_view_result On_Progress_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TProgressStage Stage,  // 目前進度通知所處的階段。
        BYTE PercentDone,  // 目前完成百分比。
        bool RedrawNow,  // 是否需要立即重繪。
        const TRect &R,  // 目前進度對應的矩形範圍。
        const UnicodeString Msg
    );
	// 在 painter 前置階段處理重繪事件。
	virtual halib_def::image_view_result On_Paint_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理尺寸變更完成事件。
    virtual halib_def::image_view_result On_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 前置階段處理 dock 開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 前置階段處理拖曳開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 前置階段處理取消 dock 事件，可決定是否允許分離。
    virtual halib_def::image_view_result On_Un_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *Client,  // 要從 docking 中分離的控制項。
        TWinControl *NewTarget,  // 新的 docking 目標。
        bool &Allow  // 是否允許這次操作。
    );
    //
    virtual halib_def::image_view_result On_Paint_Begin(hahahalib::hahaha_image_view& image_view /* 目前正在處理的 image view 物件。 */);

    //-----------------------------------
    // Vertical_Bar
    //-----------------------------------
//    halib_def::image_view_result On_Vertical_Bar_Change_Begin(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
//    //-----------------------------------
//    // Horizontal_Bar
//    //-----------------------------------
//    halib_def::image_view_result On_Horizontal_Bar_Change_Begin(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    virtual halib_def::image_view_result On_Align_Insert_Before_Design(hahahalib::hahaha_image_view& image_view,
        // event 回傳值
        bool& result,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *C1,  // 參與對齊判斷的第一個控制項。
        TControl *C2  // 參與對齊判斷的第二個控制項。
    );
    // 在 painter 設計階段處理控制項對齊定位事件，必要時可調整位置與尺寸。
    virtual halib_def::image_view_result On_Align_Position_Design(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *Control,  // 目前正在對齊或處理的控制項。
        int &NewLeft,  // 可被調整的新左側座標。
        int &NewTop,  // 可被調整的新上方座標。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        TRect &AlignRect,  // 對齊計算使用的矩形範圍。
        const TAlignInfo &AlignInfo  // 對齊相關的額外資訊。
    );
    // 在 painter 設計階段處理尺寸變更前檢查事件，可決定是否允許縮放。
    virtual halib_def::image_view_result On_Can_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        bool &Resize  // 是否允許這次尺寸變更。
    );
    // 在 painter 設計階段處理點擊事件。
    virtual halib_def::image_view_result On_Click_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理縮放限制事件，可調整最小與最大尺寸。
    virtual halib_def::image_view_result On_Constrained_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &MinWidth,  // 最小允許寬度。
        int &MinHeight,  // 最小允許高度。
        int &MaxWidth,  // 最大允許寬度。
        int &MaxHeight
    );
    // 在 painter 設計階段處理右鍵選單事件，可決定是否自行接手。
    virtual halib_def::image_view_result On_Context_Popup_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 設計階段處理雙擊事件。
    virtual halib_def::image_view_result On_DblClick_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理 dock 放下事件。
    virtual halib_def::image_view_result On_Dock_Drop_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理 dock 拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Dock_Over_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 設計階段處理拖放完成事件。
    virtual halib_def::image_view_result On_Drag_Drop_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Drag_Over_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 設計階段處理 dock 結束事件。
    virtual halib_def::image_view_result On_End_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理拖曳結束事件。
    virtual halib_def::image_view_result On_End_Drag_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理圖形類別解析事件。
    virtual halib_def::image_view_result On_Find_Graphic_Class_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TFindGraphicClassContext &Context,  // 圖形類別查找所需的上下文資訊。
        TGraphicClass &GraphicClass  // 輸出的圖形類別型別。
    );
    // 在 painter 設計階段處理游標或焦點進入事件。
    virtual halib_def::image_view_result On_Enter_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理游標或焦點離開事件。
    virtual halib_def::image_view_result On_Exit_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理手勢事件，可決定是否標記為已處理。
    virtual halib_def::image_view_result On_Gesture_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TGestureEventInfo &EventInfo,  // 手勢事件的詳細資訊。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 設計階段處理 docking 站點資訊查詢事件。
    virtual halib_def::image_view_result On_Get_Site_Info_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *DockClient,  // 正在查詢 docking 資訊的控制項。
        TRect &InfluenceRect,  // 可影響 docking 判斷的區域。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &CanDock  // 是否允許停靠。
    );
    // 在 painter 設計階段處理滑鼠啟動事件，可決定視窗啟動方式。
    virtual halib_def::image_view_result On_Mouse_Activate_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        int HitTest,  // 滑鼠命中的區域代碼。
        TMouseActivate &MouseActivate  // 輸出的滑鼠啟動結果。
    );
    // 在 painter 設計階段處理滑鼠按下事件。
    virtual halib_def::image_view_result On_Mouse_Down_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理滑鼠進入事件。
    virtual halib_def::image_view_result On_Mouse_Enter_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理滑鼠離開事件。
    virtual halib_def::image_view_result On_Mouse_Leave_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理滑鼠移動事件。
    virtual halib_def::image_view_result On_Mouse_Move_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理滑鼠放開事件。
    virtual halib_def::image_view_result On_Mouse_Up_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 設計階段處理繪圖或載入進度通知事件。
    virtual halib_def::image_view_result On_Progress_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TProgressStage Stage,  // 目前進度通知所處的階段。
        BYTE PercentDone,  // 目前完成百分比。
        bool RedrawNow,  // 是否需要立即重繪。
        const TRect &R,  // 目前進度對應的矩形範圍。
        const UnicodeString Msg
    );
	// 在 painter 設計階段處理重繪事件。
	virtual halib_def::image_view_result On_Paint_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理尺寸變更完成事件。
    virtual halib_def::image_view_result On_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 設計階段處理 dock 開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 設計階段處理拖曳開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Drag_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 設計階段處理取消 dock 事件，可決定是否允許分離。
    virtual halib_def::image_view_result On_Un_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *Client,  // 要從 docking 中分離的控制項。
        TWinControl *NewTarget,  // 新的 docking 目標。
        bool &Allow  // 是否允許這次操作。
    );
    //
    virtual halib_def::image_view_result On_Paint_Design(hahahalib::hahaha_image_view& image_view /* 目前正在處理的 image view 物件。 */);
    //-----------------------------------
    // Vertical_Bar
    //-----------------------------------
//    halib_def::image_view_result On_Vertical_Bar_Change_Design(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
//    //-----------------------------------
//    // Horizontal_Bar
//    //-----------------------------------
//    halib_def::image_view_result On_Horizontal_Bar_Change_Design(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    virtual halib_def::image_view_result On_Align_Insert_Before_End(hahahalib::hahaha_image_view& image_view,
        // event 回傳值
        bool& result,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *C1,  // 參與對齊判斷的第一個控制項。
        TControl *C2  // 參與對齊判斷的第二個控制項。
    );
    // 在 painter 收尾階段處理控制項對齊定位事件，必要時可調整位置與尺寸。
    virtual halib_def::image_view_result On_Align_Position_End(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,  // 觸發事件的元件。
        TControl *Control,  // 目前正在對齊或處理的控制項。
        int &NewLeft,  // 可被調整的新左側座標。
        int &NewTop,  // 可被調整的新上方座標。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        TRect &AlignRect,  // 對齊計算使用的矩形範圍。
        const TAlignInfo &AlignInfo  // 對齊相關的額外資訊。
    );
    // 在 painter 收尾階段處理尺寸變更前檢查事件，可決定是否允許縮放。
    virtual halib_def::image_view_result On_Can_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        bool &Resize  // 是否允許這次尺寸變更。
    );
    // 在 painter 收尾階段處理點擊事件。
    virtual halib_def::image_view_result On_Click_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理縮放限制事件，可調整最小與最大尺寸。
    virtual halib_def::image_view_result On_Constrained_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        int &MinWidth,  // 最小允許寬度。
        int &MinHeight,  // 最小允許高度。
        int &MaxWidth,  // 最大允許寬度。
        int &MaxHeight
    );
    // 在 painter 收尾階段處理右鍵選單事件，可決定是否自行接手。
    virtual halib_def::image_view_result On_Context_Popup_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 收尾階段處理雙擊事件。
    virtual halib_def::image_view_result On_DblClick_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理 dock 放下事件。
    virtual halib_def::image_view_result On_Dock_Drop_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理 dock 拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Dock_Over_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 收尾階段處理拖放完成事件。
    virtual halib_def::image_view_result On_Drag_Drop_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理拖曳經過事件，可決定是否接受。
    virtual halib_def::image_view_result On_Drag_Over_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 在 painter 收尾階段處理 dock 結束事件。
    virtual halib_def::image_view_result On_End_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理拖曳結束事件。
    virtual halib_def::image_view_result On_End_Drag_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理圖形類別解析事件。
    virtual halib_def::image_view_result On_Find_Graphic_Class_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TFindGraphicClassContext &Context,  // 圖形類別查找所需的上下文資訊。
        TGraphicClass &GraphicClass  // 輸出的圖形類別型別。
    );
    // 在 painter 收尾階段處理游標或焦點進入事件。
    virtual halib_def::image_view_result On_Enter_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理游標或焦點離開事件。
    virtual halib_def::image_view_result On_Exit_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理手勢事件，可決定是否標記為已處理。
    virtual halib_def::image_view_result On_Gesture_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        const TGestureEventInfo &EventInfo,  // 手勢事件的詳細資訊。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 在 painter 收尾階段處理 docking 站點資訊查詢事件。
    virtual halib_def::image_view_result On_Get_Site_Info_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *DockClient,  // 正在查詢 docking 資訊的控制項。
        TRect &InfluenceRect,  // 可影響 docking 判斷的區域。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &CanDock  // 是否允許停靠。
    );
    // 在 painter 收尾階段處理滑鼠啟動事件，可決定視窗啟動方式。
    virtual halib_def::image_view_result On_Mouse_Activate_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        int HitTest,  // 滑鼠命中的區域代碼。
        TMouseActivate &MouseActivate  // 輸出的滑鼠啟動結果。
    );
    // 在 painter 收尾階段處理滑鼠按下事件。
    virtual halib_def::image_view_result On_Mouse_Down_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理滑鼠進入事件。
    virtual halib_def::image_view_result On_Mouse_Enter_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理滑鼠離開事件。
    virtual halib_def::image_view_result On_Mouse_Leave_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理滑鼠移動事件。
    virtual halib_def::image_view_result On_Mouse_Move_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理滑鼠放開事件。
    virtual halib_def::image_view_result On_Mouse_Up_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 在 painter 收尾階段處理繪圖或載入進度通知事件。
    virtual halib_def::image_view_result On_Progress_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TProgressStage Stage,  // 目前進度通知所處的階段。
        BYTE PercentDone,  // 目前完成百分比。
        bool RedrawNow,  // 是否需要立即重繪。
        const TRect &R,  // 目前進度對應的矩形範圍。
        const UnicodeString Msg
    );
	// 在 painter 收尾階段處理重繪事件。
	virtual halib_def::image_view_result On_Paint_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理尺寸變更完成事件。
    virtual halib_def::image_view_result On_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    // 在 painter 收尾階段處理 dock 開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 收尾階段處理拖曳開始事件，可建立拖曳物件。
    virtual halib_def::image_view_result On_Start_Drag_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TDragObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 在 painter 收尾階段處理取消 dock 事件，可決定是否允許分離。
    virtual halib_def::image_view_result On_Un_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,  // 觸發事件的元件。
        TControl *Client,  // 要從 docking 中分離的控制項。
        TWinControl *NewTarget,  // 新的 docking 目標。
        bool &Allow  // 是否允許這次操作。
    );
    //
    virtual halib_def::image_view_result On_Paint_End(hahahalib::hahaha_image_view& image_view /* 目前正在處理的 image view 物件。 */);
    //-----------------------------------
    // Vertical_Bar
    //-----------------------------------
//    halib_def::image_view_result On_Vertical_Bar_Change_End(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
//    //-----------------------------------
//    // Horizontal_Bar
//    //-----------------------------------
//    halib_def::image_view_result On_Horizontal_Bar_Change_End(hahahalib::hahaha_image_view& image_view,
//    	TObject *Sender
//    );
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------






    //---------------------------------------------------------------------------
    //TPanel
    //---------------------------------------------------------------------------
    //OnAlignInsertBefore
    //OnAlignPosition
    //OnCanResize
    //OnClick
    //OnConstrainedResize
    //OnContextPopup
    //OnDblClick
    //OnDockDrop
    //OnDockOver
    //OnDragDrop
    //OnDragOver
    //OnEndDock
    //OnEndDrag
    //OnEnter
    //OnExit
    //OnGesture
    //OnGetSiteInfo
    //OnMouseActivate
    //OnMouseDown
    //OnMouseEnter
    //OnMouseLeave
    //OnMouseMove
    //OnMouseUp
    //OnResize
    //OnStartDock
    //OnStartDrag
    //OnUnDock
    //---------------------------------------------------------------------------
    //TImage
    //---------------------------------------------------------------------------
    //OnClick
    //OnContextPopup
    //OnDblClick
    //OnDragDrop
    //OnDragOver
    //OnEndDock
    //OnEndDrag
    //OnFindGraphicClass
    //OnGesture
    //OnMouseActivate
    //OnMouseDown
    //OnMouseEnter
    //OnMouseLeave
    //OnMouseMove
    //OnMouseUp
    //OnProgress
    //OnStartDock
    //OnStartDrag
    //---------------------------------------------------------------------------
    //TPaintBox
    //---------------------------------------------------------------------------
    //OnClick
    //OnContextPopup
    //OnDblClick
    //OnDragDrop
    //OnDragOver
    //OnEndDock
    //OnEndDrag
    //OnGesture
    //OnMouseActivate
    //OnMouseDown
    //OnMouseEnter
    //OnMouseLeave
    //OnMouseMove
    //OnMouseUp
    //OnPaint
    //OnStartDock
    //OnStartDrag
    //---------------------------------------------------------------------------
    //TScrollBar
    //---------------------------------------------------------------------------
    // 有用到才加，有需要繼承出去改
    // 有垂直水平，尚未處理
    //--------------------------------
    //OnChange
    //OnContextPopup
    //OnDragDrop
    //OnDragOver
    //OnEndDock
    //OnEndDrag
    //OnEnter
    //OnExit
    //OnKeyDown
    //OnKeyPress
    //OnKeyUp
    //OnMouseEnter
    //OnMouseLeave
    //OnScroll
    //OnStartDock
    //OnStartDrag
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
public:

public:

public:

public:

};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
