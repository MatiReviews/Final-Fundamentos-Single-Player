#pragma once
#include "Color.h"
#include "RowsCols.h"
#include "Position.h"
#include "Cursor.h"

void ShowMatrix(char matrix[][cols], Color color, Color powerUpColor);
void ShowPoints(Player player, Color color, Position showPointsPos);
void ShowScoreTable(int ScoreTable[cantScores], Color color, Position recordPos, Position pointsStPos);
void ShowActiveMode(Player player, Position modePos, Color color);
void ShowControls(Color color, Position pos);
void ShowModesInfo(Position modeInfoPos, Color powerUpColor);
