#include <iostream>
#include <Windows.h>
#include "RowsCols.h"
#include "Color.h"
#include "Cursor.h"
#include "Position.h"

void ShowScoreTable(int ScoreTable[cantScores], Color color, Position recordPos, Position pointsStPos)
{
    gotoxy(recordPos.x, recordPos.y);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    std::cout << "Records" << "\n";

    for (short i = 0; i < cantScores; i++)
    {
        gotoxy(pointsStPos.x, i + pointsStPos.y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
        std::cout << i + 1 << ". " << ScoreTable[i] << std::endl;
    }
}