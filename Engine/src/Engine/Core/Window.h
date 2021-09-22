#pragma once
#include "Ref.h"
#include <functional>
#include "Engine/Events/Event.h"
#include <string>

namespace Engine {

	struct WindowSpecification
	{
		std::string Title = "Hazel";
		uint32_t Width = 1600;
		uint32_t Height = 900;
		bool Fullscreen = false;
		bool VSync = true;
	};

	class Window  : public RefCounted {
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}
		virtual void Init() = 0;
		virtual void ProcessEvents() = 0;
		virtual void Swapbuffers() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual std::pair<uint32_t, uint32_t> GetSize() const = 0;
		virtual std::pair<float, float> GetWindowPos() const = 0;
		virtual void Maximize() = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual const std::string& GetTitle() const = 0;
		virtual void SetTitle(const std::string& title) = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual Ref<RendererContext> GetRendererContext() = 0;
		static Window* Create(const WindowSpecification& props = WindowSpecification());
	};
}