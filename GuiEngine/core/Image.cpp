#include "Image.h"


namespace GuiEngine {

	Image::Image() : position(), filePath(),hBitMap()
	{
	}

	Image::Image(Point & p, std::string & path) : position(p), filePath(path), hBitMap((HBITMAP)LoadImage(hInst, "c:\\test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));
	{
	}

	Image::~Image()
	{
	}

}