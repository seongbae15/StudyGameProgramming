#include "oPlayer.h"

void oPlayer::setPlayer(int width, int height,string StoneShape)
{
	cin >> m_strPlayerName;
	m_iUndoCount = 5;
	m_iCurrent_StoneX = width/2;
	m_iCurrent_StoneY = height/2;
	m_iMoveXmin = 0;
	m_iMoveYmin = 0;
	m_iMoveXmax = width - 1;
	m_iMoveYmax = height - 1;
	m_iStoneCount = 0;
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
void oPlayer::playerDrawStone()
{
	m_PlayerManager.drawStone(m_iCurrent_StoneX, m_iCurrent_StoneY, m_strStone);
}

void oPlayer::updatePosition()
{
	m_sPosition.m_iX = m_iCurrent_StoneX;
	m_sPosition.m_iY = m_iCurrent_StoneY;
	m_conPosition.push_back(m_sPosition);
	m_iStoneCount++;
	m_PlayerManager.drawStone(m_iCurrent_StoneX, m_iCurrent_StoneY,m_strStone);
}