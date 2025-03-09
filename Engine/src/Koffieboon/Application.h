#pragma once

#include "Koffieboon/Defines.h"
#include "Koffieboon/Window.h"
#include "Koffieboon/Events/Event.h"
#include "Koffieboon/Events/ApplicationEvent.h"

#include "Koffieboon/Layers/LayerStack.h"

namespace Koffieboon
{
	class KOFFIEBOON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in the client
	Application* CreateApplication();

}


