//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_thread_pool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include "thread_pool\hahaha_thread_pool_ha.h"
//hahaha::hahaha_thread_pool_ha thread_pool_ha_;
//thread_pool_ha_.Create();
//thread_pool_ha_.Add_Task();
//thread_pool_ha_.Add_Task();
//要傳參數有delete問題
//用std::queue<std::unique_ptr<XXX>>保存
//或用std::wstring + void*存queue，因為在thread_pool，再delete掉
//跑完再一起殺
//這邊無法展示
//---------------------------------------------------------------------------
// 建構物件並初始化預設狀態。
hahaha_thread_pool::hahaha_thread_pool()
{
	Reset();
}
//---------------------------------------------------------------------------
// 解構物件並釋放相關資源。
hahaha_thread_pool::~hahaha_thread_pool()
{

}
//---------------------------------------------------------------------------
// 以既有物件內容建構新的物件實例。
hahaha_thread_pool::hahaha_thread_pool(const hahaha_thread_pool& htp)
{
	Reset();
	Copy(htp);
}
//---------------------------------------------------------------------------
// 以移動方式建構物件並接手既有資源。
hahaha_thread_pool::hahaha_thread_pool(hahaha_thread_pool&& htp) noexcept
{
	Move(std::move(htp));

}
//---------------------------------------------------------------------------
hahaha_thread_pool& hahaha_thread_pool::operator=(const hahaha_thread_pool& htp)
{
	Copy(htp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool& hahaha_thread_pool::operator=(hahaha_thread_pool&& htp) noexcept
{
	if (this != &htp)
    {
        Move(std::move(htp));
    }

	return *this;
}
//---------------------------------------------------------------------------
// 複製來源物件的內部狀態。
void hahaha_thread_pool::Copy(const hahaha_thread_pool& htp)
{

}
//---------------------------------------------------------------------------
// 接手來源物件的內部資源。
void hahaha_thread_pool::Move(hahaha_thread_pool&& htp) noexcept
{
    Thread_Pool_ = htp.Thread_Pool_;
	Thread_Pool_Environment_ = htp.Thread_Pool_Environment_;
	Thread_Max_ = htp.Thread_Max_;
	Thread_Min_ = htp.Thread_Min_;
	Is_Open_ = htp.Is_Open_;

    htp.Reset();

}
//---------------------------------------------------------------------------
// 重設內部狀態。
int hahaha_thread_pool::Reset()
{
	Thread_Pool_ = nullptr;

	Thread_Max_ = 4;
	Thread_Min_ = 1;
    Is_Open_ = FALSE;

	return 0;
}
//---------------------------------------------------------------------------
// 建立所需資源並完成初始化。
int hahaha_thread_pool::Create(const DWORD& thread_max, const DWORD& thread_min)
{
	if(Is_Open() == TRUE)
	{
        Close();
	}

	// 建立新的 thread pool，並把執行緒數上下限寫入環境設定。
	Thread_Max_ = thread_max;
	Thread_Min_ = thread_min;

	Thread_Pool_ = CreateThreadpool(NULL);            // 创建线程池
	SetThreadpoolThreadMaximum(Thread_Pool_, thread_max);
	SetThreadpoolThreadMinimum(Thread_Pool_, thread_min);
	InitializeThreadpoolEnvironment(&Thread_Pool_Environment_);
	SetThreadpoolCallbackPool(&Thread_Pool_Environment_, Thread_Pool_);
	Is_Open_ = TRUE;

    return 0;

}
//---------------------------------------------------------------------------
// 關閉並釋放目前持有的資源。
int hahaha_thread_pool::Close()
{
	// 先銷毀 callback environment，再關閉 pool 本體。
	DestroyThreadpoolEnvironment(&Thread_Pool_Environment_);
	CloseThreadpool(Thread_Pool_);
	Is_Open_ = FALSE;

	return 0;

}
//---------------------------------------------------------------------------
// 回傳目前是否已開啟。
BOOL hahaha_thread_pool::Is_Open()
{
	return Is_Open_;

}
//---------------------------------------------------------------------------
// 作為 thread pool callback 入口並轉呼叫物件方法。
void WINAPI hahaha_thread_pool::CallBack_Task(PTP_CALLBACK_INSTANCE instance, PVOID parameter)
{
	// Windows callback 轉回物件成員函式，方便用繼承覆寫 Handle。
	hahaha_thread_pool* self = (hahaha_thread_pool*)parameter;
	self->Handle();

}
//---------------------------------------------------------------------------
// 把目前工作提交到 thread pool 佇列。
int hahaha_thread_pool::Add_Task()
{
	// 每次呼叫都把目前物件提交成一個待執行工作。
	TrySubmitThreadpoolCallback(CallBack_Task, (PVOID)this, &Thread_Pool_Environment_);

	return 0;

}
//---------------------------------------------------------------------------
// 執行主要處理邏輯。
int hahaha_thread_pool::Handle()
{
	// 預設不做事，保留給衍生類別實作。
	int rrr = 0;

	return 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------
