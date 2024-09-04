#pragma once

#include "Maxwell/Core.h"
#include "Layer.h"

namespace Maxwell {

	class MAXWELL_API LayerStack {
	
	private:

		std::vector<Layer*> m_layers;
		unsigned int m_layerInsertIndex = 0;

	public:

		LayerStack();
		~LayerStack();

		void pushLayer(Layer* p_layer);
		void pushOverlay(Layer* p_overlay);
		void popLayer(Layer* p_layer);
		void popOverlay(Layer* p_overlay);

		inline std::vector<Layer*>::iterator begin() { return m_layers.begin(); }
		inline std::vector<Layer*>::iterator end() { return m_layers.end(); }
	};
}

