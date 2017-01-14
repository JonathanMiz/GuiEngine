#include "BaseWindow.h"
#include <functional>

namespace GuiEngine
{

	BaseWindow::BaseWindow(HINSTANCE hInstance, const std::string& windowName)
	{
		
	}

	BaseWindow::~BaseWindow()
	{
	}

	void BaseWindow::show(int showParameters)
	{
		ShowWindow(winHandler, showParameters);
	}

	void BaseWindow::createWindow(HINSTANCE hInstance, const std::string& windowName)
	{
		WNDCLASSEX windowClass = {};

		windowClass.lpfnWndProc = WindowProc;
		windowClass.hInstance = hInstance;
		windowClass.lpszClassName = windowName.c_str();

		if (!RegisterClassEx(&windowClass))
		{
			throw std::runtime_error("Call to RegisterClassEx failed!");
		}

		winHandler = CreateWindow(windowName.c_str(), windowName.c_str(), WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME ^ WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, NULL, NULL, hInstance, NULL);


		if (!winHandler)
		{
			throw std::runtime_error("Call to CreateWindow failed!");
		}
	}

	//LRESULT CALLBACK BaseWindow::WindowProcBridge(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	//{
	//	BaseWindow* pwindow = NULL;
	//	pwindow = (BaseWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
	//	if (pwindow != NULL)
	//		return pwindow->WindowProc(hwnd, uMsg, wParam, lParam);
	//	return 0;
	//}

	LRESULT CALLBACK BaseWindow::WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		LRESULT result = 0;
		switch (message)
		{
		case WM_CREATE:
			OutputDebugStringA("WM_CREATE\n");
			break;

		default:
			result = DefWindowProc(hwnd, message, wParam, lParam);
			break;
		}

		return result;
	}
}
