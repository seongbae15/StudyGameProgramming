#include "Food.h"

Food::Food()
{
	m_strFood = "¢½";
}

void Food::InitFood()
{
	if (!m_vectorFoodPos.empty())
		m_vectorFoodPos.clear();

}

void Food::MakeFoodPos(int Width, int Height)
{
	bool bPosCheck;
	int iTempX, iTempY;
	
	while (1)
	{
		bPosCheck = true;
		iTempX = rand() % (Width - 2) + 1;		//1~48
		iTempY = rand() % (Height - 2) + 1;		//1~28

		if (m_vectorFoodPos.empty() == true)
			break;
		else
		{
			for (int i = 0; i < m_vectorFoodPos.size(); i++)
			{
				if (iTempX == m_vectorFoodPos[i].m_iX && iTempY == m_vectorFoodPos[i].m_iY)
				{
					bPosCheck = false;
					break;
				}
			}
			if (bPosCheck == true)
				break;
		}
	}
	m_stFood.m_iX = iTempX;
	m_stFood.m_iY = iTempY;
	m_vectorFoodPos.push_back(m_stFood);
}

void Food::DeleteFoodPos()
{
	if (m_vectorFoodPos.empty())
		return;
	else
		m_vectorFoodPos.pop_back();
}
void Food::DeleteFoodPos(int i)
{
	m_vectorFoodPos.erase(m_vectorFoodPos.begin() + i);
}

void Food::DrawFood()
{
	m_foodDrawManager.DrawObject(m_strFood, m_stFood.m_iX, m_stFood.m_iY);
}