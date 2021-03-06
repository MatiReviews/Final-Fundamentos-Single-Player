#pragma once
#include "Color.h"
#include "GameModes.h"

struct Player
{
private:
    gameModes playerModes;

    int x = 0;
    int y = 0;

    int points = 0;

    char character = 'P'; 

    bool collision = false;


public:

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    //Get
    int GetX();
    int GetY();
    bool GetCollision();
    char GetPlayerChar();
    int GetPoints();

    bool GetGodMode();
    bool GetFastMode();
    bool GetDoubleXpMode();

    int GetGodModeClock();
    int GetFastModeClock();
    int GetDoubleModeClock();

    //Set
    void SetX(int posX);
    void SetY(int posY);
    void SetPoints(int setpo);
    void SetCollision(bool collision);
    void SetPlayerChar(char character);

    void SetGodMode(bool mode);
    void SetFastMode(bool mode);
    void SetDoubleXpMode(bool mode);

    void SetGodModeClock(int clock);
    void SetFastModeClock(int clock);
    void SetDoubleXpModeClock(int clock);

    //Update
    void UpdateGodModeClock();
    void UpdateFastModeClock();
    void UpdateDoubleModeClock();


    //Otros
    void NormalPoints();
    void DoublePoints();

    //Draw
    void DrawPlayer(Player player, Color color);

};