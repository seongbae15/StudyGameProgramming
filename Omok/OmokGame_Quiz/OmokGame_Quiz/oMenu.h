#pragma once
#include <iostream>
#include <Windows.h>
#include "oTextManager.h"

using namespace std;

class oMenu
{
private:
	oTextManager m_menuTextManager;
	int m_iMapWidth;
	int m_iMapHeight;

public:
	oMenu();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void setMenu(int width, int height);
	void dispMainMenu();
	void dispBox(int width, int height, int pos_X, int pos_Y);
	void dispSetNameWindow();
	void dispControlMenu();
	
};

