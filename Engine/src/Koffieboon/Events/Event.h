#pragma once

#include "Koffieboon/Core.h"
#include "Koffieboon/Defines.h"

#include <string>
#include <functional>

namespace Koffieboon
{
	// Base class for all events
	// Event are blocking, meaning when an event is created it must be handled immediately and dispatched.
	// This is because events are created and dispatched in the same frame.
	// In the future, a better strategy might be to buffer events in an event bus and process them during the event part of the update stage.

	// Event types
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, // Window events
		AppTick, AppUpdate, AppRender, // Application events
		KeyPressed, KeyReleased, KeyTyped, // Keyboard events
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled // Mouse events
	};

	// Event categories
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
	
// Macros for defining event classes
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

// Macros for defining event categories
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class KOFFIEBOON_API Event
	{
	public:
		bool Handled = false;
		
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	/// <summary>
	/// Overload the << operator for easy printing of events
	/// </summary>
	/// <param name="os"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}