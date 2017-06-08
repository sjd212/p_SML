#include "Player.h"



Player::Player()
{
	chip = 0;
	
}

Player::Player(int Pchip)
{
	chip = Pchip;
}


Player::~Player()
{
}

void Player::printChip()
{
	std::cout << "myChip : " << chip << std::endl;
}

void Player::printCard()
{
	//for(int i=0; i<arrCard.size(); i++)
	std::cout << "Player's card : ";
	for (auto iter : arrCard)
	{
		std::cout << iter << ", ";
	}
	std::cout << std::endl;
}

int Player::sumCard()
{
	int sum = 0;
	for (auto iter : arrCard)
	{
		sum += iter;
	}
	return sum;
}

bool Player::pick()
{
	std::cout << "If you want to pick, Enter the (Y) (IF NOT (N) )" << std::endl;
	char flag;
	std::cin >> flag;
	
	if (flag == 'Y' || flag == 'y')
		return true;
	else if (flag == 'N' || flag == 'n')
		return false;
	else
		pick();
}

void Player::addCard(int paramCard)
{
	std::cout << "Player AddCard!";
	arrCard.emplace_back(paramCard);
	std::cout << std::endl;
}

