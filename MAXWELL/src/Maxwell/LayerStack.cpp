#include "mwpch.h"

#include "LayerStack.h"

namespace Maxwell {

	LayerStack::LayerStack() {

		m_layerInsert = m_layers.begin();
	}

	LayerStack::~LayerStack() {

		for (Layer* layer : m_layers)
			delete layer;
	}

	void LayerStack::pushLayer(Layer* p_layer) {

		m_layerInsert = m_layers.emplace(m_layerInsert, p_layer);
	}

	void LayerStack::pushOverlay(Layer* p_overlay) {

		m_layers.emplace_back(p_overlay);
	}

	void LayerStack::popLayer(Layer* p_layer) {

		std::vector<Layer*>::iterator iterator = std::find(m_layers.begin(), m_layers.end(), p_layer);

		if (iterator != m_layers.end()) {

			m_layers.erase(iterator);
			m_layerInsert--;
		}
	}

	void LayerStack::popOverlay (Layer* p_overlay) {

		std::vector<Layer*>::iterator iterator = std::find(m_layers.begin(), m_layers.end(), p_overlay);

		if (iterator != m_layers.end())
			m_layers.erase(iterator);
	}
}