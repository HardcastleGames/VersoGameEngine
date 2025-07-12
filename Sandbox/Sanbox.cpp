#include "Verso.h"
#include <iostream>
#include "MouseEnum.h"

// Test functions to handle key and mouse events
void KeyPressed(const char Key)
{
	std::cout << "Test: " << Key << std::endl;
}

void MousePressed(Verso::MouseButton Mouse)
{
	std::cout << "Mouse Pressed" << std::endl;
	switch (Mouse)
	{
		case Verso::MouseButton::Left:
			std::cout << "Left Mouse Button Pressed" << std::endl;
			break;
		case Verso::MouseButton::Right:
			std::cout << "Right Mouse Button Pressed" << std::endl;
			break;
		case Verso::MouseButton::Middle:
			std::cout << "Middle Mouse Button Pressed" << std::endl;
			break;
		case Verso::MouseButton::Extra1:
			std::cout << "Extra Mouse Button 1 Pressed" << std::endl;
			break;
		case Verso::MouseButton::Extra2:
			std::cout << "Extra Mouse Button 2 Pressed" << std::endl;
			break;
		default:
			std::cout << "Unknown Mouse Button Pressed" << std::endl;
			break;
	}
	
}


int main()
{
	Verso::Application* app = new Verso::Application();

	
	app->Initialize(); 
	app->Event->KeyBind(KeyPressed);
	app->Event->MouseBind(MousePressed);
	app->Run(); //This enters a while true loop so this has to be the last of our init logic
	

	
	

	return 0;
}