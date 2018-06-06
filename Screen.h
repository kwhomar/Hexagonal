#pragma once
#include "Player.h"
#include <iostream>
#include <windows.h>

extern Grid Hexes;

class Screen
{
	HANDLE hOut;
	COORD Position;
	CONSOLE_CURSOR_INFO cursor_info;
public:
	void draw(Grid& G = Hexes);
	void draw(int x, int y, char c);
	void setCursor(int x = 0, int y = 0);
	void setCursorPure(int x, int y);
	void ShowTop(int x, int y);
	Screen();
	~Screen();
};

