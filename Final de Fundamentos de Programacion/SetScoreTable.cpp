#include "ScoreTable.h"
#include "Player.h"

void SetScoreTable(int scoreTable[cantScores], Player& player, int indexST)
{
	ScoreTable(scoreTable, player, indexST);
	player.SetPoints(0);
}