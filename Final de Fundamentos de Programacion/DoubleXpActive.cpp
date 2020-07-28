#include "Player.h"

void DoubleXpActive(Player& player)
{
    if (player.GetDoubleXpMode() == true)
    {
        if (player.GetDoubleModeClock() > 0)
        {
            player.UpdateDoubleModeClock();

            if (player.GetDoubleModeClock() == 0)
            {
                player.SetDoubleXpMode(false);
                player.SetDoubleXpModeClock(40);
            }
        }
    }
}

void SetActiveDoubleXp(Player& player)
{
    player.SetDoubleXpMode(true);
}