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
	VERSO_CORE_INFO("Number of Key Observers: {}", KeyObservers.size());
}

void Verso::Event::MousePressed(MouseButton Mouse)
{
	for (std::function<void(Verso::MouseButton)>& ob : MouseObservers)
	{
		ob(Mouse);
	}
	VERSO_CORE_INFO("Number of Mouse Observers: {}", MouseObservers.size());
}
