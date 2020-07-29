#include "Player.h"

void SetSpeedTimer(Player player, int& gameTimerMax)
{
    if (player.GetFastMode())
    {
        gameTimerMax = 9;
    }
    else
    {
        gameTimerMax = 6;
    }
}