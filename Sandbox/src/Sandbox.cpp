#include <Maxwell.h>

class ExampleLayer : public Maxwell::Layer {

public:

	ExampleLayer()
		: Layer("Example") {}

	virtual void onUpdate() override final {
	
		MW_INFO("'ExampleLayer::onUpdate()' called!");
	}

	virtual void onEvent(Maxwell::Event& p_event) override final {

		MW_INFO("'ExampleLayer::onEvent()' called with event = {0}!", p_event);
	}
};

class Sandbox : public Maxwell::Application {

public:

	Sandbox() {
		
		pushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};



Maxwell::Application* Maxwell::createApplication() {

	return new Sandbox();
}