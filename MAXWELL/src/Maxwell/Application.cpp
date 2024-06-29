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

			for (Layer* layer : m_layerStack)
				layer->onUpdate();

			m_window->onUpdate();
		}
	}

	void Application::onEvent(Event& p_event) {
	
		EventDispatcher dispatcher(p_event);

		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(onWindowClosed));

		for (std::vector<Layer*>::iterator iterator = m_layerStack.end(); iterator != m_layerStack.begin(); ) {

			(*--iterator)->onEvent(p_event);
			if (p_event.isHandled())
				break;
		}
	}

	void Application::pushLayer(Layer* p_layer) {

		m_layerStack.pushLayer(p_layer);
	}

	void Application::pushOverlay (Layer* p_overlay) {

		m_layerStack.pushOverlay(p_overlay);
	}

	bool Application::onWindowClosed(WindowCloseEvent& p_event) {

		m_running = false;
		return true;
	}
}