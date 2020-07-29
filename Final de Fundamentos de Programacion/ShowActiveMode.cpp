#include <iostream>
#include <Windows.h>
#include "Color.h"
#include "Position.h"
#include "Cursor.h"
#include "Player.h"

void ShowActivePowerUp(Player player, Position powerUpPos, Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    gotoxy(powerUpPos.x, powerUpPos.y);
    std::cout << "Power Up" << "\n";

    gotoxy(powerUpPos.x, powerUpPos.y + 1);
    if (player.GetFastMode())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
        std::cout << "Rapido" << "\n";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << "Rapido" << "\n";
    }

    gotoxy(powerUpPos.x, powerUpPos.y + 2);
    if (player.GetDoubleXpMode())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
        std::cout << "2XP" << "\n";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << "2XP" << "\n";
    }

    gotoxy(powerUpPos.x, powerUpPos.y + 3);
    if (player.GetGodMode())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
        std::cout << "Dios" << "\n";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << "Dios" << "\n";
    }
}