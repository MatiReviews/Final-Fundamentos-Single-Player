#include "RowsCols.h"
#include "Player.h"

void ScoreTable(int scoreTable[cantScores], Player player, int indexST)
{
    for (short i = cantScores - 1; i >= 0; i--)
    {
        if (player.GetPoints() > scoreTable[i])
        {
            indexST = i;
        }
    }

    if (indexST != -1)
    {
        for (short i = cantScores - 1; i > indexST; i--)
        {
            scoreTable[i] = scoreTable[i - 1];
        }

        scoreTable[indexST] = player.GetPoints();
    }
}