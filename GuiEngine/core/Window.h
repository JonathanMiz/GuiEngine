#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

namespace GuiEngine {
	
#define BUTTON_ID    1001

	class Window
	{
	public:
		Window(HINSTANCE hInstance, std::string windowName);
		~Window();

		void show(int showParameters);
	private:
		void createWindow(HINSTANCE hInstance, const std::string& windowName);

	private:
		HWND windowHandler;
		static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
	};

}