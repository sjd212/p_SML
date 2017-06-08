#pragma once
#include <map>
#include <vector>
// struct와 class의 차이는?
// default 생성자의 차이
// 기본 접근한정자의 차이 (public과 private)

enum class CARD
{
	CARD_DIA = 0,
	CARD_SPD,
	CARD_CLV,
	CARD_HRT
};

struct stCard
{
	std::map<CARD, std::vector<int>> myCard;
};

class Card_Data
{
private:
	stCard card;

public:
	Card_Data();
	~Card_Data();

	stCard getCard() { return card; }
};

