#include "oDrawManager.h"

void oDrawManager::drawMap(int Width, int Height)
{
	for (int y = 0; y < Width; y++)
	{
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦¨";
			cout << "¦¤";
		}
		else if (y == Height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦ª";
			cout << "¦¥";
		}
		else
		{
			cout << "¦§";
			for (int x = 1; x < Width - 1; x++)
				cout << "¦«";
			cout << "¦©";
		}
		cout << endl;
	}
}

void oDrawManager::dispText(int pos_X, int pos_Y, string str)
{
	gotoxy(pos_X, pos_Y);
	cout << str;

}

void oDrawManager::drawBox(int width, int height, int pos_X, int pos_Y)
{
	for (int y = 0; y < height; y++)
	{
		gotoxy(pos_X, pos_Y + y);
		if (y == 0)
		{
			cout << "¦£";
			for (int x = 1; x < width - 1; x++)
				cout << "¦¡";
			cout << "¦¤";
		}
		else if (y == height - 1)
		{
			cout << "¦¦";
			for (int x = 1; x < width - 1; x++)
				cout << "¦¡";
			cout << "¦¥";
		}
		else
		{
			cout << "¦¢";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "¦¢";
		}
		cout << endl;
	}
}

void oDrawManager::drawStone(int CurrentX, int CurrentY, string Stone)
{
	gotoxy((2 * CurrentX), CurrentY);
	cout << Stone;
}

void oDrawManager::mapRefresh(int width, int height, int pos_X, int pos_Y)
{
	gotoxy(2 * pos_X, pos_Y);
	if (pos_Y == 0 && pos_X == 0)
		cout << "¦£";
	else if (pos_Y == 0 && pos_X == width - 1)
		cout << "¦¤";
	else if (pos_Y == 0 && pos_X >= 1 && pos_X < width - 1)
		cout << "¦¨";
	else if (pos_Y == height - 1 && pos_X == 0)
		cout << "¦¦";
	else if (pos_Y == height - 1 && pos_X == width - 1)
		cout << "¦¥";
	else if (pos_Y == height - 1 && pos_X >= 1 && pos_X < width - 1)
		cout << "¦ª";
	else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == 0)
		cout << "¦§";
	else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == width - 1)
		cout << "¦©";
	else
		cout << "¦«";
}