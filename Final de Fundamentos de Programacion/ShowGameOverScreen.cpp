#include <iostream>
#include "Player.h"
#include "SetScoreTable.h"
#include "ShowToScreen.h"
#include "Color.h"
#include "CurrentGameMode.h"
#include "Position.h"
#include "RowsCols.h"


void ShowGameOverScreen(Player player, int gameMode, int scoreBoard[cantScores],int indexST, Color scoreBoardColor, Position& recordPos)
{
    switch (gameMode)
    {
    case (int)CurrentGameMode::ThirtySeconds:
        std::cout << "Se agoto el tiempo" << "\n";

        SetScoreTable(scoreBoard, player, indexST);

        recordPos.x = 0;
        recordPos.y = 2;

        ShowScoreBoard(gameMode, scoreBoard, scoreBoardColor, recordPos);
        break;

    case (int)CurrentGameMode::SingleLife:
        std::cout << "Perdiste" << "\n";
        std::cout << "Puntuacion Maxima: " << player.GetPoints() << "\n";
        break;

    case (int)CurrentGameMode::Unlimited:
        std::cout << "Puntuacion Maxima: " << player.GetPoints() << "\n";
        break;
    }
}