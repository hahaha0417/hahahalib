//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
#include <timer\hahaha_timer_high_precision.h>
#include <image_view\hahaha_image_view.h>
//---------------------------------------------------------------------------
#include <System.SysUtils.hpp>

#include "hahaha_form_image_view.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
// 要這樣加，編輯器才會出現，應該是Bug
#if defined(DESIGNED_DFM)
	#pragma resource "*.dfm"                // 讓 IDE 找得到設計檔
#else
	#pragma resource "hahaha_form_image_view.dfm"
#endif

//#pragma resource "*.dfm"
Thahaha_image_view_form *hahaha_image_view_form;
//---------------------------------------------------------------------------
__fastcall Thahaha_image_view_form::Thahaha_image_view_form(TComponent* Owner)
	: TForm(Owner)
{

    //---------------------------------------------------------------------------
    Image_View_ = nullptr;
    //---------------------------------------------------------------------------

    if(Timer_.get() == NULL)
    {
        Timer_.reset(new hahahalib::hahaha_timer_high_precision);
    }


    Initial();
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------




    
    //---------------------------------------------------------------------------
    PageControl1->Visible = false;
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall Thahaha_image_view_form::Image_Title_IconMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
	{
		ReleaseCapture();
		PostMessage( Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::Label_TitleMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
	{
		ReleaseCapture();
		PostMessage( Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::Image_Title_BackgroundMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button == mbLeft)
	{
		ReleaseCapture();
		PostMessage( Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::Button_MinClick(TObject *Sender)
{
    PostMessage( Handle, WM_SYSCOMMAND, SC_MINIMIZE, 0);
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::Button_MaxClick(TObject *Sender)
{
    if(WindowState == wsNormal)
	{
		WindowState = wsMaximized;
	}
	else if(WindowState == wsMaximized)
	{
		WindowState = wsNormal;
	}
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::ButtonCloseClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::main_boxResize(TObject *Sender)
{
    if(Image_View_ != NULL)
    {
        // 重新繪製(包含縮圖)
        Image_View_->Is_View_Thumbnail_ = false;
        Image_View_->Is_Repaint_ = true;
        Image_View_->Update_UI();
        Image_View_->Repaint();
    }

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::view_ratioChange(TObject *Sender)
{
    if(Image_View_ == NULL)
    {
        return;
    }
	if(Image_View_->Bitmap_ == NULL)
    {
        return;
	}
    if(Image_View_->Is_Update_Ui_)
    {
        return;
    }
    if(view_ratio->Text == L"全部")
    {
        Image_View_->Is_View_Bitmap_Full_ = true;
		Image_View_->Is_View_Thumbnail_ = false;
		Image_View_->Is_Update_Scrollbar_Position_Center_ = false;
        Image_View_->Is_Repaint_ = true;

		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2
		);

        Image_View_->Update_UI();
        Image_View_->Repaint();
        view_image->Repaint();

    }
    else
    {
        Image_View_->Is_View_Bitmap_Full_ = false;
        Image_View_->View_Ratio_ = StringReplace(view_ratio->Text, L"%", L"", TReplaceFlags() << rfReplaceAll).ToDouble() / 100;
		Image_View_->Is_View_Thumbnail_ = false;
		Image_View_->Is_Update_Scrollbar_Position_Center_ = false;
        Image_View_->Is_Repaint_ = true;
        Image_View_->Update_UI();
        Image_View_->Repaint();
        view_image->Repaint();

    }
}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::vertical_barChange(TObject *Sender)
{

    if(Image_View_ == NULL)
    {
        return;
    }
	if(Image_View_->Bitmap_ == NULL)
    {
        return;
	}
    if(Image_View_->Is_Update_Ui_)
    {
        return;
    }



	if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::NORMAL)
    {
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 + (vertical_bar->Position - vertical_bar->Max / 2)
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
	{
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 + (vertical_bar->Position - vertical_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
    }
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
	{
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 - (vertical_bar->Position - vertical_bar->Max / 2)
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
    {
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 - (vertical_bar->Position - vertical_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
    {
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 + (vertical_bar->Position - vertical_bar->Max / 2)
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
	{
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 - (vertical_bar->Position - vertical_bar->Max / 2)
		);
	}

    Image_View_->Is_Repaint_ = true;
    Image_View_->Is_View_Thumbnail_ = false;
    Image_View_->Repaint();
    view_image->Repaint();


}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::horizontal_barChange(TObject *Sender)
{
    if(Image_View_ == NULL)
    {
        return;
    }
	if(Image_View_->Bitmap_ == NULL)
    {
        return;
	}
    if(Image_View_->Is_Update_Ui_)
    {
        return;
    }



    if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::NORMAL)
	{
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 + (horizontal_bar->Position - horizontal_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
    }
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_90)
	{
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 - (horizontal_bar->Position - horizontal_bar->Max / 2)
		);
    }
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_180)
    {
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 - (horizontal_bar->Position - horizontal_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::ROTATE_270)
    {
		Image_View_->Image_Center_ = halib::point_double(Image_View_->Image_Center_.X_,
			(double)(Image_View_->Bitmap_->Height_ - 1 ) / 2 + (horizontal_bar->Position - horizontal_bar->Max / 2)
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::HORIZONTAL_FLIP)
    {
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 - (horizontal_bar->Position - horizontal_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
	}
	else if(Image_View_->View_Direction_ == halib_def::image_view_view_direction::VERTICAL_FLIP)
    {
		Image_View_->Image_Center_ = halib::point_double((double)(Image_View_->Bitmap_->Width_ - 1 ) / 2 + (horizontal_bar->Position - horizontal_bar->Max / 2),
			Image_View_->Image_Center_.Y_
		);
	}

    Image_View_->Is_Repaint_ = true;
    Image_View_->Is_View_Thumbnail_ = false;
    Image_View_->Repaint();
    view_image->Repaint();

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::main_boxMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
    if(!Image_View_->Is_View_Scroll_)
    {
        return;
    }

    if(view_ratio->ItemIndex == 0)
    {
        return;
    }


    view_ratio->ItemIndex--;
    view_ratioChange(NULL);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::main_boxMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled)
{
    if(!Image_View_->Is_View_Scroll_)
    {
        return;
    }

    if(view_ratio->ItemIndex == view_ratio->Items->Count - 1)
    {
        return;
    }

	view_ratio->ItemIndex++;
    view_ratioChange(NULL);

}
//---------------------------------------------------------------------------

void __fastcall Thahaha_image_view_form::On_Message(TMessage& message)
{
    switch (message.Msg) {
        case MESSAGE_IMAGE_VIEW_VIEW_IMAGE_REPAINT:
		{
			
         
			break;
        }
        default:
        {
            TForm::WndProc(message);  // Default handling
        }

    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
