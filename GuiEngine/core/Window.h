#pragma once

#include "BaseWindow.h"

namespace GuiEngine {
	
#define BUTTON_ID    1001

	class Window : public BaseWindow
	{
	public:
		Window(HINSTANCE hInstance, std::string windowName);
		~Window();

	private:
		static LRESULT WindowProc(WindowHandler, UINT, WPARAM, LPARAM);
	};

}