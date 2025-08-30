//---------------------------------------------------------------------------

#ifndef hahaha_form_image_viewH
#define hahaha_form_image_viewH
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
#include <string>
#include <vector>
#include <memory>
//---------------------------------------------------------------------------
#include <timer\hahaha_timer_high_precision.h>
//---------------------------------------------------------------------------
#define MESSAGE_IMAGE_VIEW_VIEW_IMAGE_REPAINT (WM_USER + 1000)

//---------------------------------------------------------------------------
namespace hahahalib
{
class hahaha_image_view;
// class hahaha_timer_high_precision;
}

class Thahaha_image_view_form : public TForm
{
__published:	// IDE-managed Components
	TScrollBox *MainBox;
	TTitleBarPanel *TitleBarPanel;
	TImage *Image_Title_Icon;
	TLabel *Label_Title;
	TImage *Image_Title_Background;
	TButton *Button_Min;
	TButton *Button_Max;
	TButton *ButtonClose;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TScrollBox *ScrollBox1;
	TScrollBox *ScrollBox2;
	TScrollBox *ScrollBox3;
	TScrollBox *BodyBox;
	TScrollBox *TopBox;
	TScrollBox *BodyBodyBox;
	TScrollBox *BottomBox;
	TScrollBox *LeftBox;
	TScrollBox *RightBox;
	TScrollBox *BodyMainBox;
	TSplitter *Splitter_Top;
	TSplitter *Splitter_Bottom;
	TSplitter *Splitter_Left;
	TSplitter *Splitter_Right;
	TScrollBox *view_box;
	TMemo *Memo1;
	TScrollBox *view_main_box;
	TScrollBox *view_bottom_box;
	TScrollBox *vertical_box;
	TScrollBox *horizontal_box;
	TScrollBox *corner_box;
	TScrollBox *main_box;
	TImage *view_image;
	TScrollBar *vertical_bar;
	TScrollBar *horizontal_bar;
	TPanel *Panel_B;
	TPanel *Panel_G;
	TPanel *Panel_Y;
	TPanel *Panel_X;
	TPanel *Panel_R;
	TComboBox *view_ratio;
	TPanel *Panel_Time;
	void __fastcall Image_Title_IconMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Label_TitleMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Image_Title_BackgroundMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall Button_MinClick(TObject *Sender);
	void __fastcall Button_MaxClick(TObject *Sender);
	void __fastcall ButtonCloseClick(TObject *Sender);
	void __fastcall main_boxResize(TObject *Sender);
	void __fastcall view_ratioChange(TObject *Sender);
	void __fastcall vertical_barChange(TObject *Sender);
	void __fastcall horizontal_barChange(TObject *Sender);
	void __fastcall main_boxMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall main_boxMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);




















private:	// User declarations
public:		// User declarations
	__fastcall Thahaha_image_view_form(TComponent* Owner);
public:
	void Initial();
    void Initial_Layout();
    void Initial_Color();

public:
    int Set_Image_View(hahahalib::hahaha_image_view* image_view);

public:

public:
    std::unique_ptr<hahahalib::hahaha_timer_high_precision> Timer_;
public:
    hahahalib::hahaha_image_view* Image_View_;

public:
    void __fastcall On_Message(TMessage& message);

    BEGIN_MESSAGE_MAP
    	MESSAGE_HANDLER(MESSAGE_IMAGE_VIEW_VIEW_IMAGE_REPAINT, TMessage, On_Message)
    END_MESSAGE_MAP(TForm)
public:


};
//---------------------------------------------------------------------------
extern PACKAGE Thahaha_image_view_form *hahaha_image_view_form;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
namespace halib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
typedef Thahaha_image_view_form form_image_view;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // halib
//---------------------------------------------------------------------------

#endif
