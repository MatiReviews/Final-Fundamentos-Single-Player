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
	return myMode.godMode;
}

bool Player::GetFastMode()
{
	return myMode.fastMode;
}

bool Player::GetDoubleXpMode()
{
	return myMode.doubleXpMode;
}

int Player::GetGodModeClock()
{
	return myMode.godModeClock;
}

int Player::GetFastModeClock()
{
	return myMode.fastModeClock;
}

int Player::GetDoubleModeClock()
{
	return myMode.doubleXpModeClock;
}


//Set
void Player::SetPlayerChar(char playerSkin)
{
	character = playerSkin;
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
	myMode.godMode = mode;
}

void Player::SetFastMode(bool mode)
{
	myMode.fastMode = mode;
}

void Player::SetDoubleXpMode(bool mode)
{
	myMode.doubleXpMode = mode;
}

void Player::SetGodModeClock(int clock)
{
	myMode.godModeClock = clock;
}

void Player::SetFastModeClock(int clock)
{
	myMode.fastModeClock = clock;
}

void Player::SetDoubleXpModeClock(int clock)
{
	myMode.doubleXpModeClock = clock;
}

//Update
void Player::UpdateGodModeClock()
{
	myMode.godModeClock--;
}

void Player::UpdateFastModeClock()
{
	myMode.fastModeClock--;
}

void Player::UpdateDoubleModeClock()
{
	myMode.doubleXpModeClock--;
}


//Draw
void Player::DrawPlayer(Player player, Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);

	gotoxy(player.GetX(), player.GetY());
	std::cout << character << "\n";
}