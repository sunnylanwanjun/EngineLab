#include "Log.h"

namespace Engine {
	std::shared_ptr<spdlog::logger> Log::CoreLogger;
	std::shared_ptr<spdlog::logger> Log::ClientLogger;

	void Log::Init() {
		
	}

	std::shared_ptr<spdlog::logger>& Log::GetCoreLogger() {
		return CoreLogger;
	}

	std::shared_ptr<spdlog::logger>& Log::GetClientLogger() {
		return ClientLogger;
	}
}