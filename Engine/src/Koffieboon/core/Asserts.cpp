#include "kbpch.h"
#include "Asserts.h"
#include "Logger.h"

KOFFIEBOON_API void ReportAssertionFailure(const char* expression, const char* message, const char* file, u32 line)
{
	Koffieboon::Logger::LogOutput(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
	//KB_CORE_WARN("Assertion Failure: %s, message: '%s', in file: %s, line: %d\n", expression, message, file, line);
}
