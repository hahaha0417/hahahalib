//---------------------------------------------------------------------------

#pragma hdrstop
//---------------------------------------------------------------------------
#include <utility>
#include <lock\hahaha_mutex.h>
#include <thread_pool\base\hahaha_thread_pool_command_command.h>
//---------------------------------------------------------------------------
#include "hahaha_thread_pool_command.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

// 因為要指定CPU，所以弄傳統thread pool
//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
hahaha_thread_pool_command::hahaha_thread_pool_command()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command::~hahaha_thread_pool_command()
{

}
//---------------------------------------------------------------------------
hahaha_thread_pool_command::hahaha_thread_pool_command(const hahaha_thread_pool_command& htpc)
{
    Reset();
	Copy(htpc);
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command::hahaha_thread_pool_command(hahaha_thread_pool_command&& htpc) noexcept
{
    Move(std::move(htpc));
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command& hahaha_thread_pool_command::operator=(const hahaha_thread_pool_command& htpc)
{
	Copy(htpc);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_thread_pool_command& hahaha_thread_pool_command::operator=(hahaha_thread_pool_command&& htpc) noexcept
{
	if (this != &htpc)
    {
        Move(std::move(htpc));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_thread_pool_command::Copy(const hahaha_thread_pool_command& htpc)
{

}
//---------------------------------------------------------------------------
void hahaha_thread_pool_command::Move(hahaha_thread_pool_command&& htpc) noexcept
{

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Reset()
{
    if(Mutex_.get() == NULL)
    {
        Mutex_.reset(new hahaha_mutex);
    }
    std::queue<std::unique_ptr<hahaha_thread_pool_command_command>>().swap(Queue_Command_);
    Is_Close_ = false;

	return 0;
}
//---------------------------------------------------------------------------
DWORD WINAPI hahaha_thread_pool_command::Thread_Start(void* parameter)
{
	hahaha_thread_pool_command& self_ = *(hahaha_thread_pool_command*)parameter;
	self_.Thread_Proc();

	return 0;

}

//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Thread_Proc()
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
                    hahaha_thread_pool_command_command* p = Queue_Command_.front().get();
                    Queue_Command_.pop();
                    Mutex_->Un_Lock();
                    Handle(p);
                    Mutex_->Lock();

                    if(Queue_Command_.empty())
                    {
                        ResetEvent(Event_Run_);
                        SetEvent(Event_Wait_);
                        break;

                    }
                    Mutex_->Un_Lock();
                }



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
int hahaha_thread_pool_command::Handle(hahahalib::hahaha_thread_pool_command_command* p)
{
	int eee = 0;

    return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Create(const int& thread_count)
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

    Threads_.resize(thread_count);
    Thread_Ids_.resize(thread_count);
    for(int i = 0; i < thread_count; i++)
    {
        Threads_[i] = CreateThread(NULL,
            0,
            Thread_Start,
            (void*)this,
            0,
            &Thread_Ids_[i]
        );
    }


    Mutex_->Create();


	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Close()
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

    int n = Threads_.size();
    for(int i = 0; i < n; i++)
    {
        CloseHandle(Threads_[i]);

    }
    std::vector<DWORD>().swap(Thread_Ids_);
	std::vector<HANDLE>().swap(Threads_);


	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Add_Command()
{
    Mutex_->Lock();

    std::unique_ptr<hahaha_thread_pool_command_command> command_;
    command_.reset(new hahaha_thread_pool_command_command);

    command_->Command_ = 0;
    command_->Parameter_ = nullptr;

    Queue_Command_.push(std::move(command_));
    SetEvent(Event_Run_);

    Mutex_->Un_Lock();
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::On_Command()
{
    return 0;
}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Terminate()
{
    int n = Threads_.size();
    for(int i = 0; i < n; i++)
    {
        TerminateThread(Threads_[i] , 0);
        CloseHandle(Threads_[i]);
    }
    std::vector<DWORD>().swap(Thread_Ids_);
	std::vector<HANDLE>().swap(Threads_);

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_thread_pool_command::Wait()
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