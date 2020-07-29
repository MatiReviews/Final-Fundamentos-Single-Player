#include <conio.h>
#include "KBKeys.h"

void MainMenuInput(int& menuSelection)
{
	int mode = 0;

	do
	{
		mode = _getch();
	} while (mode < (int)KBNumbers::Uno || mode >(int)KBNumbers::Tres);

	switch (mode)
	{
	case (int)KBNumbers::Uno:
		menuSelection = 1;
		break;

	case (int)KBNumbers::Dos:
		menuSelection = 2;
		break;

	case (int)KBNumbers::Tres:
		menuSelection = 3;
		break;
	}
}