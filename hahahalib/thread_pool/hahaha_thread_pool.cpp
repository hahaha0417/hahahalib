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
hahaha_thread_pool::hahaha_thread_pool()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pool::~hahaha_thread_pool()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pool::hahaha_thread_pool(const hahaha_thread_pool& htp)
{
	Reset();
	Copy(htp);
}
//---------------------------------------------------------------------------
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
void hahaha_thread_pool::Copy(const hahaha_thread_pool& htp)
{

}
//---------------------------------------------------------------------------
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
int hahaha_thread_pool::Reset()
{
	Thread_Pool_ = nullptr;

	Thread_Max_ = 4;
	Thread_Min_ = 1;
    Is_Open_ = FALSE;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool::Create(const DWORD& thread_max, const DWORD& thread_min)
{
	if(Is_Open() == TRUE)
	{
        Close();
	}

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
int hahaha_thread_pool::Close()
{
	DestroyThreadpoolEnvironment(&Thread_Pool_Environment_);
	CloseThreadpool(Thread_Pool_);
	Is_Open_ = FALSE;

	return 0;

}
//---------------------------------------------------------------------------
BOOL hahaha_thread_pool::Is_Open()
{
	return Is_Open_;

}
//---------------------------------------------------------------------------
void WINAPI hahaha_thread_pool::CallBack_Task(PTP_CALLBACK_INSTANCE instance, PVOID parameter)
{
	hahaha_thread_pool* self = (hahaha_thread_pool*)parameter;
	self->Handle();

}
//---------------------------------------------------------------------------
int hahaha_thread_pool::Add_Task()
{
	TrySubmitThreadpoolCallback(CallBack_Task, (PVOID)this, &Thread_Pool_Environment_);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool::Handle()
{
	int rrr = 0;

	return 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------