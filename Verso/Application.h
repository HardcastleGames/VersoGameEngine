#pragma once  
#include "Core.h"  
#include "Input.h"  
#include "Event.h"
#include "Window.h"
#include <memory>

namespace Verso {  
	class VERSO_API Application {  
	public:  

		std::shared_ptr<Verso::Input> Input;  
		std::shared_ptr<Verso::Event> Event;
		Verso::Window* m_window;

		Application()  
		{  
			Input = std::make_shared<Verso::Input>();
			Event = std::make_shared<Verso::Event>();
		};  
		~Application()  
		{  
		};  

		void Initialize();  
		void Run();  

	};  
}
