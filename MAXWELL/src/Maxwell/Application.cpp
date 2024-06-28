#include "mwpch.h"

#include "Maxwell/Events/Event.h"

#include "Application.h"

namespace Maxwell {

	#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
	
		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(BIND_EVENT_FUNCTION(onEvent));
	}

	Application::~Application() {}

	void Application::run() {

		while (m_running) {

			m_window->onUpdate();
		}
	}

	void Application::onEvent(Event& p_event) {
	
		MW_CORE_TRACE(p_event);

		EventDispatcher dispatcher(p_event);

		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClosed));
	}

	bool Application::onWindowClosed(WindowCloseEvent& p_event) {

		m_running = false;
		return true;
	}
}