#include "Player.h"

void Player::Catch(Entity* object)
{
	hold = object;
}

Entity* Player::HoldedObject()
{
	return hold;
}

Player::Player(char c, int x, int y, Grid& G) : Movable(c, x, y, G)
{

}
