#pragma once
#include "Application.h"

#ifdef ENGINE_WINDOWS_PLATFORM
extern Engine::Application* Engine::CreateApplication();

int main(int argc,  char** argv) {
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#endif