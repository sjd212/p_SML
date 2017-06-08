#pragma once
#include <iostream>
#include <random>

#include "Card_Data.h"
#include "Player.h"
#include "AI.h"

#define GAMEOVER_COUNT 21

class Game_System
{
private:
	Card_Data *pCardDB;
	Player *pPlayer;
	AI* pAI;
	
	bool bStart;
public:
	Game_System();
	~Game_System();

	void Gameloop();
	int PickCard();
	void printLose();
	void printResult();

	void GameStart();
};

