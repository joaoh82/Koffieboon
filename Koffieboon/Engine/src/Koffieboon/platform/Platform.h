#pragma once

#include "../Defines.h"
#include "GLFW/glfw3.h"

typedef enum WindowMode
{
	WindowMode_Windowed,
	WindowMode_Fullscreen
} WindowMode;

KOFFIEBOON_API b8 PlatformStartup(
	i32 width,
	i32 height,
	const char* application_name,
	WindowMode window_mode,
	GLFWwindow* share);

void PlatformShutdown();

b8 PlatformPumpMessages(GLFWwindow* window);
