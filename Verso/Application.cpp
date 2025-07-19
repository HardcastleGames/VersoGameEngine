#include "Application.h"
#include <iostream>
#include "Window.h"
#include "Log.h"
#include "CoreTimer.h"


namespace Verso
{
	//This is the main loop of the application.
	void Verso::Application::Run()
	{
		Verso::CoreTimer* timer = new Verso::CoreTimer();
		timer->start();
		while (true)
		{
			timer->Tick();
			VERSO_CORE_INFO("Delta Time: {0}", timer->GetDeltaTime());
			m_window->ProcessMessages();

		}
		delete timer;
	}





	void Verso::Application::Initialize()
	{

		HINSTANCE hInstance = GetModuleHandle(NULL);
		UINT nCmdShow = SW_SHOWDEFAULT;

		Verso::Window* window = new Verso::Window(Input, Event);
		m_window = window;
		window->CreateAWindow(hInstance, nCmdShow);

		Verso::Log::Init();
		VERSO_CORE_INFO("Verso Engine Initialized!");


	}

}
