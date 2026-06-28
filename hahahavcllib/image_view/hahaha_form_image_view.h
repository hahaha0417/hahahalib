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
	// 處理標題列圖示上的滑鼠按下事件。
	void __fastcall Image_Title_IconMouseDown(TObject *Sender, TMouseButton Button,  // 觸發事件的滑鼠按鍵。
          TShiftState Shift, int X, int Y);
	// 處理標題文字上的滑鼠按下事件。
	void __fastcall Label_TitleMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,  // 事件當下的 Shift / Ctrl / Alt 狀態。
          int X, int Y);
	// 處理標題背景上的滑鼠按下事件。
	void __fastcall Image_Title_BackgroundMouseDown(TObject *Sender, TMouseButton Button,  // 觸發事件的滑鼠按鍵。
          TShiftState Shift, int X, int Y);
	// 處理最小化按鈕點擊事件。
	void __fastcall Button_MinClick(TObject *Sender);
	// 處理最大化按鈕點擊事件。
	void __fastcall Button_MaxClick(TObject *Sender);
	// 處理關閉按鈕點擊事件。
	void __fastcall ButtonCloseClick(TObject *Sender);
	// 處理主顯示區尺寸變更事件。
	void __fastcall main_boxResize(TObject *Sender);
	// 處理顯示倍率調整事件。
	void __fastcall view_ratioChange(TObject *Sender);
	// 處理垂直捲軸變更事件。
	void __fastcall vertical_barChange(TObject *Sender);
	// 處理水平捲軸變更事件。
	void __fastcall horizontal_barChange(TObject *Sender);
	// 處理滑鼠滾輪向下事件。
	void __fastcall main_boxMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,  // 滑鼠座標。
          bool &Handled);
	// 處理滑鼠滾輪向上事件。
	void __fastcall main_boxMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,  // 滑鼠座標。
          bool &Handled);




















private:	// User declarations
public:		// User declarations
	// 建立 image view 專用表單。
	__fastcall Thahaha_image_view_form(TComponent* Owner);
public:
	// 初始化相關設定。
	void Initial();
    // 初始化相關設定。
    void Initial_Layout();
    // 初始化相關設定。
    void Initial_Color();

public:
    // 設定指定參數或狀態。
    int Set_Image_View(hahahalib::hahaha_image_view* image_view /* 目前正在處理的 image view 物件。 */);

public:

public:
    std::unique_ptr<hahahalib::hahaha_timer_high_precision> Timer_;
public:
    hahahalib::hahaha_image_view* Image_View_;

public:
    // 接收並分派自訂視窗訊息。
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
