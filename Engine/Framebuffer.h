#pragma once
#include "Engine/Core/Ref.h"
#include <functional>

namespace Engine {

	struct FramebufferSpecification {
		float Scale = 1.0f;
		uint32_t Width = 0;
		uint32_t Height = 0;

	};

	class Framebuffer : public RefCounted {
	public:

		typedef std::function<void(Ref<Framebuffer>)> ResizeCallbackFn;

		virtual ~Framebuffer() {}
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void Resize(uint32_t width, uint32_t height, bool forceRecreate = false) = 0;
		virtual void AddResizeCallback(const ResizeCallbackFn& func) = 0;
		virtual uint32_t GetWidth() = 0;
		virtual uint32_t GetHeight() = 0;
	};
}