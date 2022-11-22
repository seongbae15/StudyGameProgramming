#pragma once
#include <iostream>
#include <Windows.h>
#include "oDrawManager.h"

using namespace std;

class oMenu
{
private:
	oDrawManager m_menuDrawManager;
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
	void dispMainMenu(bool replayMode);
	void dispBox(int width, int height, int pos_X, int pos_Y);
	void dispInputPlayerName(string str, int playerNumber=1);
	void dispControlMenu();
	void dispOptionMenu();
	void dispCusorCustomMenu();
	void dispStoneCustomMenu();
	void dispUndoSetMenu();
	void dispWarning();
};

