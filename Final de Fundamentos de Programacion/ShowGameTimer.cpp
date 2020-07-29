#include <iostream>
#include <Windows.h>

#include "Position.h"
#include "GameModes.h"
#include "Cursor.h"
#include "Color.h"
#include "CurrentGameMode.h"

void ShowGameTimer(Color infoColor,int gameMode, int gameTimer, Position timer)
{
    if (gameMode == (int)CurrentGameMode::ThirtySeconds)
    {
        gotoxy(timer.x, timer.y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), infoColor.color1);
        std::cout << "Tiempo" << "\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), infoColor.color2);
        gotoxy(timer.x + 2, timer.y + 1);
        std::cout << gameTimer << "\n";
    }
}