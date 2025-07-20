#include "Application.h"
#include <iostream>
#include "Window.h"
#include "Log.h"
#include "CoreTimer.h"
#include "UserTimerManager.h"


namespace Verso
{
	//This is the main loop of the application.
	void Verso::Application::Run()
	{
		while (true)
		{
			CoreTimer->Tick();
			m_window->ProcessMessages();
			UserTimerManager->Update(CoreTimer->GetDeltaTime());
		}
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

		CoreTimer->start();



	}

}