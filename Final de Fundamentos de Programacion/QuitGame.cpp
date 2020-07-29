#include "KBKeys.h"

void QuitGameCheck(char input, bool& playing)
{
    if (input == (char)KBKeys::Esc)
    {
        playing = false;
    }
}