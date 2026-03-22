//---------------------------------------------------------------------------

#ifndef include_allH
#define include_allH
//---------------------------------------------------------------------------

#if defined(__WIN32)
    //----------------------------------------------
	#pragma comment(lib, "hahahalib.lib")
	#pragma comment(lib, "hahahatestlib.lib")
	#pragma comment(lib, "hahahavcllib.lib")
	#pragma comment(lib, "hahahadumplib.lib")
	#pragma comment(lib, "hahahagarbagelib.lib")
	#pragma comment(lib, "hahaharecyclelib.lib")
    //----------------------------------------------
    // 指令集包
    #pragma comment(lib, "hahahaISAlib.lib")
    //----------------------------------------------
    // ipp
    //----------------------------------------------
    #pragma comment(lib, "ippcore.lib")
    #pragma comment(lib, "ippvm.lib")
    #pragma comment(lib, "ipps.lib")
    #pragma comment(lib, "ippi.lib")
    #pragma comment(lib, "ippcc.lib")
	//---------------------------------------------------------------------------
	// https://ftp.zlatkovic.com/pub/libxml/64bit/
	// MIT
	#pragma comment(lib, "libxml2-2.lib")
	// LGPL
	#pragma comment(lib, "libiconv-2.lib")
	// ZLIB
	#pragma comment(lib, "zlib1.lib")
	//---------------------------------------------------------------------------

#elif defined(__WIN64)
	#pragma comment(lib, "hahahalib.a")
	#pragma comment(lib, "hahahatestlib.a")
	#pragma comment(lib, "hahahavcllib.a")
	#pragma comment(lib, "hahahadumplib.a")
	#pragma comment(lib, "hahahagarbagelib.a")
	#pragma comment(lib, "hahaharecyclelib.a")
    //----------------------------------------------
    // 指令集包
    #pragma comment(lib, "hahahaISAlib.a")
    //----------------------------------------------
    // ipp
    //----------------------------------------------
    #pragma comment(lib, "ippcore.a")
    #pragma comment(lib, "ippvm.a")
    #pragma comment(lib, "ipps.a")
    #pragma comment(lib, "ippi.a")
    #pragma comment(lib, "ippcc.a")
	//---------------------------------------------------------------------------
    // https://ftp.zlatkovic.com/pub/libxml/64bit/
	// MIT
	#pragma comment(lib, "libxml2-2.a")
	// LGPL
	#pragma comment(lib, "libiconv-2.a")
	// ZLIB
	#pragma comment(lib, "zlib1.a")
	//---------------------------------------------------------------------------

#elif defined(__WIN64_MODERN)
	#pragma comment(lib, "hahahalib.lib")
	#pragma comment(lib, "hahahatestlib.lib")
	#pragma comment(lib, "hahahavcllib.lib")
	#pragma comment(lib, "hahahadumplib.lib")
	#pragma comment(lib, "hahahagarbagelib.lib")
	#pragma comment(lib, "hahaharecyclelib.lib")
    //----------------------------------------------
    // 指令集包
    #pragma comment(lib, "hahahaISAlib.lib")
    //----------------------------------------------
    // ipp
    //----------------------------------------------
    #pragma comment(lib, "ippcore.a")
    #pragma comment(lib, "ippvm.a")
    #pragma comment(lib, "ipps.a")
    #pragma comment(lib, "ippi.a")
    #pragma comment(lib, "ippcc.a")
	//---------------------------------------------------------------------------
    // https://ftp.zlatkovic.com/pub/libxml/64bit/
	// MIT
	#pragma comment(lib, "libxml2-2.lib")
	// LGPL
	#pragma comment(lib, "libiconv-2.lib")
	// ZLIB
	#pragma comment(lib, "zlib1.lib")
	//---------------------------------------------------------------------------



#endif

#endif
