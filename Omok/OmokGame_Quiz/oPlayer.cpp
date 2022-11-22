#include "oPlayer.h"

void oPlayer::setMovingArrange(int width, int height)
{
	m_iMoveXmin = 0;
	m_iMoveYmin = 0;
	m_iMoveXmax = width - 1;
	m_iMoveYmax = height - 1;
}

void oPlayer::setPlayerInit(string str, int width, int height,int UndoCount)
{
	m_strPlayerName = str;
	m_iCurrent_StoneX = width/2;
	m_iCurrent_StoneY = height/2;
	m_iStoneCount = 0;	
	m_iUndoCount = UndoCount;
	setMovingArrange(width, height);
}

void oPlayer::setPlayerCusor(string CusorShape)
{
	m_strCusor = CusorShape;
}
void oPlayer::setPlayerStone(string StoneShape)
{
	m_strStone = StoneShape;
}

int oPlayer::inputPlaying()
{
	char chInput;
	m_iLast_StoneX = m_iCurrent_StoneX;
	m_iLast_StoneY = m_iCurrent_StoneY;
	chInput = getch();
	switch (chInput)
	{
	case ACTION_MOVE_UP:
		if (m_iCurrent_StoneY > m_iMoveYmin)
			m_iCurrent_StoneY--;
		return 0;
	case ACTION_MOVE_DOWN:
		if (m_iCurrent_StoneY < m_iMoveYmax)
			m_iCurrent_StoneY++;
		return 0;
	case ACTION_MOVE_LEFT:
		if (m_iCurrent_StoneX > m_iMoveXmin)
			m_iCurrent_StoneX--;
		return 0;
	case ACTION_MOVE_RIGHT:
		if (m_iCurrent_StoneX < m_iMoveXmax)
			m_iCurrent_StoneX++;
		return 0;
	case ACTION_DO:
		return 1;
	case ACTION_UNDO:
		return 2;
	case ACTION_OPTION:
		return 3;
	case ACTION_EXIT:
		return 4;
	}
}
void oPlayer::playerDrawCusor()
{
	m_playerDrawManager.drawStone(m_iCurrent_StoneX, m_iCurrent_StoneY, m_strCusor);
}

void oPlayer::playerDrawStone()
{
	m_playerDrawManager.drawStone(m_iCurrent_StoneX, m_iCurrent_StoneY, m_strStone);
}
void oPlayer::playerDrawStone(int index)
{
	m_playerDrawManager.drawStone(m_conPosition[index].m_iX, m_conPosition[index].m_iY, m_strStone);
}


void oPlayer::updatePosition()
{
	m_playerDrawManager.drawStone(m_iCurrent_StoneX, m_iCurrent_StoneY, m_strStone);
	m_sPosition.m_iX = m_iCurrent_StoneX;
	m_sPosition.m_iY = m_iCurrent_StoneY;
	m_conPosition.push_back(m_sPosition);
	m_iStoneCount++;

}
void oPlayer::undoPoistion()
{
	//m_iCurrent_StoneX = m_conPosition[m_iStoneCount - 1].m_iX;
	//m_iCurrent_StoneY = m_conPosition[m_iStoneCount - 1].m_iY;
	m_iLast_StoneX = m_conPosition[m_iStoneCount - 1].m_iX;
	m_iLast_StoneY = m_conPosition[m_iStoneCount - 1].m_iY;
	m_playerDrawManager.mapRefresh(m_iMoveXmax + 1, m_iMoveYmax + 1, m_iLast_StoneX, m_iLast_StoneY);
	m_iUndoCount--;
	m_iStoneCount--;
	m_conPosition.pop_back();
}

void oPlayer::delPlayerInfo()
{
	m_conPosition.clear();
}

void oPlayer::reDispTotalStone()
{
	int iTempX, iTempY;
	if (m_conPosition.size() == 0)
		return;
	else
	{
		for (int i = 0; i < m_iStoneCount; i++)
		{
			iTempX = m_conPosition[i].m_iX;
			iTempY = m_conPosition[i].m_iY;
			m_playerDrawManager.drawStone(iTempX,iTempY,m_strStone);
		}

	}
}

int oPlayer::checkFiveStone(int iWinCount, int x, int y)
{
	int iLoopSize = m_conPosition.size() - 1;
	for (int iTempCount =1; iTempCount <= WINCHECK;iTempCount++)
	{
		int iTempWinCount = iWinCount;
		for (int j = 0; j < iLoopSize; j++)
		{
			if ((m_conPosition[j].m_iX == m_conPosition[iLoopSize].m_iX + x)&& m_conPosition[j].m_iY == (m_conPosition[iLoopSize].m_iY + y))
			{
				iWinCount++;
				break;
			}
		}
		if (iTempWinCount == iWinCount)
			break;
		if (x > 0)
			x++;
		else if (x < 0)
			x--;
		if (y > 0)
			y++;
		else if (y < 0)
			y--;
	}
	return iWinCount;
}

bool oPlayer::checkPlayerWin()
{
	if (m_conPosition.size() >= 5)
	{
		for (int i = 1; i <= 4; i++)
		{
			int iWinCount = 1;
			switch (i)
			{
			case 1:
				//가로 검사 ←
				iWinCount = checkFiveStone(iWinCount, -1, 0);
				//가로 검사 ←
				iWinCount = checkFiveStone(iWinCount, 1, 0);
				break;
			case 2:
				//세로 ↑
				iWinCount = checkFiveStone(iWinCount, 0, 1);
				//세로 ↓
				iWinCount = checkFiveStone(iWinCount, 0, -1);
				break;
			case 3:
				//대각 ↙
				iWinCount = checkFiveStone(iWinCount, -1, 1);
				//대각 ↗
				iWinCount = checkFiveStone(iWinCount, 1, -1);
				break;
			case 4:
				//대각2 ↖
				iWinCount = checkFiveStone(iWinCount, -1, -1);
				//대각2 ↘
				iWinCount = checkFiveStone(iWinCount, 1, 1);
				break;
			}
			if (iWinCount == 5)
				return false;
		}
	}
	return true;
}


void oPlayer::savePlayerInfo(string fileName)
{
	m_fPlayerSave.open(fileName);
	if (m_fPlayerSave.is_open())
	{
		m_fPlayerSave << m_strPlayerName << endl;
		m_fPlayerSave << m_iUndoCount << endl;
		m_fPlayerSave << m_iStoneCount << endl;
		m_fPlayerSave << m_iCurrent_StoneX << " " << m_iCurrent_StoneY << endl;
		for (int i = 0; i < m_iStoneCount; i++)
		{
			m_fPlayerSave << m_conPosition[i].m_iX << " " << m_conPosition[i].m_iY << endl;
		}
		m_fPlayerSave.close();
	}
}

void oPlayer::loadPlayerInfo(string fileName)
{
	m_fPlayerLoad.open(fileName);
	if (!m_fPlayerLoad.is_open())
		return;
	else
	{
		m_fPlayerLoad >> m_strPlayerName;
		m_fPlayerLoad >> m_iUndoCount;
		m_fPlayerLoad >> m_iStoneCount;
		m_fPlayerLoad >> m_iCurrent_StoneX;
		m_fPlayerLoad >> m_iCurrent_StoneY;
		for (int i = 0; i < m_iStoneCount; i++)
		{
			m_fPlayerLoad >> m_sPosition.m_iX;
			m_fPlayerLoad >> m_sPosition.m_iY;
			m_conPosition.push_back(m_sPosition);
		}
		m_fPlayerLoad.close();
	}
}
