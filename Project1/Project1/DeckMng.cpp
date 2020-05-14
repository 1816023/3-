#include <random>
#include <DxLib.h>
#include "DeckMng.h"

DeckMng::DeckMng()
{
}

DeckMng::~DeckMng()
{
}

bool DeckMng::Init()
{
	deck_vec.push_back({ "ƒqƒmƒL‚Ì–_",
	WEAPON_CARD,
	101,
	"data/card/A01.png",
	LoadGraph("data/card/A01.png"),
	2,
	0,
	5 });
	cardData_map["ƒqƒmƒL‚Ì–_"] = {
	"ƒqƒmƒL‚Ì–_",
	WEAPON_CARD,
	101,
	"data/card/A01.png",
	LoadGraph("data/card/A01.png"),
	2,
	0,
	5
	};
	cardData_map["–Ø‚Ì‚"] = {
	"–Ø‚Ì‚",
	ARMOR_CARD,
	201,
	"data/card/S01.png",
	LoadGraph("data/card/S01.png"),
	0,
	2,
	5
	};
	cardData_map["‰ñ•œ‚Ì–ò"] = {
	"‰ñ•œ‚Ì–ò",
	ITEM_CARD,
	301,
	"data/card/I01.png",
	LoadGraph("data/card/I01.png"),
	0,
	0,
	0
	};
	deck_vec.push_back(cardData_map["ƒqƒmƒL‚Ì–_"]);
	deck_vec.push_back(cardData_map["ƒqƒmƒL‚Ì–_"]);
	deck_vec.push_back(cardData_map["–Ø‚Ì‚"]);
	deck_vec.push_back(cardData_map["–Ø‚Ì‚"]);
	deck_vec.push_back(cardData_map["‰ñ•œ‚Ì–ò"]);
	deck_vec.push_back(cardData_map["‰ñ•œ‚Ì–ò"]);


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
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand_cardsize(0,deck_vec.size());

	hand_vec.push_back(deck_vec[rand_cardsize(mt)]);
	return CardData();
}

CardData DeckMng::Draw(int num)
{
	hand_vec.erase(hand_vec.begin()+num-1);

	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::uniform_int_distribution<> rand_cardsize(0, deck_vec.size());
	int a = rand_cardsize(mt);
	hand_vec.push_back(deck_vec[a]);
	return CardData();
}

std::vector<CardData> DeckMng::GetHand()
{

	return hand_vec;
}
