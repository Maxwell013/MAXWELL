#pragma once

#include "Maxwell/Core.h"
#include "Maxwell/Events/Event.h"

namespace Maxwell {

	class MAXWELL_API Layer {

	protected:

		std::string m_debugName;

	public:

		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& p_event) {}

		inline const std::string& getName() const { return m_debugName; }
	};
}


