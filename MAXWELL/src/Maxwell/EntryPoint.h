#pragma once

#ifdef MW_PLATFORM_WINDOWS

extern Maxwell::Application* Maxwell::createApplication();

int main(int p_argc, char** p_argv) {

	Maxwell::Log::init();

	MW_CORE_TRACE("Maxwell Engine");
	MW_TRACE("Sandbox!");

	Maxwell::Application* application = Maxwell::createApplication();

	application->run();

	delete application;

	return 0;
}
#endif // MW_PLATFORM_WINDOWS