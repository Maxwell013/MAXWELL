#pragma once

#include "Core.h"
#include "Maxwell/Events/ApplicationEvent.h"
#include "Window.h"

namespace Maxwell {

	class MAXWELL_API Application {

	private:

		bool m_running = true;
		std::unique_ptr<Window> m_window;

		bool onWindowClosed(WindowCloseEvent& p_event);

	public:

		Application();
		virtual ~Application();

		void run();

		void onEvent(Event& p_event);
	};

	Application* createApplication();
}