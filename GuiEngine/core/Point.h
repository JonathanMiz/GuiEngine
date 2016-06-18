#pragma once

namespace GuiEngine {

	class Point
	{
	public:
		Point();
		Point(int y, int x);

		~Point();

		int getX();
		int getY();

		void setX(int newX);
		void setY(int newY);

	private:

		int x;
		int y;
	};

}