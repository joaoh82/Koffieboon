#pragma once

#include "../Defines.h"

// Disable assertions by commenting out this line
#define KB_ENABLE_ASSERTS

#ifdef KB_ENABLE_ASSERTS

#include <intrin.h>
#define debugBreak() __debugbreak()

KOFFIEBOON_API void ReportAssertionFailure(const char* expression, const char* message, const char* file, u32 line);

#define KASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            ReportAssertionFailure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define KASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            ReportAssertionFailure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define KASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            ReportAssertionFailure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define KASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define KASSERT(expr)               // Does nothing at all
#define KASSERT_MSG(expr, message)  // Does nothing at all
#define KASSERT_DEBUG(expr)         // Does nothing at all
#endif