//---------------------------------------------------------------------------

#pragma hdrstop

#include "hahaha_mutex.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//---------------------------------------------------------------------------
namespace hahahalib
{
//---------------------------------------------------------------------------
//#include <lock\hahaha_mutex.h>
//hahahalib::hahaha_mutex Mutex_;
//Mutex_.Create(L"test");
//Mutex_.Lock();
//Mutex_.Un_Lock();
//Mutex_.Close();
//---------------------------------------------------------------------------
hahaha_mutex::hahaha_mutex()
{
	Reset();
}
//---------------------------------------------------------------------------
hahaha_mutex::~hahaha_mutex()
{
	Close();
}
//---------------------------------------------------------------------------
hahaha_mutex::hahaha_mutex(const hahaha_mutex& hm)
{
	Copy(hm);
}
//---------------------------------------------------------------------------
hahaha_mutex::hahaha_mutex(hahaha_mutex&& hm) noexcept
{
	Move(std::move(hm));
}
//---------------------------------------------------------------------------
hahaha_mutex& hahaha_mutex::operator=(const hahaha_mutex& hm)
{
	Copy(hm);

	return *this;
}
//---------------------------------------------------------------------------
hahaha_mutex& hahaha_mutex::operator=(hahaha_mutex&& hm) noexcept
{
	if (this != &hm)
    {
        Move(std::move(hm));
    }

	return *this;
}
//---------------------------------------------------------------------------
void hahaha_mutex::Copy(const hahaha_mutex& hm)
{

}
//---------------------------------------------------------------------------
void hahaha_mutex::Move(hahaha_mutex&& hm) noexcept
{
    Mutex_ = hm.Mutex_;
    Name_ = std::move(hm.Name_);

    hm.Mutex_ = nullptr;
}
//---------------------------------------------------------------------------
int hahaha_mutex::Reset()
{
	Mutex_ = NULL;

	return 0;
}
//---------------------------------------------------------------------------
int hahaha_mutex::Create(const std::wstring& name, BOOL lock)
{
	if(Mutex_ != NULL)
	{
		Close();
	}
	Mutex_ = CreateMutexW(NULL,
		lock,
		name.c_str()
	);

	if(Mutex_ == NULL)
	{
		Mutex_ = OpenMutexW(
		  NULL,
		  FALSE,
		  name.c_str()
		);

        if(Mutex_ == NULL)
		{
			Name_ = L"";
			return -1;
		}
	}

    if(Mutex_ != NULL)
	{
		Name_ = name;
	}

	return 0;

}
//---------------------------------------------------------------------------
int hahaha_mutex::Close()
{
	if(Mutex_ != NULL)
	{
		CloseHandle(Mutex_);
		Mutex_ = NULL;
		Name_ = L"";
	}
    return 0;
}
//---------------------------------------------------------------------------
hahaha_define_sync hahaha_mutex::Lock(const DWORD& milliseconds)
{
	DWORD result = WaitForSingleObject(
		Mutex_,    // handle to mutex
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
int hahaha_mutex::Un_Lock()
{
    if(Mutex_ != NULL)
	{
		ReleaseMutex(Mutex_);
	}

    return 0;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
} // hahahalib
//---------------------------------------------------------------------------