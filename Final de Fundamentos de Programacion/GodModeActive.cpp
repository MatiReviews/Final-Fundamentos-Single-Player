#include "RowsCols.h"
#include "ScoreTable.h"

void GodModeActive(bool& godMode, bool& collision, int& godModeClock, int& modMode, int scoreTable[cantScores], int& playerScore, int indexST)
{
    if (godMode && collision|| godMode && collision == false)
    {
        if (godModeClock > 0)
        {
            godModeClock--;

            if (godModeClock == 0)
            {
                godMode = false;
                collision = false;
                modMode = 0;
                godModeClock = 40;
            }
        }
    }
    else if (godMode == false && collision)
    {
        ScoreTable(scoreTable, playerScore, indexST);
        collision = false;
        playerScore = 0;
    }

}