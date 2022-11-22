#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "DrawManager.h"

#define MAX_FOOD_COUNT 10

using namespace std;

typedef struct FoodPosition
{
	int m_iX;
	int m_iY;
}FoodPosition;


class Food
{
private:
	string m_strFood;
	FoodPosition m_stFood;
	vector<FoodPosition> m_vectorFoodPos;

	DrawManager m_foodDrawManager;

public:
	Food();
	void InitFood();
	void MakeFoodPos(int Width, int Height);
	void DeleteFoodPos();
	void DeleteFoodPos(int i);
	void DrawFood();
	inline FoodPosition getLastPos()
	{
		return m_vectorFoodPos.back();
	}
	inline FoodPosition getPosition(int i)
	{
		return m_vectorFoodPos[i];
	}
	inline int getFoodCount()
	{
		return m_vectorFoodPos.size();
	}
};

