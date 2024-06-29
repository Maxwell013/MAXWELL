#pragma once

#include "Core.h"
#include "Window.h"
#include "Maxwell/LayerStack.h"
#include "Maxwell/Events/Event.h"
#include "Maxwell/Events/ApplicationEvent.h"

namespace Maxwell {

	class MAXWELL_API Application {

	private:

		bool m_running = true;
		std::unique_ptr<Window> m_window;
		LayerStack m_layerStack;

		bool onWindowClosed(WindowCloseEvent& p_event);

	public:

		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& p_event);

		void pushLayer(Layer* p_layer);
		void pushOverlay(Layer* p_overlay);
	};

	Application* createApplication();
}