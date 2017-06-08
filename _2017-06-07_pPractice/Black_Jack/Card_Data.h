#pragma once
#include <map>
#include <vector>
// struct�� class�� ���̴�?
// default �������� ����
// �⺻ ������������ ���� (public�� private)

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

