#include "mwpch.h"

#include "LayerStack.h"

namespace Maxwell {

	LayerStack::LayerStack() {}

	LayerStack::~LayerStack() {

		for (Layer* layer : m_layers)
			delete layer;
	}

	void LayerStack::pushLayer(Layer* p_layer) {

		m_layers.emplace(m_layers.begin() + m_layerInsertIndex, p_layer);
		m_layerInsertIndex++;
	}

	void LayerStack::pushOverlay(Layer* p_overlay) {

		m_layers.emplace_back(p_overlay);
	}

	void LayerStack::popLayer(Layer* p_layer) {

		std::vector<Layer*>::iterator iterator = std::find(m_layers.begin(), m_layers.end(), p_layer);

		if (iterator != m_layers.end()) {

			m_layers.erase(iterator);
			m_layerInsertIndex--;
		}
	}

	void LayerStack::popOverlay (Layer* p_overlay) {

		std::vector<Layer*>::iterator iterator = std::find(m_layers.begin(), m_layers.end(), p_overlay);

		if (iterator != m_layers.end())
			m_layers.erase(iterator);
	}
}