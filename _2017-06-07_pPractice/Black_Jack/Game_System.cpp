#include "Game_System.h"
#include <time.h>
#include <thread>
#include <chrono>


Game_System::Game_System()
{
	pCardDB = new Card_Data(); // == new Card_Data;
	pPlayer = new Player(1000);
	pAI = new AI;
		
	bStart = false;
}


Game_System::~Game_System()
{
	delete pCardDB;
	delete pPlayer;
	delete pAI;
}

void Game_System::Gameloop()
{
	while (true)
	{
		system("cls");

		if (bStart == false)
			GameStart();
	
		pPlayer->printChip();
		pPlayer->printCard();		

		if (pPlayer->pick())
			pPlayer->addCard(PickCard());

		if (pPlayer->sumCard() > GAMEOVER_COUNT)
			break;

		if (pAI->getPattern())
			pAI->addCard(PickCard());

		if (pAI->sumCard() > GAMEOVER_COUNT)
			break;

	}
	
	printResult();
}

int Game_System::PickCard()
{	
	srand((int)time(nullptr));

	for (auto mapIter : pCardDB->getCard().myCard) // 카드 종류 갯수만큼 돈다.
	{
		for (auto vecIter : mapIter.second)	// 카드 13개 만큼 돈다.
		{
			int rnd = rand() % (mapIter.second.size() + 1); // 0 ~ 13 사이의 숫자 아무거나 A,2,3,4,5,6,7,8,10,J,Q,K -> size : 12
			int pick = mapIter.second[rnd];
			
			auto iter = mapIter.second.begin() + (pick - 1);
			mapIter.second.erase(iter);

			return pick;
		}
	}

	return 0;
}

void Game_System::printLose()
{
	std::cout << "The sum of card's number is over 21, Lose!!" << std::endl;
}

void Game_System::printResult()
{
	if (pPlayer->sumCard() > GAMEOVER_COUNT)
	{
		std::cout << "Player Lose" << std::endl;
		printLose();
	}
	else if (pAI->sumCard() > GAMEOVER_COUNT)
	{
		std::cout << "AI Lose!" << std::endl;
		printLose();
	}
	else if (pPlayer->sumCard() > pAI->sumCard())
	{
		std::cout << "Player's sum is Greater than AI's, player Win!!" << std::endl;
	}
	else if (pPlayer->sumCard() < pAI->sumCard())
	{
		std::cout << "AI's sum is Greater than Player's, AI Win!!" << std::endl;
	}
	else
		std::cout << "Draw" << std::endl;
}



void Game_System::GameStart()
{
	for (int i = 0; i < 2; i++)
	{
		pPlayer->addCard(PickCard());

		//std::chrono::milliseconds duration;
		//duration = std::chrono::milliseconds(1000);
		//std::this_thread::sleep_for(duration);

		pAI ->addCard(PickCard());
		bStart = true;
	}
}
