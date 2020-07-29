#include "Collision.h"
#include "Player.h"
#include "RowsCols.h"
#include "CurrentGameMode.h"

void CheckAllCollisions(Player& player, char matrix[][cols], int scoreBoard[], int indexST, int gameMode)
{
    if (CollisionGodMode(player, matrix))
    {
        player.SetGodMode(true);
    }

    if (gameMode != (int)CurrentGameMode::SingleLife)
    {
        CollisionAsterisk(player, matrix, scoreBoard, indexST);
    }

    if (CollisionSpeedMode(player, matrix))
    {
        player.SetFastMode(true);
    }

    if (CollisionDoubleXpMode(player, matrix))
    {
        SetActiveDoubleXp(player);
    }
}