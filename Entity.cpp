#include "Entity.h"


Entity::Entity(char c, int x, int y, Grid& G)
{
	sprite = c;
	coordX = x;
	coordY = y;
	G.PushHexContent(x, y, this);
}

Entity::Entity(char c)
{
	sprite = c;
}


Entity::~Entity()
{
}
