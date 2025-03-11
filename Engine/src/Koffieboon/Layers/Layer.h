#pragma once

#include "Koffieboon/Defines.h"
#include "Koffieboon/Events/Event.h"

namespace Koffieboon
{
	class KOFFIEBOON_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

		inline bool IsEnabled() const { return m_Enabled; }

	protected:
		/// <summary>
		/// Only to be used internally
		/// </summary>
		std::string m_DebugName;

		/// <summary>
		/// Bool to check if the layer is enabled
		/// </summary>
		b8 m_Enabled = TRUE;

	};
}