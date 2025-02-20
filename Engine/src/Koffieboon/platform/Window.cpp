#include "kbpch.h"
#include "Window.h"
#include <iostream>

namespace Koffieboon
{
	Window::Window(i32 width, i32 height, const char* application_name)
	{
		if (!glfwInit())
		{
			KB_ERROR("Failed to initialize GLFW");
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(width, height, application_name, nullptr, nullptr);
		if (!m_Window)
		{
			KB_ERROR("Failed to create GLFW window");
			glfwTerminate();
		}
		glfwMakeContextCurrent(m_Window);
	}

	Window::~Window() {
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void Window::PollEvents() {
		glfwPollEvents();
	}

	bool Window::ShouldClose() const {
		return glfwWindowShouldClose(m_Window);
	}
} // namespace Koffieboon