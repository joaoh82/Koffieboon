#pragma once

#include "../Defines.h"
#include "../core/Logger.h"

#include <GLFW/glfw3.h>
#include <string>

namespace Koffieboon
{
	class KOFFIEBOON_API Window {
	public:
		Window(i32 width, i32 height, const char* application_name);
	
		~Window();

		void PollEvents();
	
		bool ShouldClose() const;
	
		GLFWwindow* GetWindow() { return m_Window; };

	private:
		GLFWwindow* m_Window;
	};
} // namespace Koffieboon