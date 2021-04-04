#pragma once
#include "EventManager.h"

#include <sstream>

namespace OPEngine {

	class OPE_API WindowsResizeEvent : public Event {
	public:
		WindowsResizeEvent(unsigned int a_width, unsigned int a_height) : m_width(a_width), m_height(a_height){}

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindwosResizeEvent: "<< m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)

	private:
		unsigned int m_width, m_height;
	};

	class OPE_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent(){}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};

	class OPE_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};

	class OPE_API WindowLostFocusEvent : public Event {
	public:
		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};

	class OPE_API WindowMovedEvent : public Event {
	public:
		WindowMovedEvent() {}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategoryWindow)
	};
}