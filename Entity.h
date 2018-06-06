#pragma once
#include "Grid.h"

extern Grid Hexes;

class Entity
{

	int position;
	char sprite;
protected:
	int coordX, coordY;
public:
	char getSprite()
	{
		if (this)
			return sprite;
		else
			return '.';
	}

	void setSprite(char newSprite)
	{
		sprite = newSprite;
	}

	char getX()
	{
		return coordX;
	}

	char getY()
	{
		return coordY;
	}

	void setX(int x)
	{
		coordX = x;
	}

	void setY(int y)
	{
		coordY = y;
	}
	Entity(char c, int x, int y, Grid& G = Hexes);
	Entity(char c);
	~Entity();
};

