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

void oMenu::dispMainMenu()
{
	int iTextPosX = m_iMapWidth - 6;
	int iTextPosY;
	string strText;
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
		m_menuTextManager.dispText(iTextPosX, iTextPosY, strText);
	}
	//DispTestBox
	int iBoxPosX = m_iMapWidth / 2;
	int iBoxPosY = m_iMapHeight * 0.7;
	int iBoxWidth = m_iMapWidth / 2;
	int iBoxHeight = 3;
	dispBox(iBoxWidth, iBoxHeight, iBoxPosX, iBoxPosY);

	//커서 이동
	gotoxy(m_iMapWidth, m_iMapHeight*0.8 - 1);
}

void oMenu::dispSetNameWindow()
{
	dispBox(m_iMapWidth, m_iMapHeight, 0, 0);
}

void oMenu::dispControlMenu()
{
	m_menuTextManager.dispText(m_iMapWidth - 7, m_iMapHeight, "====조작키====");
	m_menuTextManager.dispText(m_iMapWidth - 14, m_iMapHeight+1, "이동 : A,S,W,D  돌 놓기 : ENTER");
	m_menuTextManager.dispText(m_iMapWidth - 15, m_iMapHeight+2, "무르기 : N  옵션 : P  종료 : ESC");

}