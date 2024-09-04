#pragma once

#include "Maxwell/Events/ApplicationEvent.h"
#include "Maxwell/Events/MouseEvent.h"
#include "Maxwell/Events/KeyEvent.h"

#include "Maxwell/Layer.h"

namespace Maxwell {

	class MAXWELL_API ImGuiLayer : public Layer {

	private:

		float m_time = 0.0f;

	public:

		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override final;
		virtual void onDetach() override final;
		virtual void onImGuiRender() override final;

		void begin();
		void end();
	};
}