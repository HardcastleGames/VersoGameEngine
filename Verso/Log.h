#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Verso {

	class VERSO_API Log
	{
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

				// Logging macros for engine (core) logs
	#define VERSO_CORE_TRACE(...)    ::Verso::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define VERSO_CORE_INFO(...)     ::Verso::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define VERSO_CORE_WARN(...)     ::Verso::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define VERSO_CORE_ERROR(...)    ::Verso::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define VERSO_CORE_CRITICAL(...) ::Verso::Log::GetCoreLogger()->critical(__VA_ARGS__)

	// Logging macros for application (client) logs
	#define VERSO_CLIENT_TRACE(...)         ::Verso::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define VERSO_CLIENT_INFO(...)          ::Verso::Log::GetClientLogger()->info(__VA_ARGS__)
	#define VERSO_CLIENT_WARN(...)          ::Verso::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define VERSO_CLIENT_ERROR(...)         ::Verso::Log::GetClientLogger()->error(__VA_ARGS__)
	#define VERSO_CLIENT_CRITICAL(...)      ::Verso::Log::GetClientLogger()->critical(__VA_ARGS__)
	

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}
