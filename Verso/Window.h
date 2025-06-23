#pragma once
#include <Windows.h>

namespace Verso {
	class Window {

	public:
		Window();
		~Window();

		HWND m_hwnd;

		bool CreateAWindow(HINSTANCE hInstance, UINT nCmdShow);

		bool ProcessMessages();

		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);




	};


}
