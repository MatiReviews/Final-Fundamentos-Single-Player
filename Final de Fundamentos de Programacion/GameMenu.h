#pragma once
#include "Color.h"

void GameMenu(bool& menuOn, bool& titleScreen, bool& playing, int& gameMode, int& menuSelection, Color titleScreenColor, Color Menu);

//Show
void ShowTitleScreen(Color color);
void ShowMainMenu();
void ShowGameModes(Color Menu);
void ShowHowToPlay();

//Set - Logica
void SetGameModes(int mode, int& gameMode);
void TitleScreenOpt(char mode, int& gameMode, bool& titleScreen);
void MainMenuLogic(int& menuSelection);
void HowToPlayLogic(bool& goBack);
