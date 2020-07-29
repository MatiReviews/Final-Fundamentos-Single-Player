#pragma once
#include "Player.h"
#include "RowsCols.h"

bool PlayerCollision(Player player, char matrix[][cols]);

void CollisionAsterisk(Player& player, char matrix[][cols], int scoreTable[cantScores], int indexST);

bool CollisionSpeedMode(Player player, char matrix[][cols]);

bool CollisionDoubleXpMode(Player player, char matrix[][cols]);
void SetActiveDoubleXp(Player& player);

bool CollisionGodMode(Player player, char matrix[][cols]);

void CheckAllCollisions(Player& player, char matrix[][cols], int scoreBoard[], int indexST, int gameMode);

