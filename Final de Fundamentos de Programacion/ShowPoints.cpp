#include <iostream>
#include "Cursor.h"
#include "color.h"
#include "Position.h"

void ShowPoints(int points, Color color, Position showPointsPos)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    gotoxy(showPointsPos.x, showPointsPos.y);
    std::cout << "Points" << "\n";

    gotoxy(showPointsPos.x, showPointsPos.y + 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
    std::cout << points;
};