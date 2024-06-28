#pragma once

#include "mwpch.h"

#include "Maxwell/Core.h"
#include "Maxwell/Events/Event.h"

namespace Maxwell {

	struct WindowProperties {

		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& p_title = "MAXWELL Engine",
			unsigned int p_width = 1280, unsigned int p_height = 720)
			: title(p_title), width(p_width), height(p_height) {}
	};

	class MAXWELL_API Window {

	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void setEventCallback(const EventCallbackFn& p_callback) = 0;
		virtual void setVSync(bool p_enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProperties& p_properties = WindowProperties());
	};
}