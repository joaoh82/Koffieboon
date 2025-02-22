#pragma once

#include "Koffieboon/Defines.h"
#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging in release mode
#if KB_RELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

/// <summary>
/// The log levels that are available
/// </summary>
typedef enum LogLevel
{
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_ERROR = 1,
	LOG_LEVEL_WARN = 2,
	LOG_LEVEL_INFO = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5
} LogLevel;

namespace Koffieboon
{
	class KOFFIEBOON_API Logger
	{
	public:
		static void InitializeLogging();
		static void ShutdownLogging();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

		static void LogOutput(LogLevel level, const char* message, ...);

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}


// Define the logging macros

// These are always enabled
#define KB_CORE_FATAL(...)    ::Koffieboon::Logger::GetCoreLogger()->critical(__VA_ARGS__)
#define KB_FATAL(...)	      ::Koffieboon::Logger::GetClientLogger()->critical(__VA_ARGS__)

#define KB_CORE_ERROR(...)    ::Koffieboon::Logger::GetCoreLogger()->error(__VA_ARGS__)
#define KB_ERROR(...)	      ::Koffieboon::Logger::GetClientLogger()->error(__VA_ARGS__)

#if LOG_WARN_ENABLED
#define KB_CORE_WARN(...)     ::Koffieboon::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define KB_WARN(...)	      ::Koffieboon::Logger::GetClientLogger()->warn(__VA_ARGS__)
#else
#define KB_WARN(...)
#endif

#if LOG_INFO_ENABLED
#define KB_CORE_INFO(...)     ::Koffieboon::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define KB_INFO(...)	      ::Koffieboon::Logger::GetClientLogger()->info(__VA_ARGS__)
#else
#define KB_INFO(...)
#endif

#if LOG_DEBUG_ENABLED
#define KB_CORE_DEBUG(...)    ::Koffieboon::Logger::GetCoreLogger()->debug(__VA_ARGS__)
#define KB_DEBUG(...)	      ::Koffieboon::Logger::GetClientLogger()->debug(__VA_ARGS__)
#else
#define KB_DEBUG(...)
#endif

#if LOG_TRACE_ENABLED
#define KB_CORE_TRACE(...)    ::Koffieboon::Logger::GetCoreLogger()->trace(__VA_ARGS__)
#define KB_TRACE(...)	      ::Koffieboon::Logger::GetClientLogger()->trace(__VA_ARGS__)
#else
#define KB_TRACE(...)
#endif
