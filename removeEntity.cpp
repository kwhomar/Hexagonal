#include "removeEntity.h"



removeEntity::removeEntity(std::vector<Entity*> listOfEntities, char character, int x, int y)
{
	this->listOfEntities = listOfEntities;
	this->character = character;
	this->x = x;
	this->y = y;
}


void removeEntity::Execute()
{
	Entity* w = Hexes.PopHexContent(x, y);
	Hexes.PopHexContent(x, y);
	Hexes.PushHexContent(x, y, w);
	eventLog.emplace_back(this);
}

void removeEntity::Undo()
{
	Entity *w = Hexes.PopHexContent(x, y);
	Entity* newEntity = new Entity(character, x, y);
	listOfEntities.emplace_back(newEntity);
	Hexes.PushHexContent(x, y, w);
	eventLog.pop_back();
	delete this;
}

removeEntity::~removeEntity()
{
}
