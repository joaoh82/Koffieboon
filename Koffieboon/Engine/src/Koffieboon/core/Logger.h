#pragma once

#include "../Defines.h"

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
		static b8 InitializeLogging();
		static void ShutdownLogging();


		static void LogOutput(LogLevel level, const char* message, ...);
	};
}

// Define the logging macros
#define KB_FATAL(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_FATAL, message, __VA_ARGS__)

#define KB_ERROR(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_ERROR, message, __VA_ARGS__)

#if LOG_WARN_ENABLED
#define KB_WARN(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_WARN, message, __VA_ARGS__)
#else
#define KB_WARN(...)
#endif

#if LOG_INFO_ENABLED
#define KB_INFO(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_INFO, message, __VA_ARGS__)
#else
#define KB_INFO(...)
#endif

#if LOG_DEBUG_ENABLED
#define KB_DEBUG(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_DEBUG, message, __VA_ARGS__)
#else
#define KB_DEBUG(...)
#endif

#if LOG_TRACE_ENABLED
#define KB_TRACE(message, ...) Koffieboon::Logger::LogOutput(LogLevel::LOG_LEVEL_TRACE, message, __VA_ARGS__)
#else
#define KB_TRACE(...)
#endif
