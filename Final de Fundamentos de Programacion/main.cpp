#include <iostream>
#include <conio.h>
#include <ctime>
#include <Windows.h>

#include "Player.h"
#include "RowsCols.h"
#include "Input.h"
#include "PowerUps.h"
#include "SetColor.h"
#include "Color.h"
#include "Position.h"
#include "ShowToScreen.h"
#include "ClearMatrix.h"
#include "Collision.h"
#include "FillMatrix.h"
#include "Console.h"
#include "ActiveModes.h"
#include "MatrixObj.h"
#include "GameMenu.h"

void ShowTimer(int gameTimer, int gameTimerCont, int gameTimerMax);

int main()
{

    const unsigned int ConsoleWidth = 1280;
    const unsigned int ConsoleHeight = 768;

    SetConsoleTitle(TEXT("Adventure Game"));

    SetGameConsoleSize(ConsoleWidth, ConsoleHeight);

    srand(time(NULL));

    char Wall = (char)MatrixObj::Wall;  //Pared de mi array

    Player player;

    player.SetDoubleXpMode(false);

   
    Position pointsPos;
    pointsPos.x = 33;
    pointsPos.y = 0;

    Position modePos;
    modePos.x = 42;
    modePos.y = 0;

    Position ScoreTableRecordPos;
    ScoreTableRecordPos.x = 49;
    ScoreTableRecordPos.y = 0;
    
    Position ScoreTablePointsPos;
    ScoreTablePointsPos.x = 50;
    ScoreTablePointsPos.y = 1;

    Position controlPos;
    controlPos.x = 33;
    controlPos.y = 10;

    Position modeInfoPos;
    modeInfoPos.x = 45;
    modeInfoPos.y = 10;
    

    Color playerColor;
    playerColor.color1 = (int)SetColor::Brown;

    Color matrixColor;
    matrixColor.color1 = (int)SetColor::White;

    Color powerUpColor;
    powerUpColor.color1 = (int)SetColor::IntenseBlue;  //Double Speed
    powerUpColor.color2 = (int)SetColor::IntenseRed;   //Double Points
    powerUpColor.color3 = (int)SetColor::IntenseGreen; //God Mode
    powerUpColor.color4 = (int)SetColor::White;        //Texto

    Color pointsColor;
    pointsColor.color1 = (int)SetColor::Red;
    pointsColor.color2 = (int)SetColor::White;

    Color scoreTableColor;
    scoreTableColor.color1 = (int)SetColor::Yellow;
    scoreTableColor.color2 = (int)SetColor::White;

    Color ActiveModeColor;
    ActiveModeColor.color1 = (int)SetColor::Red;
    ActiveModeColor.color2 = (int)SetColor::White;
    ActiveModeColor.color3 = (int)SetColor::IntenseBlue;

    Color controlColor;
    controlColor.color1 = (int)SetColor::White;

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

    int cont = 0;
    int cont2 = 0;
    int max = 9;   //ciclos a esperar para refrescar el mapa
    int max2 = 27; //ciclos a esperar para refrescar el mapa
    int maxPU = 2; //Cantidad de PowerUp por el mapa
    int playerScore = 0;
    int RFMax = 15; //Cantidad de Asteriscos por el mapa

    int indexST = -1;
    int scoreBoard[cantScores] = { 0 };

    bool godMode = false;
    bool fastMode = false;
    bool doubleMode = false;
    bool collision = false;

    int godModeClock = 40;
    int fastModeClock = 40;
    int doubleModeClock = 40;
    int modMode = 0;

    int gameTimer = 300;
    int gameTimerCont = 0;
    int gameTimerMax = 6;    
    bool playing = true;

    int mode = 0;
    int gameMode = 0;

    bool menuOn = false;

    ShowGameModes();
    SetGameModes(mode, gameMode);

    FillMatrix(matrix, RFMax);
    PowerUpFill(matrix, maxPU);
    
    while (playing)
    {

        if (menuOn)
        {
            ShowGameModes();
            SetGameModes(mode, gameMode);
            menuOn = false;            
        }

        if (playing)
        {
            //Input
            if (_kbhit())
            {
                MovePlayer(player, matrix);
            }

            if (fastMode)
            {
                gameTimerMax = 9;
            }
            else
            {
                gameTimerMax = 6;
            }

            //Actualizacion


            //Set Mode
            switch (gameMode)
            {
            case 1:
                if (gameTimerCont != gameTimerMax || gameTimerCont == gameTimerMax)
                {
                    gameTimerCont++;

                    if (gameTimerCont >= gameTimerMax)
                    {
                        gameTimer--;
                        gameTimerCont = 0;

                        if (gameTimer == 0)
                        {
                            playing = false;
                        }
                    }
                }
                break;

            case 2:

                if (PlayerCollision(player, matrix))
                {
                    playing = false;
                }
                break;

            case 3:
                playing = true;
                break;
            }

            if (cont == max)
            {
                ClearMatrix(matrix);
                FillMatrix(matrix, RFMax);
                cont = 0;
            }
            cont++;

            if (cont2 == max2)
            {
                ClearPowerUp(matrix);
                PowerUpFill(matrix, maxPU);
                cont2 = 0;
            }
            cont2++;

            if (CollisionGodMode(player, matrix))
            {
                player.SetGodMode(true);
            }

            if (gameMode != 2)
            {
                CollisionAsterisk(player, matrix, scoreBoard, indexST);
            }

            if (CollisionSpeedMode(player, matrix))
            {
                player.SetFastMode(true);
            }

            if (CollisionDoubleXpMode(player, matrix))
            {
                SetActiveDoubleXp(player);
            }

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
            ShowPoints(player, pointsColor, pointsPos);
            ShowControls(controlColor, controlPos);
            ShowActiveMode(player, modePos, ActiveModeColor);

            if (gameMode != 2)
            {
                ShowScoreTable(scoreBoard, scoreTableColor, ScoreTableRecordPos, ScoreTablePointsPos);
            }

            ShowModesInfo(modeInfoPos, powerUpColor);

            //Timer On / Off
            switch (gameMode)
            {
            case 1:
                ShowTimer(gameTimer, gameTimerCont, gameTimerMax);
                break;
            }
        }
        else
        {
            std::cout << "Perdiste" << "\n";
            std::cout << "Volver al menu principal" << "\n";
            std::cout << "1 - Si" << "\n";
            std::cout << "2 - No" << "\n";

            do
            {
                std::cin >> mode;
            } while (mode < 1 || mode > 2);

            switch (mode)
            {
            case 1:
                menuOn = true;
                playing = true;
                player.SetCollision(false);
                break;

            case 2:
                menuOn = false;
                break;
            }
        }



        GameSpeedActive(player,gameSpeed);

    } 
}

void ShowTimer(int gameTimer, int gameTimerCont, int gameTimerMax)
{
    gotoxy(5,18);
    std::cout << "Time Left: "<< gameTimer << "\n";
    gotoxy(5, 19);
    std::cout << "game Timer Cont: " << gameTimerCont << "\n";
    gotoxy(5, 20);
    std::cout << "game Timer Max: " << gameTimerMax << "\n";
}


/*
    #include <iostream>
    #include <Windows.h>


    const unsigned int width = 800;
    const unsigned int height = 600;

    SetGameConsoleSize(width, height);

    //Seteo el tamaño de la consola
    void SetGameConsoleSize(int lenght, int height)
    {
        HWND console = GetConsoleWindow();
        RECT ConsoleRect;
        GetWindowRect(console, &ConsoleRect);
        MoveWindow(console, ConsoleRect.left, ConsoleRect.top, lenght, height, TRUE);
    }

    //Lo utilizo para saber la cantidad de filas y columnas que tengo en la consola.
    void DBGetConsoleSize()
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns, rows;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        std::cout << "columns: " << columns << "\n";
        std::cout << "rows: " << rows << "\n";
    }

    enum class Arrows
    {
        Up = 56,
        Down = 50,
        Left = 52,
        Right = 54,
        UpRight = 57,
        UpLeft = 55,
        DownRight = 51,
        DownLeft = 49
    };

    enum class KBKeys
    {
        Enter = 13,
        Esc = 27
    };
*/

//GameMode y Seleccion jugador
/*

void GameMode(int color, int color2)
{
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "Select Game Mode " << "\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << "1 Player Mode ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2);
	std::cout << "   " << " 2 Players Mode " << "\n";
}

int SelectCharacterMenu(Player player[])
{
	char input = ' ';
	int Single = 1;
	int Coop = 2;
	int Mode = 0;
	std::cout << "Select Game Mode " << "\n\n";
	std::cout << "1 Player Mode " << "   " << " 2 Players Mode " << "\n";

	while (input != 'c')
	{
		input = _getch();

		switch (input)
		{
		case 'a':
		case 'A':
			GameMode(4, 7);
			Mode = Single;
			break;

		case 'd':
		case 'D':
			GameMode(7, 4);
			Mode = Coop;
			break;
		}
	}

	switch (Mode)
	{
	case 1:
		return Single;
		break;

	case 2:
		return Coop;
		break;
	}
}

void ShowPlayers(Player player[], int mode)
{
	switch (mode)
	{
	case 1:
		player[0].DrawCharacter(player[0].GetPosX(), player[0].GetPosY());
		break;

	case 2:
		player[0].DrawCharacter(player[0].GetPosX(), player[0].GetPosY());
		player[1].DrawCharacter(player[1].GetPosX(), player[1].GetPosY());
		break;
	}
}

*/

//Inputs
/*
void FirstPlayerInput(Player& player, char input)
{
    switch (input)
    {
    case 'w':
        player.moveUp();
        break;

    case 's':
        player.moveDown();
        break;

    case 'a':
        player.moveLeft();
        break;

    case 'd':
        player.moveRight();
        break;

        //Diagonales
    case 'e':
        player.moveUpRight();
        break;

    case 'q':
        player.moveUpLeft();
        break;

    case 'c':
        player.moveDownRight();
        break;

    case 'z':
        player.moveDownLeft();
        break;
    }
}

void SecondPlayerInput(Player& player, char input)
{
    switch (input)
    {
    case (int)Arrows::Up:
        player.moveUp();
        break;

    case (int)Arrows::Down:
        player.moveDown();
        break;

    case (int)Arrows::Left:
        player.moveLeft();
        break;

    case (int)Arrows::Right:
        player.moveRight();
        break;

        //Diagonales
    case (int)Arrows::UpRight:
        player.moveUpRight();
        break;

    case (int)Arrows::UpLeft:
        player.moveUpLeft();
        break;

    case (int)Arrows::DownRight:
        player.moveDownRight();
        break;

    case (int)Arrows::DownLeft:
        player.moveDownLeft();
        break;
    }
}

void PlayerInputs(Player player[], char input, int mode)
{
    switch (mode)
    {
    case 1:
        FirstPlayerInput(player[0], input);
        break;

    case 2:
        FirstPlayerInput(player[0], input);
        SecondPlayerInput(player[1], input);
        break;
    }
}

*/

//Colores
/*
enum class Color
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    White = 7,
    Gray = 8,
    IntenseBlue = 9,
    IntenseGreen = 10,
    IntenseCyan = 11,
    IntenseRed = 12,
    IntenseMagenta = 13,
    Yellow = 14,
    IntenseWhite = 15
};

struct SetColor
{
    int selected;
    int unSelected;
};
*/

/*
enum class Screens
{
    TitleScreen,
    MainMenu,
    Gameplay,
    Play,
    Controls,
    Credits,
    QuitGame
};

*/