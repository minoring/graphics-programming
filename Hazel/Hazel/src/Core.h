#pragma once

#ifdef _WIN64
  #define HZ_PLATFORM_WINDOWS
  #define DEBUG_BREAK __debugbreak();
#else
  #ifdef __linux__
    #define HZ_PLATFORM_LINUX
    #define DEBUG_BREAK __builtin_debugtrap();
  #else // __APPLE__
    #define HZ_PLATFORM_MAC
    #define DEBUG_BREAK __builtin_debugtrap()
  #endif
#endif

#ifdef HZ_ENABLE_ASSERTS
  #define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); DEBUG_BREAK }}
  #define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); DEBUG_BREAK }}
#else
  #define HZ_ASSERT(x, ...)
  #define HZ_CORE_ASSERT(x, ...)
#endif

#ifdef HZ_PLATFORM_WINDOWS
  #ifdef HZ_BUILD_DLL
    #define HAZEL_API __declspec(dllexport)
  #else
    #define HAZEL_API __declspec(dllimport) 
  #endif
#else
  #ifdef HZ_PLATFORM_LINUX
    #define HAZEL_API
  #else // HZ_PLATFORM_MAC
    #define HAZEL_API
  #endif
#endif

#define BIT(x) (1 << x)
