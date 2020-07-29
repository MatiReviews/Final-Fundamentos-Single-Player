#pragma once

struct gameModes
{
    bool godMode = false;
    bool fastMode = false;
    bool doubleXpMode = false;

    int godModeClock = 40;
    int fastModeClock = 40;
    int doubleXpModeClock = 40;
};

enum class CurrentGameMode
{
    ThirtySeconds = 1,
    SingleLife = 2,
    Unlimited = 3
};