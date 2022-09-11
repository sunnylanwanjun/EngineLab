#include "first_app.h"

namespace engine
{
	FirstApp::FirstApp()
	{

	}

	FirstApp::~FirstApp()
	{

	}

	void FirstApp::run()
	{
		while (!window.shouldClose())
		{
			glfwPollEvents();
		}
	}
}
