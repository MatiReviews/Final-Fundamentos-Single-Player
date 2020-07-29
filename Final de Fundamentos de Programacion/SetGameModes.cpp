#include <conio.h>
#include "KBKeys.h"
#include "GameModes.h"
#include "CurrentGameMode.h"

void SetGameModes(int& gameMode)
{
    int mode = 0;

    do
    {
        mode = _getch();
    } while (mode < (int)KBNumbers::Uno || mode > (int)KBNumbers::Tres);

    switch (mode)
    {
    case (int)CurrentGameMode::ThirtySel:
        gameMode = (int)CurrentGameMode::ThirtySeconds;
        break;

    case (int)CurrentGameMode::SingleSel:
        gameMode = (int)CurrentGameMode::SingleLife;
        break;

    case (int)CurrentGameMode::UnlimitedSel:
        gameMode = (int)CurrentGameMode::Unlimited;
        break;
    }
}