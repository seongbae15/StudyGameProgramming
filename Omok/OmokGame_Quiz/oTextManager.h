#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class oTextManager
{
private:
public:
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void dispText(int pos_X, int pos_Y, string str);
};

