#pragma once

#include <iostream>
#include <Windows.h>
#include <time.h>

#include "DrawManager.h"
#include "Snake.h"
#include "Stone.h"
#include "Food.h"

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define MOVE_TIME_DEFAULT 400
#define MOVE_TIME_MIN 80
#define MOVE_TIME_SPEED_UP 10
#define SPACE_BAR 32

using namespace std;

class SnakeGameManager
{
private:
	int m_iMapWidth;
	int m_iMapHeight;
	int m_iScore;
	int m_iMoveTime;
	DrawManager m_gmDrawManager;
	Snake m_gmSnake;
	Stone m_gmStone;
	Food m_gmFood;

public:
	SnakeGameManager();
	void DispMainLoby();
	void SetConsoleWindow();
	void GameRun();
	void GameInit();
	void GameStart();
	void KeyboardInput();
	void CreateFood();
	void UpdateGameInfo();
	bool CheckStonePos(int posX, int posY);
	bool CheckEat(int posX, int posY);
	bool CheckHeadPos(int posX, int posY);
	bool CheckTailPos(int posX, int posY);
	bool CheckGameOver(int posX, int posY);
	bool CheckWallPos(int posX, int posY);
	void DispGameOver();
	inline int getMapWidth()
	{
		return MAP_WIDTH;
	}
	inline int getMapHeight()
	{
		return MAP_HEIGHT;
	}
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
};

