#include "kbpch.h"
#include "WindowsGLFW.h"

namespace Koffieboon
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsGLFW(props);
	}

	WindowsGLFW::WindowsGLFW(const WindowProps& props)
	{
		Init(props);
	}

	WindowsGLFW::~WindowsGLFW()
	{
		Shutdown();
	}

	void WindowsGLFW::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;
		KB_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		// Initialize GLFW
		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			KASSERT_MSG(success, "Could not initialize GLFW!");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsGLFW::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsGLFW::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsGLFW::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		
		m_Data.VSync = enabled;
	}

	bool WindowsGLFW::IsVSync() const
	{
		return m_Data.VSync;
	}


} // namespace Koffieboon