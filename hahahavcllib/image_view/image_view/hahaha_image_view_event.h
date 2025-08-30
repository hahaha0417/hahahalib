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
	hahaha_image_view_event();
	~hahaha_image_view_event();

	hahaha_image_view_event(const hahaha_image_view_event& hive);
    hahaha_image_view_event(hahaha_image_view_event&& hive) noexcept;
	hahaha_image_view_event& operator=(const hahaha_image_view_event& hive);
    hahaha_image_view_event& operator=(hahaha_image_view_event&& hive) noexcept;
	void Copy(const hahaha_image_view_event& hive);
    void Move(hahaha_image_view_event&& hive) noexcept;
public:
	int Reset();

	//---------------------------------------------------------------------------
    // event
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    virtual bool __fastcall On_Align_Insert_Before(TWinControl *Sender,
        TControl *C1,
        TControl *C2
    );
    virtual void __fastcall On_Align_Position(TWinControl *Sender,
        TControl *Control,
        int &NewLeft,
        int &NewTop,
        int &NewWidth,
        int &NewHeight,
        TRect &AlignRect,
        const TAlignInfo &AlignInfo
    );
    virtual void __fastcall On_Can_Resize(TObject *Sender,
        int &NewWidth,
        int &NewHeight,
        bool &Resize
    );
    virtual void __fastcall On_Click(TObject *Sender);
    virtual void __fastcall On_Constrained_Resize(TObject *Sender,
        int &MinWidth,
        int &MinHeight,
        int &MaxWidth,
        int &MaxHeight
    );
    virtual void __fastcall On_Context_Popup(TObject *Sender,
        const TPoint &MousePos,
        bool &Handled
    );
    virtual void __fastcall On_DblClick(TObject *Sender);
    virtual void __fastcall On_Dock_Drop(TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y
    );
    virtual void __fastcall On_Dock_Over(TObject *Sender,
        TDragDockObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual void __fastcall On_Drag_Drop(TObject *Sender,
        TObject *Source,
        int X,
        int Y
    );
    virtual void __fastcall On_Drag_Over(TObject *Sender,
        TObject *Source,
        int X,
        int Y,
        TDragState State,
        bool &Accept
    );
    virtual void __fastcall On_End_Dock(TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual void __fastcall On_End_Drag(TObject *Sender,
        TObject *Target,
        int X,
        int Y
    );
    virtual void __fastcall On_Find_Graphic_Class(TObject *Sender,
        const TFindGraphicClassContext &Context,
        TGraphicClass &GraphicClass
    );
    virtual void __fastcall On_Enter(TObject *Sender);
    virtual void __fastcall On_Exit(TObject *Sender);
    virtual void __fastcall On_Gesture(TObject *Sender,
        const TGestureEventInfo &EventInfo,
        bool &Handled
    );
    virtual void __fastcall On_Get_Site_Info(TObject *Sender,
        TControl *DockClient,
        TRect &InfluenceRect,
        const TPoint &MousePos,
        bool &CanDock
    );
    virtual void __fastcall On_Mouse_Activate(TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y,
        int HitTest,
        TMouseActivate &MouseActivate
    );
    virtual void __fastcall On_Mouse_Down(TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual void __fastcall On_Mouse_Enter(TObject *Sender);
    virtual void __fastcall On_Mouse_Leave(TObject *Sender);
    virtual void __fastcall On_Mouse_Move(TObject *Sender,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual void __fastcall On_Mouse_Up(TObject *Sender,
        TMouseButton Button,
        TShiftState Shift,
        int X,
        int Y
    );
    virtual void __fastcall On_Progress(TObject *Sender,
        TProgressStage Stage,
        BYTE PercentDone,
        bool RedrawNow,
        const TRect &R,
        const UnicodeString Msg
    );
	virtual void __fastcall On_Paint(TObject *Sender);
    virtual void __fastcall On_Resize(TObject *Sender);
    virtual void __fastcall On_Start_Dock(TObject *Sender,
        TDragDockObject *&DragObject
    );
    virtual void __fastcall On_Start_Drag(TObject *Sender,
        TDragObject *&DragObject
    );
    virtual void __fastcall On_Un_Dock(TObject *Sender,
        TControl *Client,
        TWinControl *NewTarget,
        bool &Allow
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
