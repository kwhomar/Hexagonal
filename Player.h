#pragma once
#include "Movable.h"

class Player : public Movable
{
		Entity* hold;
	public:
		void Catch(Entity* object);
		Entity* HoldedObject();
		Player(char c, int x, int y, Grid& G = Hexes);

};

