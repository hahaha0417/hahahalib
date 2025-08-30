//---------------------------------------------------------------------------

#ifndef hahaha_define_vcl_eventH
#define hahaha_define_vcl_eventH
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
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace vcl
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace event
{
//---------------------------------------------------------------------------
bool __fastcall (*OnAlignInsertBefore)(TWinControl *Sender,
    TControl *C1,
    TControl *C2
);
//---------------------------------------------------------------------------

void __fastcall (*OnAlignPosition)(TWinControl *Sender,
    TControl *Control,
    int &NewLeft,
    int &NewTop,
    int &NewWidth,
    int &NewHeight,
    TRect &AlignRect,
    const TAlignInfo &AlignInfo
);
//---------------------------------------------------------------------------

void __fastcall (*OnCanResize)(TObject *Sender,
	int &NewWidth,
	int &NewHeight,
    bool &Resize
);
//---------------------------------------------------------------------------

void __fastcall (*OnClick)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnConstrainedResize)(TObject *Sender,
	int &MinWidth,
    int &MinHeight,
    int &MaxWidth,
    int &MaxHeight
);

//---------------------------------------------------------------------------

void __fastcall (*OnChange)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnContextPopup)(TObject *Sender,
	const TPoint &MousePos,
    bool &Handled
);
//---------------------------------------------------------------------------

void __fastcall (*OnDblClick)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnDockDrop)(TObject *Sender,
	TDragDockObject *Source,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnDockOver)(TObject *Sender,
	TDragDockObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
);
//---------------------------------------------------------------------------

void __fastcall (*OnDragDrop)(TObject *Sender,
	TObject *Source,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnDragOver)(TObject *Sender,
	TObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
);
//---------------------------------------------------------------------------

void __fastcall (*OnEndDock)(TObject *Sender,
	TObject *Target,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnEndDrag)(TObject *Sender,
	TObject *Target,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnFindGraphicClass)(TObject *Sender,
	const TFindGraphicClassContext &Context,
    TGraphicClass &GraphicClass
);
//---------------------------------------------------------------------------

void __fastcall (*OnEnter)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnExit)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnGesture)(TObject *Sender,
	const TGestureEventInfo &EventInfo,
    bool &Handled
);

//---------------------------------------------------------------------------

void __fastcall (*OnGetSiteInfo)(TObject *Sender,
	TControl *DockClient,
    TRect &InfluenceRect,
    const TPoint &MousePos,
    bool &CanDock
);

//---------------------------------------------------------------------------

void __fastcall (*OnKeyDown)(TObject *Sender,
	WORD &Key,
    TShiftState Shift
);
//---------------------------------------------------------------------------

void __fastcall (*OnKeyPress)(TObject *Sender,
	System::WideChar &Key
);
//---------------------------------------------------------------------------

void __fastcall (*OnKeyUp)(TObject *Sender,
	WORD &Key,
	TShiftState Shift
);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseActivate)(TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y,
    int HitTest,
    TMouseActivate &MouseActivate
);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseDown)(TObject *Sender,
	TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseEnter)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseLeave)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseMove)(TObject *Sender,
	TShiftState Shift,
    int X,
    int Y
);
//---------------------------------------------------------------------------

void __fastcall (*OnMouseUp)(TObject *Sender,
	TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
);

//---------------------------------------------------------------------------
void __fastcall (*OnProgress)(TObject *Sender,
	TProgressStage Stage,
    BYTE PercentDone,
    bool RedrawNow,
    const TRect &R,
    const UnicodeString Msg
);
//---------------------------------------------------------------------------

void __fastcall (*OnPaint)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnResize)(TObject *Sender);
//---------------------------------------------------------------------------

void __fastcall (*OnScroll)(TObject *Sender,
	TScrollCode ScrollCode,
    int &ScrollPos
);
//---------------------------------------------------------------------------

void __fastcall (*OnStartDock)(TObject *Sender,
	TDragDockObject *&DragObject
);
//---------------------------------------------------------------------------

void __fastcall (*OnStartDrag)(TObject *Sender,
	TDragObject *&DragObject
);
//---------------------------------------------------------------------------

void __fastcall (*OnUnDock)(TObject *Sender,
	TControl *Client,
    TWinControl *NewTarget,
    bool &Allow
);
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
//---------------------------------------------------------------------------



























//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // event
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // vcl
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
namespace hadef
{
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hadef
//---------------------------------------------------------------------------


#endif
