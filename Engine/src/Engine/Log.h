#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Engine {

	class ENGINE_API Log{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger();
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger();
	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};

}