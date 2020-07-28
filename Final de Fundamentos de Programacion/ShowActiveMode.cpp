#include <iostream>
#include <Windows.h>
#include "Color.h"
#include "Position.h"
#include "Cursor.h"
#include "Player.h"

void ShowActiveMode(Player player, Position modePos, Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    gotoxy(modePos.x, modePos.y);
    std::cout << "Mode" << "\n";

    gotoxy(modePos.x, modePos.y + 1);
    if (player.GetFastMode())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
        std::cout << "Fast" << "\n";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << "Fast" << "\n";
    }

    gotoxy(modePos.x, modePos.y + 2);
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

    gotoxy(modePos.x, modePos.y + 3);
    if (player.GetGodMode())
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
        std::cout << "God" << "\n";
    }
    else
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << "God" << "\n";
    }

}