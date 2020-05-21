#include <random>
#include <DxLib.h>
#include "ImageMng.h"
#include "DeckMng.h"

DeckMng::DeckMng()
{
}

DeckMng::~DeckMng()
{
}

bool DeckMng::Init()
{
	cardData_map["NullCard"] = {
	"NullCard",
	NULL_CARD,
	500,
	"data/card/N00.png",
	IMAGE_ID("data/card/N00.png")[0],
	0,
	0,
	NO_EFFECT
	};
	cardData_map["ヒノキの棒"] = {
	"ヒノキの棒",
	WEAPON_CARD,
	101,
	"data/card/A01.png",
	IMAGE_ID("data/card/A01.png")[0],
	2,
	0,
	NO_EFFECT
	};
	cardData_map["木の盾"] = {
	"木の盾",
	ARMOR_CARD,
	201,
	"data/card/S01.png",
	IMAGE_ID("data/card/S01.png")[0],
	0,
	2,
	NO_EFFECT
	};
	cardData_map["回復の薬"] = {
	"回復の薬",
	ITEM_CARD,
	301,
	"data/card/I01.png",
	IMAGE_ID("data/card/I01.png")[0],
	5,
	0,
	RECOVERY_HP
	};
	cardData_map["回復の薬・改"] = {
	"回復の薬・改",
	ITEM_CARD,
	302,
	"data/card/I02.png",
	IMAGE_ID("data/card/I02.png")[0],
	10,
	0,
	RECOVERY_HP
	};
	cardData_map["回復の薬・真"] = {
	"回復の薬・真",
	ITEM_CARD,
	303,
	"data/card/I03.png",
	IMAGE_ID("data/card/I03.png")[0],
	15,
	0,
	RECOVERY_HP
	};
	cardData_map["狂化の丸薬"] = {
	"狂化の丸薬",
	ITEM_CARD,
	304,
	"data/card/I04.png",
	IMAGE_ID("data/card/I04.png")[0],
	5,
	0,
	ADD_ATTACK
	};
	cardData_map["狂化の丸薬・改"] = {
	"狂化の丸薬・改",
	ITEM_CARD,
	305,
	"data/card/I05.png",
	IMAGE_ID("data/card/I05.png")[0],
	7,
	0,
	ADD_ATTACK
	};
	cardData_map["狂化の丸薬・真"] = {
	"狂化の丸薬・真",
	ITEM_CARD,
	306,
	"data/card/I06.png",
	IMAGE_ID("data/card/I06.png")[0],
	10,
	0,
	ADD_ATTACK
	};
	cardData_map["硬化のオイル"] = {
	"硬化のオイル",
	ITEM_CARD,
	307,
	"data/card/I07.png",
	IMAGE_ID("data/card/I07.png")[0],
	5,
	0,
	ADD_DEFENSE
	};
	cardData_map["硬化のオイル・改"] = {
	"硬化のオイル・改",
	ITEM_CARD,
	308,
	"data/card/I08.png",
	IMAGE_ID("data/card/I08.png")[0],
	7,
	0,
	ADD_DEFENSE
	};
	cardData_map["硬化のオイル・真"] = {
	"硬化のオイル・真",
	ITEM_CARD,
	309,
	"data/card/I09.png",
	IMAGE_ID("data/card/I09.png")[0],
	10,
	0,
	ADD_DEFENSE
	};
	deck_vec.push_back(cardData_map["ヒノキの棒"]);
	deck_vec.push_back(cardData_map["ヒノキの棒"]);
	deck_vec.push_back(cardData_map["木の盾"]);
	deck_vec.push_back(cardData_map["木の盾"]);
	deck_vec.push_back(cardData_map["回復の薬"]);
	deck_vec.push_back(cardData_map["回復の薬・改"]);
	deck_vec.push_back(cardData_map["回復の薬・真"]);
	deck_vec.push_back(cardData_map["狂化の丸薬"]);
	deck_vec.push_back(cardData_map["狂化の丸薬・改"]);
	deck_vec.push_back(cardData_map["狂化の丸薬・真"]);
	deck_vec.push_back(cardData_map["硬化のオイル"]);
	deck_vec.push_back(cardData_map["硬化のオイル・改"]);
	deck_vec.push_back(cardData_map["硬化のオイル・真"]);


	return false;
}

CardData DeckMng::Choice(std::string name)
{
	return cardData_map[name];
}

CardData DeckMng::Choice(int num)
{
	for (auto card : deck_vec)
	{
		if (card.card_No == num)
		{
			return card;
		}
	}
	return CardData();
}

CardData DeckMng::Draw()
{
	hand_vec.clear();
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand_cardsize(0,deck_vec.size()-1);
	for (int x = 0; x < 5; x++)
	{
		int a = rand_cardsize(mt);
		hand_vec.push_back(deck_vec[a]);
	}
	
	return CardData();
}

std::vector<CardData> DeckMng::GetHand()
{

	return hand_vec;
}

void DeckMng::DelHand(int number)
{
	
	hand_vec.erase(hand_vec.begin()+number);
}

void DeckMng::ChangeHand(int num, CardData data)
{
	hand_vec[num] = data;
}
