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
	for (std::function<void(char)>& ob : KeyObservers)
	{
		ob(Key);
	}
	std::cout << "Number of Key Observers: " << KeyObservers.size() << std::endl;
}

void Verso::Event::MousePressed(MouseButton Mouse)
{
	for (std::function<void(Verso::MouseButton)>& ob : MouseObservers)
	{
		ob(Mouse);
	}
	std::cout << "Number of Mouse Observers: " << MouseObservers.size() << std::endl;
}
