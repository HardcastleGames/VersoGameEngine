#include <windows.h>
#include "Window.h"


Verso::Window::Window() {}

Verso::Window::~Window() {}



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
}





LRESULT Verso::Window::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

	}

	
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}


