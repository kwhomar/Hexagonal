#include "createEntity.h"



void createEntity::Execute()
{
	Entity* newEntity = new Entity(character, x, y);
	listOfEntities.emplace_back(newEntity);
	eventLog.emplace_back(this);
}

void createEntity::Undo()
{
	Entity* w = Hexes.PopHexContent(x, y);
	Hexes.PopHexContent(x, y);
	Hexes.PushHexContent(x, y, w);
	eventLog.pop_back();
	delete this;
}

createEntity::createEntity(std::vector<Entity*> listOfEntities, char character, int x, int y)
{
	this->listOfEntities = listOfEntities;
	this->character = character;
	this->x = x;
	this->y = y;
}


createEntity::~createEntity()
{
}
