#include "DrawManager.h"

void DrawManager::DrawBaseMap(int width, int height)
{
	for (int y = 0; y < height; y++)
	{
		gotoxy(0, y);
		if (y == 0 || y == height - 1)
		{
			for (int x = 0; x < width; x++)
				cout << "��";
		}
		else
		{
			cout << "��";
			gotoxy(2*(width-1), y);
			cout << "��";
		}
	}
}

void DrawManager::DispText(string str, int posX, int posY)
{
	int iTempPosX;
	iTempPosX = posX - (str.size() / 2);
	gotoxy(iTempPosX, posY);
	cout << str;
}

void DrawManager::DrawObject(string str, int posX, int posY)
{
	gotoxy(2*posX, posY);
	cout << str;
}

void DrawManager::EraseObject(int posX, int posY)
{
	gotoxy(2*posX, posY);
	cout << "  ";
}



