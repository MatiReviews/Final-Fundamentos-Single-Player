#include <conio.h>
#include "KBKeys.h"

void HowToPlayInput(bool& goBack)
{
	char input = ' ';
	do
	{
		input = _getch();
	} while (input != (char)KBKeys::Esc);

	goBack = true;
}