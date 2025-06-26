#include "Input.h"
#include <iostream>

void Verso::Input::KeyDown(char Key)
{
	KeyStates[Key] = true;
}

void Verso::Input::KeyUp(char Key)
{
	KeyStates[Key] = false;
}

//Find the current key and check if it is pressed
bool Verso::Input::IsKeyDown(char Key)
{
	auto CurrentKey = KeyStates.find(Key);
	if (CurrentKey != KeyStates.end())
	{
		return(CurrentKey->second);
	}
	else
	{
		return false;
	}
}

void Verso::Input::MouseDown(MouseButton button)
{
	MouseStates[button] = true;
	//std::cout << "Mouse down: " << static_cast<int>(button) << std::endl;
	
}

void Verso::Input::MouseUp(MouseButton button)
{
	MouseStates[button] = false;
	//std::cout << "Mouse up: " << static_cast<int>(button) << std::endl;
	
}

bool Verso::Input::IsMouseDown(MouseButton button)
{
	auto CurrentMouse = MouseStates.find(button);
	if (CurrentMouse != MouseStates.end())
	{
		return(CurrentMouse->second);
	}
	else
	{
		return false;
	}
}
