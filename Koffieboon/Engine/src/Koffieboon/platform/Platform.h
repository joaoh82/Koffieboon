#pragma once

#include "../Defines.h"

typedef struct platform_state
{
	void* internal_state;
} platform_state;

b8 PlatformStartup(
	platform_state* plat_state,
	const char* application_name,
	i32 x,
	i32 y,
	i32 width,
	i32 height);

void PlatformShutdown(platform_state* plat_state);

b8 PlatformPumpMessages(platform_state* plat_state);

void* PlatformAllocate(u64 size, b8 aligned);

void PlatformFree(void* memory_block, b8 aligned);

void* PlatformZeroMemory(void* memory_block, u64 size);

void* PlatformCopyMemory(void* destination, const void* source, u64 size);

void* PlatformSetMemory(void* destination, i32 value, u64 size);