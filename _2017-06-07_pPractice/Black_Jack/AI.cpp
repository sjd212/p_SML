#include "AI.h"



AI::AI() : Player(AI_CHIP_COUNT)
{
	aiThread = std::thread(&AI::active, this);
}


AI::~AI()
{	
	if (aiThread.joinable())
		aiThread.join();
}

void AI::active()
{
	srand((int)time(NULL));
	
	std::chrono::milliseconds duration;
	duration = std::chrono::milliseconds(5000);

	while (true)
	{
		int random = rand() % 101;

		if (random  > 50)
			pattern = PATTERN::PATTERN_A;
		else
			pattern = PATTERN::PATTERN_B;

		std::cout << "AI PATTERN : " << (int)pattern << std::endl;

		std::this_thread::sleep_for(duration);
	}	
}

bool AI::getPattern()
{
	// 패턴 A면 어떻게하자~
	if (pattern == PATTERN::PATTERN_A)
	{
		std::cout << "AI PICK Card" << std::endl;
		return true;
	}
	// 패턴 B면 어떻게하자~
	if (pattern == PATTERN::PATTERN_B)
	{
		std::cout << "AI Hold Card" << std::endl;
		return false;
	}
}



void AI::printCard()
{
	std::cout << "AI's card : ";
	for (auto iter : arrCard)
	{
		std::cout << iter << ", ";
	}
}



void AI::addCard(int paramCard)
{
	std::cout << "AI AddCard!";
	arrCard.emplace_back(paramCard);
	std::cout << std::endl;
}

int AI::sumCard()
{
	int sum = 0;
	for (auto iter : arrCard)
	{
		sum += iter;
	}
	return 0;
}
