#include <iostream>
#include "RowsCols.h"
#include "MatrixObj.h"

void FillMatrix(char matrix[][cols], int maxAsterisks)
{
    int cont = 0;

    int rowsFunc = rows - 2;
    int colsFunc = cols - 2;

    int randomI = 0;
    int randomJ = 0;

    do
    {
        randomI = rand() % rowsFunc + 1;
        randomJ = rand() % colsFunc + 1;


        for (int i = 1; i < rowsFunc; i++)
        {
            for (int j = 1; j < colsFunc; j++)
            {
                matrix[randomI][randomJ] = (char)MatrixObj::Asterisk;
            }
        }

        cont++;
    } while (cont < maxAsterisks);

}