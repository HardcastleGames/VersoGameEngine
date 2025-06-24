#include "Application.h"
#include <iostream>
#include "Window.h"


namespace Verso
{

	void Verso::Application::Run()
	{
		if (Input && Input->IsKeyDown('W'))
		{
			std::cout << Input->IsKeyDown('W') << std::endl;
		}

	}




	//This is the main loop of the application.
	void Verso::Application::Initialize()
	{
		
		HINSTANCE hInstance = GetModuleHandle(NULL);
		UINT nCmdShow = SW_SHOWDEFAULT;

		Verso::Window* window = new Verso::Window(std::move(Input));
		window->CreateAWindow(hInstance, nCmdShow);
		while (true)
		{

			Verso::Application::Run();
			window->ProcessMessages();
		}

	}

}
