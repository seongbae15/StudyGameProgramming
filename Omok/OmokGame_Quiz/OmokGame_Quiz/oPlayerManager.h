#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class oPlayerManager
{
public:
	void drawStone(int CurrentX, int CurrentY,string Stone);
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	}
};