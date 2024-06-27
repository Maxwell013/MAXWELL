#pragma once

#ifdef MW_PLATFORM_WINDOWS
	#ifdef MW_BUILD_DLL
		#define MAXWELL_API __declspec(dllexport)
	#else
		#define MAXWELL_API __declspec(dllimport)
	#endif // MW_BUILD_DLL
#else
	#error Maxwell only supports Windows!
#endif // MW_PLATFORM_WINDOWS

#define BIT(x) (1 << x)