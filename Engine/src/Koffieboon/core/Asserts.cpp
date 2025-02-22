#include "kbpch.h"
#include "Asserts.h"
#include "Logger.h"

KOFFIEBOON_API void ReportAssertionFailure(const char* expression, const char* message, const char* file, u32 line)
{
	KB_CORE_WARN("Assertion Failure: {}, message: '{}', in file: {}, line: {}\n", expression, message, file, line);
}
