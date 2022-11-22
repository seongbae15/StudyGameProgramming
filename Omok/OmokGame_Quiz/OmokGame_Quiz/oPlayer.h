#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <stack>
#include "oPlayerManager.h"
#include "oMapManager.h"

using namespace std;

enum ACTION
{
	ACTION_MOVE_UP = 'w',
	ACTION_MOVE_DOWN = 's',
	ACTION_MOVE_LEFT = 'a',
	ACTION_MOVE_RIGHT = 'd',
	ACTION_DO = 13,
	ACTION_UNDO = 110,
	ACTION_OPTION = 112,
	ACTION_EXIT = 27,
};

typedef struct Position
{
	int m_iX;
	int m_iY;

}Position;

class oPlayer
{
private:
	string m_strPlayerName;

	Position m_sPosition;
	vector<Position> m_conPosition;

	//움직임 좌표 범위
	int m_iMoveXmin, m_iMoveXmax;
	int m_iMoveYmin, m_iMoveYmax;
	//현재, 최종 좌표
	int m_iCurrent_StoneX, m_iCurrent_StoneY;
	int m_iLast_StoneX, m_iLast_StoneY;

	//돌 모양
	string m_strStone;

	int m_iStoneCount;
	int m_iUndoCount;

	ACTION m_eACTION;

	oPlayerManager m_PlayerManager;
	oMapManager m_mapManager;
	
public:

	void setPlayer(int width, int height, string StoneShape);
	void playerDrawStone();
	int inputPlaying();
	void updatePosition();

	inline string getPlayerName()
	{
		return m_strPlayerName;
	}
	inline int getUndoCount()
	{
		return m_iUndoCount;
	}

	inline int getPositionX(int index)
	{
		return m_conPosition[index].m_iX;
	}
	inline int getPositionY(int index)
	{
		return m_conPosition[index].m_iY;
	}

	inline int getCurrentPosX()
	{
		return m_iCurrent_StoneX;
	}
	inline int getCurrentPosY()
	{
		return m_iCurrent_StoneY;
	}
	inline int getLastPosX()
	{
		return m_iLast_StoneX;
	}
	inline int getLastPosY()
	{
		return m_iLast_StoneY;
	}
	inline int getStoneCount()
	{
		return m_iStoneCount;
	}

};