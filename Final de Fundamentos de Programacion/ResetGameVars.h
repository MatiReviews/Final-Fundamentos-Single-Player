#pragma once
#include "Player.h"
#include "FillMatrix.h"
#include "ClearMatrix.h"
#include "SetInitPos.h"
#include "Position.h"

void ResetGameVars(Player& player, bool& menuOn, bool& playing, int& gameTimer, char& input, Position& scoreBoardRecordPos);
void ResetGameVars(Position& timerPos, Position& pointsPos, Position& powerUpPos, Position& scoreBoardRecordPos);
void ResetGameVars(int scoreBoard[]);