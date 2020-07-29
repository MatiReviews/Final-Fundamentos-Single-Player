#include <iostream>
#include "Player.h"
#include "Cursor.h"
#include "Color.h"

void Player::DrawPlayer(Player player, Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);

	gotoxy(player.GetX(), player.GetY());
	std::cout << character << "\n";
}