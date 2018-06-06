#pragma once
#include "ICommand.h"

using namespace std;
class Entity;

class Hex
{
	vector<Entity*> content;
public:
	int Size();

	void PushContent(Entity* newContent);
	Entity* GetContent(int index);
	Entity* PopContent();
	Hex();
	~Hex();
};

