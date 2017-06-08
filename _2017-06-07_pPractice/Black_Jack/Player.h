#pragma once
#include <vector>
#include <iostream>
class Player
{
protected:
	int chip;
	std::vector<int> arrCard;

public:
	Player();
	Player(int Pchip);

	//Player(float fChip);
	//Player(float fChip, int nChip);
	//Player(int nChip, float fChip);
	//Player(int nChip1, int nChip2);
	//Player(float fChip1, float fChip2);

	~Player();

	void printChip();
	void printCard();
	int sumCard();

	bool pick();
	void addCard(int paramCard);
};

