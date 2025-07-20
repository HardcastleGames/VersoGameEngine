#pragma once
#include "Core.h"
#include <functional>
#include "Log.h"
#include "UserTimerManager.h"


namespace Verso {

	class VERSO_API UserTimer {
	public:

		UserTimer(float Seconds, bool Repeatable, std::function<void()> function)
		{
			m_Seconds = Seconds;
			m_Repeatable = Repeatable;
			m_Function = function;
		}


		~UserTimer() = default;

		void Update(float deltaTimer)
		{
			m_ElapsedTime += deltaTimer;
			if (m_ElapsedTime >= m_Seconds)
			{
				m_Function();
				if (m_Repeatable)
				{
					m_ElapsedTime = 0.0f; // Reset the elapsed time if the timer is repeatable
				}
				else
				{
					VERSO_CORE_CRITICAL("Timer has finished and is not repeatable, removing it from the manager.");
					m_IsActive = false; // Mark the timer as inactive
				}
			}
		}

		bool IsActive() const { return m_IsActive; } // Check if the timer is still active

	private:
		float m_Seconds;
		bool m_Repeatable;
		std::function<void()> m_Function;

		double m_ElapsedTime = 0.0; // Time elapsed since the timer started
		bool m_IsActive = true; // Indicates if the timer is currently active

	};
}
