#pragma once

#include "Koffieboon/Defines.h"
#include "Koffieboon/Window.h"
#include "Koffieboon/Events/Event.h"
#include "Koffieboon/Events/ApplicationEvent.h"

#include "Koffieboon/Layers/LayerStack.h"

#include "Koffieboon/ImGui/ImGuiLayer.h"

#include "Koffieboon/Renderer/Shader.h"

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
		/// <summary>
		/// ImGuiLayer pointer to the ImGuiLayer (Raw pointer)
		/// </summary>
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;

		std::unique_ptr<Shader> m_Shader;

	private:
		static Application* s_Instance;
	};

	// To be defined in the client. Client must implement this function.
	Application* CreateApplication();

}


