#include "oMenu.h"

oMenu::oMenu()
{

}

void oMenu::setMenu(int width, int height)
{
	m_iMapWidth = width;
	m_iMapHeight = height;
}

void oMenu::dispBox(int width, int height, int pos_X, int pos_Y)
{
	for (int y = 0; y < height; y++)
	{
		gotoxy(pos_X, pos_Y + y);
		if (y == 0)
		{
			cout << "┌";
			for (int x = 1; x < width - 1; x++)
				cout << "─";
			cout << "┐";
		}
		else if (y == height-1)
		{
			cout << "└";
			for (int x = 1; x < width - 1; x++)
				cout << "─";
			cout << "┘";
		}
		else
		{
			cout << "│";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "│";
		}
		cout << endl;
	}
}
void oMenu::dispMainMenu(bool replayMode)
{
	int iTextPosX = m_iMapWidth - 6;
	int iTextPosY;
	string strText;
	if (replayMode == true)
	{
		for (int i = 0; i < 5; i++)
		{
			iTextPosY = m_iMapHeight / 10 * (2 + i);
			if (i == 0)
				strText = " ★ 오 목 ★";
			else if (i == 1)
				strText = "1. 게임 시작";
			else if (i == 2)
				strText = "2. 옵션 설정";
			else if (i == 3)
				strText = "3. 게임 종료";
			else if (i == 4)
				strText = "4. Replay 재생";
			m_menuDrawManager.dispText(iTextPosX, iTextPosY, strText);
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			iTextPosY = m_iMapHeight / 10 * (3 + i);
			if (i == 0)
				strText = " ★ 오 목 ★";
			else if (i == 1)
				strText = "1. 게임 시작";
			else if (i == 2)
				strText = "2. 옵션 설정";
			else if (i == 3)
				strText = "3. 게임 종료";
			m_menuDrawManager.dispText(iTextPosX, iTextPosY, strText);
		}
	}
	//DispTextBox
	int iBoxPosX = m_iMapWidth / 2;
	int iBoxPosY = m_iMapHeight * 0.7f;
	int iBoxWidth = m_iMapWidth / 2;
	int iBoxHeight = 3;
	m_menuDrawManager.drawBox(iBoxWidth, iBoxHeight, iBoxPosX, iBoxPosY);
}


void oMenu::dispInputPlayerName(string str, int playerNumber)
{
	//소수점 자리 곱할 때, f 붙이기
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight *0.3f*playerNumber, str);
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight *0.3f*playerNumber + 1, "입력 : ");
}


void oMenu::dispControlMenu()
{
	m_menuDrawManager.dispText(m_iMapWidth - 7, m_iMapHeight, "====조작키====");
	m_menuDrawManager.dispText(m_iMapWidth - 14, m_iMapHeight+1, "이동 : A,S,W,D  돌 놓기 : ENTER");
	m_menuDrawManager.dispText(m_iMapWidth - 15, m_iMapHeight+2, "무르기 : N  옵션 : P  종료 : ESC");
}


void oMenu::dispOptionMenu()
{
	m_menuDrawManager.drawBox(m_iMapWidth, m_iMapHeight);
	m_menuDrawManager.dispText(m_iMapWidth - 5, m_iMapHeight*0.2, "= Option =");
	m_menuDrawManager.dispText(m_iMapWidth - 7, m_iMapHeight*0.3, "1. Map Size Set");
	m_menuDrawManager.dispText(m_iMapWidth - 7, m_iMapHeight*0.4, "2. Cursor Custom");
	m_menuDrawManager.dispText(m_iMapWidth - 7, m_iMapHeight*0.5, "3. Stone Custom");
	m_menuDrawManager.dispText(m_iMapWidth - 8, m_iMapHeight*0.6, "4. Undo Count Set");
	m_menuDrawManager.dispText(m_iMapWidth - 5, m_iMapHeight*0.7, "5. Return");
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight*0.8, "입력 : ");

}

void oMenu::dispCusorCustomMenu()
{
	m_menuDrawManager.drawBox(m_iMapWidth, m_iMapHeight);
	m_menuDrawManager.dispText(m_iMapWidth - 6, m_iMapHeight*0.2, "= Set Cursor =");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.3, "1. ○, ●");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.4, "2. ♡, ♥");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.5, "3. ☞, ☜");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.6, "4. ①, ②");
	m_menuDrawManager.dispText(m_iMapWidth - 5, m_iMapHeight*0.7, "5. Return");
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight*0.8, "입력 : ");
}

void oMenu::dispStoneCustomMenu()
{
	m_menuDrawManager.drawBox(m_iMapWidth, m_iMapHeight);
	m_menuDrawManager.dispText(m_iMapWidth - 6, m_iMapHeight*0.2, "= Set Stone =");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.3, "1. ○, ●");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.4, "2. ♡, ♥");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.5, "3. ☏, ☎");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.6, "4. ①, ②");
	m_menuDrawManager.dispText(m_iMapWidth - 5, m_iMapHeight*0.7, "5. Return");
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight*0.8, "입력 : ");
}

void oMenu::dispUndoSetMenu()
{
	m_menuDrawManager.drawBox(m_iMapWidth, m_iMapHeight);
	m_menuDrawManager.dispText(m_iMapWidth - 6, m_iMapHeight*0.2, "= Set Undo =");
	m_menuDrawManager.dispText(m_iMapWidth - 8, m_iMapHeight*0.3, "1. Set Undo Count");
	m_menuDrawManager.dispText(m_iMapWidth - 6, m_iMapHeight*0.4, "2. Undo On/Off");
	m_menuDrawManager.dispText(m_iMapWidth - 4, m_iMapHeight*0.5, "3. Return");
	m_menuDrawManager.dispText(m_iMapWidth - 3, m_iMapHeight*0.6, "입력 : ");
}

void oMenu::dispWarning()
{
	m_menuDrawManager.drawBox(m_iMapWidth, m_iMapHeight);
	m_menuDrawManager.dispText(m_iMapWidth - 6, m_iMapHeight*0.4, "접근 불가능");
	m_menuDrawManager.dispText(m_iMapWidth - 7, m_iMapHeight*0.5, "<Game Play 중>");
}