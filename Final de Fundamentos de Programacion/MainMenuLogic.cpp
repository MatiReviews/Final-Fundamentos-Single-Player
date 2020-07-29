#include <iostream>

void MainMenuLogic(int& menuSelection)
{
	int mode = 0;

	do
	{
		std::cin >> mode;
	} while (mode < 1 || mode > 3);

	switch (mode)
	{
	case 1:
		menuSelection = 1;
		break;

	case 2:
		menuSelection = 2;
		break;

	case 3:
		menuSelection = 3;
		break;
	}
}