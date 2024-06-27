#pragma once

#include <sstream>

#include "Event.h"

namespace Maxwell {

	class MAXWELL_API WindowResizeEvent : public Event {

	private:

		unsigned int m_width, m_height;

	public:

		WindowResizeEvent(unsigned int p_width, unsigned int p_height)
			: m_width(p_width), m_height(p_height) {}

		inline unsigned int getWidth() const { return m_width; }
		inline unsigned int getHeight() const { return m_height; }

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "WindowResizeEvent : " << m_width << ", " << m_height;

			return stream.str();
		}
	
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MAXWELL_API WindowCloseEvent : public Event {

	public:

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MAXWELL_API AppTickEvent : public Event {

	public:

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MAXWELL_API AppUpdateEvent : public Event {

	public:

		EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class MAXWELL_API AppRenderEvent : public Event {

	public:

		EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


}