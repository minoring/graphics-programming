#pragma once

#ifdef _WIN64
  #define HZ_PLATFORM_WINDOWS
#else
  #ifdef __linux__
    #define HZ_PLATFORM_LINUX
  #else // __APPLE__
    #define HZ_PLATFORM_MAC
  #endif
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
