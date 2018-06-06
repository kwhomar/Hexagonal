#pragma once
#include "placeEntity.h"
class pickEntity :
	public ICommand
{
public:
	Player * player;
	Screen* screen;
	Grid* grid;
	void Execute();
	void Undo();
	pickEntity(Player* player, Screen* screen, Grid& G);
	~pickEntity();
};

