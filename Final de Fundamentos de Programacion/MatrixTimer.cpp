#include "ClearMatrix.h"
#include "FillMatrix.h"
#include "RowsCols.h"

void MatrixTimer(char matrix[][cols], int maxAsterisks, int& contMatrix, int maxContMatrix)
{
    if (contMatrix == maxContMatrix)
    {
        ClearMatrix(matrix);
        FillMatrix(matrix, maxAsterisks);
        contMatrix = 0;
    }
    contMatrix++;
}