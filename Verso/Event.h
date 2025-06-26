#pragma once
#include <functional>
#include <vector>
#include <iostream>


namespace Verso {
	class Event {
	public:

		using observer = std::function<void(char)>;

		Event();
		~Event();

		void KeyPressed(char Key);

		void Bind(const observer& function)
		{
			Observers.push_back(function);
			
		
		};


		std::vector<observer>Observers;



	};
}
