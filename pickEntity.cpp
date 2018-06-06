#include "pickEntity.h"

void pickEntity::Execute()
{
	player->Catch(Hexes.PopHexContent(player->getX(), player->getY()));
	player->setSprite('+');
	eventLog.emplace_back(this);
}

void pickEntity::Undo()
{
	int x = player->getX();
	int y = player->getY();
	Hexes.PopHexContent(x, y);
	Hexes.PushHexContent(x, y, player->HoldedObject());
	player->Catch(nullptr);
	player->setSprite('x');
	eventLog.pop_back();
	Hexes.PushHexContent(x, y, player);
}

pickEntity::pickEntity(Player* player, Screen* screen, Grid& G)
{
	this->player = player;
	this->screen = screen;
	this->grid = &G;
}


pickEntity::~pickEntity()
{
}
