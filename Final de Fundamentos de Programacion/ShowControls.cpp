#include <iostream>
#include <Windows.h>
#include "Color.h"
#include "Position.h"
#include "Cursor.h"


void ShowControls(Color infoColor, Position pos)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), infoColor.color2);
    gotoxy(pos.x, pos.y);
    std::cout << "Controles" << "\n";
    gotoxy(pos.x, pos.y + 1);
    std::cout << "W - Arriba" << "\n";
    gotoxy(pos.x, pos.y + 2);
    std::cout << "S - Abajo" << "\n";
    gotoxy(pos.x, pos.y + 3);
    std::cout << "A - Izquierda" << "\n";
    gotoxy(pos.x, pos.y + 4);
    std::cout << "D - Derecha" << "\n";
}