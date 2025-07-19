#pragma once
#include "Core.h"
#include <chrono>
#include "Log.h"

namespace Verso {

	class VERSO_API	CoreTimer {

	public:

		CoreTimer() = default;
		~CoreTimer() = default;

		static void start();
		void Tick();

		void Pause(bool Paused);
		bool IsPaused();

		double GetDeltaTime();
		double GetRunTime();



	};

}

