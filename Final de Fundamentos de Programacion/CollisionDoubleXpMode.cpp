#include "Player.h"
#include "RowsCols.h"
#include "PowerUps.h"

bool CollisionDoubleXpMode(Player player, char matrix[][cols])
{
    if (matrix[player.GetY()][player.GetX()] == (char)PowerUp::DoublePoints)
    {
        return true;
    }
    else
    {
        return false;
    }
}