#include "Window.h"


namespace GuiEngine
{

	Window::Window(HINSTANCE hInstance, std::string windowName)
	{
		createWindow(hInstance, windowName);
	}


	Window::~Window()
	{
	}

	void Window::show(int showParameters)
	{
		ShowWindow(windowHandler, showParameters);
	}

	void Window::createWindow(HINSTANCE hInstance, const std::string& windowName)
	{
		WNDCLASS windowClass = {};

		windowClass.lpfnWndProc = WindowProc;
		windowClass.hInstance = hInstance;
		windowClass.lpszClassName = windowName.c_str();

		if (!RegisterClass(&windowClass))
		{
			OutputDebugStringA("Error register\n");
			return;
		}

		windowHandler = CreateWindow(windowName.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL);

		if (!windowHandler)
		{
			OutputDebugStringA("Error create window\n");
			return;
		}
	}


	LRESULT CALLBACK Window::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = 0;
		
		HWND button;
		switch (message)
		{
		case WM_CREATE:
			button = CreateWindow("button", "Label",
				WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
				200, 200,
				50, 20,
				hwnd, (HMENU)1001,
				GetModuleHandle(NULL), NULL);
			break;
		case WM_COMMAND:

			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			result = DefWindowProc(hwnd, message, wParam, lParam);
			break;
		}

		return result;
	}

}