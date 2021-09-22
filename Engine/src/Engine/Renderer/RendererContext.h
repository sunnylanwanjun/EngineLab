#pragma once
#include "Engine/Core/Ref.h"

namespace Engine {
	class RendererContext : public RefCounted {
	public:
		RendererContext() = default;
		virtual ~RendererContext() = default;
		virtual void Init() = 0;
		virtual void BeginFrame() = 0;
		virtual void SwapBuffers() = 0;
		virtual void OnResize(uint32_t width, uint32_t height) = 0;
		static Ref<RendererContext> Create(GLFWwindow* windowHandle);
	};
}