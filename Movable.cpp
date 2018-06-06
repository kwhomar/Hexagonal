#include "Movable.h"


extern Grid Hexes;

bool Movable::movement(Direction k)
{
	int copyX = coordX, copyY = coordY;
	bool parity = coordX % 2;
	switch (k)
	{
	case E:
		if (coordY + 1 < Hexes.width)
		copyY++;
		break;
	case NW:
		if (coordX > 0 && (!parity || (coordY > 0)))
		{
			copyX--;
			if (parity)
				copyY--;
		}
		break;
	case NE:
		if ((coordX > 0) && ((coordY + 1 < Hexes.width) || parity))
		{
			copyX--;
			if (!parity)
				copyY++;
		}
		break;
	case W:
		if (coordY > 0)
		copyY--;
		break;
	case SE:
		if ((coordX + 1 < Hexes.height) && ((coordY + 1 < Hexes.width) || parity))
		{
			copyX++;
			if (!parity)
				copyY++;
		}
		break;
	case SW:
		if ((coordY > 0 || !parity) && (coordX + 1 < Hexes.height))
		{
			copyX++;
			if (parity)
				copyY--;
		}
		break;
	}

	coordX = copyX;
	coordY = copyY;
	Hexes.PushHexContent(copyX, copyY, this);
	Entity* w = Hexes.GetContent(copyX, copyY, Hexes.Size(copyX, copyY)-1);
	return 1;
	
}

Direction Movable::getDirection()
{
	return direction;
}


Movable::Movable(char c, int x, int y, Grid& G):
	Entity(c, x, y, G)
{
}


Movable::~Movable()
{
}



