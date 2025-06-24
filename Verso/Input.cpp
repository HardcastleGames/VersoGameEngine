#include "Input.h"

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
