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
	hahaha_image_view_painter_event();
	~hahaha_image_view_painter_event();

	hahaha_image_view_painter_event(const hahaha_image_view_painter_event& hivpe);
    hahaha_image_view_painter_event(hahaha_image_view_painter_event&& hivpe);
	hahaha_image_view_painter_event& operator=(const hahaha_image_view_painter_event& hivpe);
    hahaha_image_view_painter_event& operator=(hahaha_image_view_painter_event&& hivpe);
	void Copy(const hahaha_image_view_painter_event& hivpe);
    void Move(hahaha_image_view_painter_event&& hivpe);
public:
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
    	TWinControl *Sender,
        TControl *C1,
        TControl *C2
    );
    virtual halib_def::image_view_result On_Align_Position_Begin(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,
        TControl *Control,
        int &NewLeft,
        int &NewTop,
        int &NewWidth,
        int &NewHeight,
        TRect &AlignRect,
        const TAlignInfo &AlignInfo
    );
    virtual halib_def::image_view_result On_Can_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &NewWidth,
        int &NewHeight,
        bool &Resize
    );
    virtual halib_def::image_view_result On_Click_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Constrained_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &MinWidth,
        int &MinHeight,
        int &MaxWidth,
        int &MaxHeight
    );
    virtual halib_def::image_view_result On_Context_Popup_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TPoint &MousePos,
        bool &Handled
    );
    virtual halib_def::image_view_result On_DblClick_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Dock_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Dock_Over_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_Drag_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Drag_Over_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_End_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_End_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Find_Graphic_Class_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TFindGraphicClassContext &Context,
        TGraphicClass &GraphicClass
    );
    virtual halib_def::image_view_result On_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Exit_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Gesture_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TGestureEventInfo &EventInfo,
        bool &Handled
    );
    virtual halib_def::image_view_result On_Get_Site_Info_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *DockClient,
        TRect &InfluenceRect,
        const TPoint &MousePos,
        bool &CanDock
    );
    virtual halib_def::image_view_result On_Mouse_Activate_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y,
        int HitTest,
        TMouseActivate &MouseActivate
    );
    virtual halib_def::image_view_result On_Mouse_Down_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Leave_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Move_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Up_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Progress_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TProgressStage Stage,
        BYTE PercentDone,
        bool RedrawNow,
        const TRect &R,
        const UnicodeString Msg
    );
	virtual halib_def::image_view_result On_Paint_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Start_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *&DragObject
    );
    virtual halib_def::image_view_result On_Start_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragObject *&DragObject
    );
    virtual halib_def::image_view_result On_Un_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *Client,
        TWinControl *NewTarget,
        bool &Allow
    );
    //
    virtual halib_def::image_view_result On_Paint_Begin(hahahalib::hahaha_image_view& image_view);

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
    	TWinControl *Sender,
        TControl *C1,
        TControl *C2
    );
    virtual halib_def::image_view_result On_Align_Position_Design(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,
        TControl *Control,
        int &NewLeft,
        int &NewTop,
        int &NewWidth,
        int &NewHeight,
        TRect &AlignRect,
        const TAlignInfo &AlignInfo
    );
    virtual halib_def::image_view_result On_Can_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &NewWidth,
        int &NewHeight,
        bool &Resize
    );
    virtual halib_def::image_view_result On_Click_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Constrained_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &MinWidth,
        int &MinHeight,
        int &MaxWidth,
        int &MaxHeight
    );
    virtual halib_def::image_view_result On_Context_Popup_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TPoint &MousePos,
        bool &Handled
    );
    virtual halib_def::image_view_result On_DblClick_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Dock_Drop_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Dock_Over_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_Drag_Drop_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Drag_Over_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_End_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_End_Drag_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Find_Graphic_Class_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TFindGraphicClassContext &Context,
        TGraphicClass &GraphicClass
    );
    virtual halib_def::image_view_result On_Enter_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Exit_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Gesture_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TGestureEventInfo &EventInfo,
        bool &Handled
    );
    virtual halib_def::image_view_result On_Get_Site_Info_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *DockClient,
        TRect &InfluenceRect,
        const TPoint &MousePos,
        bool &CanDock
    );
    virtual halib_def::image_view_result On_Mouse_Activate_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y,
        int HitTest,
        TMouseActivate &MouseActivate
    );
    virtual halib_def::image_view_result On_Mouse_Down_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Enter_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Leave_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Move_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Up_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Progress_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TProgressStage Stage,
        BYTE PercentDone,
        bool RedrawNow,
        const TRect &R,
        const UnicodeString Msg
    );
	virtual halib_def::image_view_result On_Paint_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Resize_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Start_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *&DragObject
    );
    virtual halib_def::image_view_result On_Start_Drag_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragObject *&DragObject
    );
    virtual halib_def::image_view_result On_Un_Dock_Design(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *Client,
        TWinControl *NewTarget,
        bool &Allow
    );
    //
    virtual halib_def::image_view_result On_Paint_Design(hahahalib::hahaha_image_view& image_view);
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
    	TWinControl *Sender,
        TControl *C1,
        TControl *C2
    );
    virtual halib_def::image_view_result On_Align_Position_End(hahahalib::hahaha_image_view& image_view,
    	TWinControl *Sender,
        TControl *Control,
        int &NewLeft,
        int &NewTop,
        int &NewWidth,
        int &NewHeight,
        TRect &AlignRect,
        const TAlignInfo &AlignInfo
    );
    virtual halib_def::image_view_result On_Can_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &NewWidth,
        int &NewHeight,
        bool &Resize
    );
    virtual halib_def::image_view_result On_Click_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Constrained_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        int &MinWidth,
        int &MinHeight,
        int &MaxWidth,
        int &MaxHeight
    );
    virtual halib_def::image_view_result On_Context_Popup_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TPoint &MousePos,
        bool &Handled
    );
    virtual halib_def::image_view_result On_DblClick_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Dock_Drop_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Dock_Over_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_Drag_Drop_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Drag_Over_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual halib_def::image_view_result On_End_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_End_Drag_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Find_Graphic_Class_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TFindGraphicClassContext &Context,
        TGraphicClass &GraphicClass
    );
    virtual halib_def::image_view_result On_Enter_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Exit_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Gesture_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        const TGestureEventInfo &EventInfo,
        bool &Handled
    );
    virtual halib_def::image_view_result On_Get_Site_Info_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *DockClient,
        TRect &InfluenceRect,
        const TPoint &MousePos,
        bool &CanDock
    );
    virtual halib_def::image_view_result On_Mouse_Activate_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y,
        int HitTest,
        TMouseActivate &MouseActivate
    );
    virtual halib_def::image_view_result On_Mouse_Down_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Enter_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Leave_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Mouse_Move_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Mouse_Up_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual halib_def::image_view_result On_Progress_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TProgressStage Stage,
        BYTE PercentDone,
        bool RedrawNow,
        const TRect &R,
        const UnicodeString Msg
    );
	virtual halib_def::image_view_result On_Paint_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Resize_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender
    );
    virtual halib_def::image_view_result On_Start_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragDockObject *&DragObject
    );
    virtual halib_def::image_view_result On_Start_Drag_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TDragObject *&DragObject
    );
    virtual halib_def::image_view_result On_Un_Dock_End(hahahalib::hahaha_image_view& image_view,
    	TObject *Sender,
        TControl *Client,
        TWinControl *NewTarget,
        bool &Allow
    );
    //
    virtual halib_def::image_view_result On_Paint_End(hahahalib::hahaha_image_view& image_view);
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
