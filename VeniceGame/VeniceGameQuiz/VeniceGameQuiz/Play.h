#pragma once
#include "Interface.h"
#include "DrawManager.h"
#include "Word.h"
#include "Story.h"
#include "Lib.h"
#include <fstream>
#include <vector>
#include <list>
#include <time.h>
#include <algorithm>

#define INIT_SCORE 0
#define INIT_LIFE 9
#define TEXT_LINE_COUNT 10
#define STORY_TEXT_DELAY 1000
#define MAX_NAME_LEN 10
#define KEY_SKIP_s 115
#define KEY_SKIP_S 83
#define KEY_BS 8
#define KEY_ENTER 13
#define SCROLL_MODE_STORY 0
#define SCROLL_MODE_WORD 1
#define TIME_WORD_CREATE 1000
#define TIME_WORD_MOVING 500
#define WORD_CHANGE_RATE 50
#define MAX_WORD_LEN 20
#define ITEM_TIME_SPEED 7000
#define ITEM_TIME_PAUSE 5000
#define ITEM_TIME_HIDE 5000
#define SCORE_RATE 30
#define NUMBER_RANK_MAX 10

typedef struct PlayerInfo
{
	string strName;
	int iStage;
	int iScore;
	int iLife;
}PlayerInfo;

class Play
{
private:
	bool m_bGameState;
	bool m_bLifeDecCheck;
	int m_iWordMoveRate;
	int m_iWordMoveRateChange;
	int m_iWordCreateRate;
	bool m_bWordPauseItemState;
	bool m_bWordHideItemState;
	bool m_bWordSpeedChangeState;
	PlayerInfo m_stP;
	DrawManager m_pDrawManager;
	Interface m_pInterface;
	vector<Story> m_vStoryClass;
	vector<Word> m_vWordClass;
	vector<Word> m_vPlayingWordClass;
	vector<PlayerInfo> m_vPList;
	int m_iWordCount;

public:
	Play();
	void PlayerInit();
	void GameOn();
	void SetConsoleWindow(int width, int height);
	void DispPlayerInfo();
	void StartGame();
	void DispStory();
	void LoadStory();
	void SetPlayerName();
	bool KeyboardInput(string* str, int maxLen);
	void LoadWord();
	void InGame();
	template <typename t>
	void TextScroll(vector<t>* vectorClass, int max_size, int limit_y, int Mode, int Scoll_dir);
	bool CheckWordBoxPos(string str, int posX, int posY);
	void CreateWord();
	bool CheckWordFailed(string str);
	void ActivateItem(int item_number);
	void StageUp();
	void SaveRank();
	void ClearWord();
	void InRankSys();
	void LoadRank();
	inline void gotoxy(int x, int y)
	{
		COORD Pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}

};

