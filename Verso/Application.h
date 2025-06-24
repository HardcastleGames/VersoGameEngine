#pragma once  
#include "Core.h"  
#include "Input.h"  
#include <memory>

namespace Verso {  
	class VERSO_API Application {  
	public:  

		std::unique_ptr<Verso::Input> Input;  

		Application()  
		{  
			Input = std::make_unique<Verso::Input>();
		};  
		~Application()  
		{  
		};  

		void Initialize();  
		void Run();  

	};  
}
