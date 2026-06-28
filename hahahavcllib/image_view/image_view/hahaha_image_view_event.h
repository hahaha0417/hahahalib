//---------------------------------------------------------------------------

#ifndef hahaha_image_view_eventH
#define hahaha_image_view_eventH
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
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
class hahaha_image_view;
//---------------------------------------------------------------------------
class hahaha_image_view_event
{
public:
	// 建構物件並初始化預設狀態。
	hahaha_image_view_event();
	// 解構物件並釋放相關資源。
	~hahaha_image_view_event();

	// 以既有物件內容建構新的物件實例。
	hahaha_image_view_event(const hahaha_image_view_event& hive);
    // 以移動方式建構物件並接手既有資源。
    hahaha_image_view_event(hahaha_image_view_event&& hive) noexcept;
	// 複製指派目前物件內容。
	hahaha_image_view_event& operator=(const hahaha_image_view_event& hive);
    // 移動指派目前物件內容。
    hahaha_image_view_event& operator=(hahaha_image_view_event&& hive) noexcept;
	// 複製來源物件的內部狀態。
	void Copy(const hahaha_image_view_event& hive);
    // 接手來源物件的內部資源。
    void Move(hahaha_image_view_event&& hive) noexcept;
public:
	// 重設內部狀態。
	int Reset();

	//---------------------------------------------------------------------------
    // event
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // 處理對應的 UI 或互動事件。
    virtual bool __fastcall On_Align_Insert_Before(TWinControl *Sender,  // 觸發事件的元件。
        TControl *C1,  // 參與對齊判斷的第一個控制項。
        TControl *C2  // 參與對齊判斷的第二個控制項。
    );
    // 處理控制項對齊定位事件，必要時可調整位置與尺寸。
    virtual void __fastcall On_Align_Position(TWinControl *Sender,  // 觸發事件的元件。
        TControl *Control,  // 目前正在對齊或處理的控制項。
        int &NewLeft,  // 可被調整的新左側座標。
        int &NewTop,  // 可被調整的新上方座標。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        TRect &AlignRect,  // 對齊計算使用的矩形範圍。
        const TAlignInfo &AlignInfo  // 對齊相關的額外資訊。
    );
    // 處理尺寸變更前檢查事件，可決定是否允許縮放。
    virtual void __fastcall On_Can_Resize(TObject *Sender,  // 觸發事件的元件。
        int &NewWidth,  // 可被調整的新寬度。
        int &NewHeight,  // 可被調整的新高度。
        bool &Resize  // 是否允許這次尺寸變更。
    );
    // 處理點擊事件。
    virtual void __fastcall On_Click(TObject *Sender);
    // 處理縮放限制事件，可調整最小與最大尺寸。
    virtual void __fastcall On_Constrained_Resize(TObject *Sender,  // 觸發事件的元件。
        int &MinWidth,  // 最小允許寬度。
        int &MinHeight,  // 最小允許高度。
        int &MaxWidth,  // 最大允許寬度。
        int &MaxHeight
    );
    // 處理右鍵選單事件，可決定是否自行接手。
    virtual void __fastcall On_Context_Popup(TObject *Sender,  // 觸發事件的元件。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 處理雙擊事件。
    virtual void __fastcall On_DblClick(TObject *Sender);
    // 處理 dock 放下事件。
    virtual void __fastcall On_Dock_Drop(TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理 dock 拖曳經過事件，可決定是否接受。
    virtual void __fastcall On_Dock_Over(TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 處理拖放完成事件。
    virtual void __fastcall On_Drag_Drop(TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理拖曳經過事件，可決定是否接受。
    virtual void __fastcall On_Drag_Over(TObject *Sender,  // 觸發事件的元件。
        TObject *Source,  // 拖曳、dock 或事件來源物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        TDragState State,  // 目前拖曳或互動狀態。
        bool &Accept  // 是否接受這次拖曳或 dock。
    );
    // 處理 dock 結束事件。
    virtual void __fastcall On_End_Dock(TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理拖曳結束事件。
    virtual void __fastcall On_End_Drag(TObject *Sender,  // 觸發事件的元件。
        TObject *Target,  // 拖曳結束時的目標物件。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理圖形類別解析事件。
    virtual void __fastcall On_Find_Graphic_Class(TObject *Sender,  // 觸發事件的元件。
        const TFindGraphicClassContext &Context,  // 圖形類別查找所需的上下文資訊。
        TGraphicClass &GraphicClass  // 輸出的圖形類別型別。
    );
    // 處理游標或焦點進入事件。
    virtual void __fastcall On_Enter(TObject *Sender);
    // 處理游標或焦點離開事件。
    virtual void __fastcall On_Exit(TObject *Sender);
    // 處理手勢事件，可決定是否標記為已處理。
    virtual void __fastcall On_Gesture(TObject *Sender,  // 觸發事件的元件。
        const TGestureEventInfo &EventInfo,  // 手勢事件的詳細資訊。
        bool &Handled  // 是否已由目前流程處理完成。
    );
    // 處理 docking 站點資訊查詢事件。
    virtual void __fastcall On_Get_Site_Info(TObject *Sender,  // 觸發事件的元件。
        TControl *DockClient,  // 正在查詢 docking 資訊的控制項。
        TRect &InfluenceRect,  // 可影響 docking 判斷的區域。
        const TPoint &MousePos,  // 滑鼠座標。
        bool &CanDock  // 是否允許停靠。
    );
    // 處理滑鼠啟動事件，可決定視窗啟動方式。
    virtual void __fastcall On_Mouse_Activate(TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y,  // 滑鼠或拖曳位置的 Y 座標。
        int HitTest,  // 滑鼠命中的區域代碼。
        TMouseActivate &MouseActivate  // 輸出的滑鼠啟動結果。
    );
    // 處理滑鼠按下事件。
    virtual void __fastcall On_Mouse_Down(TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理滑鼠進入事件。
    virtual void __fastcall On_Mouse_Enter(TObject *Sender);
    // 處理滑鼠離開事件。
    virtual void __fastcall On_Mouse_Leave(TObject *Sender);
    // 處理滑鼠移動事件。
    virtual void __fastcall On_Mouse_Move(TObject *Sender,  // 觸發事件的元件。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理滑鼠放開事件。
    virtual void __fastcall On_Mouse_Up(TObject *Sender,  // 觸發事件的元件。
        TMouseButton Button,  // 觸發事件的滑鼠按鍵。
        TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
        int X,  // 滑鼠或拖曳位置的 X 座標。
        int Y  // 滑鼠或拖曳位置的 Y 座標。
    );
    // 處理繪圖或載入進度通知事件。
    virtual void __fastcall On_Progress(TObject *Sender,  // 觸發事件的元件。
        TProgressStage Stage,  // 目前進度通知所處的階段。
        BYTE PercentDone,  // 目前完成百分比。
        bool RedrawNow,  // 是否需要立即重繪。
        const TRect &R,  // 目前進度對應的矩形範圍。
        const UnicodeString Msg
    );
	// 處理重繪事件。
	virtual void __fastcall On_Paint(TObject *Sender);
    // 處理尺寸變更完成事件。
    virtual void __fastcall On_Resize(TObject *Sender);
    // 處理 dock 開始事件，可建立拖曳物件。
    virtual void __fastcall On_Start_Dock(TObject *Sender,  // 觸發事件的元件。
        TDragDockObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 處理拖曳開始事件，可建立拖曳物件。
    virtual void __fastcall On_Start_Drag(TObject *Sender,  // 觸發事件的元件。
        TDragObject *&DragObject  // 要建立或傳出的拖曳物件。
    );
    // 處理取消 dock 事件，可決定是否允許分離。
    virtual void __fastcall On_Un_Dock(TObject *Sender,  // 觸發事件的元件。
        TControl *Client,  // 要從 docking 中分離的控制項。
        TWinControl *NewTarget,  // 新的 docking 目標。
        bool &Allow  // 是否允許這次操作。
    );
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    //---------------------------------------------------------------------------
    //TScrollBar
    //---------------------------------------------------------------------------
//    virtual void __fastcall On_Vertical_Bar_Change(TObject *Sender);
//    //---------------------------------------------------------------------------
//    virtual void __fastcall On_Horizontal_Bar_Change(TObject *Sender);
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
public:

public:

public:

public:
    // 指向自己的物件
    hahaha_image_view* Image_View_;
};



//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------



#endif
