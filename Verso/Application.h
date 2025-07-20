#pragma once  
#include "Core.h"  
#include "Input.h"  
#include "Event.h"
#include "Window.h"
#include "UserTimerManager.h"
#include <memory>
#include "CoreTimer.h"

namespace Verso {
	class VERSO_API Application {
	public:

		std::shared_ptr<Verso::Input> Input;
		std::shared_ptr<Verso::Event> Event;
		std::shared_ptr<Verso::UserTimerManager> UserTimerManager;
		std::shared_ptr<Verso::CoreTimer> CoreTimer;
		Verso::Window* m_window;

		Application()
		{
			Input = std::make_shared<Verso::Input>();
			Event = std::make_shared<Verso::Event>();
			UserTimerManager = std::make_shared<Verso::UserTimerManager>();
			CoreTimer = std::make_shared<Verso::CoreTimer>();
		};
		~Application()
		{
		};

		void Initialize();
		void Run();

	};
}

