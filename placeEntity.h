#pragma once
#include "createEntity.h"


class placeEntity :
	public ICommand
{
public:
	Player * player;
	Screen* screen;
	Grid* grid;

	void Execute();
	void Undo();
	placeEntity(Player* player, Screen* screen, Grid& G);
	~placeEntity();
};
