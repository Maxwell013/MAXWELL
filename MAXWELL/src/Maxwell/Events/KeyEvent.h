#pragma once

#include <sstream>

#include "Event.h"

namespace Maxwell {

	class MAXWELL_API KeyEvent : public Event {

	protected:

		KeyEvent(int p_keycode)
			: m_keycode(p_keycode) {}

		int m_keycode;

	public:

		inline int getKeyCode() const { return m_keycode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};

	class MAXWELL_API KeyPressedEvent : public KeyEvent {

	private:
		
		int m_repeatCount;

	public:

		KeyPressedEvent(int p_keycode, int p_repeatCount)
			: KeyEvent(p_keycode), m_repeatCount(p_repeatCount) {}

		inline int getRepeatCount() const { return m_repeatCount; }

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "KeyPressedEvent : " << m_keycode << " (" << m_repeatCount << " repeats)";

			return stream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class MAXWELL_API KeyReleasedEvent : public KeyEvent {

	public:

		KeyReleasedEvent(int p_keycode)
			: KeyEvent(p_keycode) {}

		virtual std::string toString() const override final {

			std::stringstream stream;

			stream << "KeyReleasedEvent : " << m_keycode;

			return stream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}