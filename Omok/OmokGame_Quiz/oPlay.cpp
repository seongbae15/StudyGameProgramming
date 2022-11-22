#include "oPlay.h"

oPlay::oPlay()
{
	m_iWidth = WIDTH;
	m_iHeight = HEIGHT;

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			m_sStoneShape[i].m_strStoneBlack = "○";
			m_sStoneShape[i].m_strStoneWhite = "●";
			m_sCusorShape[i].m_strCusorBlack = "○";
			m_sCusorShape[i].m_strCusorWhite = "●";
			break;
		case 1:
			m_sStoneShape[i].m_strStoneBlack = "♡";
			m_sStoneShape[i].m_strStoneWhite = "♥";
			m_sCusorShape[i].m_strCusorBlack = "♡";
			m_sCusorShape[i].m_strCusorWhite = "♥";
			break;
		case 2:
			m_sStoneShape[i].m_strStoneBlack = "☏";
			m_sStoneShape[i].m_strStoneWhite = "☎";
			m_sCusorShape[i].m_strCusorBlack = "☞";
			m_sCusorShape[i].m_strCusorWhite = "☜";
			break;
		case 3:
			m_sStoneShape[i].m_strStoneBlack = "①";
			m_sStoneShape[i].m_strStoneWhite = "②";
			m_sCusorShape[i].m_strCusorBlack = "①";
			m_sCusorShape[i].m_strCusorWhite = "②";
			break;
		}
	}
	//Stone Shape
	m_strArrStone[BLACK] = m_sStoneShape[DEFAULT].m_strStoneBlack;
	m_strArrStone[WHITE] = m_sStoneShape[DEFAULT].m_strStoneWhite;
	//Cusor Shape
	m_strArrCusor[BLACK] = m_sCusorShape[DEFAULT].m_strCusorBlack;
	m_strArrCusor[WHITE] = m_sCusorShape[DEFAULT].m_strCusorWhite;

	m_bGameState = false;
	m_bUndoState = true;
	m_iInitUndoCount = INIT_UNDO;
	m_iArrUndoCount[BLACK] = m_iInitUndoCount;
	m_iArrUndoCount[WHITE] = m_iInitUndoCount;
	m_iArrStoneCount[BLACK] = 0;
	m_iArrStoneCount[WHITE] = 0;
}

oPlay::~oPlay()
{
}

void oPlay::setConsoleWindow()
{
	char buf[256];
	int width = (m_iWidth * 2) + 1;
	int height = m_iHeight + 6;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void oPlay::dispPlayerInfo(int turn)
{
	m_playDrawManager.dispText(m_iWidth - 18, m_iHeight + 3, "Player Name : ");
	cout << m_strArrName[turn%2];
	m_playDrawManager.dispText(m_iWidth + 6, m_iHeight + 3, "무르기 :   \b\b");
	cout << m_iArrUndoCount[(turn +1)%2];
	cout << " ("<<m_strArrName[(turn +1) % 2]<<")";
	m_playDrawManager.dispText(m_iWidth - 5, m_iHeight + 4, "Turn : ");
	cout << turn;
}

int oPlay::checkStonePoisition(int pos_X, int pos_Y)
{
	if (m_iArrStoneCount[WHITE] == 0 && m_iArrStoneCount[BLACK] == 0)
		return -1;
	else
	{
		//White Stone Check
		for (int i = 0; i < m_iArrStoneCount[WHITE]; i++)
		{
			if (pos_X == m_playPlayer[WHITE].getPositionX(i) && pos_Y == m_playPlayer[WHITE].getPositionY(i))
				return 0;
		}
		//Black Stone Check
		for (int i = 0; i < m_iArrStoneCount[BLACK]; i++)
		{
			if (pos_X == m_playPlayer[BLACK].getPositionX(i) && pos_Y == m_playPlayer[BLACK].getPositionY(i))
				return 1;
		}
		return -1;
	}
}
void oPlay::inputPlayerName()
{
	//P1 Set
	m_playDrawManager.drawBox(m_iWidth,m_iHeight);
	m_playMenu.dispInputPlayerName("P1 이름");
	cin >> m_strArrName[BLACK];
	m_playPlayer[BLACK].setPlayerInit(m_strArrName[BLACK], m_iWidth, m_iHeight, m_iInitUndoCount);
	m_playPlayer[BLACK].setPlayerCusor(m_strArrCusor[BLACK]);
	m_playPlayer[BLACK].setPlayerStone(m_strArrStone[BLACK]);
	//P2 Set
	m_playMenu.dispInputPlayerName("P2 이름",2);
	cin >> m_strArrName[WHITE];
	m_playPlayer[WHITE].setPlayerInit(m_strArrName[WHITE], m_iWidth, m_iHeight, m_iInitUndoCount);
	m_playPlayer[WHITE].setPlayerCusor(m_strArrCusor[WHITE]);
	m_playPlayer[WHITE].setPlayerStone(m_strArrStone[WHITE]);
}

void oPlay::checkWin()
{
	m_bGameState = m_playPlayer[m_iTurn % 2].checkPlayerWin();
	if (m_bGameState == false)
	{
		m_playDrawManager.dispText(m_iWidth - (4 + (m_strArrName[m_iTurn % 2].size() / 2)), m_iHeight*0.5, m_strArrName[m_iTurn % 2]);
		cout << "팀 승리!!" << endl;
		getch();
	}
}

void oPlay::savePlayInfo(string fileName)
{
	m_fPlaySave.open(fileName);
	if (m_fPlaySave.is_open())
	{
		m_fPlaySave << m_bContinuePlay << endl;
		m_fPlaySave << m_bGameState << endl;
		m_fPlaySave << m_bUndoState << endl;
		m_fPlaySave << m_iWidth << endl;
		m_fPlaySave << m_iHeight << endl;
		m_fPlaySave << m_iTurn << endl;
		m_fPlaySave << m_strArrCusor[WHITE] << " " << m_strArrCusor[BLACK] << endl;
		m_fPlaySave << m_strArrStone[WHITE] << " " << m_strArrStone[BLACK] << endl;
		m_fPlaySave.close();
	}
	if (m_bContinuePlay == true)
	{
		m_playPlayer[WHITE].savePlayerInfo("playerWhiteInfo.txt");
		m_playPlayer[BLACK].savePlayerInfo("playerBlackInfo.txt");
	}
	else
	{
		m_playPlayer[WHITE].savePlayerInfo("replayWhiteInfo.txt");
		m_playPlayer[BLACK].savePlayerInfo("replayBlackInfo.txt");
	}
}

void oPlay::loadPlayInfo(string fileName)
{
	m_fPlayLoad.open(fileName);
	if (!m_fPlayLoad.is_open())
	{
		m_bContinuePlay = false;
		return;
	}
	else
	{
		m_fPlayLoad >> m_bContinuePlay;
		m_fPlayLoad >> m_bGameState;
		m_fPlayLoad >> m_bUndoState;
		m_fPlayLoad >> m_iWidth;
		m_fPlayLoad >> m_iHeight;
		m_fPlayLoad >> m_iTurn;
		m_fPlayLoad >> m_strArrCusor[WHITE];
		m_fPlayLoad >> m_strArrCusor[BLACK];
		m_fPlayLoad >> m_strArrStone[WHITE];
		m_fPlayLoad >> m_strArrStone[BLACK];
		m_fPlayLoad.close();
		if (m_bContinuePlay == true)
		{
			m_playPlayer[WHITE].loadPlayerInfo("playerWhiteInfo.txt");
			m_playPlayer[BLACK].loadPlayerInfo("playerBlackInfo.txt");
		}
		else
		{
			m_playPlayer[WHITE].loadPlayerInfo("replayWhiteInfo.txt");
			m_playPlayer[BLACK].loadPlayerInfo("replayBlackInfo.txt");
		}
	}
}

void oPlay::setContinuePlaying()
{
	m_strArrName[WHITE] = m_playPlayer[WHITE].getPlayerName();
	m_strArrName[BLACK] = m_playPlayer[BLACK].getPlayerName();
	m_playPlayer[BLACK].setMovingArrange(m_iWidth, m_iHeight);
	m_playPlayer[WHITE].setMovingArrange(m_iWidth, m_iHeight);
	m_playPlayer[BLACK].setPlayerCusor(m_strArrCusor[BLACK]);
	m_playPlayer[BLACK].setPlayerStone(m_strArrStone[BLACK]);
	m_playPlayer[WHITE].setPlayerCusor(m_strArrCusor[WHITE]);
	m_playPlayer[WHITE].setPlayerStone(m_strArrStone[WHITE]);

	m_iArrUndoCount[BLACK] = m_playPlayer[BLACK].getUndoCount();
	m_iArrStoneCount[BLACK] = m_playPlayer[BLACK].getStoneCount();
	m_iArrUndoCount[WHITE] = m_playPlayer[WHITE].getUndoCount();
	m_iArrStoneCount[WHITE] = m_playPlayer[WHITE].getStoneCount();
}

void oPlay::startPlaying()
{
	system("cls");
	//load Play Info
	loadPlayInfo("playingInfo.txt");
	if (m_bContinuePlay == true)
	{
		//Setting menu window
		m_playMenu.setMenu(m_iWidth, m_iHeight);
		//Setting Player info to Play info
		setContinuePlaying();
		//콘솔 창 변경
		setConsoleWindow();
		//맵 복구
		m_playDrawManager.drawMap(m_iWidth, m_iHeight);
		m_playMenu.dispControlMenu();
		//돌 복구
		m_playPlayer[BLACK].reDispTotalStone();
		m_playPlayer[WHITE].reDispTotalStone();
	}
	else
	{
		m_iTurn = 1;
		m_bGameState = true;
		//남은 좌표 삭제
		m_playPlayer[BLACK].delPlayerInfo();
		m_playPlayer[WHITE].delPlayerInfo();
		//player 정보 입력
		inputPlayerName();
		system("cls");
		m_playDrawManager.drawMap(m_iWidth, m_iHeight);
		m_playMenu.dispControlMenu();
		//Get Stone & Undo Count
		m_iArrUndoCount[BLACK] = m_playPlayer[BLACK].getUndoCount();
		m_iArrStoneCount[BLACK] = m_playPlayer[BLACK].getStoneCount();
		m_iArrUndoCount[WHITE] = m_playPlayer[WHITE].getUndoCount();
		m_iArrStoneCount[WHITE] = m_playPlayer[WHITE].getStoneCount();
	}

	//임시 변수 선언
	int iPlayerState;
	int iLastStoneX, iLastStoneY;
	int iCurrentStoneX, iCurrentStoneY;

	//Game Start
	while (m_bGameState==true)
	{
		//Stone Check Variable
		int iStoneCheck = -1;
		dispPlayerInfo(m_iTurn);
		//DrawCusor
		m_playPlayer[m_iTurn % 2].playerDrawCusor();

		//Keyboard Input
		iPlayerState = m_playPlayer[m_iTurn % 2].inputPlaying();
		//playInput(iPlayerState);
		switch (iPlayerState)
		{
		case PLAYERSTATE_MOVE:
			//현재 플레이어의 움직이기 전 좌표 확인
			iLastStoneX = m_playPlayer[m_iTurn % 2].getLastPosX();
			iLastStoneY = m_playPlayer[m_iTurn % 2].getLastPosY();
			//움직임에 의한 위치 체크.
			iStoneCheck = checkStonePoisition(iLastStoneX, iLastStoneY);
			if (iStoneCheck == -1)
				m_playDrawManager.mapRefresh(m_iWidth, m_iHeight, iLastStoneX, iLastStoneY);
			else if (iStoneCheck == 1)
				m_playDrawManager.drawStone(iLastStoneX, iLastStoneY, m_strArrStone[BLACK]);
			else if (iStoneCheck == 0)
				m_playDrawManager.drawStone(iLastStoneX, iLastStoneY, m_strArrStone[WHITE]);
			break;
		case PLAYERSTATE_DO:
			//돌 놓기에 의한 위치 체크
			iCurrentStoneX = m_playPlayer[m_iTurn % 2].getCurrentPosX();
			iCurrentStoneY = m_playPlayer[m_iTurn % 2].getCurrentPosY();
			iStoneCheck = checkStonePoisition(iCurrentStoneX, iCurrentStoneY);
			if (iStoneCheck == -1)
			{
				m_playPlayer[m_iTurn % 2].updatePosition();
				//승리검사
				checkWin();
				if (m_bGameState == true)
				{
					m_iArrStoneCount[m_iTurn % 2] = m_playPlayer[m_iTurn % 2].getStoneCount();
					m_iTurn++;
				}
				else
				{
					m_bContinuePlay = false;
					//replay 할 파일 저장
					savePlayInfo("playingInfo.txt");
					savePlayInfo("rePlayLastGame.txt");
					m_playPlayer[BLACK].delPlayerInfo();
					m_playPlayer[WHITE].delPlayerInfo();
				}
			}
			break;
		case PLAYERSTATE_UNDO:
			//상대방 돌의 갯수가 0일 때
			if (m_iArrStoneCount[(m_iTurn+1)%2]==0)
				break;
			//상대방 무르기 카운트가 0일 때,
			else if (m_playPlayer[(m_iTurn+1)%2].getUndoCount()==0)
				break;
			//무르기 기능이 off 일때,
			else if (m_bUndoState == false)
				break;
			else
			{
				//현재 턴의 돌 삭제
				iCurrentStoneX = m_playPlayer[m_iTurn % 2].getCurrentPosX();
				iCurrentStoneY = m_playPlayer[m_iTurn % 2].getCurrentPosY();
				m_playDrawManager.mapRefresh(m_iWidth, m_iHeight, iCurrentStoneX, iCurrentStoneY);
				//턴 변경
				m_iTurn--;
				//무르기 실행
				m_playPlayer[m_iTurn % 2].undoPoistion();
				m_iArrUndoCount[m_iTurn % 2] = m_playPlayer[m_iTurn % 2].getUndoCount();
				m_iArrStoneCount[m_iTurn % 2] = m_playPlayer[m_iTurn % 2].getStoneCount();
				break;
			}
		case PLAYERSTATE_OPTION:
			setOption();
			//맵 복구
			system("cls");
			m_playDrawManager.drawMap(m_iWidth, m_iHeight);
			m_playMenu.dispControlMenu();
			//돌 복구
			m_playPlayer[BLACK].reDispTotalStone();
			m_playPlayer[WHITE].reDispTotalStone();
			break;
		case PLAYERSTATE_EXIT:
			//게임 진행 중, 종료 시, 게임 좌표 저장
			if (m_bGameState == true)
			{
				m_bContinuePlay = true;
				//play정보 저장
				savePlayInfo("playingInfo.txt");
			}
			//게임 상태 변경(true -> false)
			m_bGameState = false;
			m_playPlayer[BLACK].delPlayerInfo();
			m_playPlayer[WHITE].delPlayerInfo();
			return;
		default:
			break;
		}
		
	}
	return;
}

void oPlay::modifyMapSize()
{
	int iTempWidth, iTempHeight;
	while (1)
	{
		system("cls");
		m_playDrawManager.drawBox(m_iWidth,m_iHeight);
		m_playDrawManager.dispText(m_iWidth - 4, m_iHeight*0.4, "Width : ");
		cin >> iTempWidth;
		m_playDrawManager.dispText(m_iWidth - 5, m_iHeight*0.6, "Height : ");
		cin >> iTempHeight;
		if (iTempWidth < 20 || iTempWidth>90 || iTempHeight < 20 || iTempHeight>45)
		{
			system("cls");
			m_playDrawManager.dispText(m_iWidth - 5, m_iHeight*0.4, "변경 불가능");
			m_playDrawManager.dispText(m_iWidth - 16, m_iHeight*0.5, "<가로 : 20 ~ 90, 세로 : 20 ~ 45>\n");
			getch();
		}
		else
		{
			m_iWidth = iTempWidth;
			m_iHeight = iTempHeight;
			m_playMenu.setMenu(m_iWidth, m_iHeight);
			break;
		}
	}
	setConsoleWindow();
}

void oPlay::modifyCursor()
{
	int iSelect;

	system("cls");
	m_playMenu.dispCusorCustomMenu();
	cin >> iSelect;
	switch (iSelect)
	{
	case 1:
		m_strArrCusor[BLACK] = m_sCusorShape[DEFAULT].m_strCusorBlack;
		m_strArrCusor[WHITE] = m_sCusorShape[DEFAULT].m_strCusorWhite;
		break;
	case 2:
		m_strArrCusor[BLACK] = m_sCusorShape[1].m_strCusorBlack;
		m_strArrCusor[WHITE] = m_sCusorShape[1].m_strCusorWhite;
		break;
	case 3:
		m_strArrCusor[BLACK] = m_sCusorShape[2].m_strCusorBlack;
		m_strArrCusor[WHITE] = m_sCusorShape[2].m_strCusorWhite;
		break;
	case 4:
		m_strArrCusor[BLACK] = m_sCusorShape[3].m_strCusorBlack;
		m_strArrCusor[WHITE] = m_sCusorShape[3].m_strCusorWhite;
		break;
	default:
		break;
	}
	m_playPlayer[BLACK].setPlayerCusor(m_strArrCusor[BLACK]);
	m_playPlayer[WHITE].setPlayerCusor(m_strArrCusor[WHITE]);
}

void oPlay::modifyStone()
{
	int iSelect;
	system("cls");
	m_playMenu.dispStoneCustomMenu();
	cin >> iSelect;
	switch (iSelect)
	{
	case 1:
		m_strArrStone[BLACK] = m_sStoneShape[DEFAULT].m_strStoneBlack;
		m_strArrStone[WHITE] = m_sStoneShape[DEFAULT].m_strStoneWhite;
		break;
	case 2:
		m_strArrStone[BLACK] = m_sStoneShape[1].m_strStoneBlack;
		m_strArrStone[WHITE] = m_sStoneShape[1].m_strStoneWhite;
		break;
	case 3:
		m_strArrStone[BLACK] = m_sStoneShape[2].m_strStoneBlack;
		m_strArrStone[WHITE] = m_sStoneShape[2].m_strStoneWhite;
		break;
	case 4:
		m_strArrStone[BLACK] = m_sStoneShape[3].m_strStoneBlack;
		m_strArrStone[WHITE] = m_sStoneShape[3].m_strStoneWhite;
		break;
	default:
		break;
	}
	m_playPlayer[BLACK].setPlayerStone(m_strArrStone[BLACK]);
	m_playPlayer[WHITE].setPlayerStone(m_strArrStone[WHITE]);
}

void oPlay::changeUndoCount()
{
	int iTempUndoCount;
	while (1)
	{
		system("cls");
		m_playDrawManager.drawBox(m_iWidth,m_iHeight);
		m_playDrawManager.dispText(m_iWidth-15, m_iHeight*0.5, "무르기 횟수 입력<최대 10회> : ");
		cin >> iTempUndoCount;
		if (iTempUndoCount >= 0 && iTempUndoCount <= 10)
		{
			m_iInitUndoCount = iTempUndoCount;
			m_iArrUndoCount[BLACK] = m_iInitUndoCount;
			m_iArrUndoCount[WHITE] = m_iInitUndoCount;
			break;
		}
			
		else
		{
			m_playDrawManager.dispText(m_iWidth - 15, m_iHeight*0.6, "범위가 맞지 않습니다 < 0 ~ 10 >\n");
			getch();
		}
	}
}

void oPlay::changeUndoState()
{
	system("cls");
	bool bTempUndoState;
	m_playDrawManager.drawBox(m_iWidth, m_iHeight);
	if (m_bUndoState == true)
	{
		m_playDrawManager.dispText(m_iWidth-5, m_iHeight*0.5, "무르기 Off\n");
		m_bUndoState = false;
		getch();
	}
	else
	{
		m_playDrawManager.dispText(m_iWidth-5, m_iHeight*0.5, "무르기 On\n");
		m_bUndoState = true;
		getch();
	}
}

void oPlay::modifyUndoSet()
{
	int iSelect;
	while (1)
	{
		system("cls");
		m_playMenu.dispUndoSetMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			changeUndoCount();
			break;
		case 2:
			changeUndoState();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void oPlay::setOption()
{
	int iSelect;
	while(1)
	{
		system("cls");
		m_playMenu.dispOptionMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if(m_bGameState == false)
				modifyMapSize();
			else
			{
				m_playMenu.dispWarning();
				getch();
			}
			break;
		case 2:
			modifyCursor();
			break;
		case 3:
			modifyStone();
			break;
		case 4:
			if(m_bGameState == false)
				modifyUndoSet();
			else
			{
				m_playMenu.dispWarning();
				getch();
			}
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}

void oPlay::replayLastGame()
{
	loadPlayInfo("rePlayLastGame.txt");
	if (m_bReplayMode == true)
	{
		//Setting menu window
		m_playMenu.setMenu(m_iWidth, m_iHeight);
		//Setting Player info to Play info
		setContinuePlaying();
		//콘솔 창 변경
		setConsoleWindow();
		//맵 복구
		system("cls");
		m_playDrawManager.drawMap(m_iWidth, m_iHeight);
		m_playDrawManager.dispText(m_iWidth - 5, m_iHeight+1, "Replaying...");
		int iTempTurn = m_iTurn;
		int iStoneIndex = 0;
		for (int i = 1; i <= iTempTurn;i++)
		{
			dispPlayerInfo(i);
			m_playPlayer[i % 2].playerDrawStone(iStoneIndex);
			if (i % 2 == 0)
				iStoneIndex++;
			Sleep(500);
			if(kbhit())
			{
				getch();
				m_playDrawManager.dispText(m_iWidth - 3, m_iHeight + 2, "Pause");
				getch();
				m_playDrawManager.dispText(m_iWidth - 3, m_iHeight + 2, "     ");
			}
		}
		m_playDrawManager.dispText(m_iWidth - 5, m_iHeight + 1, "Replay End");
		getch();
	}
	else
		return;
}

void oPlay::startOmok()
{
	int iSelect;
	setConsoleWindow();
	m_playMenu.setMenu(m_iWidth, m_iHeight);
	while (1)
	{
		system("cls");
		m_playDrawManager.drawMap(m_iWidth, m_iHeight);
		//replay 가능 여부 확인
		m_fPlayLoad.open("rePlayLastGame.txt");
		if (m_fPlayLoad.is_open())
		{
			m_bReplayMode = true;
			m_fPlayLoad.close();
		}
		else
			m_bReplayMode = false;

		m_playMenu.dispMainMenu(m_bReplayMode);
		gotoxy(m_iWidth, m_iHeight*0.7+1);
		cin >> iSelect;
		switch (iSelect)
		{
		case LOBYMENU_GAME_START:
			
			startPlaying();
			break;
		case LOBYMENU_OPTION:
			setOption();
			break;
		case LOBYMENU_GAME_END:
			//삭제
			m_playPlayer[BLACK].delPlayerInfo();
			m_playPlayer[WHITE].delPlayerInfo();
			return;
		case LOBYMENU_REPLAY:
			if(m_bReplayMode == true)
				replayLastGame();
			m_playPlayer[BLACK].delPlayerInfo();
			m_playPlayer[WHITE].delPlayerInfo();
			break;
		default:
			break;
		}
	}
}