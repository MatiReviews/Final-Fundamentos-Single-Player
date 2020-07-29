void GameTimer(int& gameTimerCont, int gameTimerMax, int& gameTimer, bool& playing)
{
    if (gameTimerCont != gameTimerMax || gameTimerCont == gameTimerMax)
    {
        gameTimerCont++;

        if (gameTimerCont >= gameTimerMax)
        {
            gameTimer--;
            gameTimerCont = 0;

            if (gameTimer == 0)
            {
                playing = false;
            }
        }
    }
}