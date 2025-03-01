#include "kbpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Koffieboon/Events/ApplicationEvent.h"

namespace Koffieboon
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		// Testing events
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			KB_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			KB_TRACE(e.ToString());
		}

		while (m_Running)
		{
			//glClearColor(1, 0, 1, 1);/*
			//glClear(GL_COLOR_BUFFER_BIT);*/
			m_Window->OnUpdate();
		}
	}
}