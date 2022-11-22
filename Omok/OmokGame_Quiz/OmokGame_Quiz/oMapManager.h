#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

class oMapManager
{
public:
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void mapDraw(int Width, int Height);
	void mapRefresh(int width, int height, int x, int y);

};

