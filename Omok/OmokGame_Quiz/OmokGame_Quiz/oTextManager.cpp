#include "oTextManager.h"

void oTextManager::dispText(int pos_X, int pos_Y, string str)
{
	gotoxy(pos_X, pos_Y);
	cout << str;

}


