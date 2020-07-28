#include "Player.h"
#include "RowsCols.h"
#include "MatrixObj.h"

bool CollisionAsterisk(Player player, char matrix[][cols])
{
    if (matrix[player.GetY()][player.GetX()] == (char)MatrixObj::Asterisk)
    {
        return true;
    }
    else
    {
        return false;
    }
}