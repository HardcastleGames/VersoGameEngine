#include "CoreTimer.h"

bool paused = true;

std::chrono::time_point<std::chrono::steady_clock> StartTime;

std::chrono::time_point<std::chrono::steady_clock> RunTime;

std::chrono::time_point<std::chrono::steady_clock> m_LastFrameTime;

std::chrono::time_point<std::chrono::steady_clock> m_CurrentFrameTime;

std::chrono::duration<double> m_FrameTimeDif;

double m_DeltaTime = 0.0;

namespace Verso {

	void CoreTimer::Pause(bool Paused)
	{
		paused = Paused;
	}

	bool CoreTimer::IsPaused()
	{
		return paused;
	}

	double CoreTimer::GetDeltaTime()
	{
		return m_DeltaTime;
	}

	double CoreTimer::GetRunTime()
	{
		return((m_CurrentFrameTime - StartTime).count());
	}

	void Verso::CoreTimer::start()
	{
		paused = false;
		StartTime = std::chrono::steady_clock::now();
		m_LastFrameTime = StartTime;

	}

	void CoreTimer::Tick()
	{
		if (paused)
			return;

		m_CurrentFrameTime = std::chrono::steady_clock::now();
		m_FrameTimeDif = m_CurrentFrameTime - m_LastFrameTime;
		m_DeltaTime = m_FrameTimeDif.count();
		m_LastFrameTime = m_CurrentFrameTime;
		VERSO_CORE_INFO("Delta Time: {0}", m_DeltaTime);



	}
}
