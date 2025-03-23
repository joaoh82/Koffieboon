#pragma once

#include "Koffieboon/Layers/Layer.h"

#include "Koffieboon/Events/ApplicationEvent.h"
#include "Koffieboon/Events/KeyEvent.h"
#include "Koffieboon/Events/MouseEvent.h"

#include <map>

namespace Koffieboon
{
	class KOFFIEBOON_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		/// <summary>
		/// Begin and end the frame
		/// </summary>
		void Begin();

		/// <summary>
		/// End the frame
		/// </summary>
		void End();

	private:
		float m_Time = 0.0f;

		/// <summary>
		/// Map to store the key states
		/// </summary>
		std::map<int, int> m_KeyMap;
		
	};
} // namespace Koffieboon