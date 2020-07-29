#include <iostream>
#include "Position.h"
#include "Cursor.h"
#include "PowerUps.h"
#include "Color.h"


void ShowPowerUpInfo(Position powerUpInfoPos, Color powerUpColor)
{
    gotoxy(powerUpInfoPos.x, powerUpInfoPos.y);
    std::cout << "Info" << "\n";

    gotoxy(powerUpInfoPos.x, powerUpInfoPos.y + 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color1);
    std::cout << (char)PowerUp::SpeedUp;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout <<" - Velocidad Rapida" << "\n";


    gotoxy(powerUpInfoPos.x, powerUpInfoPos.y + 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color2);
    std::cout << (char)PowerUp::DoublePoints;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout <<" - Puntos Dobles" << "\n";


    gotoxy(powerUpInfoPos.x, powerUpInfoPos.y + 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color3);
    std::cout << (char)PowerUp::GodMode;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout << " - Modo Dios" << "\n";
}