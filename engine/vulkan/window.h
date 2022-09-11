#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace engine
{
	class Window 
	{
	public:
		Window(int w, int h, std::string name);
		virtual ~Window();

		Window(const Window& win) = delete;
		Window& operator=(const Window& win) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
	private:
		void initWindow();
		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window = nullptr;
	};
}
