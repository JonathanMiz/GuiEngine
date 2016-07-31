#include "Window.h"


namespace GuiEngine
{

	Window::Window(HINSTANCE hInstance, std::string windowName) : BaseWindow(hInstance, windowName)
	{

	}


	Window::~Window()
	{
	}

	LRESULT Window::WindowProc(WindowHandler hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CREATE:

			break;
		case WM_COMMAND:

			break;
		}
		return BaseWindow::WindowProc(hwnd, message, wParam, lParam);
	}

}