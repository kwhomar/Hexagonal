#pragma once
#include "Entity.h"

enum Direction { E, NE, NW, W, SW, SE };

class Movable :
	public Entity
{
	Entity* hold;
	Direction direction;
public:
	bool movement(Direction k);
	Direction getDirection();
	Movable(char c, int x, int y, Grid& G = Hexes);
	~Movable();

};

