#include "Application.h"
#include <iostream>
#include "Window.h"


namespace Verso
{

	void Verso::Application::Run()
	{
		while (true)
		{			
			m_window->ProcessMessages();
		}
	}




	//This is the main loop of the application.
	void Verso::Application::Initialize()
	{
		
		HINSTANCE hInstance = GetModuleHandle(NULL);
		UINT nCmdShow = SW_SHOWDEFAULT;

		Verso::Window* window = new Verso::Window(Input, Event);
		m_window = window;
		window->CreateAWindow(hInstance, nCmdShow);


	}

}
