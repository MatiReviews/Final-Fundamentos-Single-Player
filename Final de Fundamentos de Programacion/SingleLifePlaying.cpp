#include "Collision.h"
#include "Player.h"
#include "RowsCols.h"

void SingleLifePlaying(Player player, char matrix[][cols], bool& playing)
{
    if (PlayerCollision(player, matrix) && player.GetGodMode() != true)
    {
        playing = false;
    }
}