#include "kbpch.h"
#include "WindowsGLFW.h"

// Events include
#include "Koffieboon/Events/ApplicationEvent.h"
#include "Koffieboon/Events/KeyEvent.h"
#include "Koffieboon/Events/MouseEvent.h"

namespace Koffieboon
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		KB_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

#ifdef KB_PLATFORM_WINDOWS
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsGLFW(props);
	}
#endif
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

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

#pragma region OpenGL

		//// Setup OpenGL Version
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		//// Core profile = no backwards compatibility
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		//// Forward compatibility = no deprecated functionality
		//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		// Create window
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		if (!m_Window)
		{
			KB_CORE_ERROR("Could not create window!");
			Shutdown();
		}

		// Get buffer size information
		int bufferWidth, bufferHeight;
		glfwGetFramebufferSize(m_Window, &bufferWidth, &bufferHeight);

		// Set context for GLEW to use
		glfwMakeContextCurrent(m_Window);

		//// Allow modern extension features
		//glewExperimental = GL_TRUE;

		//if (glewInit() != GLEW_OK)
		//{
		//	KB_CORE_ERROR("Could not initialize GLEW!");
		//	Shutdown();
		//}

#pragma endregion

		// Setup viewport size
		//glViewport(0, 0, bufferWidth, bufferHeight);

		// Set GLFW window user pointer
		//glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		// Set GLFW event callbacks
		SetGLFWCallbacks();
	}

	/// <summary>
	/// SetGLFWCallbacks is a function that sets the GLFW event callbacks.
	/// </summary>
	void WindowsGLFW::SetGLFWCallbacks()
	{
		// Set GLFW event callbacks

		// Window resize callback
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		// Window close callback
		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		// Key callback
		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		// Mouse button callback
		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		// Mouse scroll callback
		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		// Mouse move callback
		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WindowsGLFW::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
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