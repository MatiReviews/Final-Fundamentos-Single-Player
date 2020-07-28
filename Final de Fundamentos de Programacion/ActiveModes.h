#pragma once
#include "SleepSpeed.h"
#include "RowsCols.h"

void PointsCounterActive(int& points, bool doublePoints);
void GameSpeedActive(bool& fastMode, int& fastModeClock, int& modMode, SleepSpeed speed);
void DoubleXpActive(bool& doubleMode, int& doubleModeClock, int& modMode);
void GodModeActive(bool& godMode, bool& collision, int& godModeClock, int& modMode, int scoreTable[cantScores], int& playerScore, int indexST);