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
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else if (y == height-1)
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "��";
			cout << "��";
		}
		else
		{
			cout << "��";
			for (int x = 1; x < width - 1; x++)
				cout << "  ";
			cout << "��";
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
			strText = " �� �� �� ��";
		else if (i == 1)
			strText = "1. ���� ����";
		else if (i == 2)
			strText = "2. �ɼ� ����";
		else if (i == 3)
			strText = "3. ���� ����";
		m_menuTextManager.dispText(iTextPosX, iTextPosY, strText);
	}
	//DispTestBox
	int iBoxPosX = m_iMapWidth / 2;
	int iBoxPosY = m_iMapHeight * 0.7;
	int iBoxWidth = m_iMapWidth / 2;
	int iBoxHeight = 3;
	dispBox(iBoxWidth, iBoxHeight, iBoxPosX, iBoxPosY);

	//Ŀ�� �̵�
	gotoxy(m_iMapWidth, m_iMapHeight*0.8 - 1);
}

void oMenu::dispSetNameWindow()
{
	dispBox(m_iMapWidth, m_iMapHeight, 0, 0);
}

void oMenu::dispControlMenu()
{
	m_menuTextManager.dispText(m_iMapWidth - 7, m_iMapHeight, "====����Ű====");
	m_menuTextManager.dispText(m_iMapWidth - 14, m_iMapHeight+1, "�̵� : A,S,W,D  �� ���� : ENTER");
	m_menuTextManager.dispText(m_iMapWidth - 15, m_iMapHeight+2, "������ : N  �ɼ� : P  ���� : ESC");

}