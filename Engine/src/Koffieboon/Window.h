#pragma once

#include "kbpch.h"

namespace Koffieboon
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Koffieboon Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class KOFFIEBOON_API Window 
	{
		public:
			//Window(const WindowProps& props);
			
			// Class destructor
			virtual ~Window() {};

			virtual void OnUpdate() = 0;

			// Window size attributes
			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			//void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			
			static Window* Create(const WindowProps& props = WindowProps());
	};

}