#include <windows.h>
#include "SleepSpeed.h"

void GameSpeedActive(bool& fastMode, int& fastModeClock, int& modMode, SleepSpeed speed)
{
    if (fastMode != true)
    {
        Sleep(speed.normal);
    }
    else
    {
        Sleep(speed.fast);

        if (fastModeClock > 0)
        {
            fastModeClock--;

            if (fastModeClock == 0)
            {
                fastMode = false;
                modMode = 0;
                fastModeClock = 40;
            }
        }
    }
}