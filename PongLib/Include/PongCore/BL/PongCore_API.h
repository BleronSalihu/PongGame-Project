#pragma once

#ifdef __BUILD_PONGCORE_DLL__
#define PONGCORE_API __declspec(dllexport)
#endif

#ifdef __USE_PONGCORE_DLL__
#define PONGCORE_API __declspec(dllimport)
#endif
