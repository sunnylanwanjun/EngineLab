
#include "WindowsWindow.h"
#include "GLFW/glfw3.h"
#include "Engine/Core/Log.h"
#include "Engine/Core/Assert.h"
#include "Engine/Renderer/RendererAPI.h"
#include "Engine/Core/Window.h"
#include "Engine/Events/ApplicationEvent.h"

namespace Engine {

	static bool GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* desc) {
		ENGINE_CORE_ERROR("GLFW Error ({0}: {1})", error, desc);
	}

	Window* Window::Create(const WindowSpecification& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowSpecification& props)
		: specification(props) {
		Init();
	}
	
	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Shutdown() {
		glfwTerminate();
		GLFWInitialized = false;
	}

	void WindowsWindow::Init() {
		data.Title = specification.Title;
		data.Width = specification.Width;
		data.Height = specification.Height;

		ENGINE_CORE_INFO("Create window {0}, ({1}, {2})", data.Title, data.Width, data.Height);

		if (!GLFWInitialized) {
			int success = glfwInit();
			ENGINE_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			GLFWInitialized = true;
		}

		if (RendererAPI::Current() == RendererAPIType::OpenGL) {
			//设置Opengl版本至3.3
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
			//设置opengl为核心模式，表示只使用Opengl功能的一个子集
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef ENGINE_PLATFORM_MAC
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		}

		if (specification.Fullscreen) {
			// TODO
		}
		else {
			window = glfwCreateWindow((int)specification.Width, (int)specification.Height, specification.Title.c_str(), nullptr, nullptr);
			ENGINE_CORE_ASSERT(window, "Could not create GLFW Window!");
			glfwMakeContextCurrent(window);
		}

		rendererContext = RendererContext::Create(window);
		rendererContext->Init();

		glfwSetWindowUserPointer(window, &data);

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			auto& data = *((WindowData*)glfwGetWindowUserPointer(window));
			WindowResizeEvent event(width, height);
			if (data.EventCallback) {
				data.EventCallback(event);
			}
			data.Width = width;
			data.Height = height;
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			auto& data = *((WindowData*)glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			if (data.EventCallback) {
				data.EventCallback(event);
			}
		});

		{
			int width, height;
			glfwGetWindowSize(window, &width, &height);
			data.Width = width;
			data.Height = height;
		}
	}

	void WindowsWindow::ProcessEvents() {
		glfwPollEvents();
	}

	void WindowsWindow::Swapbuffers() {
		rendererContext->SwapBuffers();
	}

	std::pair<float, float> WindowsWindow::GetWindowPos() const {
		int x, y;
		glfwGetWindowPos(window, &x, &y);
		return { x, y };
	}

	void WindowsWindow::Maximize() {
		glfwMaximizeWindow(window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		data.VSync = enabled;
		if (RendererAPI::Current() == RendererAPIType::OpenGL) {
			if (enabled) {
				glfwSwapInterval(1);
			}
			else {
				glfwSwapInterval(0);
			}
		}
	}

	bool WindowsWindow::IsVSync() const {
		return data.VSync;
	}

	void WindowsWindow::SetTitle(const std::string& title) {
		data.Title = title;
		glfwSetWindowTitle(window, data.Title.c_str());
	}

}