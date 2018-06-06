#include "moveEntity.h"

void moveEntity::Execute()
{
	grid->PopHexContent(target->getX(), target->getY());
	screen->ShowTop(target->getX(), target->getY());
	target->movement(direction);
	eventLog.emplace_back(this);
}

void moveEntity::Undo()
{
	direction = static_cast<Direction>((direction + 3) % 6);
	grid->PopHexContent(target->getX(), target->getY());
	screen->ShowTop(target->getX(), target->getY());
	target->movement(direction);
	direction = static_cast<Direction>((direction + 3) % 6);
	eventLog.pop_back();
	delete this;
}

moveEntity::moveEntity(Movable* target, Direction direction, Screen* screen, Grid& G)
{
	this->target = target;
	this->direction = direction;
	this->screen = screen;
	this->grid = &G;
}


moveEntity::~moveEntity()
{
}
