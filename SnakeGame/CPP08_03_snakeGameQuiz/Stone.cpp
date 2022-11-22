#include "Stone.h"

Stone::Stone()
{
	m_strStone = "¢Ã";
}

void Stone::InitStonePosition(int Width, int Height)
{
	bool bRandPositionCheck;
	int iStartX = Width / 2, iStartY = Height / 2;
	if (!m_vectorStonePos.empty())
		m_vectorStonePos.clear();
	srand((unsigned)time(NULL));
	while (1)
	{
		for (int i = 0; i < MAX_STONE_COUNT;)
		{
			bRandPositionCheck = true;
			int randPositionX = rand() % (Width-2) + 1;		//1~48
			int randPositionY = rand() % (Height-2) + 1;	//1~28
			if (randPositionX == iStartX && randPositionY == iStartY)
				bRandPositionCheck = false;
			else if (m_vectorStonePos.empty());
			else
			{
				for (int j = 0; j < i; j++)
				{
					if (randPositionX == m_vectorStonePos[j].m_iX && randPositionY == m_vectorStonePos[j].m_iY)
					{
						bRandPositionCheck = false;
						break;
					}
				}
			}
			if (bRandPositionCheck == true)
			{
				m_stStoneList.m_iX = randPositionX;
				m_stStoneList.m_iY = randPositionY;
				m_vectorStonePos.push_back(m_stStoneList);
				i++;
			}
		}
		break;
	}
}

void Stone::DrawStone()
{
	for (int i = 0; i < MAX_STONE_COUNT; i++)
	{
		m_stoneDrawManager.DrawObject(m_strStone, m_vectorStonePos[i].m_iX, m_vectorStonePos[i].m_iY);
	}
}
