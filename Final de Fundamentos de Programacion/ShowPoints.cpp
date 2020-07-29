#include <iostream>
#include "Cursor.h"
#include "color.h"
#include "Position.h"
#include "Player.h"

void ShowPoints(Player player, Color infoColor, Position showPointsPos)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), infoColor.color1);
    gotoxy(showPointsPos.x, showPointsPos.y);
    std::cout << "Puntos" << "\n";

    gotoxy(showPointsPos.x, showPointsPos.y + 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), infoColor.color2);
    std::cout << player.GetPoints();
};