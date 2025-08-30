//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_semaphore.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <lock\hahaha_semaphore.h>
//hahahalib::hahaha_semaphore Semaphore_;
//Semaphore_.Create(L"test", 4, 4);
//Semaphore_.Lock();
//Semaphore_.Un_Lock();
//Semaphore_.Close();
//---------------------------------------------------------------------------
hahaha_semaphore::hahaha_semaphore()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_semaphore::~hahaha_semaphore()
{

}
//---------------------------------------------------------------------------
hahaha_semaphore::hahaha_semaphore(const hahaha_semaphore& hs)
{
	Copy(hs);
}
//---------------------------------------------------------------------------
hahaha_semaphore::hahaha_semaphore(hahaha_semaphore&& hs) noexcept
{
	Move(std::move(hs));
}
//---------------------------------------------------------------------------
hahaha_semaphore& hahaha_semaphore::operator=(const hahaha_semaphore& hs)
{
	Copy(hs);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_semaphore& hahaha_semaphore::operator=(hahaha_semaphore&& hs) noexcept
{
	if (this != &hs)
    {
        Move(std::move(hs));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_semaphore::Copy(const hahaha_semaphore& hs)
{

}
//---------------------------------------------------------------------------
void hahaha_semaphore::Move(hahaha_semaphore&& hs) noexcept
{
    Semaphore_ = hs.Semaphore_;
	Name_ = std::move(hs.Name_);
	Count_Initial_ = hs.Count_Initial_;
	Count_Max_ = hs.Count_Max_;

    hs.Reset();
}
//---------------------------------------------------------------------------
int hahaha_semaphore::Reset()
{
	Semaphore_ = NULL;
	Name_ = L"";
	Count_Initial_ = 0;
	Count_Max_ = 0;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_semaphore::Create(const std::wstring& name,const int& count_initial, const int& count_max)
{
	if(Semaphore_ != NULL)
	{
		Close();
	}
	Semaphore_ = CreateSemaphoreW(
        NULL,           // default security attributes
		count_initial,  // initial count
		count_max,  // maximum count
		name.c_str()
	);

	if(Semaphore_ == NULL)
	{
		Semaphore_ = OpenSemaphoreW(
			NULL,
			FALSE,
			name.c_str()
		);

		if(Semaphore_ == NULL)
		{
			Name_ = L"";
			return -1;
		}
	}

	if(Semaphore_ != NULL)
	{
		Name_ = name;
		Count_Initial_ = count_initial;
		Count_Max_ = count_max;
	}

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_semaphore::Close()
{
	if(Semaphore_ != NULL)
	{
		CloseHandle(Semaphore_);
		Semaphore_ = NULL;
		Name_ = L"";
		Count_Initial_ = 0;
		Count_Max_ = 0;
	}

	return 0;

}
//---------------------------------------------------------------------------
hahaha_define_sync hahaha_semaphore::Lock(const DWORD& milliseconds)
{
	DWORD result = WaitForSingleObject(
		Semaphore_,    // handle to mutex
		milliseconds
	);  // no time-out interval

	switch (result)
	{
		// The thread got ownership of the mutex
		case WAIT_OBJECT_0:

			break;
		case WAIT_TIMEOUT:
			return hahaha_define_sync::TIMEOUT;
		// The thread got ownership of an abandoned mutex
		// The database is in an indeterminate state
		case WAIT_ABANDONED:
			return hahaha_define_sync::ABANDONED;
	}

	return hahaha_define_sync::OK;
}
//---------------------------------------------------------------------------
int hahaha_semaphore::Un_Lock()
{
    if(Semaphore_ != NULL)
	{
		ReleaseSemaphore(
			Semaphore_,  // handle to semaphore
			1,            // increase count by one
			NULL
			);
	}

    return 0;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------