#include "kbpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Koffieboon
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());

		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		KB_TRACE(e.ToString());
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		// Testing events
		//WindowResizeEvent e(1280, 720);
		//if (e.IsInCategory(EventCategoryApplication))
		//{
		//	KB_TRACE(e.ToString());
		//}
		//if (e.IsInCategory(EventCategoryInput))
		//{
		//	KB_TRACE(e.ToString());
		//}

		while (m_Running)
		{
			//glClearColor(1, 0, 1, 1);/*
			//glClear(GL_COLOR_BUFFER_BIT);*/
			m_Window->OnUpdate();
		}
	}
}