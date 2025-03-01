#pragma once

#include "Koffieboon/Window.h"

#include <GLFW/glfw3.h>

namespace Koffieboon
{

	class WindowsGLFW : public Window
	{
	public:
		WindowsGLFW(const WindowProps& props);
		virtual ~WindowsGLFW();

		void OnUpdate() override;

		// Window size attributes
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		private:
			virtual void Init(const WindowProps& props);
			virtual void Shutdown();

		private:
			GLFWwindow* m_Window;
			struct WindowData
			{
				std::string Title;
				unsigned int Width, Height;
				bool VSync;
				
				EventCallbackFn EventCallback;
			};
			WindowData m_Data;
	};

}