#include "RowsCols.h"
#include "Player.h"

void ScoreTable(int scoreTable[cantScores], Player player, int indexST)
{
    for (short i = cantScores - 1; i >= 0; i--)
    {
        if (player.GetPoints() > scoreTable[i])
        {
            indexST = i; //setea el indice segun la posicion en la que esté el num ingresado.
        }
    }

    if (indexST != -1)
    {
        for (short i = cantScores - 1; i > indexST; i--) //Hace el for hasta llegar al index del num ingresado
        {
            scoreTable[i] = scoreTable[i - 1]; //el indice anterior pasa a ser el indice que le sigue.
        }

        scoreTable[indexST] = player.GetPoints();
    }
}