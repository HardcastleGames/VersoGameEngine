#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Verso
{

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;


	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$"); // Set log pattern to include time and logger name

		s_CoreLogger = spdlog::stdout_color_mt("VERSO"); // Create a core logger with colored output
		s_CoreLogger->set_level(spdlog::level::trace); // Set log level to trace for core logger

		s_ClientLogger = spdlog::stdout_color_mt("APP"); // Create a client logger with colored output
		s_ClientLogger->set_level(spdlog::level::trace); // Set log level to trace for client logger

	}

}