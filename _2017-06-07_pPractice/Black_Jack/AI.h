#pragma once
#include "Player.h"
#include <time.h>
#include <thread>
#include <chrono>

#define AI_CHIP_COUNT 1000

enum class PATTERN
{
	PATTERN_A, PATTERN_B
};

class AI : public Player
{
private:
	PATTERN pattern;
	std::vector<int> arrCard;
	
	std::thread aiThread;

public:
	AI();
	~AI();

	void active();
	bool getPattern();
	
	void printCard();
	void addCard(int paramCard);
	int sumCard();
};

