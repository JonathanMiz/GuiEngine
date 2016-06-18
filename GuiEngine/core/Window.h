#pragma once

#include <Windows.h>
#include <string>
namespace GuiEngine {

	class Window
	{
	public:
		Window();
		Window(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow, std::string windowName);
		~Window();

	private:
		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
	};

}