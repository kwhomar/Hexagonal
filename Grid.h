#pragma once
#include "Hex.h"


class Grid
{
	Hex** board;
	
public:
	int width, height;
	void PushHexContent(int x, int y, Entity* content);
	Entity* PopHexContent(int x, int y);
	int Size(int x, int y);
	Entity* GetContent(int x, int y, int index);
	Grid(int width, int height);
	~Grid();
};

