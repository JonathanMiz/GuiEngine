
#include "core\Window.h"
#include <memory>

using namespace GuiEngine;


int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdLineParams)
{
	
	std::unique_ptr<Window> win(new Window(hInst, "Window"));
	win->show(SW_SHOW);


	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}