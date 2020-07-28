#include "Player.h"
#include "RowsCols.h"
#include "Collision.h"
#include "SetScoreTable.h"

void CollisionAsterisk(Player& player, char matrix[][cols], int scoreTable[cantScores], int indexST)
{
    if (player.GetGodMode() != true)
    {
        if (PlayerCollision(player, matrix))
        {
            SetScoreTable(scoreTable, player, indexST);
        }
    }
}