#pragma once
#include "Player.h"
#include "RowsCols.h"

bool CollisionAsterisk(Player player, char matrix[][cols]);
bool CollisionSpeedMode(Player player, char matrix[][cols]);
bool CollisionDoubleXpMode(Player player, char matrix[][cols]);
bool CollisionGodMode(Player player, char matrix[][cols]);