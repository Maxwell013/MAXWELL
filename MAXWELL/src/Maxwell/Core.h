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

#ifdef MW_ENABLE_ASSERTS
	#define MW_CORE_ASSERT(x, ...) { if(!(x) { MW_CORE_ERROR("Assertion failed! : {0}", __VA_ARGS__); __debugbreak(); } }
	#define MW_ASSERT(x, ...) { if(!(x) { MW_ERROR("Assertion failed! : {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define MW_CORE_ASSERT(x, ...)
	#define MW_ASSERT(x, ...)
#endif // MW_ENABLE_ASSERTS

#define BIT(x) (1 << x)