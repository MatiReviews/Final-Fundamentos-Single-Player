#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

#include "Player.h"
#include "RowsCols.h"
#include "Input.h"
#include "ShowToScreen.h"
#include "SetInitPos.h"
#include "SetScoreTable.h"
#include "SetGameSpeed.h"
#include "SetColor.h"
#include "Color.h"
#include "Position.h"
#include "ClearMatrix.h"
#include "FillMatrix.h"
#include "MatrixObj.h"
#include "Collision.h"
#include "Console.h"
#include "ActiveModes.h"
#include "KBKeys.h"
#include "GameTimers.h"
#include "QuitGameCheck.h"
#include "ResetGameVars.h"
#include "CurrentGameMode.h"
#include "GameMenu.h"
#include "MenuShow.h"
#include "MenuInput.h"


int main()
{

    const unsigned int ConsoleWidth = 1280;
    const unsigned int ConsoleHeight = 768;

    SetConsoleTitle(TEXT("Asterisk"));

    SetGameConsoleSize(ConsoleWidth, ConsoleHeight);

    srand(time(NULL));

    char Wall = (char)MatrixObj::Wall;  //Pared de mi array

    Player player;   

    //Pos
    Position timerPos;
    timerPos.x = 33;
    timerPos.y = 0;

    Position pointsPos;
    pointsPos.x = 41;
    pointsPos.y = 0;

    Position powerUpPos;
    powerUpPos.x = 49; 
    powerUpPos.y = 0;

    Position scoreBoardRecordPos;
    scoreBoardRecordPos.x = 59;
    scoreBoardRecordPos.y = 0; 

    Position controlPos;
    controlPos.x = 33;
    controlPos.y = 10;

    Position powerUpInfoPos;
    powerUpInfoPos.x = 49;
    powerUpInfoPos.y = 10;
    
    //Colores
    Color playerColor;
    playerColor.color1 = (int)SetColor::Brown;

    Color matrixColor;
    matrixColor.color1 = (int)SetColor::White;

    Color powerUpColor;
    powerUpColor.color1 = (int)SetColor::IntenseBlue;  //Double Speed
    powerUpColor.color2 = (int)SetColor::IntenseRed;   //Double Points
    powerUpColor.color3 = (int)SetColor::IntenseGreen; //God Mode
    powerUpColor.color4 = (int)SetColor::White;        //Texto

    Color scoreBoardColor;
    scoreBoardColor.color1 = (int)SetColor::Yellow;
    scoreBoardColor.color2 = (int)SetColor::White;

    Color activePowerUpColor;
    activePowerUpColor.color1 = (int)SetColor::Red;
    activePowerUpColor.color2 = (int)SetColor::White;
    activePowerUpColor.color3 = (int)SetColor::IntenseBlue;

    Color titleScreenColor;
    titleScreenColor.color1 = (int)SetColor::IntenseGreen;
    titleScreenColor.color2 = (int)SetColor::IntenseBlue;
    titleScreenColor.color3 = (int)SetColor::IntenseRed;

    Color menuColor;
    menuColor.color1 = (int)SetColor::White;

    Color infoColor;
    infoColor.color1 = (int)SetColor::Red;
    infoColor.color2 = (int)SetColor::White;

    SleepSpeed gameSpeed;
    gameSpeed.fast = 50;
    gameSpeed.normal = 100;

    char matrix[rows][cols] = { {Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',Wall},
                                {Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall,Wall} };
    
    int contMatrix = 0;
    int maxContMatrix = 9; //ciclos a esperar para refrescar el mapa

    int contPowerUps = 0;
    int maxContPowerUps = 27; //ciclos a esperar para refrescar el mapa

    int maxAsterisks = 15; //Cantidad de Asteriscos por el mapa
    int maxPowerUps = 2;  //Cantidad de PowerUp el mapa por actualización

    int indexST = -1;
    int scoreBoard[cantScores] = { 0 }; 

    int gameTimer = 30;
    int gameTimerCont = 0;
    int gameTimerMax = 6;  //ciclos que espera el juego para restarle tiempo a gameTimer.

    int option = 0;

    int menuSelection = 0;
    int gameMode = 0;

    bool playing = true;
    bool menuOn = true;

    char input = ' ';

    FillMatrix(matrix, maxAsterisks);
    PowerUpFill(matrix, maxPowerUps);
    
    SetInitPos(player, matrix);
 
    while (playing)
    {     
   
        GameMenu(menuOn, playing,  gameMode, menuSelection, titleScreenColor, menuColor, powerUpColor);

        //Input
        if (playing)
        {
            if (_kbhit())
            {
                PlayerInput(player, matrix, input);
            }
        }

        //Actualizacion
        if (playing)
        {
            SetSpeedTimer(player, gameTimerMax);

            //Set Mode
            switch (gameMode)
            {
            case (int)CurrentGameMode::ThirtySeconds:  
                QuitGameCheck(input, playing);
                GameTimer(gameTimerCont, gameTimerMax, gameTimer, playing);
                break;

            case (int)CurrentGameMode::SingleLife:
                if (PlayerCollision(player, matrix) && player.GetGodMode() != true || input == (char)KBKeys::Esc)
                {
                    playing = false;
                }
                powerUpPos.x = 41;
                pointsPos.x = 33;
                break;

            case (int)CurrentGameMode::Unlimited:
                QuitGameCheck(input, playing);
                pointsPos.x = 33;
                powerUpPos.x = 41;
                scoreBoardRecordPos.x = 51;
                break;
            }

            MatrixTimer(matrix, maxAsterisks, contMatrix, maxContMatrix);
            PowerUpTimer(matrix, contPowerUps, maxContPowerUps, maxPowerUps);

            CheckAllCollisions(player, matrix, scoreBoard, indexST, gameMode);

            PointsCounterActive(player);
            DoubleXpActive(player);
            GodModeActive(player);
            system("cls");
        }

        //Dibujado
        if (playing)
        {
            ShowMatrix(matrix, matrixColor, powerUpColor);
            player.DrawPlayer(player, playerColor);
            ShowPoints(player, infoColor, pointsPos);
            ShowControls(infoColor, controlPos);
            ShowActivePowerUp(player, powerUpPos, activePowerUpColor);            
            ShowScoreBoard(gameMode, scoreBoard, scoreBoardColor, scoreBoardRecordPos);
            ShowPowerUpInfo(powerUpInfoPos, powerUpColor);
            ShowGameTimer(infoColor,gameMode, gameTimer, timerPos);
        }

        //Mensaje que se muestra al terminar la partida o morir.
        if (playing != true && menuSelection != 3)
        {  
            switch (gameMode)
            {
            case (int)CurrentGameMode::ThirtySeconds:
                std::cout << "Se agoto el tiempo" << "\n";

                SetScoreTable(scoreBoard, player, indexST);

                scoreBoardRecordPos.x = 0;
                scoreBoardRecordPos.y = 2;
               
                ShowScoreBoard(gameMode,scoreBoard, scoreBoardColor, scoreBoardRecordPos);                 
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

        //Para ir al menú principal o salir
        if(playing != true && menuSelection != 3)
        {
            ShowGoToMainMenu();
            GoToMainMenuInput(option);

            switch (option)
            {
             //Reset de variables
            case (int)KBNumbers::Uno:
                ResetGameVars(player, menuOn, playing, gameTimer, input, scoreBoardRecordPos);
                ResetGameVars(timerPos, pointsPos, powerUpPos, scoreBoardRecordPos);
                ResetGameVars(scoreBoard);
                ClearMatrix(matrix);
                FillMatrix(matrix, maxAsterisks);
                SetInitPos(player, matrix);
                break;

            case (int)KBNumbers::Dos:
                std::cout << "\nGracias por Jugar" << "\n";
                break;
            }
        }

        GameSpeedActive(player,gameSpeed);
    } 
}