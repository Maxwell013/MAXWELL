#include "mwpch.h"

#include <GLFW/glfw3.h>

#include "Maxwell/Application.h"
#include "WindowsInput.h"

namespace Maxwell {

	Input* Input::s_instance = new WindowsInput();

	bool WindowsInput::isKeyPressedImpl(int p_keycode) {

		GLFWwindow* window = (GLFWwindow*)Application::get().getWindow().getNativeWindow();
		int state = glfwGetKey(window, p_keycode);

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::isMouseButtonPressedImpl(int p_button) {

		GLFWwindow* window = (GLFWwindow*)Application::get().getWindow().getNativeWindow();
		int state = glfwGetMouseButton(window, p_button);

		return state == GLFW_PRESS;
	}

	float WindowsInput::getMouseXImpl() {

		std::pair<float, float> position = getMousePositionImpl();

		return position.first;
	}

	float WindowsInput::getMouseYImpl() {

		std::pair<float, float> position = getMousePositionImpl();

		return position.second;
	}

	std::pair<float, float> WindowsInput::getMousePositionImpl() {

		GLFWwindow* window = (GLFWwindow*)Application::get().getWindow().getNativeWindow();
		double x, y;
		glfwGetCursorPos(window, &x, &y);

		return { (float)x, (float)y };
	}
}