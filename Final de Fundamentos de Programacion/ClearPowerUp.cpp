#include "RowsCols.h"
#include "PowerUps.h"
#include "MatrixObj.h"

void ClearPowerUp(char matrix[][cols])
{
    for (int i = 1; i < rows - 1; i++)
    {
        for (int j = 1; j < cols - 1; j++)
        {
            if (matrix[i][j] == (char)PowerUp::GodMode || matrix[i][j] == (char)PowerUp::SpeedUp || matrix[i][j] == (char)PowerUp::DoublePoints)
            {
                matrix[i][j] = (char)MatrixObj::Empty;
            }
        }
    }
}