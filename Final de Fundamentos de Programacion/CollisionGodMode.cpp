#include "RowsCols.h"
#include "Player.h"
#include "PowerUps.h"

bool CollisionGodMode(Player player, char matrix[][cols])
{
    if (matrix[player.GetY()][player.GetX()] == (char)PowerUp::GodMode)
    {
        return true;
    }
    else
    {
        return false;
    }
}