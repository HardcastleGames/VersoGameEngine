#pragma once
#include <Windows.h>
#include <memory>
#include "Input.h"
#include "Event.h"


namespace Verso {
	class Window {

	public:
		std::shared_ptr<Verso::Input> m_Input;
		std::shared_ptr<Verso::Event> m_Event;

		Window(std::shared_ptr<Verso::Input> Input, std::shared_ptr<Verso::Event> Event) : m_Input(Input), m_Event(Event) {};
		~Window() {};

		HWND m_hwnd;

		bool CreateAWindow(HINSTANCE hInstance, UINT nCmdShow);

		bool ProcessMessages();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);




	};


}
