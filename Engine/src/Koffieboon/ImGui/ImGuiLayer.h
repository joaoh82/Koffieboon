#pragma once

#include "Koffieboon/Layers/Layer.h"

#include "Koffieboon/Events/ApplicationEvent.h"
#include "Koffieboon/Events/KeyEvent.h"
#include "Koffieboon/Events/MouseEvent.h"

namespace Koffieboon
{
	class KOFFIEBOON_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

		

	private:
		float m_Time = 0.0f;
		
	};
} // namespace Koffieboon