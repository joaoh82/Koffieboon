#include "kbpch.h"
#include "Logger.h"


#include "spdlog/sinks/stdout_color_sinks.h"

namespace Koffieboon
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::InitializeLogging()
	{
		// For now, we don't need to do anything to initialize logging
		// TODO: Add file logging

		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("KOFFIEBOON");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
	
	/// <summary>
	/// Shuts down the logging system
	/// </summary>
	void Logger::ShutdownLogging()
	{
		// TODO: Clean up any resources that were allocated for logging
	}

}

