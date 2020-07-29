#pragma once
#include "Color.h"
#include "RowsCols.h"
#include "Position.h"
#include "Cursor.h"

void ShowMatrix(char matrix[][cols], Color color, Color powerUpColor);
//Muestra los puntos actuales del jugador

void ShowPoints(Player player, Color color, Position showPointsPos);
//Muestra la tabla de puntuaciones del jugador

void ShowScoreBoard(int gameMode, int ScoreTable[cantScores], Color color, Position recordPos);
//Muestra el/los PowerUp/s activos del jugador

void ShowActivePowerUp(Player player, Position modePos, Color color);

void ShowControls(Color color, Position pos);
//Muestra que hace cada Power Up

void ShowPowerUpInfo(Position modeInfoPos, Color powerUpColor);
//Muestra el tiempo restante

void ShowGameTimer(Color timerColor, int gameMode, int gameTimer, Position timer);
