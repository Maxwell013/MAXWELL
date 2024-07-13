#include "mwpch.h"

#include "Input.h"
#include "Application.h"

//temp
#include <glad/glad.h>

namespace Maxwell {

//#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;	

	Application::Application() {
		
		MW_CORE_ASSERT(!s_instance, "Application already exists!");
		s_instance = this;

		m_window = std::unique_ptr<Window>(Window::create());
		m_window->setEventCallback(MW_BIND_EVENT_FUNCTION(Application::onEvent));
	}

	Application::~Application() {}

	void Application::run() {

		while (m_running) {

			//temp
			glClearColor(0.5, 0.5, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerStack)
				layer->onUpdate();

			m_window->onUpdate();
		}
	}

	void Application::onEvent(Event& p_event) {
	
		EventDispatcher dispatcher(p_event);

		dispatcher.dispatch<WindowCloseEvent>(MW_BIND_EVENT_FUNCTION(Application::onWindowClosed));

		for (std::vector<Layer*>::iterator iterator = m_layerStack.end(); iterator != m_layerStack.begin(); ) {

			(*--iterator)->onEvent(p_event);
			if (p_event.isHandled())
				break;
		}
	}

	void Application::pushLayer(Layer* p_layer) {

		m_layerStack.pushLayer(p_layer);
		p_layer->onAttach();
	}

	void Application::pushOverlay (Layer* p_overlay) {

		m_layerStack.pushOverlay(p_overlay);
		p_overlay->onAttach();
	}

	bool Application::onWindowClosed(WindowCloseEvent& p_event) {

		m_running = false;
		return true;
	}
}