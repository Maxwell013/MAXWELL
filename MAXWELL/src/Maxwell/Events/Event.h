#pragma once

#include "mwpch.h"

#include "Maxwell/Core.h"

namespace Maxwell {

	enum class EventType {

		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {

		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput				= BIT(1),
		EventCategoryKeyboard			= BIT(2),
		EventCategoryMouse				= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
									virtual EventType getEventType() const override { return getStaticType(); }\
									virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }

	class MAXWELL_API Event {

		friend class EventDispatcher;

	protected:

		bool m_handled = false;

	public:

		virtual EventType getEventType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isInCategory(EventCategory p_category) const {

			return getCategoryFlags() & p_category;
		}
	};

	class EventDispatcher {

		template<typename T>
		using EventFn = std::function<bool(T&)>;

	private:

		Event& m_event;

	public:

		EventDispatcher(Event& p_event)
			: m_event(p_event) {}

		template<typename T>
		bool Dispatch(EventFn<T> p_function) {

			if (m_event.getEventType() == T::getStaticType()) {

				m_event.m_handled = p_function(*(T*)&m_event);
				return true;
			}

			return false;
		}
	};

	inline std::string format_as(const Event& p_event) { return p_event.toString(); }
	inline std::ostream& operator<<(std::ostream& p_stream, const Event& p_event) { return p_stream << p_event.toString(); }
}