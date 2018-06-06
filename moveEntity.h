#pragma once
#include "pickEntity.h"



class moveEntity :
	public ICommand
{
public:
	Movable* target;
	Direction direction;
	Screen* screen;
	Grid* grid;

	void Execute();
	void Undo();
	moveEntity(Movable* target, Direction direction, Screen* screen, Grid& G);
	~moveEntity();
};

