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
	0
	};
	cardData_map["ƒqƒmƒL‚Ì–_"] = {
	"ƒqƒmƒL‚Ì–_",
	WEAPON_CARD,
	101,
	"data/card/A01.png",
	IMAGE_ID("data/card/A01.png")[0],
	2,
	0
	};
	cardData_map["–Ø‚Ì‚"] = {
	"–Ø‚Ì‚",
	ARMOR_CARD,
	201,
	"data/card/S01.png",
	IMAGE_ID("data/card/S01.png")[0],
	0,
	2
	};
	cardData_map["‰ñ•œ‚Ì–ò"] = {
	"‰ñ•œ‚Ì–ò",
	ITEM_CARD,
	301,
	"data/card/I01.png",
	IMAGE_ID("data/card/I01.png")[0],
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
