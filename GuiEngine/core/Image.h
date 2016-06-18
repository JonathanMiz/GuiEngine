#pragma once
#include "Point.h"
#include <iostream>
#include <Windows.h>

namespace GuiEngine {

	class Image
	{
	public:
		Image();
		Image(Point &p, std::string& path);
		~Image();

	private:
		Point position;
		std::string filePath;

		HBITMAP hBitMap;

	};
}

