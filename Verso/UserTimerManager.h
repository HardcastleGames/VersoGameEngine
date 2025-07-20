#pragma once
#include "Core.h"
#include <functional>
#include <vector>
#include "UserTimer.h"
#include "Log.h"


namespace Verso {
	class VERSO_API UserTimerManager {
	public:
		UserTimerManager() = default;
		~UserTimerManager() = default;



		void Update(double deltaTime)
		{
			for (auto& timer : m_Timers) {
				timer.Update(deltaTime);
			}
			for (auto& timer : m_Timers)
			{
				if (!timer.IsActive())
				{
					StopTimer(timer);
				}

			}
		}


		template<typename Func, typename ...Args>
		decltype(auto) StartTimer(float seconds, bool repeatable, Func&& func, Args&&... args)
		{
			m_Seconds = seconds;
			m_Repeatable = repeatable;
			m_Callback = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);

			UserTimer newTimer(m_Seconds, m_Repeatable, m_Callback);
			m_Timers.push_back(newTimer);
		}


		void StopTimer(UserTimer& timer)
		{
			auto it = std::remove_if(m_Timers.begin(), m_Timers.end(),
				[&timer](const UserTimer& t) { return &t == &timer; });
			if (it != m_Timers.end()) {
				m_Timers.erase(it, m_Timers.end());
			}
		}





	private:
		float m_Seconds = 0.0f;
		bool m_Repeatable = false;
		std::function<void()> m_Callback;

		std::vector<UserTimer> m_Timers;





	};
}
