#pragma once
#include <iostream>
#include <Windows.h>

#include "oMapManager.h"
#include "oTextManager.h"
#include "oMenu.h"
#include "oPlayer.h"
#include "oPlayerManager.h"

#define WIDTH 20
#define HEIGHT 20
#define BLACK 1
#define WHITE 0

using namespace std;

enum PLAYERSTATE
{
	PLAYERSTATE_MOVE = 0,
	PLAYERSTATE_DO = 1,
	PLAYERSTATE_UNDO = 2,
	PLAYERSTATE_OPTION = 3,
	PLAYERSTATE_EXIT = 4,
};

class oPlay
{
private:
	int m_iWidth;
	int m_iHeight;
	int m_iTurn;
	string m_strArrStone[2];
	bool m_bGameState;
	int m_iArrStoneCount[2];
	PLAYERSTATE m_ePSTATE;

	oMenu m_menuManager;
	oTextManager m_playTextManager;
	oMapManager m_mapManager;
	oPlayer m_Player[2];
	oPlayerManager m_playerManager;

public:
	oPlay();
	~oPlay();
	//프로그램 시작
	void startOmok();
	//게임 시작
	void startPlaying();
	void inputPlayerName();

	//플레이어 정보 표시
	void DispPlayerInfo();

	//돌 위치 체크
	int checkStonePoisition(int pos_X, int pos_Y);

	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

};

