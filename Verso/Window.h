#pragma once
#include <Windows.h>
#include <memory>
#include "Input.h"

namespace Verso {
	class Window {

	public:
		std::unique_ptr<Verso::Input> m_Input;

		Window(std::unique_ptr<Verso::Input> Input) : m_Input(std::move(Input)) {};
		~Window() {};

		HWND m_hwnd;

		bool CreateAWindow(HINSTANCE hInstance, UINT nCmdShow);

		bool ProcessMessages();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);




	};


}
