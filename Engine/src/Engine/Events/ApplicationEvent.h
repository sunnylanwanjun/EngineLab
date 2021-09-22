#pragma once
#include "Event.h"
#include <stdint.h>
#include <string>
#include <sstream>

namespace Engine {
	class WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(uint32_t w, uint32_t h): width(w), height(h) {
		}
		inline uint32_t GetWidth() const { return width; }
		inline uint32_t GetHeight() const { return height; }

		virtual std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << width << ", " << height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(Application)
	private:
		uint32_t width = 0, height = 0;
	};

	class WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(Application)
	};

	class AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(Application)
	};

	class AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(Application)
	};

	class AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(Application)
	};
}