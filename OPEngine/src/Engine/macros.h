#pragma once
//#include "Log.h"

#ifdef OPE_PLATFORM_WINDOWS
	#ifdef OPE_BUILD_DLL
		#define OPE_API __declspec(dllexport)
	#else
		#define OPE_API __declspec(dllimport)
	#endif
#else 
	#error OPEngine only supports Windows. For now.
#endif

