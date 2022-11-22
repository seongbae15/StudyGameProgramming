#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>

#include "oMenu.h"
#include "oPlayer.h"
#include "oDrawManager.h"

#define WIDTH 20
#define HEIGHT 20
#define BLACK 1
#define WHITE 0

#define DEFAULT 0
#define INIT_UNDO 5

using namespace std;

enum LOBYMENU
{
	LOBYMENU_GAME_START = 1,
	LOBYMENU_OPTION,
	LOBYMENU_GAME_END ,
	LOBYMENU_REPLAY,

};

enum PLAYERSTATE
{
	PLAYERSTATE_MOVE = 0,
	PLAYERSTATE_DO = 1,
	PLAYERSTATE_UNDO = 2,
	PLAYERSTATE_OPTION = 3,
	PLAYERSTATE_EXIT = 4,
};

typedef struct CusorShape
{
	string m_strCusorBlack;
	string m_strCusorWhite;
}CusorShape;

typedef struct StoneShape
{
	string m_strStoneBlack;
	string m_strStoneWhite;
}StoneShape;

class oPlay
{
private:
	//map관련 정보
	int m_iWidth;
	int m_iHeight;
	
	//Game Play 정보
	int m_iTurn;
	StoneShape m_sStoneShape[4];
	CusorShape m_sCusorShape[4];
	int m_iInitUndoCount;
	bool m_bGameState;
	bool m_bUndoState;
	bool m_bReplayMode;
	bool m_bContinuePlay;
	//Play 저장관련
	ofstream m_fPlaySave;
	ifstream m_fPlayLoad;
\
	//player 정보
	string m_strArrStone[2];
	string m_strArrCusor[2];
	int m_iArrStoneCount[2];
	PLAYERSTATE m_ePSTATE;
	int m_iArrUndoCount[2];
	string m_strArrName[2];

	oMenu m_playMenu;
	oPlayer m_playPlayer[2];
	oDrawManager m_playDrawManager;
	

public:
	oPlay();
	~oPlay();

	//프로그램 시작
	void startOmok();
	void setConsoleWindow();
	//게임 시작
	void startPlaying();
	void inputPlayerName();

	//플레이어 정보 표시
	void dispPlayerInfo(int tunr);

	//돌 위치 체크
	int checkStonePoisition(int pos_X, int pos_Y);

	//Setting 값 변경
	void setOption();
	void modifyMapSize();
	void modifyCursor();
	void modifyStone();
	void modifyUndoSet();
	void changeUndoCount();
	void changeUndoState();
	void setContinuePlaying();

	//승리체크
	void checkWin();

	//저장, 불러오기
	void savePlayInfo(string fileName);
	void loadPlayInfo(string fileName);
	//Replay
	void replayLastGame();

	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

};