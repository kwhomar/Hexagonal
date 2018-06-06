#pragma once
#include "ICommand.h"
#include "ICommand.h"
#include "Player.h"
#include "Screen.h"

class removeEntity :
	public ICommand
{
public:
	std::vector<Entity*> listOfEntities;
	char character;
	int x, y;

	void Execute();
	void Undo();
	removeEntity(std::vector<Entity*> listOfEntities, char character, int x, int y);
	~removeEntity();
};

