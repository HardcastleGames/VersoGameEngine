#include "Verso.h"
#include <iostream>

// Corrected function declaration and removed the stray semicolon
void KeyPressed(char Key)
{
	std::cout << "Test: " << Key << std::endl;
}

int main()
{
	Verso::Application* app = new Verso::Application();

	
	app->Initialize(); 
	app->Event->Bind(KeyPressed);
	app->Run(); //This enters a while true loop so this has to be the last of our init logic
	

	
	

	return 0;
}