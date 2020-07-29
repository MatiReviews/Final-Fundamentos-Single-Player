#include <iostream>
#include <ctime>

#include "Player.h"
#include "RowsCols.h"
#include "MatrixObj.h"
#include "PowerUps.h"

void SetInitPos(Player& player, char matrix[][cols])
{
    int minX = 1;
    int maxX = cols - 2;

    int minY = 1;
    int maxY = rows - 2;

    int randomY = 0;
    int randomX = 0;
    bool isEmpty{ true };

    do
    {
        randomX = rand() % (maxX - minX + 1) + minX;
        randomY = rand() % (maxY - minY + 1) + minY;

        if (matrix[randomY][randomX] != (char)MatrixObj::Asterisk && matrix[randomY][randomX] != (char)PowerUp::DoublePoints &&
            matrix[randomY][randomX] != (char)PowerUp::GodMode && matrix[randomY][randomX] != (char)PowerUp::SpeedUp)
        {
            player.SetX(randomX);
            player.SetY(randomY);
            isEmpty = true;
        }
        else
        {
            isEmpty = false;
        }

    } while (isEmpty == false);

}