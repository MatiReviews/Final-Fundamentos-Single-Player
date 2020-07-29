#include <conio.h>
#include "KBKeys.h"

void GoToMainMenuInput(int& option)
{
    do
    {
        option = _getch();
    } while (option < (int)KBNumbers::Uno || option >(int)KBNumbers::Dos);
}