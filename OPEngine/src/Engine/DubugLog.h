#pragma once
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "macros.h"

#include <memory>

namespace OPEngine {

	class OPE_API DebugLog {
	public:
	
		DebugLog() {}
		~DebugLog() {}
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return sp_engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sp_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> sp_engineLogger;
		static std::shared_ptr<spdlog::logger> sp_clientLogger;
	
	};

}

// Engine log Macros
#define OPE_ENGINE_INFO(...)    ::OPEngine::DebugLog::GetEngineLogger()->info(__VA_ARGS__)
#define OPE_ENGINE_TRACE(...)   ::OPEngine::DebugLog::GetEngineLogger()->trace(__VA_ARGS__)
#define OPE_ENGINE_WARNING(...) ::OPEngine::DebugLog::GetEngineLogger()->warn(__VA_ARGS__)
#define OPE_ENGINE_ERROR(...)   ::OPEngine::DebugLog::GetEngineLogger()->error(__VA_ARGS__)


// Client log Marcos
#define LOG_INFO(...)    ::OPEngine::DebugLog::GetClientLogger()->info(__VA_ARGS__)
#define LOG_TRACE(...)   ::OPEngine::DebugLog::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_WARNING(...) ::OPEngine::DebugLog::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)   ::OPEngine::DebugLog::GetClientLogger()->error(__VA_ARGS__)