#include "GameMenu.h"
#include "Color.h"

void GameMenu(bool& menuOn, bool& titleScreen, bool& playing, int& gameMode, int& menuSelection, Color titleScreenColor, Color Menu)
{      
    int mode = 0;
    bool goBack = false;

    do
    {

        if (menuOn)
        {
            if (titleScreen)
            {
                ShowTitleScreen(titleScreenColor);
                TitleScreenOpt(mode, gameMode, titleScreen);
                titleScreen = false;
            }

            ShowMainMenu();
            MainMenuLogic(menuSelection);

            switch (menuSelection)
            {
            case 1:
                ShowGameModes(Menu);
                SetGameModes(mode, gameMode);
                menuOn = false;
                goBack = false;
                break;

            case 2:
                ShowHowToPlay();
                HowToPlayLogic(goBack);                
                break;

            case 3:
                playing = false;
                goBack = false;
                break;
            }
        }

    } while (goBack);

    
}