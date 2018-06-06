#include "placeEntity.h"

void placeEntity::Execute()
{
	Hexes.PushHexContent(player->getX(), player->getY(), player->HoldedObject());
	player->Catch(nullptr);
	player->setSprite('x');
	eventLog.emplace_back(this);
}

void placeEntity::Undo()
{
	int x = player->getX();
	int y = player->getY();
	Hexes.PopHexContent(x, y);
	player->Catch(Hexes.PopHexContent(x, y));
	player->setSprite('+');
	eventLog.pop_back();
	Hexes.PushHexContent(x, y, player);
}

placeEntity::placeEntity(Player* player, Screen* screen, Grid& G)
{
	this->player = player;
	this->screen = screen;
	this->grid = &G;
}


placeEntity::~placeEntity()
{
}
