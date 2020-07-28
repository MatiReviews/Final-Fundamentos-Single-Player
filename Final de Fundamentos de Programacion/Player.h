#pragma once
#include "Color.h"
#include "playerMode.h"

struct Player
{
private:
    playerMode myMode;

    int x = 3;
    int y = 3;

    int points = 0;
    
    char character = 'P';
    bool alive = false;
    bool collision = false;

public:
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    //Get
    int GetX();
    int GetY();
    char GetPlayerChar();
    int GetPoints();

    bool GetGodMode();
    bool GetFastMode();
    bool GetDoubleXpMode();

    int GetGodModeClock();
    int GetFastModeClock();
    int GetDoubleModeClock();

    //Set
    void SetPlayerChar(char character);
    void SetPoints(int setpo);
    void SetCollision(bool collision);    

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

    //Draw
    void DrawPlayer(Player player, Color color);

};