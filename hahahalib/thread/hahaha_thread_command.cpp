//---------------------------------------------------------------------------

#pragma hdrstop

#include <lock\hahaha_mutex.h>
#include <thread\base\hahaha_thread_command_command.h>

#include "hahaha_thread_command.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//要繼承後使用，Handle()是Callback
//#include <thread\hahaha_thread_command.h>
//hahaha::hahaha_thread_command_ha thread_command_ha_;
//thread_command_ha_.Create();
//thread_command_ha_.Test();
//int hahaha_thread_command_ha::Test()
//{
//	SetEvent(Event_Run_);
//
//}
//thread_command_ha_.Close();
//---------------------------------------------------------------------------
hahaha_thread_command_command::hahaha_thread_command_command()
{
    Reset();

}

//---------------------------------------------------------------------------
hahaha_thread_command_command::~hahaha_thread_command_command()
{

}

//---------------------------------------------------------------------------

hahaha_thread_command_command::hahaha_thread_command_command(const hahaha_thread_command_command& htcc)
{
    Reset();

	Copy(htcc);
}
//---------------------------------------------------------------------------
hahaha_thread_command_command::hahaha_thread_command_command(hahaha_thread_command_command&& htcc) noexcept
{
    Move(std::move(htcc));
}

//---------------------------------------------------------------------------
hahaha_thread_command_command& hahaha_thread_command_command::operator=(const hahaha_thread_command_command& htcc)
{
    Copy(htcc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command_command& hahaha_thread_command_command::operator=(hahaha_thread_command_command&& htcc) noexcept
{
    if (this != &htcc)
    {
        Move(std::move(htcc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command_command::Copy(const hahaha_thread_command_command& htcc)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command_command::Move(hahaha_thread_command_command&& htcc) noexcept
{
    Command_ = htcc.Command_;
    Parameter_ = htcc.Parameter_;

    htcc.Reset();
}
//---------------------------------------------------------------------------
int hahaha_thread_command_command::Reset()
{
    Command_ = -999999;
    Parameter_ = nullptr;


}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
hahaha_thread_command::hahaha_thread_command()
{
	Reset();
    // 不能在這邊Create()
}
//---------------------------------------------------------------------------
hahaha_thread_command::~hahaha_thread_command()
{

}
//---------------------------------------------------------------------------
hahaha_thread_command::hahaha_thread_command(const hahaha_thread_command& htc)
{
	Reset();

	Copy(htc);
}
//---------------------------------------------------------------------------
hahaha_thread_command::hahaha_thread_command(hahaha_thread_command&& htc) noexcept
{
	Move(std::move(htc));

}
//---------------------------------------------------------------------------
hahaha_thread_command& hahaha_thread_command::operator=(const hahaha_thread_command& htc)
{
	Copy(htc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_command& hahaha_thread_command::operator=(hahaha_thread_command&& htc) noexcept
{
	if (this != &htc)
    {
        Move(std::move(htc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_command::Copy(const hahaha_thread_command& htc)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_command::Move(hahaha_thread_command&& htc) noexcept
{
    Thread_Id_ = htc.Thread_Id_;
	Thread_ = htc.Thread_;
    Event_Run_ = htc.Event_Run_;
    Event_Wait_ = htc.Event_Wait_;
	Event_Exit_ = htc.Event_Exit_;
    Mutex_ = std::move(htc.Mutex_);
    Queue_Command_ = std::move(htc.Queue_Command_);
    Is_Close_ = htc.Is_Close_;

    htc.Reset();

}
//---------------------------------------------------------------------------
int hahaha_thread_command::Reset()
{
	Thread_Id_ = 0;
	Thread_ = NULL;
    Event_Run_ = NULL;
    Event_Wait_ = NULL;
	Event_Exit_ = NULL;

    if(Mutex_.get() == NULL)
    {
        Mutex_.reset(new hahaha_mutex);
    }
    std::queue<std::unique_ptr<hahaha_thread_command_command>>().swap(Queue_Command_);
    Is_Close_ = false;

	return 0;
}
//---------------------------------------------------------------------------
DWORD WINAPI hahaha_thread_command::Thread_Start(void* parameter)
{
	hahaha_thread_command& self_ = *(hahaha_thread_command*)parameter;
	self_.Thread_Proc();

	return 0;

}

//---------------------------------------------------------------------------
int hahaha_thread_command::Thread_Proc()
{
	HANDLE handles_[2] = {Event_Run_, Event_Exit_};

	BOOL exit_ = FALSE;
	while(!exit_)
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
                while(!Is_Close_ && !Queue_Command_.empty())
                {
                    Mutex_->Lock();
                    hahaha_thread_command_command* p = Queue_Command_.front().get();
                    Queue_Command_.pop();
                    Mutex_->Un_Lock();
                    Handle(p);
                  
                }

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
int hahaha_thread_command::Handle(hahahalib::hahaha_thread_command_command* p)
{
	int eee = 0;

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_command::Create()
{
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

    Mutex_->Create();


	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_command::Close()
{
    Is_Close_ = true;
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
int hahaha_thread_command::Add_Command()
{
    Mutex_->Lock();

    std::unique_ptr<hahaha_thread_command_command> command_;
    command_.reset(new hahaha_thread_command_command);

    command_->Command_ = 0;
    command_->Parameter_ = nullptr;

    Queue_Command_.push(std::move(command_));
    SetEvent(Event_Run_);

    Mutex_->Un_Lock();
}
//---------------------------------------------------------------------------
int hahaha_thread_command::On_Command()
{

}
//---------------------------------------------------------------------------
int hahaha_thread_command::Terminate()
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
int hahaha_thread_command::Wait()
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

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------