#pragma once
#include <vector>

class ICommand
{
public:
	virtual void Execute() = 0;
	virtual void Undo() = 0;
	ICommand();
	~ICommand();
};

extern std::vector<ICommand*> eventLog;
