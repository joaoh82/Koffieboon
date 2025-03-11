#include "kbpch.h"
#include "Application.h"

#include <glad/glad.h>

#include "Input.h"

namespace Koffieboon
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		KASSERT_MSG(!s_Instance, "Application already exists!");

		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());

		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		// Add ImGuiLayer to the layer stack
		PushOverlay(m_ImGuiLayer);

		// Generate Vertex Array. It works because we have GLEW
		// TODO: Debug code. Remove this.
		// unsigned int id;
		// glGenVertexArrays(1, &id);
	}
	Application::~Application()
	{
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		KB_CORE_TRACE(e.ToString());

		// Dispatch event to layers. Iterate through the layer stack from end to beginning.
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			// Update layers
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			//auto [x, y] = Input::GetMousePosition();
			//KB_CORE_TRACE("Mouse position: {0}, {1}", x, y);

			// Render ImGui
			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}
}