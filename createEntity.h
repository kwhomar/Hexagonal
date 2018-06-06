#pragma once
#include "removeEntity.h"

class createEntity :
	public ICommand
{
public:
	std::vector<Entity*> listOfEntities;
	char character;
	int x, y;

	void Execute();
	void Undo();
	createEntity(std::vector<Entity*> listOfEntities, char character, int x, int y);
	~createEntity();
};

