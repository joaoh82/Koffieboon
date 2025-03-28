#pragma once

// Unsigned integer types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed integer types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean type
typedef bool b8;
typedef int b32;

/// <summary>
/// BIT is a macro that returns the bit at the specified index.
/// </summary>
#define BIT(x) (1 << x)

#define KB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

// Properly define static assertions
#define STATIC_ASSERT(expression, message) static_assert(expression, message)

// Ensure all types are of the correct size
STATIC_ASSERT(sizeof(u8) == 1, "u8 is not 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "u16 is not 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "u32 is not 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "u64 is not 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "i8 is not 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "i16 is not 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "i32 is not 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "i64 is not 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "f32 is not 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "f64 is not 8 bytes");

#define TRUE 1
#define FALSE 0

#ifdef KB_PLATFORM_WINDOWS
#ifdef KB_DYNAMIC_LINK
	#ifdef KB_BUILD_DLL
	#define KOFFIEBOON_API __declspec(dllexport)
	#else
	#define KOFFIEBOON_API __declspec(dllimport)
	#endif
#else
#define KOFFIEBOON_API
#endif
#else
#error "Koffieboon only supports windows for now!"
#endif

//xcopy / Y "$(SolutionDir)bin\$(Configuration)-$(Platform)\Engine\engine.dll" "$(OutDir)"
// 
//opengl32.lib; glew32.lib; glfw3.lib
//$(SolutionDir)Engine\vendor\glew\lib\Release\x64; $(SolutionDir)Engine\vendor\glfw\lib