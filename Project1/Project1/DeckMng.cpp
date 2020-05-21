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
	cardData_map["�q�m�L�̖_"] = {
	"�q�m�L�̖_",
	WEAPON_CARD,
	101,
	"data/card/A01.png",
	IMAGE_ID("data/card/A01.png")[0],
	2,
	0,
	NO_EFFECT
	};
	cardData_map["�؂̏�"] = {
	"�؂̏�",
	ARMOR_CARD,
	201,
	"data/card/S01.png",
	IMAGE_ID("data/card/S01.png")[0],
	0,
	2,
	NO_EFFECT
	};
	cardData_map["�񕜂̖�"] = {
	"�񕜂̖�",
	ITEM_CARD,
	301,
	"data/card/I01.png",
	IMAGE_ID("data/card/I01.png")[0],
	5,
	0,
	RECOVERY_HP
	};
	cardData_map["�񕜂̖�E��"] = {
	"�񕜂̖�E��",
	ITEM_CARD,
	302,
	"data/card/I02.png",
	IMAGE_ID("data/card/I02.png")[0],
	10,
	0,
	RECOVERY_HP
	};
	cardData_map["�񕜂̖�E�^"] = {
	"�񕜂̖�E�^",
	ITEM_CARD,
	303,
	"data/card/I03.png",
	IMAGE_ID("data/card/I03.png")[0],
	15,
	0,
	RECOVERY_HP
	};
	cardData_map["�����̊ۖ�"] = {
	"�����̊ۖ�",
	ITEM_CARD,
	304,
	"data/card/I04.png",
	IMAGE_ID("data/card/I04.png")[0],
	5,
	0,
	ADD_ATTACK
	};
	cardData_map["�����̊ۖ�E��"] = {
	"�����̊ۖ�E��",
	ITEM_CARD,
	305,
	"data/card/I05.png",
	IMAGE_ID("data/card/I05.png")[0],
	7,
	0,
	ADD_ATTACK
	};
	cardData_map["�����̊ۖ�E�^"] = {
	"�����̊ۖ�E�^",
	ITEM_CARD,
	306,
	"data/card/I06.png",
	IMAGE_ID("data/card/I06.png")[0],
	10,
	0,
	ADD_ATTACK
	};
	cardData_map["�d���̃I�C��"] = {
	"�d���̃I�C��",
	ITEM_CARD,
	307,
	"data/card/I07.png",
	IMAGE_ID("data/card/I07.png")[0],
	5,
	0,
	ADD_DEFENSE
	};
	cardData_map["�d���̃I�C���E��"] = {
	"�d���̃I�C���E��",
	ITEM_CARD,
	308,
	"data/card/I08.png",
	IMAGE_ID("data/card/I08.png")[0],
	7,
	0,
	ADD_DEFENSE
	};
	cardData_map["�d���̃I�C���E�^"] = {
	"�d���̃I�C���E�^",
	ITEM_CARD,
	309,
	"data/card/I09.png",
	IMAGE_ID("data/card/I09.png")[0],
	10,
	0,
	ADD_DEFENSE
	};
	deck_vec.push_back(cardData_map["�q�m�L�̖_"]);
	deck_vec.push_back(cardData_map["�q�m�L�̖_"]);
	deck_vec.push_back(cardData_map["�؂̏�"]);
	deck_vec.push_back(cardData_map["�؂̏�"]);
	deck_vec.push_back(cardData_map["�񕜂̖�"]);
	deck_vec.push_back(cardData_map["�񕜂̖�E��"]);
	deck_vec.push_back(cardData_map["�񕜂̖�E�^"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�E��"]);
	deck_vec.push_back(cardData_map["�����̊ۖ�E�^"]);
	deck_vec.push_back(cardData_map["�d���̃I�C��"]);
	deck_vec.push_back(cardData_map["�d���̃I�C���E��"]);
	deck_vec.push_back(cardData_map["�d���̃I�C���E�^"]);


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
