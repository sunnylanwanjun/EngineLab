#pragma once

#include "Log.h"

#ifdef ENGINE_DEBUG
#define ENGINE_ENABLE_ASSERTS
#endif

#ifdef ENGINE_ENABLE_ASSERTS
#define ENGINE_ASSERT_NO_MESSAGE(condition) {if(!condition) {ENGINE_ERROR("Assertion Failed"); __debugbreak(); } }
#define ENGINE_ASSERT_MESSAGE(condition, ...) {if(!condition) {ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
// 当参数只有一个时，condition, ENGINE_ASSERT_MESSAGE, ENGINE_ASSERT_NO_MESSAGE, macro此时等于ENGINE_ASSERT_NO_MESSAGE
// 当参数是两个时，condition, msg, ENGINE_ASSERT_MESSAGE, ENGINE_ASSERT_NO_MESSAGE, macro此时等于ENGINE_ASSERT_MESSAGE
#define ENGINE_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro
#define ENGINE_GET_ASSERT_MACRO(...) ENGINE_ASSERT_RESOLVE(__VA_ARGS__, ENGINE_ASSERT_MESSAGE, ENGINE_ASSERT_NO_MESSAGE)
#define ENGINE_ASSERT(...) ENGINE_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__)
#define ENGINE_CORE_ASSERT(...) ENGINE_GET_ASSERT_MACRO(__VA_ARGS__)(__VA_ARGS__)
#else
#define ENGINE_ASSERT(...)
#define ENGINE_CORE_ASSERT(...)
#endif