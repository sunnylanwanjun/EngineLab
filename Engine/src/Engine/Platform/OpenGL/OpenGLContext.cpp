#include "OpenGLContext.h"
#include "glad/glad.h"
#include "Engine/Core/Assert.h"

namespace Engine {

	OpenGLContext::OpenGLContext(GLFWwindow* window): windowHandle(window) {

	}

	OpenGLContext::~OpenGLContext() {

	}

	void OpenGLContext::Init() {
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ENGINE_CORE_ASSERT(status, "Failed to initialize Glad!");
		ENGINE_CORE_INFO("OpenGL Info:");
		ENGINE_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		ENGINE_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		ENGINE_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));
#ifdef ENGINE_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);
		ENGINE_CORE_ASSERT(versionMajor >= 4 && versionMinor >= 5, "Engine requires at least OpenGl version 4.5!");
#endif
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(windowHandle);
	}
}