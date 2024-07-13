#pragma once

#include <GLFW/glfw3.h>

#include "Maxwell/Window.h"

namespace Maxwell {

	class WindowsWindow : public Window {
	
	private:

		GLFWwindow* m_window;

		struct WindowData {
		
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData m_data;

		virtual void init(const WindowProperties& p_properties);
		virtual void shutdown();

	public:

		WindowsWindow(const WindowProperties& p_properties);
		~WindowsWindow();

		virtual void onUpdate() override final;

		virtual inline unsigned int getWidth() const override final { return m_data.width; }
		virtual inline unsigned int getHeight() const override final { return m_data.height; }

		virtual inline void setEventCallback(const EventCallbackFn& p_callback) override final { m_data.eventCallback = p_callback; }
		virtual void setVSync(bool p_enabled) override final;
		virtual bool isVSync() const override final;

		inline virtual void* getNativeWindow() const { return m_window; }
	};
}

