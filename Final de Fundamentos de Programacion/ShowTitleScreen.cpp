#include <iostream>
#include <Windows.h>

#include "Color.h"

void ShowTitleScreen(Color color)
{
	int min = 0;
	int max = 5;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
	std::cout << "Asterisk" << "\n";
	std::cout << "Ingrese Enter para continuar" << "\n";
}