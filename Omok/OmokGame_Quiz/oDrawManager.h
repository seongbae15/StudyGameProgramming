#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class oDrawManager
{
public:
	void drawMap(int width, int height);
	void mapRefresh(int width, int height, int x, int y);
	void dispText(int pos_X, int pos_Y, string str);
	void drawBox(int width, int height, int pos_X = 0, int pos_Y = 0);
	void drawStone(int CurrentX, int CurrentY, string Stone);

	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

