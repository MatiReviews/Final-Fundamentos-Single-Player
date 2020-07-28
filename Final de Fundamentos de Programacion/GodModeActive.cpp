#include "RowsCols.h"
#include "Player.h"
#include "ScoreTable.h"

void GodModeActive(Player& player)
{
    if (player.GetGodMode() && player.GetCollision() || player.GetGodMode() && player.GetCollision() == false)
    {
        if (player.GetGodModeClock() > 0)
        {
            player.UpdateGodModeClock();

            if (player.GetGodModeClock() == 0)
            {
                player.SetGodMode(false);
                player.SetCollision(false);
                player.SetGodModeClock(40);
            }
        }
    }

}