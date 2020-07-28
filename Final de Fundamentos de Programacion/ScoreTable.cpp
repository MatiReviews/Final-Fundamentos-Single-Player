#include "RowsCols.h"

void ScoreTable(int scoreTable[cantScores], int& playerScore, int indexST)
{
    for (short i = cantScores - 1; i >= 0; i--)
    {
        if (playerScore > scoreTable[i])
        {
            indexST = i; //setea el indice segun la posicion en la que est� el num ingresado.
        }
    }

    if (indexST != -1)
    {
        for (short i = cantScores - 1; i > indexST; i--) //Hace el for hasta llegar al index del num ingresado
        {
            scoreTable[i] = scoreTable[i - 1]; //el indice anterior pasa a ser el indice que le sigue.
        }

        scoreTable[indexST] = playerScore;
    }
}