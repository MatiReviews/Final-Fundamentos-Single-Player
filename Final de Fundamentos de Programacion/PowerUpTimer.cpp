#include "ClearMatrix.h"
#include "FillMatrix.h"
#include "RowsCols.h"

void PowerUpTimer(char matrix[][cols], int& contPowerUps,int maxContPowerUps, int maxPowerUps)
{
    if (contPowerUps == maxContPowerUps)
    {
        ClearPowerUp(matrix);
        PowerUpFill(matrix, maxPowerUps);
        contPowerUps = 0;
    }
    contPowerUps++;
}