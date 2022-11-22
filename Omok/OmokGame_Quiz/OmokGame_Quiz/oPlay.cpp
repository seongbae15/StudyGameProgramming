#include "oPlay.h"

oPlay::oPlay()
{
	m_iWidth = WIDTH;
	m_iHeight = HEIGHT;
	m_strArrStone[WHITE] = "��";
	m_strArrStone[BLACK] = "��";
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
	m_playTextManager.dispText(m_iWidth + 6, m_iHeight + 3, "������ : ");
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
		//�� ��ġ üũ(��)
		for (int i = 0; i < m_iArrStoneCount[WHITE]; i++)
		{
			if (pos_X == m_Player[WHITE].getPositionX(i) && pos_Y == m_Player[WHITE].getPositionY(i))
				return 0;
		}

		//�� ��ġ üũ(��)
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

	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.3, "P1 �̸�");
	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.3 + 1, "�Է� : ");
	m_Player[BLACK].setPlayer(m_iWidth, m_iHeight, m_strArrStone[BLACK]);

	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.5, "P2 �̸�");
	m_playTextManager.dispText(m_iWidth - 3, m_iHeight *0.5 + 1, "�Է� : ");
	m_Player[WHITE].setPlayer(m_iWidth, m_iHeight, m_strArrStone[WHITE]);
}

void oPlay::startPlaying()
{
	system("cls");
	//player ���� �Է�
	inputPlayerName();

	//Game Start
	system("cls");
	m_mapManager.mapDraw(m_iWidth, m_iHeight);
	m_menuManager.dispControlMenu();
	//player ����ǥ��
	DispPlayerInfo();

	//�ӽ� ����
	int iPlayerState;
	int iLastStoneX, iLastStoneY;
	int iCurrentStoneX, iCurrentStoneY;
	int iStoneCount[2] = { 0 };
	
	while (1)
	{
		//�����̴� �� ǥ��
		m_Player[m_iTurn % 2].playerDrawStone();
		//Ű���� �Է� ����
		iPlayerState = m_Player[m_iTurn % 2].inputPlaying();
		
		//�����÷��̾� ��ī��Ʈ �ޱ�
		iStoneCount[m_iTurn % 2] = m_Player[m_iTurn % 2].getStoneCount();
		m_iArrStoneCount[BLACK] = m_Player[BLACK].getStoneCount();
		m_iArrStoneCount[WHITE] = m_Player[WHITE].getStoneCount();
		//�� ��ġ üũ ����
		int iStoneCheck = -1;
		
		//�÷��̾� ���¿� ���� �ൿ �Ŵ�����Ʈ ���α׷� �����ൿ ����
		switch (iPlayerState)
		{
		case PLAYERSTATE_MOVE:
			//���� �÷��̾��� ��ǥ(������, ����) Ȯ��
			iLastStoneX = m_Player[m_iTurn % 2].getLastPosX();
			iLastStoneY = m_Player[m_iTurn % 2].getLastPosY();
			//�����ӿ� ���� ��ġ üũ.
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
			//�� ���⿡ ���� ��ġ üũ
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
			//�� �����

			//�� ����
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

	//(�׳� ���� ����, �¸� ����, �Ϲ� �������� �� �� ���� ����

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