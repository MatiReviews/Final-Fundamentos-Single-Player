#include <iostream>
#include <Windows.h>
#include "RowsCols.h"
#include "Color.h"
#include "Cursor.h"
#include "Position.h"
#include "CurrentGameMode.h"

void ShowScoreBoard(int gameMode, int ScoreTable[cantScores], Color color, Position recordPos)
{
    if (gameMode != (int)CurrentGameMode::SingleLife)
    {
        gotoxy(recordPos.x, recordPos.y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
        std::cout << "Records" << "\n";

        for (short i = 0; i < cantScores; i++)
        {
            gotoxy(recordPos.x + 1, i + recordPos.y + 1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
            std::cout << i + 1 << ". " << ScoreTable[i] << std::endl;
        }
    }    
}