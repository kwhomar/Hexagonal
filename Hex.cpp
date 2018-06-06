#include "Hex.h"

void Hex::PushContent(Entity* newContent)
{
	content.emplace_back(newContent);
}

Entity* Hex::GetContent(int index)
{
	return content[index];
}

Entity* Hex::PopContent()
{
	Entity* buf = GetContent(content.size()-1);
	content.pop_back();
	return buf;

}

int Hex::Size()
{
	return content.size();
}

Hex::Hex()
{
	content.emplace_back(nullptr);
}


Hex::~Hex()
{
}
