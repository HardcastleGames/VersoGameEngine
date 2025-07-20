#include "Verso.h"
#include <iostream>
#include "MouseEnum.h"
#include "Log.h"

// Test functions to handle key and mouse events
void KeyPressed(const char Key)//this has to take in a const char key variable because thatat the event system expects
{
	VERSO_CLIENT_INFO("Key Pressed: {}", Key);
}

void MousePressed(Verso::MouseButton Mouse)//this has to take in a Verso::MouseButton Mouse variable because that is what the event system expects
{
	switch (Mouse)
	{
	case Verso::MouseButton::Left:
		VERSO_CLIENT_INFO("Left Mouse Button Pressed");
		break;
	case Verso::MouseButton::Right:
		VERSO_CLIENT_INFO("Right Mouse Button Pressed");
		break;
	case Verso::MouseButton::Middle:
		VERSO_CLIENT_INFO("Middle Mouse Button Pressed");
		break;
	case Verso::MouseButton::Extra1:
		VERSO_CLIENT_INFO("Extra Mouse Button 1 Pressed");
		break;
	case Verso::MouseButton::Extra2:
		VERSO_CLIENT_INFO("Extra Mouse Button 2 Pressed");
		break;
	default:
		VERSO_CLIENT_INFO("Unknown Mouse Button Pressed");
		break;
	}

}

void TestFunction()
{
	VERSO_CLIENT_INFO("Test Function Called");
}


int main()
{

	//Init Start----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	Verso::Application* app = new Verso::Application();
	app->Initialize();
	//Init End------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	app->Event->KeyBind(KeyPressed);
	app->Event->MouseBind(MousePressed);
	app->UserTimerManager->StartTimer(2.0f, false, TestFunction); // Start a timer that calls TestFunction after 2 seconds, not repeatable







	app->Run(); //This enters a while true loop so this has to be the last of our logic
	return 0;
}