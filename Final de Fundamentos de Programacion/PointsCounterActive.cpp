#include "Player.h"

void PointsCounterActive(Player& player)
{
    if (player.GetDoubleXpMode() != true)
    {
        player.NormalPoints();
    }
    else
    {
        player.DoublePoints();
    }
};