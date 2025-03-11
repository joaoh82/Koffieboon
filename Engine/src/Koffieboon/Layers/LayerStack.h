#pragma once

#include "Koffieboon/Defines.h"
#include "Koffieboon/Layers/Layer.h"

#include <vector>

namespace Koffieboon
{
	class KOFFIEBOON_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		/// <summary>
		/// Index to insert the layer in the layer stack
		/// </summary>
		unsigned int m_LayerInsertIndex = 0;
	};
} // namespace Koffieboon