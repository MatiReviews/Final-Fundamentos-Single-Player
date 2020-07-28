#include <windows.h>
#include "Player.h"
#include "SleepSpeed.h"

void GameSpeedActive(Player& player, SleepSpeed speed)
{

    if (player.GetFastMode() != true)
    {
        Sleep(speed.normal);
    }
    else
    {
        Sleep(speed.fast);

        if (player.GetFastModeClock() > 0)
        {
            player.UpdateFastModeClock();

            if (player.GetFastModeClock() == 0)
            {
                player.SetFastMode(false);
                player.SetFastModeClock(40);
            }
        }
    }
}