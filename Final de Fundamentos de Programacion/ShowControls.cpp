#include <iostream>
#include <Windows.h>
#include "Color.h"
#include "Position.h"
#include "Cursor.h"


void ShowControls(Color color, Position pos)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    gotoxy(pos.x, pos.y);
    std::cout << "Controls" << "\n";
    gotoxy(pos.x, pos.y + 1);
    std::cout << "W - Up" << "\n";
    gotoxy(pos.x, pos.y + 2);
    std::cout << "S - Down" << "\n";
    gotoxy(pos.x, pos.y + 3);
    std::cout << "A - Left" << "\n";
    gotoxy(pos.x, pos.y + 4);
    std::cout << "D - Right" << "\n";
}