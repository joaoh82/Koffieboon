#include "kbpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Koffieboon
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		KASSERT_MSG(windowHandle, "Window handle is null!");
	}
	
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		KASSERT_MSG(status, "Failed to initialize Glad!");

		KB_CORE_INFO("OpenGL Info:");
	/*	KB_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		KB_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		KB_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));*/
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

	void OpenGLContext::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}


} // namespace Koffieboon