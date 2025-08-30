//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <define\hahaha_define_result.h>
//---------------------------------------------------------------------------
#include <image_view\hahaha_form_image_view.h>
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
#include "hahaha_form_image_view_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
int Thahaha_image_view_form::Set_Image_View(hahahalib::hahaha_image_view* image_view)
{
    //---------------------------------------------------------------------------
    Image_View_ = image_view;
    //---------------------------------------------------------------------------
    Image_View_->Form_Image_View_ = this;
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    //TImage - view_image
    //---------------------------------------------------------------------------
    //OnClick
    view_image->OnClick = Image_View_->On_Click;
    //OnContextPopup
    view_image->OnContextPopup = Image_View_->On_Context_Popup;
    //OnDblClick
    view_image->OnDblClick = Image_View_->On_DblClick;
    //OnDragDrop
    view_image->OnDragDrop = Image_View_->On_Drag_Drop;
    //OnDragOver
    view_image->OnDragOver = Image_View_->On_Drag_Over;
    //OnEndDock
    view_image->OnEndDock = Image_View_->On_End_Dock;
    //OnEndDrag
    view_image->OnEndDrag = Image_View_->On_End_Drag;
    //OnFindGraphicClass
    view_image->OnFindGraphicClass = Image_View_->On_Find_Graphic_Class;
    //OnGesture
    view_image->OnGesture = Image_View_->On_Gesture;
    //OnMouseActivate
    view_image->OnMouseActivate = Image_View_->On_Mouse_Activate;
    //OnMouseDown
    view_image->OnMouseDown = Image_View_->On_Mouse_Down;
    //OnMouseEnter
    view_image->OnMouseEnter = Image_View_->On_Mouse_Enter;
    //OnMouseLeave
    view_image->OnMouseLeave = Image_View_->On_Mouse_Leave;
    //OnMouseMove
    view_image->OnMouseMove = Image_View_->On_Mouse_Move;
    //OnMouseUp
    view_image->OnMouseUp = Image_View_->On_Mouse_Up;
    //OnProgress
    view_image->OnProgress = Image_View_->On_Progress;
    //OnStartDock
    view_image->OnStartDock = Image_View_->On_Start_Dock;
    //OnStartDrag
    view_image->OnStartDrag = Image_View_->On_Start_Drag;
    //---------------------------------------------------------------------------
    //TScrollBar - horizontal_bar
    //---------------------------------------------------------------------------
//    //OnChange
//    horizontal_bar->OnChange = Image_View_->On_Horizontal_Bar_Change;
//    //OnContextPopup
//    horizontal_bar->OnContextPopup = NULL;
//    //OnDragDrop
//    horizontal_bar->OnDragDrop = NULL;
//    //OnDragOver
//    horizontal_bar->OnDragOver = NULL;
//    //OnEndDock
//    horizontal_bar->OnEndDock = NULL;
//    //OnEndDrag
//    horizontal_bar->OnEndDrag = NULL;
//    //OnEnter
//    horizontal_bar->OnEnter = NULL;
//    //OnExit
//    horizontal_bar->OnExit = NULL;
//    //OnKeyDown
//    horizontal_bar->OnKeyDown = NULL;
//    //OnKeyPress
//    horizontal_bar->OnKeyPress = NULL;
//    //OnKeyUp
//    horizontal_bar->OnKeyUp = NULL;
//    //OnMouseEnter
//    horizontal_bar->OnMouseEnter = NULL;
//    //OnMouseLeave
//    horizontal_bar->OnMouseLeave = NULL;
//    //OnScroll
//    horizontal_bar->OnScroll = NULL;
//    //OnStartDock
//    horizontal_bar->OnStartDock = NULL;
//    //OnStartDrag
//    horizontal_bar->OnStartDrag = NULL;
    //---------------------------------------------------------------------------
    //TScrollBar - vertical_bar
    //---------------------------------------------------------------------------
//    //OnChange
//    vertical_bar->OnChange = Image_View_->On_Vertical_Bar_Change;
//    //OnContextPopup
//    vertical_bar->OnContextPopup = NULL;
//    //OnDragDrop
//    vertical_bar->OnDragDrop = NULL;
//    //OnDragOver
//    vertical_bar->OnDragOver = NULL;
//    //OnEndDock
//    vertical_bar->OnEndDock = NULL;
//    //OnEndDrag
//    vertical_bar->OnEndDrag = NULL;
//    //OnEnter
//    vertical_bar->OnEnter = NULL;
//    //OnExit
//    vertical_bar->OnExit = NULL;
//    //OnKeyDown
//    vertical_bar->OnKeyDown = NULL;
//    //OnKeyPress
//    vertical_bar->OnKeyPress = NULL;
//    //OnKeyUp
//    vertical_bar->OnKeyUp = NULL;
//    //OnMouseEnter
//    vertical_bar->OnMouseEnter = NULL;
//    //OnMouseLeave
//    vertical_bar->OnMouseLeave = NULL;
//    //OnScroll
//    vertical_bar->OnScroll = NULL;
//    //OnStartDock
//    vertical_bar->OnStartDock = NULL;
//    //OnStartDrag
//    vertical_bar->OnStartDrag = NULL;
    //---------------------------------------------------------------------------

    view_image->Visible = true;

    //---------------------------------------------------------------------------
    Image_View_->Canvas_ = view_image->Canvas;

    return 0;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
