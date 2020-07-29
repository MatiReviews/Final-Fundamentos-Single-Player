#include "Player.h"
#include <iostream>
#include <Windows.h>
#include "Color.h"
#include "Cursor.h"

//Movement
void Player::MoveUp()
{
	y--;
}

void Player::MoveDown()
{
	y++;
}

void Player::MoveLeft()
{
	x--;
}

void Player::MoveRight()
{
	x++;
}


//Get
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


//Set
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

//Update
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


//Otros
void Player::NormalPoints()
{
	points++;
}

void Player::DoublePoints()
{
	points += 2;
}


//Draw
void Player::DrawPlayer(Player player, Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);

	gotoxy(player.GetX(), player.GetY());
	std::cout << character << "\n";
}