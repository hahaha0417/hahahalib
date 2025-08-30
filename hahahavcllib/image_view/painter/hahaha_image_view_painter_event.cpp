//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_image_view_painter_event.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_painter_event::hahaha_image_view_painter_event()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_event::~hahaha_image_view_painter_event()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_painter_event::hahaha_image_view_painter_event(const hahaha_image_view_painter_event& hivpe)
{
    Reset();
	Copy(hivpe);
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_event::hahaha_image_view_painter_event(hahaha_image_view_painter_event&& hivpe)
{
    Move(std::move(hivpe));
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_event& hahaha_image_view_painter_event::operator=(const hahaha_image_view_painter_event& hivpe)
{
	Copy(hivpe);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_painter_event& hahaha_image_view_painter_event::operator=(hahaha_image_view_painter_event&& hivpe)
{
	if (this != &hivpe)
    {
        Move(std::move(hivpe));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_painter_event::Copy(const hahaha_image_view_painter_event& hivpe)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view_painter_event::Move(hahaha_image_view_painter_event&& hivpe)
{


}
//---------------------------------------------------------------------------
int hahaha_image_view_painter_event::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
// begin
//-----------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Insert_Before_Begin(hahahalib::hahaha_image_view& image_view,
	bool& result,
    TWinControl *Sender,
    TControl *C1,
    TControl *C2
)
{
    // https://docwiki.embarcadero.com/Libraries/Sydney/en/Vcl.Controls.TAlignInsertBeforeEvent
    // returns true if C2 should be presented before C1, and false otherwise.
    // C1
    // First control to be ordered.
    // C2
    // Second control to be ordered
    result = false;

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Position_Begin(hahahalib::hahaha_image_view& image_view,
    TWinControl *Sender,
    TControl *Control,
    int &NewLeft,
    int &NewTop,
    int &NewWidth,
    int &NewHeight,
    TRect &AlignRect,
    const TAlignInfo &AlignInfo
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Can_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &NewWidth,
    int &NewHeight,
    bool &Resize
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Click_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Constrained_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &MinWidth,
    int &MinHeight,
    int &MaxWidth,
    int &MaxHeight
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Context_Popup_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TPoint &MousePos,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_DblClick_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Over_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Drop_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Over_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Find_Graphic_Class_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TFindGraphicClassContext &Context,
    TGraphicClass &GraphicClass
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Exit_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Gesture_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TGestureEventInfo &EventInfo,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Get_Site_Info_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *DockClient,
    TRect &InfluenceRect,
    const TPoint &MousePos,
    bool &CanDock
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Activate_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y,
    int HitTest,
    TMouseActivate &MouseActivate
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Down_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Enter_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Leave_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Move_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Up_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Progress_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TProgressStage Stage,
    BYTE PercentDone,
    bool RedrawNow,
    const TRect &R,
    const UnicodeString Msg
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Resize_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Drag_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Un_Dock_Begin(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *Client,
    TWinControl *NewTarget,
    bool &Allow
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_Begin(hahahalib::hahaha_image_view& image_view)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//-----------------------------------
// Vertical_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Vertical_Bar_Change_Begin(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------
//-----------------------------------
// Horizontal_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Horizontal_Bar_Change_Begin(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// design
//-----------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Insert_Before_Design(hahahalib::hahaha_image_view& image_view,
	bool& result,
    TWinControl *Sender,
    TControl *C1,
    TControl *C2
)
{
    // https://docwiki.embarcadero.com/Libraries/Sydney/en/Vcl.Controls.TAlignInsertBeforeEvent
    // returns true if C2 should be presented before C1, and false otherwise.
    // C1
    // First control to be ordered.
    // C2
    // Second control to be ordered
    result = false;

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Position_Design(hahahalib::hahaha_image_view& image_view,
    TWinControl *Sender,
    TControl *Control,
    int &NewLeft,
    int &NewTop,
    int &NewWidth,
    int &NewHeight,
    TRect &AlignRect,
    const TAlignInfo &AlignInfo
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Can_Resize_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &NewWidth,
    int &NewHeight,
    bool &Resize
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Click_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Constrained_Resize_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &MinWidth,
    int &MinHeight,
    int &MaxWidth,
    int &MaxHeight
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Context_Popup_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TPoint &MousePos,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_DblClick_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Drop_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Over_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Drop_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Over_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Dock_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Drag_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Find_Graphic_Class_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TFindGraphicClassContext &Context,
    TGraphicClass &GraphicClass
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Enter_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Exit_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Gesture_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TGestureEventInfo &EventInfo,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Get_Site_Info_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *DockClient,
    TRect &InfluenceRect,
    const TPoint &MousePos,
    bool &CanDock
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Activate_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y,
    int HitTest,
    TMouseActivate &MouseActivate
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Down_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Enter_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Leave_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Move_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Up_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Progress_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TProgressStage Stage,
    BYTE PercentDone,
    bool RedrawNow,
    const TRect &R,
    const UnicodeString Msg
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Resize_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Dock_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Drag_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Un_Dock_Design(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *Client,
    TWinControl *NewTarget,
    bool &Allow
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_Design(hahahalib::hahaha_image_view& image_view)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//-----------------------------------
// Vertical_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Vertical_Bar_Change_Design(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------
//-----------------------------------
// Horizontal_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Horizontal_Bar_Change_Design(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// end
//-----------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Insert_Before_End(hahahalib::hahaha_image_view& image_view,
	bool& result,
    TWinControl *Sender,
    TControl *C1,
    TControl *C2
)
{
    // https://docwiki.embarcadero.com/Libraries/Sydney/en/Vcl.Controls.TAlignInsertBeforeEvent
    // returns true if C2 should be presented before C1, and false otherwise.
    // C1
    // First control to be ordered.
    // C2
    // Second control to be ordered
    result = false;

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Align_Position_End(hahahalib::hahaha_image_view& image_view,
    TWinControl *Sender,
    TControl *Control,
    int &NewLeft,
    int &NewTop,
    int &NewWidth,
    int &NewHeight,
    TRect &AlignRect,
    const TAlignInfo &AlignInfo
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Can_Resize_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &NewWidth,
    int &NewHeight,
    bool &Resize
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Click_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Constrained_Resize_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    int &MinWidth,
    int &MinHeight,
    int &MaxWidth,
    int &MaxHeight
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Context_Popup_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TPoint &MousePos,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_DblClick_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Drop_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Dock_Over_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Drop_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Drag_Over_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Dock_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_End_Drag_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TObject *Target,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Find_Graphic_Class_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TFindGraphicClassContext &Context,
    TGraphicClass &GraphicClass
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Enter_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Exit_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Gesture_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    const TGestureEventInfo &EventInfo,
    bool &Handled
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Get_Site_Info_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *DockClient,
    TRect &InfluenceRect,
    const TPoint &MousePos,
    bool &CanDock
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Activate_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y,
    int HitTest,
    TMouseActivate &MouseActivate
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Down_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Enter_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Leave_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Move_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Mouse_Up_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Progress_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TProgressStage Stage,
    BYTE PercentDone,
    bool RedrawNow,
    const TRect &R,
    const UnicodeString Msg
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Resize_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Dock_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragDockObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Start_Drag_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TDragObject *&DragObject
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Un_Dock_End(hahahalib::hahaha_image_view& image_view,
    TObject *Sender,
    TControl *Client,
    TWinControl *NewTarget,
    bool &Allow
)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
halib_def::image_view_result hahaha_image_view_painter_event::On_Paint_End(hahahalib::hahaha_image_view& image_view)
{

    return halib_def::image_view_result::SUCCESS;
}
//---------------------------------------------------------------------------
//-----------------------------------
// Vertical_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Vertical_Bar_Change_End(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------
//-----------------------------------
// Horizontal_Bar
//-----------------------------------
//---------------------------------------------------------------------------
//halib_def::image_view_result hahaha_image_view_painter_event::On_Horizontal_Bar_Change_End(hahahalib::hahaha_image_view& image_view,
//    TObject *Sender
//)
//{
//
//    return halib_def::image_view_result::SUCCESS;
//}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------