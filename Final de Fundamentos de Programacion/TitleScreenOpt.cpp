#include <iostream>
#include "KBKeys.h"
#include <conio.h>

void TitleScreenOpt(char mode, int& gameMode, bool& titleScreen)
{
    do
    {
        mode = _getch();
    } while (mode != (char)KBKeys::Enter);

    switch (mode)
    {
    case (char)KBKeys::Enter:
        titleScreen = false;
        break;
    }
}