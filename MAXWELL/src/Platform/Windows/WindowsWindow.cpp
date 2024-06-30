#include "mwpch.h"

#include <glad/glad.h>

#include "Maxwell/Events/ApplicationEvent.h"
#include "Maxwell/Events/MouseEvent.h"
#include "Maxwell/Events/KeyEvent.h"
#include "WindowsWindow.h"

namespace Maxwell {

	static bool s_glfwInitialized = false;

	static void glfwErrorCallback(int p_error, const char* p_description) {

		MW_CORE_ERROR("GLFW Error ({0}) : {1}", p_error, p_description);
	}

	Window* Window::create(const WindowProperties& p_properties) {

		return new WindowsWindow(p_properties);
	}

	WindowsWindow::WindowsWindow(const WindowProperties& p_properties) {

		init(p_properties);
	}

	WindowsWindow::~WindowsWindow() {
	
		shutdown();
	}

	void WindowsWindow::init(const WindowProperties& p_properties) {
	
		m_data.title = p_properties.title;
		m_data.width = p_properties.width;
		m_data.height = p_properties.height;

		MW_CORE_INFO("Creating window {0} ({1}, {2})", m_data.title, m_data.width, m_data.height);

		if (!s_glfwInitialized) {

			int succes = glfwInit();
			MW_CORE_ASSERT(succes, "Could not initialize GLFW!");

			glfwSetErrorCallback(glfwErrorCallback);

			s_glfwInitialized = true;
		}


		m_window = glfwCreateWindow((int)m_data.width, (int)m_data.height, m_data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MW_CORE_ASSERT(status, "Could not initialize Glad!");

		glfwSetWindowUserPointer(m_window, &m_data);
		setVSync(true);

		// GLFW callbacks
		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* p_window, int p_width, int p_height) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			data.width = p_width;
			data.height = p_height;

			WindowResizeEvent event(p_width, p_height);
			data.eventCallback(event);
		});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* p_window) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetKeyCallback(m_window, [](GLFWwindow* p_window, int p_key, int p_scancode, int p_action, int p_mods) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			switch (p_action) {

				case GLFW_PRESS: {

					// TODO keycode conversion
					KeyPressedEvent event(p_key, 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {

					KeyReleasedEvent event(p_key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT: {

					// TODO count update
					KeyPressedEvent event(p_key, 1);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* p_window, int p_button, int p_action, int p_mods) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			switch (p_action) {

				case GLFW_PRESS: {

					// TODO keycode conversion
					MouseButtonPressedEvent event(p_button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE: {

					MouseButtonReleasedEvent event(p_button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_window, [](GLFWwindow* p_window, double p_offsetX, double p_offsetY) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			MouseScrolledEvent event((float)p_offsetX, (float)p_offsetY);
			data.eventCallback(event);
		});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* p_window, double p_positionX, double p_positionY) {

			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(p_window);

			MouseMovedEvent event((float)p_positionX, (float)p_positionY);
			data.eventCallback(event);
		});
	}

	void WindowsWindow::shutdown() {

		glfwDestroyWindow(m_window);
	}

	void WindowsWindow::onUpdate() {

		glfwPollEvents();
		glfwSwapBuffers(m_window);
	}

	void WindowsWindow::setVSync(bool p_enabled) {

		if (p_enabled)
			glfwSwapInterval(1);

		else
			glfwSwapInterval(0);

		m_data.vSync = p_enabled;
	}

	bool WindowsWindow::isVSync() const {

		return m_data.vSync;
	}
}