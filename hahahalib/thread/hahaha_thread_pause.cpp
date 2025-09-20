//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
//---------------------------------------------------------------------------
#include "hahaha_thread_pause.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//要繼承後使用，Handle()是Callback
//#include <thread\hahaha_thread_pause.h>
//hahaha::hahaha_thread_pause_ha thread_pause_ha_;
//thread_pause_ha_.Create();
//thread_pause_ha_.Enabled();
//thread_pause_ha_.Disabled();
//thread_pause_ha_.Wait();
//thread_pause_ha_.Close();
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
hahaha_thread_pause::hahaha_thread_pause()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pause::~hahaha_thread_pause()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pause::hahaha_thread_pause(const hahaha_thread_pause& htp)
{
    Reset();
	Copy(htp);
}
//---------------------------------------------------------------------------
hahaha_thread_pause::hahaha_thread_pause(hahaha_thread_pause&& htp) noexcept
{
    Move(std::move(htp));
}
//---------------------------------------------------------------------------
hahaha_thread_pause& hahaha_thread_pause::operator=(const hahaha_thread_pause& htp)
{
	Copy(htp);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pause& hahaha_thread_pause::operator=(hahaha_thread_pause&& htp) noexcept
{
	if (this != &htp)
    {
        Move(std::move(htp));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pause::Copy(const hahaha_thread_pause& htp)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_pause::Move(hahaha_thread_pause&& htp) noexcept
{
    Thread_Id_ = htp.Thread_Id_;
	Thread_ = htp.Thread_;
    Event_Run_ = htp.Event_Run_;
    Event_Wait_ = htp.Event_Wait_;
	Event_Exit_ = htp.Event_Exit_;
    Is_Close_ = htp.Is_Close_;

    htp.Reset();

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Reset()
{
	Thread_Id_ = 0;
	Thread_ = NULL;
    Event_Run_ = NULL;
    Event_Wait_ = NULL;
	Event_Exit_ = NULL;
    Is_Close_ = false;

	return 0;
}
//---------------------------------------------------------------------------
DWORD WINAPI hahaha_thread_pause::Thread_Start(void* parameter)
{
	hahaha_thread_pause& self_ = *(hahaha_thread_pause*)parameter;
	self_.Thread_Proc();

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Thread_Proc()
{
	HANDLE handles_[2] = {Event_Run_, Event_Exit_};

	BOOL exit_ = FALSE;
	while(!Is_Close_ && !exit_)
	{
		DWORD result = WaitForMultipleObjects(
			2,
			handles_,
			FALSE,
			INFINITE
		);  // no time-out interval

		switch (result)
		{
			// The thread got ownership of the mutex
			case WAIT_OBJECT_0:
				//---------------------------------------------------------------------------
				Handle();
				ResetEvent(Event_Run_);
                SetEvent(Event_Wait_);
				//---------------------------------------------------------------------------
				break;
			case WAIT_OBJECT_0 + 1:
				exit_ = TRUE;
				break;
//			case WAIT_TIMEOUT:
//				return hahaha_define_sync::TIMEOUT;
//			// The thread got ownership of an abandoned mutex
//			// The database is in an indeterminate state
//			case WAIT_ABANDONED:
//				return hahaha_define_sync::ABANDONED;
		}
	}
	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Handle()
{
	int eee = 0;

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Create()
{
	if(Thread_ != NULL)
	{
		Close();
	}
	Event_Run_ = CreateEventW(
		NULL,               // default security attributes
		TRUE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		NULL  // object name
		);
    Event_Wait_ = CreateEventW(
		NULL,               // default security attributes
		FALSE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		NULL  // object name
		);
	Event_Exit_ = CreateEventW(
		NULL,               // default security attributes
		FALSE,               // manual-reset event
		FALSE,              // initial state is nonsignaled
		NULL  // object name
		);
	Thread_ = CreateThread(NULL,
		0,
		Thread_Start,
		(void*)this,
		0,
		&Thread_Id_
	);



	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Close()
{

	if(Event_Exit_ != NULL)
	{
		SetEvent(Event_Exit_);
		CloseHandle(Event_Exit_);
		Event_Exit_ = NULL;
	}
	if(Event_Run_ != NULL)
	{
		CloseHandle(Event_Run_);
		Event_Run_ = NULL;
	}
    if(Event_Wait_ != NULL)
	{
		CloseHandle(Event_Wait_);
		Event_Wait_ = NULL;
	}
	if(Thread_ != NULL)
	{
		CloseHandle(Thread_);
		Thread_ = NULL;

	}

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Enabled()
{
    SetEvent(Event_Run_);
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Disabled()
{
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Terminate()
{
	TerminateThread(Thread_ , 0);
    if(Thread_ != NULL)
	{
		CloseHandle(Thread_);
		Thread_ = NULL;
	}
	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pause::Wait()
{
    HANDLE handles_[2] = {Event_Wait_, Event_Exit_};

	DWORD result = WaitForMultipleObjects(
        2,
        handles_,
        FALSE,
        INFINITE
    );  // no time-out interval

    switch (result)
    {
        // The thread got ownership of the mutex
        case WAIT_OBJECT_0:
            return 0;
        case WAIT_OBJECT_0 + 1:
            return -1;
    }
    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------