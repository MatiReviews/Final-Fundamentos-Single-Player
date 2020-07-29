#pragma once
#include "RowsCols.h"

//Timer que le indica al juego cada cuanto hay que actualizar los datos en la pantalla
void MatrixTimer(char matrix[][cols], int maxAsterisks, int& contMatrix, int maxContMatrix);

//Timer que le indica al juego cada cuanto hay que actualizar los datos en  la pantalla
void PowerUpTimer(char matrix[][cols], int& contPowerUps, int maxContPowerUps, int maxPowerUps);

//Timer para el modo de 30 segundos
void GameTimer(int& gameTimerCont, int gameTimerMax, int& gameTimer, bool& playing);