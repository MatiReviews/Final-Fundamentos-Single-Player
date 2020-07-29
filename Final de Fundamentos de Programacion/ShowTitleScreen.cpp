#include <iostream>
#include <Windows.h>

#include "Color.h"

void ShowTitleScreen(Color color)
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
	std::cout << "	Asterisk" << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
	std::cout << "\nIngrese Enter para continuar" << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color2);
	std::cout << "\nHecho por";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color3);
	std::cout << " Matias Szamrynskyj" << "\n";
}