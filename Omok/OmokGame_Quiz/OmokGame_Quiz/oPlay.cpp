#include "oPlay.h"

oPlay::oPlay()
{
	m_iWidth = WIDTH;
	m_iHeight = HEIGHT;
	m_strArrStone[WHITE] = "●";
	m_strArrStone[BLACK] = "○";
}

oPlay::~oPlay()
{
}


void oPlay::DispPlayerInfo()
{
	string strName = m_Player[m_iTurn % 2].getPlayerName();
	int iUndoCount = m_Player[m_iTurn % 2].getUndoCount();
	m_playTextManager.dispText(m_iWidth - 18, m_iHeight + 3, "Player Name : ");
	cout << strName;
	m_playTextManager.dispText(m_iWidth + 6, m_iHeight + 3, "무르기 : ");
	cout << iUndoCount;
	m_playTextManager.dispText(m_iWidth - 5, m_iHeight + 4, "Turn : ");
	cout << m_iTurn;
}

int oPlay::checkStonePoisition(int pos_X, int pos_Y)
{
	if (m_iArrStoneCount[WHITE] == 0 && m_iArrStoneCount[BLACK] == 0)
		return -1;
	else
	{
		//돌 위치 체크(백)
		for (int i = 0; i < m_iArrStoneCount[WHITE]; i++)
		{
			if (pos_X == m_Player[WHITE].getPositionX(i) && pos_Y == m_Player[WHITE].getPositionY(i))
				return 0;
		}

		//돌 위치 체크(흑)
		for (int i = 0; i < m_iArrStoneCount[BLACK]; i++)
		{
			if (pos_X == m_Player[BLACK].getPositionX(i) && pos_Y == m_Player[BLACK].getPositionY(i))
				return 1;
		}
		return -1;
	}
}
void oPlay::inputPlayerName()
{
	m_menuManager.dispSetNameWindow();

	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.3, "P1 이름");
	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.3 + 1, "입력 : ");
	m_Player[BLACK].setPlayer(m_iWidth, m_iHeight, m_strArrStone[BLACK]);

	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.5, "P2 이름");
	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.5 + 1, "입력 : ");
	m_Player[WHITE].setPlayer(m_iWidth, m_iHeight, m_strArrStone[WHITE]);
}

void oPlay::startPlaying()
{
	system("cls");
	//player 정보 입력
	inputPlayerName();

	//Game Start
	system("cls");
	m_mapManager.mapDraw(m_iWidth, m_iHeight);
	m_menuManager.dispControlMenu();
	//player 정보표시
	DispPlayerInfo();

	//임시 변수
	int iPlayerState;
	int iLastStoneX, iLastStoneY;
	int iCurrentStoneX, iCurrentStoneY;
	int iStoneCount[2] = { 0 };
	
	while (1)
	{
		//움직이는 돌 표시
		m_Player[m_iTurn % 2].playerDrawStone();
		//키보드 입력 실행
		iPlayerState = m_Player[m_iTurn % 2].inputPlaying();
		
		//현재플레이어 돌카운트 받기
		iStoneCount[m_iTurn % 2] = m_Player[m_iTurn % 2].getStoneCount();
		m_iArrStoneCount[BLACK] = m_Player[BLACK].getStoneCount();
		m_iArrStoneCount[WHITE] = m_Player[WHITE].getStoneCount();
		//돌 위치 체크 변수
		int iStoneCheck = -1;
		
		//플레이어 상태에 따라 행동 매니지먼트 프로그램 동작행동 판정
		switch (iPlayerState)
		{
		case PLAYERSTATE_MOVE:
			//현재 플레이어의 좌표(마지막, 현재) 확인
			iLastStoneX = m_Player[m_iTurn % 2].getLastPosX();
			iLastStoneY = m_Player[m_iTurn % 2].getLastPosY();
			//움직임에 의한 위치 체크.
			iStoneCheck = checkStonePoisition(iLastStoneX, iLastStoneY);
			if (iStoneCheck == -1)
				m_mapManager.mapRefresh(m_iWidth, m_iHeight, iLastStoneX, iLastStoneY);
			else if (iStoneCheck == 1)
			{
				m_playerManager.drawStone(iLastStoneX,iLastStoneY,m_strArrStone[BLACK]);
			}
			else if (iStoneCheck == 0)
			{
				m_playerManager.drawStone(iLastStoneX, iLastStoneY, m_strArrStone[WHITE]);
			}
			break;
		case PLAYERSTATE_DO:
			//돌 놓기에 의한 위치 체크
			iCurrentStoneX = m_Player[m_iTurn % 2].getCurrentPosX();
			iCurrentStoneY = m_Player[m_iTurn % 2].getCurrentPosY();
			iStoneCheck = checkStonePoisition(iCurrentStoneX, iCurrentStoneY);
			if (iStoneCheck == -1)
			{
				m_Player[m_iTurn % 2].updatePosition();
				m_iTurn++;
			}

			break;
		case PLAYERSTATE_UNDO:
			//돌 지우기

			//턴 감소
			m_iTurn--;
			break;
		case PLAYERSTATE_OPTION:
			break;
		case PLAYERSTATE_EXIT:
			break;
		default:
			break;
		}
		DispPlayerInfo();
	}

	//(그냥 게임 종료, 승리 조건, 일반 진행으로 턴 수 증가 포함

	return;

}

void oPlay::startOmok()
{
	int iSelect;
	m_menuManager.setMenu(m_iWidth, m_iHeight);
	while (1)
	{
		system("cls");
		m_mapManager.mapDraw(m_iWidth, m_iHeight);
		m_menuManager.dispMainMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			m_iTurn = 1;
			m_bGameState = true;
			startPlaying();
			break;
		case 2:
			break;
		case 3:
			return;
		default:
			break;
		}

	}

}