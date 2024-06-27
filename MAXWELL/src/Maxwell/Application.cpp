#include "Maxwell/Events/ApplicationEvent.h"

#include "Log.h"
#include "Application.h"

namespace Maxwell {

	Application::Application() {}

	Application::~Application() {}

	void Application::run() {

		WindowResizeEvent event(1280, 720);
		MW_TRACE(event);

		while (true);
	}
}