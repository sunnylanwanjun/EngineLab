#pragma once
#include "Engine/Core/Window.h"
#include <string>
#include "Engine/Renderer/RendererContext.h"

namespace Engine {
	class WindowsWindow: public Window {
	public:
		WindowsWindow(const WindowSpecification& specification);
		virtual ~WindowsWindow();

		virtual void Init() override;
		virtual void ProcessEvents() override;
		virtual void Swapbuffers() override;
		virtual uint32_t GetWidth() const { return data.Width; }
		virtual uint32_t GetHeight() const { return data.Height; }
		virtual std::pair<uint32_t, uint32_t> GetSize() const override {
			return { data.Width, data.Height };
		}

		virtual std::pair<float, float> GetWindowPos() const override;
		virtual void Maximize() override;

		virtual void SetEventCallback(const EventCallbackFn& callback) override {
			data.EventCallback = callback;
		}
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

		virtual const std::string& GetTitle() const override {
			return data.Title;
		}
		virtual void SetTitle(const std::string& title) override;

		virtual void* GetNativeWindow() const {
			return window;
		}
		virtual Ref<RendererContext> GetRendererContext() override {
			return rendererContext;
		}
	private:
		virtual void Shutdown();
	private:
		GLFWwindow* window = nullptr;
		GLFWcursor* imguiMouseCursors[9] = { 0 };
		WindowSpecification specification;
		struct WindowData {
			std::string Title = "";
			uint32_t Width = 0;
			uint32_t Height = 0;
			bool VSync = false;
			EventCallbackFn EventCallback = nullptr;
		};
		WindowData data;
		Ref<RendererContext> rendererContext;
	};
}