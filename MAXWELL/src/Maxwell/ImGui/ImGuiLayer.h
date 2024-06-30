#pragma once

#include "Maxwell/Events/ApplicationEvent.h"
#include "Maxwell/Events/MouseEvent.h"
#include "Maxwell/Events/KeyEvent.h"

#include "Maxwell/Layer.h"

namespace Maxwell {

	class MAXWELL_API ImGuiLayer : public Layer {

	private:

		float m_time = 0.0f;

		bool onMouseButtonPressedEvent(MouseButtonPressedEvent& p_event);
		bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& p_event);
		bool onMouseMovedEvent(MouseMovedEvent& p_event);
		bool onMouseScrolledEvent(MouseScrolledEvent& p_event);
		bool onKeyPressedEvent(KeyPressedEvent& p_event);
		bool onKeyReleasedEvent(KeyReleasedEvent& p_event);
		bool onKeyTypedEvent(KeyTypedEvent& p_event);
		bool onWindowResizeEvent(WindowResizeEvent& p_event);

	public:

		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override final;
		virtual void onDetach() override final;
		virtual void onUpdate() override final;
		virtual void onEvent(Event& p_event) override final;
	};
}