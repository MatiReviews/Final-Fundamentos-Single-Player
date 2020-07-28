#include <iostream>
#include "Position.h"
#include "Cursor.h"
#include "PowerUps.h"
#include "Color.h"


void ShowModesInfo(Position modeInfoPos, Color powerUpColor)
{
    gotoxy(modeInfoPos.x, modeInfoPos.y);
    std::cout << "Info" << "\n";


    gotoxy(modeInfoPos.x, modeInfoPos.y + 1);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color1);
    std::cout << (char)PowerUp::SpeedUp;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout <<" - Double speed" << "\n";


    gotoxy(modeInfoPos.x, modeInfoPos.y + 2);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color2);
    std::cout << (char)PowerUp::DoublePoints;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout <<" - Double points" << "\n";


    gotoxy(modeInfoPos.x, modeInfoPos.y + 3);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color3);
    std::cout << (char)PowerUp::GodMode;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color4);
    std::cout << " - God Mode" << "\n";
}