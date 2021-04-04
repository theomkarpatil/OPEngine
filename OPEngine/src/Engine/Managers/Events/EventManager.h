#pragma once
#include "../../macros.h"


namespace OPEngine {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyDown, KeyReleased, KeyPressed,
		MouseButtonDown, MouseButtonReleased, MouseButtonPressed, MouseScrolled, MouseMoved
	};

	enum EventCategory {
		None = 0,
		EventCategoryWindow = BIT(0),
		EventCategoryInput       = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type;}\
								   virtual EventType GetEventType() const override {return GetStaticType(); }\
								   virtual const char* GetName() const override { return #type;}

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class OPE_API Event{

		friend class EventDispatcher;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const{ return GetName(); }

		inline bool IsInCategory(EventCategory a_category) {
			return GetCategoryFlags() & a_category;
		}

	protected:
		bool m_eventHandled = false;
	
	};

	class EventManager {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventManager(Event &a_event) : m_event(a_event) {}

		template <typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_event.GetEventType() == T::GetStaticType()) {
				m_event.m_eventHandled = func(*(T*)&m_event);
				return true;
			}

			return false;
		}

	private:
		Event &m_event;
	};
}
