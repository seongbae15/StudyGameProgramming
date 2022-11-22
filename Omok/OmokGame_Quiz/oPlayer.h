#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <fstream>
#include "oDrawManager.h"

#define WINCHECK 5

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

	//Move Min, Max
	int m_iMoveXmin, m_iMoveXmax;
	int m_iMoveYmin, m_iMoveYmax;

	//Position
	int m_iCurrent_StoneX, m_iCurrent_StoneY;
	int m_iLast_StoneX, m_iLast_StoneY;
	Position m_sPosition;
	vector<Position> m_conPosition;

	//Stone & Cusor Shape
	string m_strStone;
	string m_strCusor;
	//Count Set
	int m_iStoneCount;
	int m_iUndoCount;
	//Action
	ACTION m_eACTION;

	//Save, Load
	ofstream m_fPlayerSave;
	ifstream m_fPlayerLoad;

	//Draw Manager
	oDrawManager m_playerDrawManager;
	
public:

	void setPlayerInit(string str, int width, int height,int UndoCount);
	void setMovingArrange(int width, int height);
	void setPlayerCusor(string CusorShape);
	void setPlayerStone(string StoneShape);
	void playerDrawCusor();
	void playerDrawStone();
	void playerDrawStone(int index);
	int inputPlaying();
	void updatePosition();
	void undoPoistion();
	void delPlayerInfo();
	void reDispTotalStone();
	bool checkPlayerWin();
	int checkFiveStone(int iWinCount, int x, int y);

	void savePlayerInfo(string fileName);
	void loadPlayerInfo(string fileName);

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