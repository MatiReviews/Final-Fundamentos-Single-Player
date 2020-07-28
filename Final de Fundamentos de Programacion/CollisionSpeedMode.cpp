#include "Player.h"
#include "RowsCols.h"
#include "PowerUps.h"

bool CollisionSpeedMode(Player player, char matrix[][cols])
{
    if (matrix[player.GetY()][player.GetX()] == (char)PowerUp::SpeedUp)
    {
        return true;
    }
    else
    {
        return false;
    }
}