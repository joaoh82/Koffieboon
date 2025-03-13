#pragma once

#include "Koffieboon/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Koffieboon
{
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		
		virtual void SwapBuffers() override;

		virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
	
	private:
		GLFWwindow* m_WindowHandle;
	};
}