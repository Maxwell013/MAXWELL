#include <Maxwell.h>

#include <imgui/imgui.h>

//#include <glm/vec3.hpp>
//#include <glm/vec4.hpp>
//#include <glm/mat4x4.hpp>
//#include <glm/gtc/matrix_transform.hpp>

//glm::mat4 camera(float p_translate, const glm::vec2& p_rotate) {
//
//	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
//	glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -p_translate));
//	view = glm::rotate(view, p_rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
//	view = glm::rotate(view, p_rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
//	glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
//	return projection * view * model;
//}

class ExampleLayer : public Maxwell::Layer {

public:

	ExampleLayer()
		: Layer("Example") {}

	virtual void onUpdate() override final {
	
		if (Maxwell::Input::isKeyPressed(MW_KEY_TAB))
			MW_TRACE("TAB key was pressed!");
	}

	virtual void onImGuiRender() override final {

		//ImGui::Begin("Test");
		//ImGui::Text("Hello, World!");
		//ImGui::End();
	}

	virtual void onEvent(Maxwell::Event& p_event) override final {}
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