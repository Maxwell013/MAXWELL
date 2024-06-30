#pragma once

#ifdef MW_PLATFORM_WINDOWS

extern Maxwell::Application* Maxwell::createApplication();

int main(int p_argc, char** p_argv) {

	Maxwell::Log::init();

	MW_CORE_TRACE("Maxwell Engine");
	MW_TRACE("Sandbox!");
	//MW_TRACE("--newline--\n");

	//MW_CORE_TRACE("CORE TRACE TEST");
	//MW_CORE_INFO("CORE INFO TEST");
	//MW_CORE_WARN("CORE WARN TEST");
	//MW_CORE_ERROR("CORE ERROR TEST");
	//MW_CORE_CRITICAL("CORE CRITICAL TEST");

	//MW_TRACE("CLIENT TRACE TEST");
	//MW_INFO("CLIENT INFO TEST");
	//MW_WARN("CLIENT WARN TEST");
	//MW_ERROR("CLIENT ERROR TEST");
	//MW_CRITICAL("CLIENT CRITICAL TEST");

	//MW_TRACE("--newline--\n");

	Maxwell::Application* application = Maxwell::createApplication();

	application->run();

	delete application;

	return 0;
}
#endif // MW_PLATFORM_WINDOWS