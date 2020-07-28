#include <iostream>
#include "RowsCols.h"
#include "PowerUps.h"
#include "MatrixObj.h"

void PowerUpFill(char matrix[][cols], int maxPU)
{
    int cont = 0;

    int rowsFunc = rows - 2;
    int colsFunc = cols - 2;

    int randomI = 0;
    int randomJ = 0;
    int powerUpId = 0;

    char powerUp = ' ';

    do
    {
        randomI = rand() % rowsFunc + 1;
        randomJ = rand() % colsFunc + 1;
        powerUpId = rand() % 3;

        switch (powerUpId)
        {
        case 0:
            powerUp = (char)PowerUp::GodMode;
            break;

        case 1:
            powerUp = (char)PowerUp::SpeedUp;
            break;

        case 2:
            powerUp = (char)PowerUp::DoublePoints;
            break;
        }

        for (int i = 1; i < rowsFunc; i++)
        {
            for (int j = 1; j < colsFunc; j++)
            {
                if (matrix[randomI][randomJ] != (char)MatrixObj::Asterisk)
                {
                    matrix[randomI][randomJ] = powerUp;
                }
            }
        }

        cont++;
    } while (cont < maxPU);
}