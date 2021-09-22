#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Engine {

	class Log{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
			return CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
			return ClientLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetEditorConsoleLogger() {
			return EditorConsoleLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
		static std::shared_ptr<spdlog::logger> EditorConsoleLogger;
	};
}

// Core Logging Macros
#define ENGINE_CORE_TRACE(...) Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ENGINE_CORE_INFO(...) Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ENGINE_CORE_WARN(...) Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...) Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ENGINE_CORE_FATAL(...) Engine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Logging Macros
#define ENGINE_TRACE(...) Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ENGINE_INFO(...) Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define ENGINE_WARN(...) Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ENGINE_ERROR(...) Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define ENGINE_FATAL(...) Engine::Log::GetClientLogger()->critical(__VA_ARGS__)

// Editor Logging Macros
#define ENGINE_CONSOLE_LOG_TRACE(...) Engine::Log::GetEditorConsoleLogger()->trace(__VA_ARGS__)
#define ENGINE_CONSOLE_LOG_INFO(...) Engine::Log::GetEditorConsoleLogger()->info(__VA_ARGS__)
#define ENGINE_CONSOLE_LOG_WARN(...) Engine::Log::GetEditorConsoleLogger()->warn(__VA_ARGS__)
#define ENGINE_CONSOLE_LOG_ERROR(...) Engine::Log::GetEditorConsoleLogger()->error(__VA_ARGS__)
#define ENGINE_CONSOLE_LOG_FATAL(...) Engine::Log::GetEditorConsoleLogger()->critical(__VA_ARGS__)