#pragma once

#include "Core.h"
#include "Defines.h"

namespace Koffieboon
{
	class KOFFIEBOON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in the client
	Application* CreateApplication();

}


