#include "KBKeys.h"
#include <conio.h>

char mode = ' ';

void TitleScreenInput(bool& titleScreenOn)
{
    do
    {
        mode = _getch();
    } while (mode != (char)KBKeys::Enter);

    switch (mode)
    {
    case (char)KBKeys::Enter:
        titleScreenOn = false;
        break;
    }
}