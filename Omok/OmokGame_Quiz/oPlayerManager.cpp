#include "oPlayerManager.h"

void oPlayerManager::drawStone(int CurrentX, int CurrentY, string Stone)
{
	gotoxy((2 * CurrentX), CurrentY);
	cout << Stone;
}