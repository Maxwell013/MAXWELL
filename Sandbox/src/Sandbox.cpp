#include <Maxwell.h>

class Sandbox : public Maxwell::Application {

public:

	Sandbox() {}
	~Sandbox() {}
};



Maxwell::Application* Maxwell::createApplication() {

	return new Sandbox();
}