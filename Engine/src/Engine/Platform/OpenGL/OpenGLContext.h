#pragma once
#include "Engine/Renderer/RendererContext.h"
#include "GLFW/glfw3.h"

namespace Engine {
	class OpenGLContext : public RendererContext {
		OpenGLContext(GLFWwindow* window);
		virtual ~OpenGLContext();
		virtual void Init() override;
		virtual void BeginFrame() override {}
		virtual void SwapBuffers() override;
		virtual void OnResize(uint32_t width, uint32_t height) override {}
	private:
		GLFWwindow* windowHandle = nullptr;
	};
}