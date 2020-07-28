#include <Windows.h>

void gotoxy(short x, short y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}