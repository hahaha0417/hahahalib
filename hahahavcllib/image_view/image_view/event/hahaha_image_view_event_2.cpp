//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <memory>
#include <vector>
//---------------------------------------------------------------------------
#include <image_view\hahaha_image_view.h>
#include <image_view\hahaha_image_view_painter.h>
#include <image_view\image_view\hahaha_image_view_action.h>
#include <image_view\image_view\hahaha_image_view_deal_painter.h>
#include <image_view\define\hahaha_define_image_view_result.h>
#include <image_view\image_view\hahaha_image_view_event.h>
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include "hahaha_image_view_event_2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Activate(TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y,
    int HitTest,
    TMouseActivate &MouseActivate
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Activate_Begin(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y,
                    HitTest,
                    MouseActivate
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Activate_Design(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y,
                    HitTest,
                    MouseActivate
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Activate_End(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y,
                    HitTest,
                    MouseActivate
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Down(TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Down_Begin(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Down_Design(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Down_End(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Enter(TObject *Sender)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Enter_Begin(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Enter_Design(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Enter_End(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Leave(TObject *Sender)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Leave_Begin(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Leave_Design(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Leave_End(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Move(TObject *Sender,
    TShiftState Shift,
    int X,
    int Y
)
{

    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Move_Begin(*Image_View_,
                	Sender,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Move_Design(*Image_View_,
                	Sender,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Move_End(*Image_View_,
                	Sender,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Mouse_Up(TObject *Sender,
    TMouseButton Button,
    TShiftState Shift,
    int X,
    int Y
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Up_Begin(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Up_Design(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Mouse_Up_End(*Image_View_,
                	Sender,
                    Button,
                    Shift,
                    X,
                    Y
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Progress(TObject *Sender,
    TProgressStage Stage,
    BYTE PercentDone,
    bool RedrawNow,
    const TRect &R,
    const UnicodeString Msg
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Progress_Begin(*Image_View_,
                	Sender,
                    Stage,
                    PercentDone,
                    RedrawNow,
                    R,
                    Msg
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Progress_Design(*Image_View_,
                	Sender,
                    Stage,
                    PercentDone,
                    RedrawNow,
                    R,
                    Msg
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Progress_End(*Image_View_,
                	Sender,
                    Stage,
                    PercentDone,
                    RedrawNow,
                    R,
                    Msg
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Paint(TObject *Sender)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Paint_Begin(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Paint_Design(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Paint_End(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Resize(TObject *Sender)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Resize_Begin(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Resize_Design(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Resize_End(*Image_View_,
                	Sender
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Start_Dock(TObject *Sender,
    TDragDockObject *&DragObject
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Dock_Begin(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Dock_Design(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Dock_End(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Start_Drag(TObject *Sender,
    TDragObject *&DragObject
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Drag_Begin(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Drag_Design(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Start_Drag_End(*Image_View_,
                	Sender,
                    DragObject
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Un_Dock(TObject *Sender,
    TControl *Client,
    TWinControl *NewTarget,
    bool &Allow
)
{
    if(!Image_View_->Enabled_)
    {
        return;
    }

    //---------------------------------------------------------------------------
    // begin
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Un_Dock_Begin(*Image_View_,
                	Sender,
                    Client,
                    NewTarget,
                    Allow
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
					i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------



    //---------------------------------------------------------------------------
    // design
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
				}

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Un_Dock_Design(*Image_View_,
                	Sender,
                    Client,
                    NewTarget,
                    Allow
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }
            }
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // repaint
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

        if(Image_View_->Visibled_)
        {
            Image_View_->Repaint();
        }
    }
    //---------------------------------------------------------------------------

    //---------------------------------------------------------------------------
    // end
    //-----------------------------------
    {
        int n = Image_View_->Painters_.size();

		if(Image_View_->Action_)
        {
            for(int i = 0; i < n; i++)
            {
                // 在這裡處理判斷，比較快
                if(!Image_View_->Painters_[i]->Enabled_)
                {
                    continue;
                }

                if(!Image_View_->Painters_[i]->Action_)
                {
                    continue;
                }

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Un_Dock_End(*Image_View_,
                	Sender,
                    Client,
                    NewTarget,
                    Allow
                );

                if(result_ == halib_def::image_view_result::AGAIN)
                {
                    // debug用
                    i--;
                    continue;
                }
                else if(result_ == halib_def::image_view_result::BREAK)
                {
                    break;
                }
                else if(result_ == halib_def::image_view_result::RETURN)
                {
                    return;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------