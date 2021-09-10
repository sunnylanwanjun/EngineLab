#pragma once

#ifdef ENGINE_WINDOWS_PLATFORM
	#ifdef ENGINE_BUILD_DLL
		#define ENGINE_API _declspec(dllexport)
	#else
		#define ENGINE_API _declspec(dllimport)
	#endif
#else
	#error Only Support Windows Platform!
#endif