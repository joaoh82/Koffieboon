#pragma once

#include "kbpch.h"
#include "Koffieboon/Events/Event.h"

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

	// Interface representing a desktop system based Window. Mobile dont have windows, they have views or surfaces.
	class KOFFIEBOON_API Window 
	{
		public:
			using EventCallbackFn = std::function<void(Event&)>;
			
			// Class destructor
			virtual ~Window() = default;

			virtual void OnUpdate() = 0;

			// Window size attributes
			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			// Window attributes
			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			/// <summary>
			/// GetNativeWindow is a function that returns a pointer to the native window.
			/// </summary>
			/// <returns></returns>
			virtual void* GetNativeWindow() const = 0;

			/// <summary>
			/// Create is a static function that creates a new window. It is platform specific.
			/// </summary>
			/// <param name="props">The properties of the window.</param>
			/// <returns>A pointer to the window.</returns>
			static Window* Create(const WindowProps& props = WindowProps());
	};

}