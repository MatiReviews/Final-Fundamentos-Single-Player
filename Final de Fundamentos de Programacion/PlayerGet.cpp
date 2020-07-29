#include "Player.h"

int Player::GetX()
{
	return x;
}

int Player::GetY()
{
	return y;
}

bool Player::GetCollision()
{
	return collision;
}

char Player::GetPlayerChar()
{
	return character;
}

int Player::GetPoints()
{
	return points;
}

bool Player::GetGodMode()
{
	return playerModes.godMode;
}

bool Player::GetFastMode()
{
	return playerModes.fastMode;
}

bool Player::GetDoubleXpMode()
{
	return playerModes.doubleXpMode;
}

int Player::GetGodModeClock()
{
	return playerModes.godModeClock;
}

int Player::GetFastModeClock()
{
	return playerModes.fastModeClock;
}

int Player::GetDoubleModeClock()
{
	return playerModes.doubleXpModeClock;
}