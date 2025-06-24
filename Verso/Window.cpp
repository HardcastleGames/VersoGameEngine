#include <windows.h>
#include "Window.h"
#include <iostream>




bool Verso::Window::CreateAWindow(HINSTANCE hInstance, UINT nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"Verso Window Class";

	WNDCLASS wc = {};
	wc.hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	m_hwnd = CreateWindowEx(
		0,                          // Optional window styles.
		CLASS_NAME,                 // Window class
		L"Verso Window",            // Window text
		WS_OVERLAPPEDWINDOW,        // Window style
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // Size and position
		NULL,                       // Parent window
		NULL,                       // Menu
		hInstance,                 // Instance handle
		this                        // Additional application data
	);

	if (m_hwnd == NULL)
	{
		return false;
	}

	ShowWindow(m_hwnd, nCmdShow);

	return true;

}




bool Verso::Window::ProcessMessages()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if (msg.message == WM_QUIT)
		{
			return false;
		}
	}

	return true;
}





LRESULT Verso::Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// On WM_NCCREATE, store the Window* pointer in window user data
	if (uMsg == WM_NCCREATE)
	{
		CREATESTRUCT* cs = reinterpret_cast<CREATESTRUCT*>(lParam);
		Window* pWindow = reinterpret_cast<Window*>(cs->lpCreateParams);

		// Associate the pointer with this hwnd
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWindow));

		// Also store hwnd in the Window object
		pWindow->m_hwnd = hwnd;

		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	// Retrieve Window* pointer for other messages
	Window* pWindow = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));


	switch (uMsg)
	{
		
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		return 0;

	}
	case WM_KEYDOWN:
	{
		if (pWindow && pWindow->m_Input)
		{
			char Key = static_cast<char>(wParam);
			pWindow->m_Input->KeyDown(Key);
			return 0;
		}
	}

	case WM_KEYUP:
	{
		if (pWindow && pWindow->m_Input)
		{
			char Key = static_cast<char>(wParam);
			pWindow->m_Input->KeyUp(Key);
			return 0;
		}
	}



	//Dont remove this curely bracket by mistake
	///////////////////////////////////////////////
	}
	///////////////////////////////////////////////

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


