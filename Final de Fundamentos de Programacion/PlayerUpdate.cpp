#include "Player.h"

void Player::UpdateGodModeClock()
{
	playerModes.godModeClock--;
}

void Player::UpdateFastModeClock()
{
	playerModes.fastModeClock--;
}

void Player::UpdateDoubleModeClock()
{
	playerModes.doubleXpModeClock--;
}