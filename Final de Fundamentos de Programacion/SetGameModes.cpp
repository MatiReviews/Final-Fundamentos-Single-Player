#include <iostream>

void SetGameModes(int mode, int& gameMode)
{
    do
    {
        std::cin >> mode;
    } while (mode < 1 || mode > 3);

    switch (mode)
    {
    case 1:
        gameMode = 1;
        break;

    case 2:
        gameMode = 2;
        break;

    case 3:
        gameMode = 3;
        break;
    }
}