#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "DrawManager.h"

#define MAX_STONE_COUNT 40

using namespace std;

typedef struct StonePosition
{
	int m_iX;
	int m_iY;
}StonePosition;

class Stone
{
private:
	StonePosition m_stStoneList;
	vector<StonePosition> m_vectorStonePos;
	string m_strStone;
	DrawManager m_stoneDrawManager;
public:
	Stone();
	void InitStonePosition(int Width, int Height);
	void DrawStone();
	inline int getStonePosX(int index)
	{
		return m_vectorStonePos[index].m_iX;
	}
	inline int getStonePosY(int index)
	{
		return m_vectorStonePos[index].m_iY;
	}
	inline int getStoneCount()
	{
		return MAX_STONE_COUNT;
	}

};

