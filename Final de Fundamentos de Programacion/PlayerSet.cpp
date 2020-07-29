#include "Player.h"

void Player::SetPlayerChar(char playerSkin)
{
	character = playerSkin;
}

void Player::SetX(int posX)
{
	x = posX;
}

void Player::SetY(int posY)
{
	y = posY;
}

void Player::SetPoints(int setpo)
{
	points = setpo;
}

void Player::SetCollision(bool pCollision)
{
	collision = pCollision;
}

void Player::SetGodMode(bool mode)
{
	playerModes.godMode = mode;
}

void Player::SetFastMode(bool mode)
{
	playerModes.fastMode = mode;
}

void Player::SetDoubleXpMode(bool mode)
{
	playerModes.doubleXpMode = mode;
}

void Player::SetGodModeClock(int clock)
{
	playerModes.godModeClock = clock;
}

void Player::SetFastModeClock(int clock)
{
	playerModes.fastModeClock = clock;
}

void Player::SetDoubleXpModeClock(int clock)
{
	playerModes.doubleXpModeClock = clock;
}