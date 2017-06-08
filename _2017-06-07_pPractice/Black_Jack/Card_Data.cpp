#include "Card_Data.h"



Card_Data::Card_Data()
{
	for (int c = 0; c < 4; c++)
	{
		std::vector<int> tempCard;
		for (int i = 1; i <= 13; i++)
		{
			tempCard.emplace_back(i);
		}
		card.myCard.emplace((CARD)c, tempCard);
		tempCard.clear();
	}
}


Card_Data::~Card_Data()
{
}
