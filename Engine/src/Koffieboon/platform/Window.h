#pragma once

#include "kbpch.h"

#include <GLFW/glfw3.h>
#include <string>

namespace Koffieboon
{
	struct WindowProps
	{
		std::string Title;
		i32 Width;
		i32 Height;
		WindowProps(const std::string& title = "Koffieboon Engine",
			i32 width = 1280,
			i32 height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

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