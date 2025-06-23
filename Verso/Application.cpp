#include "Application.h"
#include <iostream>
#include "Window.h"

namespace Verso
{
	Verso::Application::Application()
	{
	}

	Verso::Application::~Application()
	{
	}

	void Verso::Application::Run()
	{
		std::cout << "Running application..." << std::endl;
	}




	//This is the main loop of the application.
	void Verso::Application::Initialize()
	{
		
		HINSTANCE hInstance = GetModuleHandle(NULL);
		UINT nCmdShow = SW_SHOWDEFAULT;

		Verso::Window* window = new Verso::Window();
		window->CreateAWindow(hInstance, nCmdShow);
		while (true)
		{

			Verso::Application::Run();
			window->ProcessMessages();
		}

	}

}
