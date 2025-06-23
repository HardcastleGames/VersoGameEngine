#pragma once

#ifdef V_PLATFORM_WINDOWS
#ifdef V_BUILD_DLL
#define VERSO_API __declspec(dllexport)
#else
#define VERSO_API __declspec(dllimport)
#endif
#else 
#error Verso only supports Windows!
#endif
