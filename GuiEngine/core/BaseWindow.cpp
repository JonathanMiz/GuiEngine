#include "BaseWindow.h"


namespace GuiEngine
{

	BaseWindow::BaseWindow(HINSTANCE hInstance, std::string windowName)
	{
		createWindow(hInstance, windowName);
	}

	BaseWindow::~BaseWindow()
	{
	}

	void BaseWindow::show(int showParameters)
	{
		ShowWindow(winHandler, showParameters);
	}

	void BaseWindow::createWindow(HINSTANCE hInstance, std::string windowName)
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = windowName.c_str();
		wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

		if (!RegisterClassEx(&wcex))
		{
			throw std::runtime_error("Call to RegisterClassEx failed!");
		}

		winHandler = CreateWindow(windowName.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL);

		if (!winHandler)
		{
			throw std::runtime_error("Call to CreateWindow failed!");
		}
	}
	LRESULT BaseWindow::WindowProc(WindowHandler hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{

		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
			break;
		}
		return 0;
	}
}
