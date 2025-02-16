#include "Logger.h"
#include "Asserts.h"

#include <stdio.h>
#include <stdarg.h>

namespace Koffieboon
{
	b8 Logger::InitializeLogging()
	{
		// For now, we don't need to do anything to initialize logging
		// TODO: Add file logging
		return TRUE;
	}
	
	/// <summary>
	/// Shuts down the logging system
	/// </summary>
	void Logger::ShutdownLogging()
	{
		// TODO: Clean up any resources that were allocated for logging
	}

	/// <summary>
	/// Logs a message to the console
	/// </summary>
	/// <param name="level"></param>
	/// <param name="message"></param>
	/// <param name=""></param>
	void Logger::LogOutput(LogLevel level, const char* message, ...)
	{
		va_list args;
		va_start(args, message);
		switch (level)
		{
		case LogLevel::LOG_LEVEL_FATAL:
			printf("[FATAL]: ");
			break;
		case LogLevel::LOG_LEVEL_ERROR:
			printf("[ERROR]: ");
			break;
		case LogLevel::LOG_LEVEL_WARN:
			printf("[WARN]: ");
			break;
		case LogLevel::LOG_LEVEL_INFO:
			printf("[INFO]: ");
			break;
		case LogLevel::LOG_LEVEL_DEBUG:
			printf("[DEBUG]: ");
			break;
		case LogLevel::LOG_LEVEL_TRACE:
			printf("[TRACE]: ");
			break;
		default:
			break;
		}
		vprintf(message, args);
		va_end(args);
	}

}

