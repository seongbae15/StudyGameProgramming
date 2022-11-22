#include "oDrawManager.h"

void oDrawManager::drawMap(int Width, int Height)
{
	//for (int y = 0; y < Width; y++)
	//{
	//	if (y == 0)
	//	{
	//		cout << "жг";
	//		for (int x = 1; x < Width - 1; x++)
	//			cout << "жи";
	//		cout << "жд";
	//	}
	//	else if (y == Height - 1)
	//	{
	//		cout << "жж";
	//		for (int x = 1; x < Width - 1; x++)
	//			cout << "жк";
	//		cout << "же";
	//	}
	//	else
	//	{
	//		cout << "жз";
	//		for (int x = 1; x < Width - 1; x++)
	//			cout << "жл";
	//		cout << "жй";
	//	}
	//	cout << endl;
	//}
	for (int y = 0; y < Width; y++)
	{
		if (y == 0)
		{
			cout << "гл";
			for (int x = 1; x < Width - 1; x++)
				cout << "гл";
			cout << "гл";
		}
		else if (y == Height - 1)
		{
			cout << "гл";
			for (int x = 1; x < Width - 1; x++)
				cout << "гл";
			cout << "гл";
		}
		else
		{
			cout << "гл";
			for (int x = 1; x < Width - 1; x++)
				cout << "гл";
			cout << "гл";
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
			cout << "гл";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "гл";
		}
		else if (y == height - 1)
		{
			cout << "гл";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "гл";
		}
		else
		{
			cout << "  ";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "  ";
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
	//if (pos_Y == 0 && pos_X == 0)
	//	cout << "жг";
	//else if (pos_Y == 0 && pos_X == width - 1)
	//	cout << "жд";
	//else if (pos_Y == 0 && pos_X >= 1 && pos_X < width - 1)
	//	cout << "жи";
	//else if (pos_Y == height - 1 && pos_X == 0)
	//	cout << "жж";
	//else if (pos_Y == height - 1 && pos_X == width - 1)
	//	cout << "же";
	//else if (pos_Y == height - 1 && pos_X >= 1 && pos_X < width - 1)
	//	cout << "жк";
	//else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == 0)
	//	cout << "жз";
	//else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == width - 1)
	//	cout << "жй";
	//else
	//	cout << "жл";
	if (pos_Y == 0 && pos_X == 0)
		cout << "гл";
	else if (pos_Y == 0 && pos_X == width - 1)
		cout << "гл";
	else if (pos_Y == 0 && pos_X >= 1 && pos_X < width - 1)
		cout << "гл";
	else if (pos_Y == height - 1 && pos_X == 0)
		cout << "гл";
	else if (pos_Y == height - 1 && pos_X == width - 1)
		cout << "гл";
	else if (pos_Y == height - 1 && pos_X >= 1 && pos_X < width - 1)
		cout << "гл";
	else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == 0)
		cout << "гл";
	else if (pos_Y > 0 && pos_Y < height - 1 && pos_X == width - 1)
		cout << "гл";
	else
		cout << "гл";
}