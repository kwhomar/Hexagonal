#include "Grid.h"

void Grid::PushHexContent(int x, int y, Entity* content)
{
	board[x][y].PushContent(content);
}

Entity* Grid::PopHexContent(int x, int y)
{
	return board[x][y].PopContent();
}



Grid::Grid(int width, int height)
{
	this->width = width;
	this->height = height;
	board = new Hex*[width];
	for (int i = 0; i < width; i++)
	{
		board[i] = new Hex[height];
	}
}

int Grid::Size(int x, int y)
{
	return board[x][y].Size();
}

Entity* Grid::GetContent(int x, int y, int index)
{
	return board[x][y].GetContent(index);
}

Grid::~Grid()
{
	for (int i = 0; i < width; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}
