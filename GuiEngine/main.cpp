#include "core\Window.h"

using namespace GuiEngine;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdLineParams)
{
	Window w{ hInst,hPrevInstance,cmdLine,cmdLineParams,"Test window" };


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}