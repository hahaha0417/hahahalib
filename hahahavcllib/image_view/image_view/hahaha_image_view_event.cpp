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
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#include "hahaha_image_view_event.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_image_view_event::hahaha_image_view_event()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_image_view_event::~hahaha_image_view_event()
{

}
//---------------------------------------------------------------------------
hahaha_image_view_event::hahaha_image_view_event(const hahaha_image_view_event& hive)
{
    Reset();
	Copy(hive);
}
//---------------------------------------------------------------------------
hahaha_image_view_event::hahaha_image_view_event(hahaha_image_view_event&& hive) noexcept
{
    Move(std::move(hive));

}
//---------------------------------------------------------------------------
hahaha_image_view_event& hahaha_image_view_event::operator=(const hahaha_image_view_event& hive)
{
	Copy(hive);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_image_view_event& hahaha_image_view_event::operator=(hahaha_image_view_event&& hive) noexcept
{
	if (this != &hive)
    {
        Move(std::move(hive));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_image_view_event::Copy(const hahaha_image_view_event& hive)
{

}
//---------------------------------------------------------------------------
void hahaha_image_view_event::Move(hahaha_image_view_event&& hive) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_image_view_event::Reset()
{


	return 0;
}
//---------------------------------------------------------------------------
bool __fastcall hahaha_image_view_event::On_Align_Insert_Before(TWinControl *Sender,
    TControl *C1,
    TControl *C2
)
{
    bool result_On_align_insert_before_ = false;

    if(!Image_View_->Enabled_)
    {
        return result_On_align_insert_before_;
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Insert_Before_Begin(*Image_View_,
                    result_On_align_insert_before_,
                    Sender,
                    C1,
                    C2
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
                    return result_On_align_insert_before_;
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Insert_Before_Design(*Image_View_,
                    result_On_align_insert_before_,
                    Sender,
                    C1,
                    C2
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
                    return result_On_align_insert_before_;
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Insert_Before_End(*Image_View_,
                    result_On_align_insert_before_,
                    Sender,
                    C1,
                    C2
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
                    return result_On_align_insert_before_;
                }

            }
        }
    }
    //---------------------------------------------------------------------------


    // https://docwiki.embarcadero.com/Libraries/Sydney/en/Vcl.Controls.TAlignInsertBeforeEvent
    // returns true if C2 should be presented before C1, and false otherwise.
    // C1
    // First control to be ordered.
    // C2
    // Second control to be ordered

    return result_On_align_insert_before_;
}
//---------------------------------------------------------------------------
void __fastcall hahaha_image_view_event::On_Align_Position(TWinControl *Sender,
    TControl *Control,
    int &NewLeft,
    int &NewTop,
    int &NewWidth,
    int &NewHeight,
    TRect &AlignRect,
    const TAlignInfo &AlignInfo
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Position_Begin(*Image_View_,
                	Sender,
                    Control,
                    NewLeft,
                    NewTop,
                    NewWidth,
                    NewHeight,
                    AlignRect,
                    AlignInfo
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Position_Design(*Image_View_,
                	Sender,
                    Control,
                    NewLeft,
                    NewTop,
                    NewWidth,
                    NewHeight,
                    AlignRect,
                    AlignInfo
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Align_Position_End(*Image_View_,
                	Sender,
                    Control,
                    NewLeft,
                    NewTop,
                    NewWidth,
                    NewHeight,
                    AlignRect,
                    AlignInfo
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
void __fastcall hahaha_image_view_event::On_Can_Resize(TObject *Sender,
    int &NewWidth,
    int &NewHeight,
    bool &Resize
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Can_Resize_Begin(*Image_View_,
                	Sender,
                    NewWidth,
                    NewHeight,
                    Resize
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Can_Resize_Design(*Image_View_,
                	Sender,
                    NewWidth,
                    NewHeight,
                    Resize
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Can_Resize_End(*Image_View_,
                	Sender,
                    NewWidth,
                    NewHeight,
                    Resize
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
void __fastcall hahaha_image_view_event::On_Click(TObject *Sender)
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Click_Begin(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Click_Design(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Click_End(*Image_View_,
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
void __fastcall hahaha_image_view_event::On_Constrained_Resize(TObject *Sender,
    int &MinWidth,
    int &MinHeight,
    int &MaxWidth,
    int &MaxHeight
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Constrained_Resize_Begin(*Image_View_,
                	Sender,
                    MinWidth,
                    MinHeight,
                    MaxWidth,
                    MaxHeight
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Constrained_Resize_Design(*Image_View_,
                	Sender,
                    MinWidth,
                    MinHeight,
                    MaxWidth,
                    MaxHeight
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Constrained_Resize_End(*Image_View_,
                	Sender,
                    MinWidth,
                    MinHeight,
                    MaxWidth,
                    MaxHeight
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
void __fastcall hahaha_image_view_event::On_Context_Popup(TObject *Sender,
    const TPoint &MousePos,
    bool &Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Context_Popup_Begin(*Image_View_,
                	Sender,
                    MousePos,
                    Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Context_Popup_Design(*Image_View_,
                	Sender,
                    MousePos,
                    Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Context_Popup_End(*Image_View_,
                	Sender,
                    MousePos,
                    Handled
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
void __fastcall hahaha_image_view_event::On_DblClick(TObject *Sender)
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_DblClick_Begin(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_DblClick_Design(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_DblClick_End(*Image_View_,
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
void __fastcall hahaha_image_view_event::On_Dock_Drop(TObject *Sender,
    TDragDockObject *Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Drop_Begin(*Image_View_,
                	Sender,
                    Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Drop_Design(*Image_View_,
                	Sender,
                    Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Drop_End(*Image_View_,
                	Sender,
                    Source,
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
void __fastcall hahaha_image_view_event::On_Dock_Over(TObject *Sender,
    TDragDockObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Over_Begin(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Over_Design(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Dock_Over_End(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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
void __fastcall hahaha_image_view_event::On_Drag_Drop(TObject *Sender,
    TObject *Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Drop_Begin(*Image_View_,
                	Sender,
                    Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Drop_Design(*Image_View_,
                	Sender,
                    Source,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Drop_End(*Image_View_,
                	Sender,
                    Source,
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
void __fastcall hahaha_image_view_event::On_Drag_Over(TObject *Sender,
    TObject *Source,
    int X,
    int Y,
    TDragState State,
    bool &Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Over_Begin(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Over_Design(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Drag_Over_End(*Image_View_,
                	Sender,
                    Source,
                    X,
                    Y,
                    State,
                    Accept
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
void __fastcall hahaha_image_view_event::On_End_Dock(TObject *Sender,
    TObject *Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Dock_Begin(*Image_View_,
                	Sender,
                    Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Dock_Design(*Image_View_,
                	Sender,
                    Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Dock_End(*Image_View_,
                	Sender,
                    Target,
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
void __fastcall hahaha_image_view_event::On_End_Drag(TObject *Sender,
    TObject *Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Drag_Begin(*Image_View_,
                	Sender,
                    Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Drag_Design(*Image_View_,
                	Sender,
                    Target,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_End_Drag_End(*Image_View_,
                	Sender,
                    Target,
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
void __fastcall hahaha_image_view_event::On_Find_Graphic_Class(TObject *Sender,
    const TFindGraphicClassContext &Context,
    TGraphicClass &GraphicClass
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Find_Graphic_Class_Begin(*Image_View_,
                	Sender,
                    Context,
                    GraphicClass
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Find_Graphic_Class_Design(*Image_View_,
                	Sender,
                    Context,
                    GraphicClass
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Find_Graphic_Class_End(*Image_View_,
                	Sender,
                    Context,
                    GraphicClass
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
void __fastcall hahaha_image_view_event::On_Enter(TObject *Sender)
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Enter_Begin(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Enter_Design(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Enter_End(*Image_View_,
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
void __fastcall hahaha_image_view_event::On_Exit(TObject *Sender)
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Exit_Begin(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Exit_Design(*Image_View_,
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Exit_End(*Image_View_,
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
void __fastcall hahaha_image_view_event::On_Gesture(TObject *Sender,
    const TGestureEventInfo &EventInfo,
    bool &Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Gesture_Begin(*Image_View_,
                	Sender,
                    EventInfo,
                    Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Gesture_Design(*Image_View_,
                	Sender,
                    EventInfo,
                    Handled
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Gesture_End(*Image_View_,
                	Sender,
                    EventInfo,
                    Handled
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
void __fastcall hahaha_image_view_event::On_Get_Site_Info(TObject *Sender,
    TControl *DockClient,
    TRect &InfluenceRect,
    const TPoint &MousePos,
    bool &CanDock
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Get_Site_Info_Begin(*Image_View_,
                	Sender,
                    DockClient,
                    InfluenceRect,
                    MousePos,
                    CanDock
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Get_Site_Info_Design(*Image_View_,
                	Sender,
                    DockClient,
                    InfluenceRect,
                    MousePos,
                    CanDock
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

                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Get_Site_Info_End(*Image_View_,
                	Sender,
                    DockClient,
                    InfluenceRect,
                    MousePos,
                    CanDock
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
//TScrollBar
//---------------------------------------------------------------------------
//void __fastcall hahaha_image_view_event::On_Vertical_Bar_Change(TObject *Sender)
//{
//    if(!Image_View_->Enabled_)
//    {
//        return;
//    }
//
//    //---------------------------------------------------------------------------
//    // begin
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Vertical_Bar_Change_Begin(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//
//    //---------------------------------------------------------------------------
//    // design
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Vertical_Bar_Change_Design(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//    //---------------------------------------------------------------------------
//    // repaint
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Visibled_)
//        {
//            Image_View_->Repaint(false);
//        }
//    }
//    //---------------------------------------------------------------------------
//
//    //---------------------------------------------------------------------------
//    // end
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Vertical_Bar_Change_End(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//
//}
////---------------------------------------------------------------------------
//void __fastcall hahaha_image_view_event::On_Horizontal_Bar_Change(TObject *Sender)
//{
//    if(!Image_View_->Enabled_)
//    {
//        return;
//    }
//
//    //---------------------------------------------------------------------------
//    // begin
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Horizontal_Bar_Change_Begin(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//
//    //---------------------------------------------------------------------------
//    // design
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Horizontal_Bar_Change_Design(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//    //---------------------------------------------------------------------------
//    // repaint
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Visibled_)
//        {
//            Image_View_->Repaint(false);
//        }
//    }
//    //---------------------------------------------------------------------------
//
//    //---------------------------------------------------------------------------
//    // end
//    //-----------------------------------
//    {
//        int n = Image_View_->Painters_.size();
//
//        if(Image_View_->Action_)
//        {
//            for(int i = 0; i < n; i++)
//            {
//                // 在這裡處理判斷，比較快
//                if(!Image_View_->Painters_[i]->Enabled_)
//                {
//                    continue;
//                }
//
//                if(!Image_View_->Painters_[i]->Action_)
//                {
//                    continue;
//                }
//
//                halib_def::image_view_result result_ = Image_View_->Painters_[i]->On_Horizontal_Bar_Change_End(*Image_View_,
//                    Sender
//                );
//
//                if(result_ == halib_def::image_view_result::AGAIN)
//                {
//                    // debug用
//                    i--;
//                    continue;
//                }
//                else if(result_ == halib_def::image_view_result::BREAK)
//                {
//                    break;
//                }
//                else if(result_ == halib_def::image_view_result::RETURN)
//                {
//                    return;
//                }
//
//            }
//        }
//    }
//    //---------------------------------------------------------------------------
//
//
//}

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------