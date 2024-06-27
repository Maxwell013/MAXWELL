#pragma once

#include <sstream>

#include "Event.h"

namespace Maxwell {

	class MAXWELL_API MouseMovedEvent : public Event {

	private:

		float m_mouseX, m_mouseY;

	public:

		MouseMovedEvent(float p_mouseX, float p_mouseY)
			: m_mouseX(p_mouseX), m_mouseY(p_mouseY) {}

		inline float getX() const { return m_mouseX; }
		inline float getY() const { return m_mouseY; }

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "MouseMovedEvent : " << m_mouseX << ", " << m_mouseY;

			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MAXWELL_API MouseScrolledEvent : public Event {

	private:

		float m_offsetX, m_offsetY;

	public:

		MouseScrolledEvent(float p_offsetX, float p_offsetY)
			: m_offsetX(p_offsetX), m_offsetY(p_offsetY) {}

		inline float getX() const { return m_offsetX; }
		inline float getY() const { return m_offsetY; }

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "MouseScrolledEvent : " << m_offsetX << ", " << m_offsetY;

			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

		class MAXWELL_API MouseButtonEvent : public Event {

	protected:

		MouseButtonEvent(int p_button)
			: m_button(p_button) {}

		int m_button;

	public:

		inline int getButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class MAXWELL_API MouseButtonPressedEvent : public MouseButtonEvent {

	public:

		MouseButtonPressedEvent(int p_button)
			: MouseButtonEvent(p_button) {}

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "MouseButtonPressedEvent : " << m_button;

			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MAXWELL_API MouseButtonReleasedEvent : public MouseButtonEvent {

	public:

		MouseButtonReleasedEvent(int p_button)
			: MouseButtonEvent(p_button) {}

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "MouseButtonReleasedEvent : " << m_button;

			return stream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}