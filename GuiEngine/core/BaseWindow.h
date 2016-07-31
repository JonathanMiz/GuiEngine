#pragma once
#include <Windows.h>
#include <string>

namespace GuiEngine
{
	using WindowHandler = HWND;
	class BaseWindow
	{
	public:
		BaseWindow(HINSTANCE hInstance, std::string windowName);
		~BaseWindow();

		void show(int showParameters);

	private:
		void createWindow(HINSTANCE hInstance, std::string windowName);

	protected:
		WindowHandler winHandler;

		static LRESULT CALLBACK WindowProc(WindowHandler, UINT, WPARAM, LPARAM);
	};

}
