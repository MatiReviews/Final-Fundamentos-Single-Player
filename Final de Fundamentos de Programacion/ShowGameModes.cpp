#include <iostream>
#include <Windows.h>}
#include "Color.h"

void ShowGameModes(Color color)
{
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
    std::cout << "Seleccione un modo" << "\n";
    std::cout << "1 - 30 Segundos" << "\n";
    std::cout << "2 - Unica Vida" << "\n";
    std::cout << "3 - Tiempo Ilimitado" << "\n";
}