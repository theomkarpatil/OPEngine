#pragma once
#include "EventManager.h"

#include <sstream>

namespace OPEngine {
	class OPE_API MouseMoveEvent : public Event {
	public:
		MouseMoveEvent(float a_x, float a_y) : m_mouseX(a_x), m_mouseY(a_y) {}

		inline float GetMouseX()const { return m_mouseX;  }
		inline float GetMouseY()const { return m_mouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_mouseX << ", " << m_mouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		int m_mouseX, m_mouseY;

	};

	class OPE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float a_offsetX, float a_offsetY) : m_offsetX(a_offsetX), m_offsetY(a_offsetY) {}
		
		inline float GetXOffset() const { return m_offsetX; }
		inline float GetYOffset() const { return m_offsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_offsetX << ", " << m_offsetY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float m_offsetX, m_offsetY;
	};

	class OPE_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return m_button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput) 

	protected:
		MouseButtonEvent(int a_button) : m_button(a_button) {}

		int m_button;
	};


	class OPE_API MouseButtonDownEvent : public MouseButtonEvent
	{
	public:
		MouseButtonDownEvent(int a_button) : MouseButtonEvent(a_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonDownEvent: "<< m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonDown)
	};

	class OPE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int a_button) : MouseButtonEvent(a_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class OPE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int a_button) : MouseButtonEvent(a_button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};


}