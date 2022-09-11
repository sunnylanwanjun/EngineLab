#pragma once

#include "defines.h"
#include "window.h"
#include "pipeline.h"

namespace engine
{
	class FirstApp
	{
	public:
		FirstApp();
		virtual ~FirstApp();

		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void run();

	private:
		Window window{ WIDTH, HEIGHT, "Hello vulkan" };
		Pipeline pipeline {"shaders/simple_shader.vert.spv", "shaders/simple_shader.frag.spv"};
	};
}
