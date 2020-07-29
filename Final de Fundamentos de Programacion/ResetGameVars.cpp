#include "Player.h"
#include "FillMatrix.h"
#include "ClearMatrix.h"
#include "SetInitPos.h"
#include "Position.h"

void ResetGameVars(Player& player, bool& menuOn, bool& playing, int& gameTimer, char& input, Position& scoreBoardRecordPos)
{
    menuOn = true;
    playing = true;
    gameTimer = 30;
    player.SetPoints(0);
    player.SetGodMode(false);
    player.SetFastMode(false);
    player.SetDoubleXpMode(false);
    input = ' ';
    scoreBoardRecordPos.x = 59;
    scoreBoardRecordPos.y = 0;    
}

void ResetGameVars(Position& timerPos, Position& pointsPos, Position& powerUpPos, Position& scoreBoardRecordPos)
{
    timerPos.x = 33;
    timerPos.y = 0;
    
    pointsPos.x = 41;
    pointsPos.y = 0;

    powerUpPos.x = 49;
    powerUpPos.y = 0;
   
    scoreBoardRecordPos.x = 59;
    scoreBoardRecordPos.y = 0;
}

void ResetGameVars(int scoreBoard[])
{
    for (int i = 0; i < cantScores; i++)
    {
        scoreBoard[i] = 0;
    }
}