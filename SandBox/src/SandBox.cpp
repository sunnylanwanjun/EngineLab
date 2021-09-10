#include "Engine.h"

class SandBox : public Engine::Application {
public:
	SandBox() {

	}

	~SandBox() {

	}

	void Run() {
		
	}
};

Engine::Application* Engine::CreateApplication() {
	return new SandBox;
}