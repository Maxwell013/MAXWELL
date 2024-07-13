#include <Maxwell.h>

class ExampleLayer : public Maxwell::Layer {

public:

	ExampleLayer()
		: Layer("Example") {}

	virtual void onUpdate() override final {
	
		if (Maxwell::Input::isKeyPressed(MW_KEY_TAB))
			MW_TRACE("TAB key was pressed!");
	}

	virtual void onEvent(Maxwell::Event& p_event) override final {}
};

class Sandbox : public Maxwell::Application {

public:

	Sandbox() {
		
		pushLayer(new ExampleLayer());
		pushOverlay(new Maxwell::ImGuiLayer());
	}
	~Sandbox() {}
};



Maxwell::Application* Maxwell::createApplication() {

	return new Sandbox();
}