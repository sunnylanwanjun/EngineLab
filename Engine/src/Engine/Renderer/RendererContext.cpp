#include "RendererContext.h"
#include "RendererAPI.h"
#include "GLFW/glfw3.h"

namespace Engine {
	Ref<RendererContext> RendererContext::Create(GLFWwindow* windowHandle) {
		switch (RendererAPI::Current()) {
		case RendererAPIType::OpenGL:

			break;
		}
	}
}