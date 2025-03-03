#include "kbpch.h"
#include "LayerStack.h"

namespace Koffieboon
{
	LayerStack::LayerStack()
	{
		// This initializes the m_LayerInsert iterator to the beginning of the vector
		m_LayerInsert = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			delete layer;
		}
	}

	/// <summary>
	/// PushLayer pushes a layer to the layer stack. It pushed the layer to the position of m_LayerInsert and increments m_LayerInsert.
	/// Worth noting that it pushes the layer to the first half of the vector.
	/// </summary>
	/// <param name="layer"></param>
	void LayerStack::PushLayer(Layer* layer)
	{
		// This pushes the layer to the layer stack at the position of m_LayerInsert and increments m_LayerInsert
		m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
	}

	/// <summary>
	/// PushOverlay pushes an overlay to the layer stack. It pushes the overlay to the end of the vector.
	/// Worth noting that it pushes the overlay to the second half of the vector.
	/// </summary>
	/// <param name="overlay"></param>
	void LayerStack::PushOverlay(Layer* overlay)
	{
		// This pushes the overlay to the layer stack at the end of the vector
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// This finds the layer in the vector and removes it from the vector`
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			// Not the end of the vector
			m_Layers.erase(it);
			// If the layer is removed before the m_LayerInsert, decrement m_LayerInsert
			m_LayerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
} // namespace Koffieboon