#include "Screen.h"


void Screen::draw(Grid& G)
{
	for (int i = 0; i < G.height; i++)
	{
		if (!(i % 2)) std::cout << " ";
		for (int j = 0; j < G.width; j++)
		{
			Entity* w = G.GetContent(i, j, G.Size(i,j)-1);
			std::cout << w->getSprite() << " ";
		}
		std::cout << std::endl;
	}
}

void Screen::draw(int x, int y, char c)
{
	setCursor(x, y);
		std::cout << c;
}

void Screen::ShowTop(int x, int y)
{
	Entity* currentEntity = Hexes.GetContent(x, y, Hexes.Size(x,y)-1);
	draw(x, y, currentEntity->getSprite());
}

void Screen::setCursor(int x, int y)
{
	Position.Y = x;
	Position.X = 2 * y;
	if (!(x % 2))
		Position.X++;
		
	SetConsoleCursorPosition(hOut, Position);
}

void Screen::setCursorPure(int x, int y)
{
	Position.Y = x;
	Position.X = 2 * y;
	SetConsoleCursorPosition(hOut, Position);
}

Screen::Screen()
{
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hOut, &cursor_info);
	cursor_info.bVisible = 0;
	SetConsoleCursorInfo(hOut, &cursor_info);
}


Screen::~Screen()
{
}
