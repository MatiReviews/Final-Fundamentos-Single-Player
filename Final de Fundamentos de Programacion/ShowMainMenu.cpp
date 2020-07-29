#include <iostream>
#include <Windows.h>
#include "SetColor.h"

void ShowMainMenu()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)SetColor::White);
	std::cout << "1. Jugar" << "\n";
	std::cout << "2. Como Jugar" << "\n";
	std::cout << "3. Salir" << "\n";
}