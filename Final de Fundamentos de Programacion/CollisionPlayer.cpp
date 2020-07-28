#include "Player.h"
#include "RowsCols.h"
#include "MatrixObj.h"


bool PlayerCollision(Player player, char matrix[][cols])
{
	if (matrix[player.GetY()][player.GetX()] == (char)MatrixObj::Asterisk)
	{
		return true;
	}
	else
	{
		return false;
	}
}