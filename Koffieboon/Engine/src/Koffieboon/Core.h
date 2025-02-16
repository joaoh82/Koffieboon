#pragma once

#ifdef KB_PLATFORM_WINDOWS
	#ifdef KB_BUILD_DLL
		#define KOFFIEBOON_API __declspec(dllexport)
	#else
		#define KOFFIEBOON_API __declspec(dllimport)
	#endif
#else
	#error "Koffieboon only supports windows for now!"
#endif