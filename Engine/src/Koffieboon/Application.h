#pragma once

#include "Defines.h"
#include "Window.h"

namespace Koffieboon
{
	class KOFFIEBOON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		// 
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in the client
	Application* CreateApplication();

}


