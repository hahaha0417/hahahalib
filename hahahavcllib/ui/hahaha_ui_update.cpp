//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_ui_update.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//Embarcadero 官方文件說明（概略）
//PCH is supported for application and DLL projects using the Clang compilers. Static library projects do not support PCH.

// 因為static library不能使用預編譯，這裡採用callback方式呼叫某個集中處理UI的cpp
// 不要直接
//halib::ui::update::Queue([=](){
//    ShowMessage(UnicodeString(rrr));
//    ShowMessage(UnicodeString(*eee));
//    delete eee;
//});

//採用
//halib::ui::update::Queue([=](){
//    xxx->update_ui();
//});
// 在exe or dll不要直接用
// TThread::Queue(nullptr, callback);
// 用這樣
//halib::ui::update::Queue([=](){
//    ShowMessage(UnicodeString(rrr));
//    ShowMessage(UnicodeString(*eee));
//    delete eee;
//});
//到時候移到static library比較好改成
//halib::ui::update::Queue([=](){
//    xxx->update_ui();
//});

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
int hahaha_ui_update::Synchronize(
    const std::function<void()>& callback
)
{
    TThread::Synchronize(nullptr, callback);
}
//---------------------------------------------------------------------------
int hahaha_ui_update::Queue(
    const std::function<void()>& callback
)
{
    TThread::Queue(nullptr, callback);
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------