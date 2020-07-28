#include <Windows.h>

void SetGameConsoleSize(int lenght, int height)
{
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, lenght, height, TRUE);
}