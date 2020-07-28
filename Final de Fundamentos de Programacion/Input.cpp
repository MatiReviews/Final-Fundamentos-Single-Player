#include "Player.h"
#include <conio.h>
#include "RowsCols.h"
#include "MatrixObj.h"

void MovePlayer(Player& player, char matrix[][cols])
{
    char input = ' ';

    input = _getch();

    switch (input)
    {
    case 'w':
    case 'W':

        if (matrix[player.GetY() - 1][player.GetX()] != (char)MatrixObj::Wall)
        {
            player.MoveUp();
        }
        break;

    case 's':
    case 'S':

        if (matrix[player.GetY() + 1][player.GetX()] != (char)MatrixObj::Wall)
        {
            player.MoveDown();
        }
        break;

    case 'a':
    case 'A':

        if (matrix[player.GetY()][player.GetX() - 1] != (char)MatrixObj::Wall)
        {
            player.MoveLeft();
        }
        break;

    case 'd':
    case 'D':

        if (matrix[player.GetY()][player.GetX() + 1] != (char)MatrixObj::Wall)
        {
            player.MoveRight();
        }
        break;
    }
}