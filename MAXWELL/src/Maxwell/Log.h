#pragma once

#include "spdlog\spdlog.h"

#include "Core.h"

namespace Maxwell {

	class MAXWELL_API Log {

	private:

		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;

	public:

		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCorelogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientlogger() { return s_clientLogger; }
	};
}

// Core Log marcos
#define MW_CORE_TRACE(...)		::Maxwell::Log::getCorelogger()->trace(__VA_ARGS__)
#define MW_CORE_INFO(...)		::Maxwell::Log::getCorelogger()->info(__VA_ARGS__)
#define MW_CORE_WARN(...)		::Maxwell::Log::getCorelogger()->warn(__VA_ARGS__)
#define MW_CORE_ERROR(...)		::Maxwell::Log::getCorelogger()->error(__VA_ARGS__)
#define MW_CORE_CRITICAL(...)	::Maxwell::Log::getCorelogger()->critical(__VA_ARGS__)

// Client Log macros
#define MW_TRACE(...)			::Maxwell::Log::getClientlogger()->trace(__VA_ARGS__)
#define MW_INFO(...)			::Maxwell::Log::getClientlogger()->info(__VA_ARGS__)
#define MW_WARN(...)			::Maxwell::Log::getClientlogger()->warn(__VA_ARGS__)
#define MW_ERROR(...)			::Maxwell::Log::getClientlogger()->error(__VA_ARGS__)
#define MW_CRITICAL(...)		::Maxwell::Log::getClientlogger()->critical(__VA_ARGS__)