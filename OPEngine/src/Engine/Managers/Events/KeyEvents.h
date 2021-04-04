#pragma once
#include "EventManager.h"

namespace OPEngine {
	
	class OPE_API KeyEvents : public Event {

	public:
		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvents(int a_keycode) : m_keyCode(a_keycode){}

		int m_keyCode;
	};


	class OPE_API KeyDownEvent : public KeyEvents {

	public:
		KeyDownEvent(int a_keyCode) : KeyEvents(a_keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyDown Event: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyDown)
	};

	class OPE_API KeyPressedEvent : public KeyEvents {
	
	public:
		KeyPressedEvent(int a_keyCode, int a_repeatCount) : KeyEvents(a_keyCode), m_repeatCount(a_repeatCount) {}

		inline int GetRepeatedCount() const { return m_repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressed Event: " << m_keyCode << " (" << m_repeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_repeatCount;
	};

	class OPE_API KeyReleasedEvent : public KeyEvents {

	public:
		KeyReleasedEvent(int a_keyCode) : KeyEvents(a_keyCode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleased Event: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}