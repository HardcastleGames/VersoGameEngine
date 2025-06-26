#include "Event.h"
#include <iostream>

Verso::Event::Event()
{
}

Verso::Event::~Event()
{
}

void Verso::Event::KeyPressed(char Key)
{
	for (std::function<void(char)>& ob : Observers)
	{
		ob(Key);
	}
	std::cout << "Number of Observers: " << Observers.size() << std::endl;
}
