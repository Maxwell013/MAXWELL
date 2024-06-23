#pragma once

#include "Core.h"

namespace Maxwell {

	class MAXWELL_API Application {

	public:

		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}