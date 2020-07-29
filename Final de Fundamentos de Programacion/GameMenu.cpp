#include "GameMenu.h"
#include "MenuShow.h"
#include "MenuInput.h"
#include "MenuOptions.h"

bool titleScreenOn = true;
bool goBack = false;

void GameMenu(bool& menuOn, bool& playing, int& gameMode, int& menuSelection, Color titleScreenColor, Color menuColor, Color powerUpColor)
{
    do
    {
        if (menuOn)
        {
            if (titleScreenOn)
            {
                ShowTitleScreen(titleScreenColor);                
                TitleScreenInput(titleScreenOn);                
                titleScreenOn = false;
            }

            ShowMainMenu();
            MainMenuInput(menuSelection);

            switch (menuSelection)
            {
            case (int)MenuOptions::Jugar:
                ShowGameModes(menuColor);
                SetGameModes(gameMode);
                menuOn = false;
                goBack = false;
                break;

            case (int)MenuOptions::ComoJugar:
                ShowHowToPlay(powerUpColor);
                HowToPlayInput(goBack);                
                break;

            case (int)MenuOptions::Salir:
                playing = false;
                goBack = false;
                break;
            }
        }

    } while (goBack);    
}