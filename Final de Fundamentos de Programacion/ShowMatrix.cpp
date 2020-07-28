#include <iostream>
#include <Windows.h>
#include "RowsCols.h"
#include "Color.h"
#include "PowerUps.h"
#include "MatrixObj.h"

void ShowMatrix(char matrix[][cols], Color color, Color powerUpColor)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == (char)MatrixObj::Empty || matrix[i][j] == (char)MatrixObj::Asterisk || matrix[i][j] == (char)MatrixObj::Wall)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.color1);
                std::cout << matrix[i][j];
            }

            if (matrix[i][j] == (char)PowerUp::SpeedUp)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color1);
                std::cout << matrix[i][j];
            }

            if (matrix[i][j] == (char)PowerUp::DoublePoints)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color2);
                std::cout << matrix[i][j];
            }

            if (matrix[i][j] == (char)PowerUp::GodMode)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), powerUpColor.color3);
                std::cout << matrix[i][j];
            }

        }std::cout << "\n";
    }
}