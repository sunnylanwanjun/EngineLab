#pragma once

#ifdef _WIN32
	//define something for Windows (32-bit and 64-bit, this part is common)
	#define ENGINE_PLATFORM_WINDOWS
	#ifdef _WIN64
	   //define something for Windows (64-bit only)
	#else
	   //define something for Windows (32-bit only)
	#endif
#elif __APPLE__
	#include "TargetConditionals.h"
	#if TARGET_IPHONE_SIMULATOR
		#define ENGINE_PLATFORM_IPHONE_SIMULATOR
	// iOS Simulator
	#elif TARGET_OS_IPHONE
		#define ENGINE_PLATFORM_IPHONE
	// iOS device
	#elif TARGET_OS_MAC
		#define ENGINE_PLATFORM_MAC
	// Other kinds of Mac OS
	#else
	#   error "Unknown Apple platform"
	#endif
#elif __ANDROID__
	#define ENGINE_PLATFORM_ANDROID
// android
#elif __linux__
	#define ENGINE_PLATFORM_LINUX
// linux
#elif __unix__ // all unices not caught above
	#define ENGINE_PLATFORM_UNIX
// Unix
#elif defined(_POSIX_VERSION)
// POSIX
#else
#   error "Unknown compiler"
#endif

// 如果是数字的话，就不需要##连字符
#define BIT(x) (1 << x)

#define ENGINE_BIND_EVENT_FN(fn) std::bind(&##fn, this, std::placeholders::_1)