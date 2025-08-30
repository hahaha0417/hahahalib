//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <image_view\hahaha_form_image_view.h>
#include "hahaha_form_image_view_initial.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
void Thahaha_image_view_form::Initial()
{
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    Initial_Layout();
    Initial_Color();
    //---------------------------------------------------------------------------
}
//---------------------------------------------------------------------------
void Thahaha_image_view_form::Initial_Layout()
{
    //---------------------------------------------------------------------------
    MainBox->BorderStyle = bsNone;
    MainBox->Align = alClient;

    ShowInTaskBar = true;
    CustomTitleBar->Enabled = true;
    //---------------------------------------------------------------------------
    BodyBox->BorderStyle = bsNone;
    BodyBox->Align = alClient;
    TopBox->BorderStyle = bsNone;
    TopBox->Align = alTop;
    Splitter_Top->Align = alTop;
    BodyBodyBox->BorderStyle = bsNone;
    BodyBodyBox->Align = alClient;
    Splitter_Bottom->Align = alBottom;
    BottomBox->BorderStyle = bsNone;
    BottomBox->Align = alBottom;
    LeftBox->BorderStyle = bsNone;
    LeftBox->Align = alLeft;
    Splitter_Left->Align = alLeft;
    BodyMainBox->BorderStyle = bsNone;
    BodyMainBox->Align = alClient;
    Splitter_Right->Align = alRight;
    RightBox->BorderStyle = bsNone;
    RightBox->Align = alRight;
    //---------------------------------------------------------------------------
    BodyBox->Parent = MainBox;

    view_box->Parent = BodyMainBox;
    view_box->Align = alClient;
    view_box->BorderStyle = bsNone;


    view_bottom_box->Align = alBottom;
    view_main_box->Align = alClient;

    view_bottom_box->BorderStyle = bsNone;
    view_main_box->BorderStyle = bsNone;

    vertical_box->Align = alRight;
    main_box->Align = alClient;
    corner_box->Align = alRight;
    horizontal_box->Align = alClient;

    vertical_box->BorderStyle = bsNone;
    main_box->BorderStyle = bsNone;
    corner_box->BorderStyle = bsNone;
    horizontal_box->BorderStyle = bsNone;

    horizontal_bar->Align = alClient;
    vertical_bar->Align = alClient;

    corner_box->Width = 30;
    vertical_box->Width = 30;
    view_bottom_box->Height = 30;


    view_image->Align = alClient;

    //---------------------------------------------------------------------------
    TopBox->Visible = false;
    LeftBox->Visible = false;
    RightBox->Visible = false;

    BottomBox->Height = 45;
    Splitter_Top->Height = 5;
    Splitter_Bottom->Height = 5;
    Splitter_Left->Width = 5;
    Splitter_Right->Width = 5;

    Splitter_Top->Visible = false;
    // Splitter_Bottom->Visible = false;
    Splitter_Left->Visible = false;
    Splitter_Right->Visible = false;

    TopBox->Constraints->MinWidth = 1;
    LeftBox->Constraints->MinWidth = 1;
    RightBox->Constraints->MinWidth = 1;
    BottomBox->Constraints->MinWidth = 1;

    TopBox->Constraints->MinHeight = 1;
    LeftBox->Constraints->MinHeight = 1;
    RightBox->Constraints->MinHeight = 1;
    BottomBox->Constraints->MinHeight = 1;
    //---------------------------------------------------------------------------
    Panel_X->ParentBackground = false;
    Panel_Y->ParentBackground = false;
    Panel_R->ParentBackground = false;
    Panel_G->ParentBackground = false;
    Panel_B->ParentBackground = false;
    Panel_Time->ParentBackground = false;


    Panel_X->BevelOuter = bvNone;
    Panel_Y->BevelOuter = bvNone;
    Panel_R->BevelOuter = bvNone;
    Panel_G->BevelOuter = bvNone;
    Panel_B->BevelOuter = bvNone;
    Panel_Time->BevelOuter = bvNone;
    //---------------------------------------------------------------------------

    horizontal_bar->Min = 0;
    horizontal_bar->Max = 2;
    horizontal_bar->LargeChange = 1;
    horizontal_bar->SmallChange = 1;
    horizontal_bar->Position = 1;
    horizontal_bar->Enabled = false;


    vertical_bar->Min = 0;
    vertical_bar->Max = 2;
    vertical_bar->LargeChange = 1;
    vertical_bar->SmallChange = 1;
    vertical_bar->Position = 1;
    vertical_bar->Enabled = false;

//    main_box->DoubleBuffered = true;
    view_box->DoubleBuffered = true;
//    DoubleBuffered = true;
//    TitleBarPanel->DoubleBuffered = true;
	BottomBox->HorzScrollBar->Visible = false;
    BottomBox->VertScrollBar->Visible = false;
    //---------------------------------------------------------------------------

}
//---------------------------------------------------------------------------
void Thahaha_image_view_form::Initial_Color()
{
    //---------------------------------------------------------------------------
    CustomTitleBar->BackgroundColor = (TColor)RGB(190, 255, 190);
    CustomTitleBar->InactiveBackgroundColor = (TColor)RGB(210, 255, 210);


    BottomBox->ParentColor = false;



//    main_box->Color = (TColor)RGB(50, 50, 50);
    BottomBox->Color = (TColor)RGB(50, 50, 50);
    //---------------------------------------------------------------------------
    Splitter_Top->Color = (TColor)RGB(190, 255, 190);
    Splitter_Bottom->Color = (TColor)RGB(190, 255, 190);
    Splitter_Left->Color = (TColor)RGB(190, 255, 190);
    Splitter_Right->Color = (TColor)RGB(190, 255, 190);
    //---------------------------------------------------------------------------
    Panel_X->ParentColor = false;
    Panel_Y->ParentColor = false;
    Panel_R->ParentColor = false;
    Panel_G->ParentColor = false;
    Panel_B->ParentColor = false;
    Panel_Time->ParentColor = false;

    Panel_X->Color = (TColor)RGB(190, 255, 190);
    Panel_Y->Color = (TColor)RGB(190, 255, 190);
    Panel_R->Color = (TColor)RGB(190, 255, 190);
    Panel_G->Color = (TColor)RGB(190, 255, 190);
    Panel_B->Color = (TColor)RGB(190, 255, 190);
    Panel_Time->Color = (TColor)RGB(190, 255, 190);
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

}