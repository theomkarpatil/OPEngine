#include "DubugLog.h"

namespace OPEngine {

	std::shared_ptr<spdlog::logger> DebugLog::sp_engineLogger;
	std::shared_ptr<spdlog::logger> DebugLog::sp_clientLogger;

	void DebugLog::Init()
	{
							//%T-> time, %n-> logger's name, %v-> actual log// 
		spdlog::set_pattern("[%T] %n %^%v%$");
		sp_engineLogger = spdlog::stdout_color_mt("OPENGINE:");
		sp_engineLogger->set_level(spdlog::level::trace);
		sp_clientLogger = spdlog::stdout_color_mt("SANDBOX :");
		sp_clientLogger->set_level(spdlog::level::trace);
	}
}